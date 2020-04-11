/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework application starter.
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      19.02.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Framework settings.
 *
 ******************************************************************************/


#ifndef VTMINE_FRAMEWORK_CORE_FRAMEWORK_SETTINGS_H
#define VTMINE_FRAMEWORK_CORE_FRAMEWORK_SETTINGS_H


#include <string>
#include <vector>

#include "../extlib/json.hpp"


namespace vtmine {

//namespace configKeys {
//    const char* pluginsConfiguration = "pluginsConfig";
//    const char* pluginBaseDir = "pluginBaseDir";
//    const char* pluginFileNames = "pluginFileNames";
//    const char* mainPlugin = "mainPlugin";
//    const char* allowOptimize = "allowOptimizeFileList";
//}

/***************************************************************************//**
 *  Represents framework settings obtained from configuration parameters.
 ******************************************************************************/
class FrameworkSettings {
public:
    /** \brief Framework settings contructor.
     * \param plugins -- names of plugin files.
     */
    FrameworkSettings(std::string configFileName);


    /** \brief Parses plugin configuration from config file.
     * \param configFileName -- name of configuration file.
     * \return True in case of success.
     */
    bool parseConfigJSON(nlohmann::json& pluginsConfig);

public:
    // Getters

    std::vector<std::string> getPluginFileNames() const
    {
        return _pluginFileNames;
    }

    std::string getMainPluginId() const { return _mainPluginId; }

    bool getAllowOptimize() const { return _allowOptimizeFileList; }

private:
    /// Configuration file name.
    std::string _configFileName;

    /// Plugin files.
    std::vector<std::string> _plugins;

    /// Names of plugin files to be loaded.
    std::vector<std::string> _pluginFileNames;

    /// Plugin to be loaded first.
    std::string _mainPluginId;

    /// If true, the manager can perform a topological sort
    /// on plugins to load them in linear time later.
    bool _allowOptimizeFileList = true;

    // Helper methods for json parsing.

    std::string getPluginsBaseDir(nlohmann::json config);

    std::vector<std::string> getPluginFileNames(nlohmann::json config);

    std::string getMainPluginId(nlohmann::json config);

    bool getAllowOptimize(nlohmann::json config);


    // configuration JSON keys

    const char* pluginsConfiguration = "pluginsConfig";
    const char* pluginBaseDir = "pluginBaseDir";
    const char* pluginFileNames = "pluginFileNames";
    const char* mainPlugin = "mainPlugin";
    const char* allowOptimize = "allowOptimizeFileList";

}; // class FrameworkSettings

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_FRAMEWORK_SETTINGS_H
