/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/

#include <fstream>

#include "framework_settings.h"
#include "vtmexception.h"


namespace vtmine {

FrameworkSettings::FrameworkSettings(std::string configFileName)
{
    _configFileName = configFileName;
}


bool FrameworkSettings::parseConfigJSON(nlohmann::json& pluginsConfig)
{
    std::ifstream configFile(_configFileName);
    if (!configFile)
        throw VTMException("Couldn't open configuration file."
                           "Perhaps it doesn't exist or the path is incorrect");

    // json parsing
    nlohmann::json j;
    configFile >> j;
    configFile.close();

    pluginsConfig = j["pluginsConfig"];
    if (pluginsConfig == nullptr)
        return false;  
    return true;
}

} // namespace vtmine
