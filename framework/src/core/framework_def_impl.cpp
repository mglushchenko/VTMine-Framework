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
    delete _pluginManager;      // TODO: порядок удаления — обычно стековый
}


void FrameworkDefImpl::init(const CmdLineParams& params)
{ 
    _settings = new FrameworkSettings(/*this,*/params.getConfigFileName());

    nlohmann::json pluginsConfig;                           // TODO: имя неудачное
    if (!_settings->parseConfigJSON(pluginsConfig))
        throw VTMException("Invalid configuration file");

    // TODO: initialize logger
    // в принципе, параметры логгирования (имя файла, где он лежит, тип компонента
    // логгирование — все это может быть востребовано в настройках)
    // _logger = new..... логгер опр. типа с параметрами из настроек
    //  если получится (скорее всего, с учетом анализа настроек) много кода,
    //  лучше вынести это в отдельный метод: ( _logger = ) makeLogger()


    _pluginManager = new PluginManager(/*this,*/ _settings);



}


} // namespace vtmine
