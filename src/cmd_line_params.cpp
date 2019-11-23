#include "cmd_line_params.h"

namespace vtmine {

CmdLineParams::CmdLineParams()
{
    _configFileName = "";
}

bool CmdLineParams::parse(int argc, char* argv[])
{
    if (argc < 2)
        return false;

    std::string cmdArgs(argv);
    bool configFilePassed = false;
    for (int i = 0; i < argc - 1; ++i)
        if (cmdArgs.compare("-c") == 0)
        {
            _configFileName = cmdArgs[i+1];
            configFilePassed = true;
        }

    if (!configFilePassed)
        return false;

    // in case of success
    return true;
}
} // namespace vtmine
