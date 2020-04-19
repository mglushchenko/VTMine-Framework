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
   for (std::string plugin: _pluginFileNames) // ← для QString это замечание, возможно, будет неактуально,
                                              // но для обычных строк используем const std::string&
   {

       // TODO: когда работаем изначально с Qt (загружаем настройки УЖЕ из
       // окружения Qt, т.к. есть MainApplication), то решаем СРАЗУ работать c QString

       // ?: should it be a QString from the start or is this type cast OK? ←←←← YES!
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
        std::cout << errStr.toStdString();          // TODO: работаем тут с логом!

        // TODO: возможно, какие-то (выработать!) настройки должны регулировать поведение в
        // ситуации, когда отдельный файл-плагина почему-то не загружается

        delete curLoader;
        return;
    }

    IPlugin* curPlugin = qobject_cast<IPlugin*>(curPluginInstance);
    if(!curPlugin)
    {
        curLoader->unload();
        delete curLoader;                           // TODO: работаем с логом, и то же про настройки
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
                // TODO: логгировать информацию о неуспешности + причина неуспешности

                (*cur)->unload();
                delete (*cur);

                cur = _candidates.erase(cur);

                hasExecutions = true;
                continue;
            }

            if(lr == lrLoaded)
            {
                // TODO: добавить коллекцию (vector) с указателями на загруженные
                // плагины + имена соответств. файлов (через лоадеры?!)
                // и каждый раз при успешной загрузке добавлять соотв. элемент
                // в коллекцию. Ее впоследствии можно/нужно будет использовать
                // для 1) выгрузки загруженных плагинов в порядке, обратном их
                // загрузки (вообще, плагины нужно (написать в док!) обязать уметь
                // выгружать максимально корректно даже в случае, когда его,
                // плагина, зависимости уже утрачены)
                // 2) для подготовки adviseList (топологически сортированный список
                // зависимостей, см. параметр _allowOptimizeFileList)


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

// TODO: вынести для дальнейшего размышления (Glo-карточка? док?) систему
// глобальных уведомлений плагинов о событиях фреймворка — например, что такой-то
// плагин был уже выгружен — сделать через: систему сигналов/слотов ЛИБО, что вероятнее
// добавить соответствующий интерфейс в сам плагин



PluginManager::LoadResult PluginManager::tryLoadPlugin(QPluginLoader *curLoader)
{                                                                //  ^ TODO: везде проверить кодстайл
    QObject* curPluginInstance = curLoader->instance();
    IPlugin* curPlugin = qobject_cast<IPlugin*>(curPluginInstance);

    if(checkForDuplicateID(curPlugin))      // TODO: ругаться в логгер, м.б. здесь эксцепция, если соотв. настройки?
        return lrExclude;

    LoadResult lres = loadPlugin(curLoader, curPluginInstance, curPlugin);

    return lres;
}

PluginManager::LoadResult PluginManager::loadPlugin(QPluginLoader *loader,
                                                    QObject *instance, IPlugin *plugin)
{
    bool res = plugin->registerItself(_owner);  // TODO: переименовать в activate
    if (!res)
        return lrRegFailed;

    std::string id = plugin->getID();       // TODO: const std::string& id
    _plugins[id] = instance;

    return lrLoaded;
}

bool PluginManager::checkForDuplicateID(IPlugin* plugin)
{
    std::string id = plugin->getID();
    return _plugins.find(id) != _plugins.end();
}

} // namespace vtmine
