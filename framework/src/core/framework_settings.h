/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework framework settings.
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
#include <QString>
#include <QDir>

#include "../extlib/json.hpp"


namespace vtmine {

/***************************************************************************//**
 *  Represents framework settings obtained from configuration parameters.
 ******************************************************************************/
class FrameworkSettings {
public:
    /** \brief Framework settings contructor.
     *  \param plugins -- names of plugin files.
     */
    FrameworkSettings(const std::string& configFileName);


    /** \brief Parses plugin configuration from config file.
     *  \return True in case of success.
     */
    bool parseConfigJSON();

public:
    // Getters

    // Plugins configuration

    /// Getter for plugin files names.
    std::vector<QString> getPluginFileNames() const
    {
        return _pluginFileNames;
    }

    /// Getter for plugins base directory.
    QDir getPluginsBaseDir() const { return _basepluginsDir; }

    /// Getter for main plugin ID.
    std::string getMainPluginId() const { return _mainPluginId; }

    /// Getter for optimization permission flag.
    bool getAllowOptimize() const { return _allowOptimizeFileList; }


    // Logger configuration

    /// Getter for logger type.
    std::string getLoggerType() const { return _outputType; }

    /// Getter for log file name.
    std::string getLogFileName() const { return _fileName; }

    /// Getter for logger output level.
    std::string getOutputLevel() const { return _minOutputLevel; }

protected:
    /// Configuration file name.
    std::string _configFileName;

protected:
    // Plugins settings

    /// Plugin files.
    std::vector<std::string> _plugins;

    /// Base plugins directory.
    QDir _basepluginsDir;

    /// Names of plugin files to be loaded.
    std::vector<QString> _pluginFileNames;

    /// ID of the main plugin.
    std::string _mainPluginId;

    /// If true, the manager can perform a topological sort on plugins to load
    /// them in linear time later.
    bool _allowOptimizeFileList = true;

protected:

    // Logger settings

    /// Logger type: console, file, etc.
    std::string _outputType;

    /// Log file name for file logger.
    std::string _fileName = "";

    /// Minimum message level for output.
    std::string _minOutputLevel = "INFO";

protected:
    // Helper methods for parsing.

    // Plugins configuration

    /** \brief Gets plugins base directory from configuration JSON.
     *  \param config -- configuration JSON.
     *  \return Plugins base directory.
     */
    std::string getPluginsBaseDir(const nlohmann::json& config);

    /** \brief Gets plugin files names from configuration JSON.
     *  \param config -- configuration JSON.
     *  \return Plugin files names.
     */
    std::vector<QString> getPluginFileNames(const nlohmann::json& config);

    /** \brief Gets main plugin ID from configuration JSON.
     *  \param config -- configuration JSON.
     *  \return Main plugin ID.
     */
    std::string getMainPluginId(const nlohmann::json& config);

    /** \brief Gets optimization permission flag from configuration JSON.
     *  \param config -- configuration JSON.
     *  \return Optimization permission flag.
     */
    bool getAllowOptimize(const nlohmann::json& config);

protected:
    // Logger configuration

    /** \brief Gets logger type from configuration JSON.
     *  \param config -- configuration JSON.
     *  \return Logger output type.
     */
    std::string getOutputType(const nlohmann::json& config);

    /** \brief Gets log file name from configuration JSON.
     *  \param config -- configuration JSON.
     *  \return Log file name.
     */
    std::string getFileName(const nlohmann::json& config);

    /** \brief Gets minimum log level from configuration JSON.
     *  \param config -- configuration JSON.
     *  \return Minimum outout level.
     */
    std::string getOutputLevel(const nlohmann::json& config);

protected:
    // configuration JSON keys

    // plugins configuration
    const char* pluginsConfiguration = "pluginsConfig";
    const char* pluginBaseDir = "pluginBaseDir";
    const char* pluginFileNames = "pluginFileNames";
    const char* mainPlugin = "mainPlugin";
    const char* allowOptimize = "allowOptimizeFileList";

    // logger configuration
    const char* loggerConfiguration = "loggerConfig";
    const char* outputType = "outputType";
    const char* fileName = "fileName";
    const char* minOutputLevel = "minOutputLevel";

}; // class FrameworkSettings

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_FRAMEWORK_SETTINGS_H
