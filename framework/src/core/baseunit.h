/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework base unit.
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      20.04.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Base unit for framework components.
 *
 ******************************************************************************/

#ifndef VTMINE_FRAMEWORK_CORE_BASEUNIT_H_
#define VTMINE_FRAMEWORK_CORE_BASEUNIT_H_


#include "framework.h"
#include "logger.h"


namespace vtmine {

/***************************************************************************//**
 *  Class representing framework base unit.
 ******************************************************************************/
class BaseUnit {
public:
    /** \brief Class constructor.
     *  \param frmv -- Framework object to which the unit belongs.
     */
    BaseUnit(IFramework* frmv, ILogger* logger)
        : _owner(frmv)
        , _logger(logger)
    {

    }

    /// Class destructor.
    virtual ~BaseUnit() {}

    /// Getter for owner framework object.
    const IFramework* getOwner() const { return _owner; }

    /// Getter for logger.
    ILogger* getLog() const { return _logger; }

    /** \brief Adds an info level  message to the log.
     *  \param message -- info message
     */
    void logI(const char* message)
    {
        _logger->reportEvent(getUnitName(), message, ILogger::LogLevel::INFO);
    }

    /** \brief Adds a warning level  message to the log.
     *  \param message -- info message
     */
    void logW(const char* message)
    {
        _logger->reportEvent(getUnitName(), message, ILogger::LogLevel::WARNING);
    }

    /** \brief Adds an error level  message to the log.
     *  \param message -- info message
     */
    void logE(const char* message)
    {
        _logger->reportEvent(getUnitName(), message, ILogger::LogLevel::EXCEPTION);
    }

    /** \brief Adds a critical level  message to the log.
     *  \param message -- info message
     */
    void logC(const char* message)
    {
        _logger->reportEvent(getUnitName(), message, ILogger::LogLevel::CRITICAL);
    }

    /// Getter for unit name.
    virtual const char* getUnitName() = 0;

protected:
    /// Framework object to which the unit belongs.
    IFramework* _owner;

    /// Logger component.
    ILogger* _logger;

}; // class BaseUnit

} // namespace vtmine

#endif // VTMINE_FRAMEWORK_CORE_BASEUNIT_H_
