/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/


#include "streamlogger.h"


namespace vtmine {

IStreamLogger::IStreamLogger(const FrameworkSettings* settings,
                             std::ofstream* out):
    ILogger(settings), _out(out)
{

}

int IStreamLogger::reportEvent(const char* unitName, const char* text,
                              LogLevel eventType, unsigned int errorCode)
{
    if ((int)eventType < _outputLvl)
        return 0;

    std::string message = "";
    message += eventTypes[(int)eventType];
    message +=  ": ";
    message += unitName;
    message += " says:";
    message +=  text;
    message += " Error code: " + errorCode;

    if (!_out)
        std::cout << message;
    else
        *_out << message;

    return 0;
}

IStreamLogger::IStreamLogger(const FrameworkSettings* settings):
    ILogger(settings)
{

}

} // namespace vtmine
