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

#include "framework_def_impl.h"
#include "plugin_manager.h"
#include "vtmexception.h"


namespace vtmine {

PluginManager::PluginManager(const IFramework* owner):
    BaseUnit(owner)
{
     FrameworkSettings* settings = ((FrameworkDefImpl*)owner)->getSettings();
    _pluginFileNames = settings->getPluginFileNames();
    _mainPluginId = settings->getMainPluginId();
    _allowOptimizeFileList = settings->getAllowOptimize();

    _unitName = "Plugin manager";
}

PluginManager::~PluginManager()
{
    unloadPlugins();
}

void PluginManager::loadPlugins()
{
    if(_alreadyLoaded)
    {
        logError("Plugins already loaded!");
        throw VTMException("Plugins already loaded!");
    }

    prepareCandidatesList();
    loadCandidates();

    _alreadyLoaded = true;
}

void PluginManager::unloadPlugins()
{
    for (std::pair<std::string, QObject*> curr: _plugins)
    {
        if (!((IPlugin*)curr.second)->deactivate())
        {
            logError(("Failed to deactivate plugin " + curr.first + ".").c_str());
        }
    }
}

void PluginManager::prepareCandidatesList()
{
   for (const QString& plugin: _pluginFileNames)
   {
       QPluginLoader* curLoader = new QPluginLoader(plugin);
       processPluginLoader(curLoader);
   }
}

void PluginManager::processPluginLoader(QPluginLoader* curLoader)
{
    QObject* curPluginInstance = curLoader->instance();
    if(!curPluginInstance)
    {
        QString errStr = curLoader->errorString();
        logError("Not a QT plugin!");

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

            if(lr == LoadResult::exclude || lr == LoadResult::regFailed)
            {
                (*cur)->unload();
                delete (*cur);

                logError("Failed to load plugin!");

                cur = _candidates.erase(cur);

                hasExecutions = true;
                continue;
            }

            if(lr == LoadResult::loaded)
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
    {
        logError("Plugin with this ID has already been loaded!");

        return LoadResult::exclude;
    }

    LoadResult lres = loadPlugin(curLoader, curPluginInstance, curPlugin);

    return lres;
}

PluginManager::LoadResult PluginManager::loadPlugin(QPluginLoader *loader,
                                                    QObject *instance, IPlugin *plugin)
{
    bool res = plugin->activate(_owner);
    if (!res)
        return LoadResult::regFailed;

    const std::string& id = plugin->getID().toStdString();
    _plugins[id] = instance;
    return LoadResult::loaded;
}

bool PluginManager::checkForDuplicateID(IPlugin* plugin)
{
    const std::string& id = plugin->getID().toStdString();
    return _plugins.find(id) != _plugins.end();
}

} // namespace vtmine
