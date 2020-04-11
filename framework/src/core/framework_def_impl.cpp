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


void FrameworkDefImpl::init(const CmdLineParams& params)
{ 
    _settings = new FrameworkSettings(params.getConfigFileName());

    nlohmann::json pluginsConfig;
    if (!_settings->parseConfigJSON(pluginsConfig))
        throw VTMException("Invalid configuration file");

    _pluginManager = new PluginManager(_settings);
    // TODO: initialize logger
}


} // namespace vtmine
