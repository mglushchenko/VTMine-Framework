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
#include "textfilelogger.h"
#include "../extlib/json.hpp"

namespace vtmine {

FrameworkDefImpl::~FrameworkDefImpl()
{
    delete _pluginManager;

    _logger->close();
    delete _logger;

    delete _settings; 
}


void FrameworkDefImpl::init(const CmdLineParams& params)
{ 
    _settings = new FrameworkSettings(params.getConfigFileName());

    if (!_settings->parseConfigJSON())
        throw VTMException("Invalid configuration file");

    _logger = makeLogger();
    _logger->open();

    _pluginManager = new PluginManager(this, _logger);
    _pluginManager->loadPlugins();

    std::string mainPluginID = _pluginManager->getMainPluginID();
    IPlugin* mainPlugin = (IPlugin*)_pluginManager->getPlugins()[mainPluginID];
    if (mainPlugin)
        mainPlugin->activate(this);
}

ILogger* FrameworkDefImpl::makeLogger()
{
    std::string outputLevel = _settings->getOutputLevel();
    if (_settings->getLoggerType() == "textFile")
    {
        std::string logFile = _settings->getLogFileName();
        return new TextFileLogger(_settings);
    }

    // default output stream is std::cout
    return new StreamLogger(_settings);
}


} // namespace vtmine
