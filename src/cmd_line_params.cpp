#include "cmd_line_params.h"
#include <string.h>

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
        if (strcmp(argv[i], "-c") == 0)
        {
            _configFileName = argv[i+1];
            configFilePassed = true;
        }

    if (!configFilePassed)
        return false;

    // in case of success
    return true;
}
} // namespace vtmine
