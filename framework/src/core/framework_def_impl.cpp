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


// TODO: сделать конструктор для фреймворка

FrameworkDefImpl::~FrameworkDefImpl()
{
    delete _settings;
    delete _pluginManager;
}


// Важный компонентный вопрос: в каких случаях инициализация фреймворка м.б.
// разнесена с его конструированием?
void FrameworkDefImpl::init(CmdLineParams& params)
{ 
    // 1) вычитываем настройки из заданного конфига — важно
    _settings = new FrameworkSettings(params.getConfigFileName());    

    // 2) Логгер — подготовить, открыть, начать дальше все сообщения писать в него
    //_logger = new DefLoggerImpl(_settings); // ← логгер, как и все компоненты, сам вытащит нужные ему настройки


    // 3) Менеджер плагинов
    _pluginManager = new PluginManager();
    //pluginManager = new PluginManager(_settings); // ← ПМ, как и все компоненты, сам вытащит нужные ему настройки


    // TODO: убрать в соотв. компоненты
    nlohmann::json pluginsConfig;
    if (_settings->parseConfigJSON(pluginsConfig))
        _pluginManager->parsePluginsConfig(pluginsConfig);
}


} // namespace vtmine
