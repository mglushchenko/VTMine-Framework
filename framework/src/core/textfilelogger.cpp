/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/


#include "textfilelogger.h"
#include "vtmexception.h"


namespace vtmine {

TextFileLogger::TextFileLogger(const FrameworkSettings* settings)
               : StreamLogger(settings)
{
    _logFileName = settings->getLogFileName();
}

void TextFileLogger::open()
{
    _out = new std::ofstream(_logFileName);
}

void TextFileLogger::close()
{
    _out->close();
}

} // namespace vtmine
