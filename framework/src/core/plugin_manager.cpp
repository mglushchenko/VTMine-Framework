/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/


#include "plugin_manager.h"


namespace vtmine {

void PluginManager::parsePluginsConfig(nlohmann::json pluginsConfig)
{

    // TODO: Обработку случаев, когда соотв. ключей нет

    // Нужен доп. слой абстракции между конкретным компонентом представления
    // настроек и собственного самими (высокоуровневыми) настройками:
    //      pluginsConfig["pluginBaseDir"].get<std::string>() — плохо
    //      getPluginBaseDir() ← метод, который сам знает, откуда взять настройки
    //
    //  std::string getPluginBaseDir() const { pluginsConfig["pluginBaseDir"].get<std::string>() + проверка, что строка не пустая...}

    //      pluginsConfig["pluginBaseDir"] ← плохо
    //      pluginsConfig[SET_PLUGIN_BASE_DIR] ← лучше, где
    //      const char* SET_PLUGIN_BASE_DIR = "pluginBaseDir";


    std::string base_dir = pluginsConfig["pluginBaseDir"].get<std::string>();
    _pluginFileNames = pluginsConfig["pluginFileNames"].
            get<std::vector<std::string>>();
    for (size_t i = 0; i < _pluginFileNames.size(); ++i)
    {
        std::string& curPluginName = _pluginFileNames[i];

        if(curPluginName.empty())       // если пустое имя файла, как мы реагируем?
            ;                           // скорее всего, в лог нужно кинуть сообщения уровня WARN и двигать дальше

        // уровни сообщений в лог: CRIT, WARN, INFO, VERB

        if (_pluginFileNames[i][0] == '?')
            _pluginFileNames[i] = base_dir + _pluginFileNames[i];
    }

    _mainPluginId = pluginsConfig["mainPlugin"].get<std::string>();

    if (pluginsConfig["allowOptimizeFileList"] != nullptr &&
            !pluginsConfig["allowOptimizeFileList"].get<bool>())
        _allowOptimizeFileList = false;
        // TODO: ^^^ getter к нему

    // TODO: parsing settings for each plugin and topological sorting
    //?: how are dependencies between plugins speicifed in config?
}

} // namespace vtmine
