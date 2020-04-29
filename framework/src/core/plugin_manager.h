/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework plugin manager.
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
#include <unordered_map>

#include "../extlib/json.hpp"

#include "framework_settings.h"
#include "iplugin.h"
#include "baseunit.h"


namespace vtmine {

class BaseUnit;

/***************************************************************************//**
 *  Plugin manager.
 ******************************************************************************/
class PluginManager: public BaseUnit {

public:
    typedef std::vector<QPluginLoader*> PluginLoadersList;

    enum class LoadResult {
        nothing = 0, loaded, exclude, regFailed
    };

public:
    /// Class constructor.
    PluginManager(const IFramework* owner, ILogger* logger);

    /// Class destructor.
    ~PluginManager();

    /// Performs plugin loading.
    void loadPlugins();

    /// Performs plugin unloading.
    void unloadPlugins();

    /// Main plugin ID getter.
    std::string getMainPluginID() const { return _mainPluginId; }

    /// Plugins map getter.
    std::unordered_map<std::string, QObject*> getPlugins() const { return _plugins; }

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

protected:
    /// Names of plugin files to be loaded.
    std::vector<QString> _pluginFileNames;

    /// ID of the main plugin.
    std::string _mainPluginId;

    /// If true, the manager can perform a topological sort
    /// on plugins to load them in linear time later.
    bool _allowOptimizeFileList = true;

    /// Candidates for loading.
    PluginLoadersList _candidates;

    /// Map of plugins and their IDs.
    std::unordered_map<std::string, QObject*> _plugins;

    QDir _basePluginsDir;

    /// Flag indicating whether the plugins have already been loaded.
    bool _alreadyLoaded = false;
};

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_H_
