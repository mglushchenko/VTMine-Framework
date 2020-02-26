/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/


#include <string.h>
#include <fstream>
#include <QJsonDocument>
#include <iostream>

#include "cmd_line_params.h"
#include "vtmexception.h"
#include "framework_settings.h"
#include "json.hpp"


namespace vtmine {


CmdLineParams::CmdLineParams()
{
    _configFileName = "";
}


bool CmdLineParams::parse(int argc, char* argv[])
{
    if (argc < 2)
        return false;

    bool configFilePassed = false;
    for (int i = 0; i < argc - 1; ++i)
        if (strcmp(argv[i], "-c") == 0 && i != argc - 1)
        {
            _configFileName = argv[i+1];
            configFilePassed = true;
        }

    if (!configFilePassed)
        return false;

    // in case of success
    parseConfigJSON();
    return true;
}


bool CmdLineParams::parseConfigJSON()
{
    std::ifstream configFile(_configFileName);
    if (!configFile)
        throw VTMException("Couldn't open configuration file."
                           "Perhaps it doesn't exist or the path is incorrect");
    // json parsing
    nlohmann::json j;
    configFile >> j;
    _pluginFiles = j["pluginfiles"].get<std::vector<std::string>>();
    configFile.close();
    return false;
}


} // namespace vtmine
