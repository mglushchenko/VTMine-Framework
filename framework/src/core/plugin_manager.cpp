/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/


#include <iostream>

#include "plugin_manager.h"
#include "vtmexception.h"


namespace vtmine {

PluginManager::PluginManager(const FrameworkSettings* settings)
{
    _pluginFileNames = settings->getPluginFileNames();
    _mainPluginId = settings->getMainPluginId();
    _allowOptimizeFileList = settings->getAllowOptimize();
}

void PluginManager::loadPlugins()
{
    if(_alreadyLoaded)
        throw VTMException("Plugins already loaded!");

    prepareCandidatesList();
    loadCandidates();

    _alreadyLoaded = true;
}

void PluginManager::prepareCandidatesList()
{
   for (std::string plugin: _pluginFileNames)
   {
       // ?: should it be a QString from the start or is this type cast OK?
       QPluginLoader* curLoader = new QPluginLoader((const QString&)plugin);
       processPluginLoader(curLoader);
   }
}

void PluginManager::processPluginLoader(QPluginLoader* curLoader)
{
    QObject* curPluginInstance = curLoader->instance();
    if(!curPluginInstance)
    {
        QString errStr = curLoader->errorString();
        std::cout << errStr.toStdString();

        delete curLoader;
        return;
    }

    IPlugin* curPlugin = qobject_cast<IPlugin*>(curPluginInstance);
    if(!curPlugin)
    {
        curLoader->unload();
        delete curLoader;
        return;
    }
    _candidates.push_back(curLoader);
}

void PluginManager::loadCandidates()
{
    // _plugins
    bool incomplete;                /// флаг, указывающий на то, что хотя бы один плагин за полный оборот не был загружен
    bool hasExecutions;             /// флаг, указывающий на то, что хотя бы один плагин за полный оборот был выполнен

    do {
        incomplete = false;
        hasExecutions = false;

        PluginLoadersList::iterator cur = _candidates.begin();
        while(cur != _candidates.end())
        {
            LoadResult lr = tryLoadPlugin(*cur);

            if(lr == lrExclude || lr == lrRegFailed)
            {
                (*cur)->unload();
                delete (*cur);

                cur = _candidates.erase(cur);

                hasExecutions = true;
                continue;
            }

            if(lr == lrLoaded)
            {
                cur = _candidates.erase(cur);
                hasExecutions = true;
                continue;
            }

            ++cur;

        } // while

        incomplete = !_candidates.empty();
        if(!hasExecutions && incomplete)
            break;
    } while(incomplete);  // do .. while
}

PluginManager::LoadResult PluginManager::tryLoadPlugin(QPluginLoader *curLoader)
{
    QObject* curPluginInstance = curLoader->instance();
    IPlugin* curPlugin = qobject_cast<IPlugin*>(curPluginInstance);

    if(checkForDuplicateID(curPlugin))
        return lrExclude;

    LoadResult lres = loadPlugin(curLoader, curPluginInstance, curPlugin);

    return lres;
}

PluginManager::LoadResult PluginManager::loadPlugin(QPluginLoader *loader,
                                                    QObject *instance, IPlugin *plugin)
{
    bool res = plugin->registerItself(_owner);
    if (!res)
        return lrRegFailed;

    std::string id = plugin->getID();
    _plugins[id] = instance;
    return lrLoaded;
}

bool PluginManager::checkForDuplicateID(IPlugin* plugin)
{
    std::string id = plugin->getID();
    return _plugins.find(id) != _plugins.end();
}

} // namespace vtmine
