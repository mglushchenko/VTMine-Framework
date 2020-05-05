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


FrameworkSettings::FrameworkSettings(const std::string& configFileName)
{
    _configFileName = configFileName;
}


bool FrameworkSettings::parseConfigJSON()
{
    std::ifstream configFile(_configFileName);
    if (!configFile)
        throw VTMException("Couldn't open configuration file."
                           "Perhaps it doesn't exist or the path is incorrect");

    // json parsing
    nlohmann::json configJSON;
    configFile >> configJSON;
    configFile.close();

    // plugin configuration parsing
    if (configJSON.find(pluginsConfiguration) == configJSON.end())
    {
        throw VTMException("No plugins configuration provided.");
    }
    nlohmann::json pluginsConfig = configJSON[pluginsConfiguration];
    std::string baseDir = getPluginsBaseDir(pluginsConfig);
    _pluginFileNames = getPluginFileNames(pluginsConfig);

    _mainPluginId = getMainPluginId(pluginsConfig);
    _allowOptimizeFileList = getAllowOptimize(pluginsConfig);

    // logger configuration parsing
    if (configJSON.find(loggerConfiguration) == configJSON.end())
    {
        throw VTMException("No logger configuration provided.");
    }
    nlohmann::json loggerConfig = configJSON[loggerConfiguration];
    _outputType = getOutputType(loggerConfig);
    if (_outputType == "textFile")
        _fileName = getFileName(loggerConfig);
    _minOutputLevel = getOutputLevel(loggerConfig);

    return true;
}

std::string FrameworkSettings::getPluginsBaseDir(const nlohmann::json& config)
{
    if (config.find(pluginBaseDir) == config.end())
    {
        std::cerr << "No plugins base directory set\n";
        return "";
    }

    std::string baseDir = config[pluginBaseDir].get<std::string>();
    _basePluginsDir = QDir(QString::fromStdString(baseDir));

    return baseDir;
}

std::vector<QString> FrameworkSettings::getPluginFileNames(const nlohmann::json& config)
{
    if (config.find(pluginFileNames) == config.end())
    {
        std::cout << "No plugins passed\n";
        return std::vector<QString>();
    }

    std::vector<std::string> tmp = config[pluginFileNames].
            get<std::vector<std::string>>();

    std::vector<QString> res;
    for (std::string str: tmp)
        res.push_back(QString::fromStdString(str));
    return res;
}

std::string FrameworkSettings::getMainPluginId(const nlohmann::json& config)
{
    if (config.find(mainPlugin) == config.end())
    {
        std::cout << "No main plugin set\n";
        return "";
    }

    return config[mainPlugin].get<std::string>();
}

bool FrameworkSettings::getAllowOptimize(const nlohmann::json& config)
{
    // no logging because it's a normal situation
    if (config.find(allowOptimize) == config.end())
        return true;

    return config[allowOptimize].get<bool>();
}

std::string FrameworkSettings::getOutputType(const nlohmann::json& config)
{
    if (config.find(outputType) == config.end())
        throw VTMException("Logger type not specified");

    return config[outputType];
}

std::string FrameworkSettings::getFileName(const nlohmann::json& config)
{
    if (config.find(fileName) == config.end())
        throw VTMException("Logger type is text file, yet "
                           "no output file was specified");
    return config[fileName];
}

std::string FrameworkSettings::getOutputLevel(const nlohmann::json& config)
{
    if (config.find(minOutputLevel) == config.end())
        return "INFO";

    return config[minOutputLevel];
}

} // namespace vtmine
