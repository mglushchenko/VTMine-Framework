/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/


#include "baseunit.h"


namespace vtmine {

void BaseUnit::logInfo(const char* message)
{
    _logger->reportEvent(_unitName, message, LogLevel::INFO);
}

void BaseUnit::logWarning(const char* message)
{
    _logger->reportEvent(_unitName, message, LogLevel::WARNING);
}

void BaseUnit::logError(const char* message)
{
    _logger->reportEvent(_unitName, message, LogLevel::EXCEPTION);
}

void BaseUnit::logCritical(const char* message)
{
    _logger->reportEvent(_unitName, message, LogLevel::CRITICAL);
}

// это ^^^ все уходит в заголовочный файл, т.к. идеально для inline-оптимизации



} // namespace vtmine
