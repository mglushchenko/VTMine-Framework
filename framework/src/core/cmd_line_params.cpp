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
#include "help_message.h"

#include "../extlib/json.hpp"


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
    for (int i = 0; i < argc; ++i)
    {
        // Configuration file
        if (strcmp(argv[i], "-c") == 0 && i != argc - 1)
        {
            _configFileName = argv[i+1];
            configFilePassed = true;
        }
        // Help
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            std::cout << helpMsg;
        }
    }

    if (!configFilePassed)
        return false;

    return true;
}


} // namespace vtmine
