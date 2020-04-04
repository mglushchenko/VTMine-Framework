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
 *  Plugin manager.
 *
 ******************************************************************************/

#ifndef VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_H_
#define VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_H_


#include "../extlib/json.hpp"


namespace vtmine {

/***************************************************************************//**
 *  Default plugin manager.
 ******************************************************************************/
class PluginManager {
public:
    PluginManager() {}
    //virtual ~PluginManager() {}
    //virtual void loadPlugins();

    /// Parses configuration of plugins.
    void parsePluginsConfig(nlohmann::json pluginsConfig);

private:
    /// Names of plugin files to be loaded.
    std::vector<std::string> _pluginFileNames;

    /// Plugin to be loaded first.
    std::string _mainPluginId;

    /// If true, the manager can perform a topological sort
    /// on plugins to load them in linear time later.
    bool _allowOptimizeFileList = true;
};

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_H_
