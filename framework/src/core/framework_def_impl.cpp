/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/

#include "framework_def_impl.h"
#include "../extlib/json.hpp"

namespace vtmine {

FrameworkDefImpl::~FrameworkDefImpl()
{
    delete _settings;
    delete _pluginManager;
}


void FrameworkDefImpl::init(CmdLineParams& params)
{ 
    _settings = new FrameworkSettings(params.getConfigFileName());
    _pluginManager = new PluginManager();
    nlohmann::json pluginsConfig;
    if (_settings->parseConfigJSON(pluginsConfig))
        _pluginManager->parsePluginsConfig(pluginsConfig);
}


} // namespace vtmine
