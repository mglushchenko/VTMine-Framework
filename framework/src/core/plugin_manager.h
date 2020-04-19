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


#include <QPluginLoader>

#include "../extlib/json.hpp"
#include "framework_settings.h"
#include "iplugin.h"
#include "framework.h"


namespace vtmine {

/***************************************************************************//**
 *  Default plugin manager.
 ******************************************************************************/
class PluginManager {

public:
    typedef std::vector<QPluginLoader*> PluginLoadersList;

    enum LoadResult {
            lrNothing,              ///< plugin was not loaded, nothing to do
            lrLoaded,               ///< plugin was loaded, delete from candidate list
            lrExclude,              ///< plugin was not loaded and should be excluded
            lrRegFailed,            ///< there is an error on registerItself stage of plugin loading
                                    ///< Should behave the same way as where a plugin is excluded
                                    /// + some resources cleanup
        }; // enum LoadResult

public:
    PluginManager(const FrameworkSettings* settings);
    //virtual ~PluginManager() {}

    /// Performs plugin loading.
    virtual void loadPlugins();

protected:
    /// Prepares plugins for loading.
    void prepareCandidatesList();

    /**
     * \brief Proccesses a plugin loader and tries to add it to the list.
     * \param curLoader -- Loader to be proccessed.
     */
    void processPluginLoader(QPluginLoader* curLoader);

    /// Load plugins from the candidates list according to their dependencies.
    void loadCandidates();

    /**
     * \brief Tries to load a plugin.
     * \param curLoader -- Current plugin loader.
     * \return Load result.
     */
    LoadResult tryLoadPlugin(QPluginLoader* curLoader);

    /**
     * \brief Loads plugin and adds it to the map of loaded plugins.
     * \param loader -- Plugin loader.
     * \param instance -- Plugin instance.
     * \param plugin -- Plugin interface.
     * \return Load result.
     */
    LoadResult loadPlugin(QPluginLoader* loader, QObject* instance, IPlugin* plugin);

    /// Checks if plugin with given ID has already been loaded.
    bool checkForDuplicateID(IPlugin* plugin);

private:
    /// Names of plugin files to be loaded.
    std::vector<std::string> _pluginFileNames;

    /// Plugin to be loaded first.
    std::string _mainPluginId;

    /// If true, the manager can perform a topological sort
    /// on plugins to load them in linear time later.
    bool _allowOptimizeFileList = true;

    PluginLoadersList _candidates;
    std::map<std::string, QObject*> _plugins;

    bool _alreadyLoaded;

    IFramework* _owner;
};

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_H_
