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
    std::string base_dir = pluginsConfig["pluginBaseDir"].get<std::string>();
    _pluginFileNames = pluginsConfig["pluginFileNames"].
            get<std::vector<std::string>>();
    for (size_t i = 0; i < _pluginFileNames.size(); ++i)
    {
        if (_pluginFileNames[i][0] == '?')
            _pluginFileNames[i] = base_dir + _pluginFileNames[i];
    }

    _mainPluginId = pluginsConfig["mainPlugin"].get<std::string>();

    if (pluginsConfig["allowOptimizeFileList"] != nullptr &&
            !pluginsConfig["allowOptimizeFileList"].get<bool>())
        _allowOptimizeFileList = false;

    // TODO: parsing settings for each plugin and topological sorting
    //?: how are dependencies between plugins speicifed in config?
}

} // namespace vtmine
