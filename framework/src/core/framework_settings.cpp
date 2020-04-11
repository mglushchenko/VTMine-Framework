/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/


#include <fstream>
#include <iostream>

#include "framework_settings.h"
#include "vtmexception.h"


namespace vtmine {


FrameworkSettings::FrameworkSettings(std::string configFileName)
{
    _configFileName = configFileName;
}


bool FrameworkSettings::parseConfigJSON(nlohmann::json& pluginsConfig)
{
    std::ifstream configFile(_configFileName);
    if (!configFile)
        throw VTMException("Couldn't open configuration file."
                           "Perhaps it doesn't exist or the path is incorrect");

    // json parsing
    nlohmann::json configJSON;
    configFile >> configJSON;
    configFile.close();

    if (configJSON.find(pluginsConfiguration) == configJSON.end())
    {
        throw VTMException("No plugins configuration provided.");
    }
    pluginsConfig = configJSON[pluginsConfiguration];
    std::string baseDir = getPluginsBaseDir(pluginsConfig);
    _pluginFileNames = getPluginFileNames(pluginsConfig);
    for (size_t i = 0; i < _pluginFileNames.size(); ++i)
    {
        if (!_pluginFileNames[i].empty() && _pluginFileNames[i][0] == '?')
            _pluginFileNames[i] = baseDir + _pluginFileNames[i];
    }

    _mainPluginId = getMainPluginId(pluginsConfig);
    _allowOptimizeFileList = getAllowOptimize(pluginsConfig);

    return true;
}

std::string FrameworkSettings::getPluginsBaseDir(nlohmann::json config)
{
    if (config.find(pluginBaseDir) == config.end())
    {
        // TODO: redirect message to logger
        std::cout << "No plugins base directory set\n";
        return "";
    }

    return config[pluginBaseDir].get<std::string>();
}

std::vector<std::string> FrameworkSettings::getPluginFileNames(nlohmann::json config)
{
    if (config.find(pluginFileNames) == config.end())
    {
        std::cout << "No plugins passed\n";
        return std::vector<std::string>();
    }

    return config[pluginFileNames].get<std::vector<std::string>>();
}

std::string FrameworkSettings::getMainPluginId(nlohmann::json config)
{
    if (config.find(mainPlugin) == config.end())
    {
        std::cout << "No main plugin set\n";
        return "";
    }

    return config[mainPlugin].get<std::string>();
}

bool FrameworkSettings::getAllowOptimize(nlohmann::json config)
{
    // no logging because it's a normal situation
    if (config.find(allowOptimize) == config.end())
        return true;

    return config[allowOptimize].get<bool>();
}

} // namespace vtmine
