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

ITextFileLogger::ITextFileLogger(const FrameworkSettings* settings):
    IStreamLogger(settings)
{
    _logFileName = settings->getLogFileName();
}

} // namespace vtmine
