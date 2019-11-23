#include "stdafx.h"

#include "app_params_parser.h"
#include "utils.h"


AppParamsParser::AppParamsParser() //int argc, _TCHAR* argv[])
    : _atrNumCase(0),
    _atrNumAct(1),
    _atrNumTime(2),
    _wsSize(-1),
    _flStateActLabel(true)
{
    //if (argc < 2)
    //    throw std::exception("Not enough parameters");
    //_csvLogFn = argv[0];
}
//------------------------------------------------------------------------------

//AppParamsParser::~AppParamsParser()
//{
//}

//------------------------------------------------------------------------------

bool AppParamsParser::parse(int argc, _TCHAR* argv[])
{
    if (argc < 3)
        return false;

    CharShPtr s1(WideStrToUtf8(argv[1]));
    _csvLogFn = s1.get();

    CharShPtr s2(WideStrToUtf8(argv[2]));
    _dotGraphFn = s2.get();

    for (int i = 3; i < argc; ++i)
    {
        // simply compares
        if (wcsncmp(argv[i], L"-Ac", 3) == 0)
            _atrNumCase = extractNum(argv[i] + 3);
        else if (wcsncmp(argv[i], L"-Aa", 3) == 0)
            _atrNumAct = extractNum(argv[i] + 3);
        else if (wcsncmp(argv[i], L"-At", 3) == 0)
            _atrNumTime = extractNum(argv[i] + 3);
        else if (wcsncmp(argv[i], L"-Ws", 3) == 0)
            _wsSize = extractNum(argv[i] + 3);
        else if (wcsncmp(argv[i], L"-Sl", 3) == 0)
            _flStateActLabel = false;

        
    }


    // argv[0];
    // = argv[1];

    return true;
}

//------------------------------------------------------------------------------

int AppParamsParser::extractNum(_TCHAR* sPar)
{
    int res = wcstol(sPar, nullptr, 10);
    return res;
}
