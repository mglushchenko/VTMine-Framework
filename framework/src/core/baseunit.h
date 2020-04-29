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

class BaseUnit  {
public:
    /**
     *  \brief Class constructor.
     *  \param frmv -- Framework object to which the unit belongs.
     */
    BaseUnit(const IFramework* frmv, ILogger* logger)
        //: _owner(frmv)
    {
        _owner = frmv;          // здесь _owner уже инициализирован мусором, переопр.
        _logger = logger;
        _logger->open();        // этому тут не место
    }

    /// Class destructor.
    ~BaseUnit()
    {
        _logger->close();       // тем более этому
    }

    /// Getter for owner framework object.
    const IFramework* getOwner() const { return _owner; }   // NOTE: для примера: это отл. оптимизация для inline

    /// Getter for logger.
    ILogger* getLogger() const { return _logger; }  // TODO: getLog()

    /**
     * \brief Adds an info level  message to the log.
     * \param message -- info message
     */
    void logInfo(const char* message);

    /**
     * \brief Adds a warning level  message to the log.
     * \param message -- info message
     */
    void logWarning(const char* message);

    /**
     * \brief Adds an error level  message to the log.
     * \param message -- info message
     */
    void logError(const char* message);

    /**
     * \brief Adds a critical level  message to the log.
     * \param message -- info message
     */
    void logCritical(const char* message);

protected:
    /// Framework object to which the unit belongs.
    const IFramework* _owner;                           // TODO: const?

    /// Logger component.
    ILogger* _logger;

    /// Unit name.
    const char* _unitName;                  // TODO: заменить его на метод virtual const char* getUnitName() = 0
}; // class BaseUnit



//// пример модуля
//class MyUnit : public BaseUnit {

//public:
//    virtual const char* getUnitName() { return UNIT_NAME; } // TODO: тело д.б. в cpp-файле, т.к. вирт.
//protected:
//    const char* UNIT_NAME = "NyUnit";
//};


} // namespace vtmine

#endif // VTMINE_FRAMEWORK_CORE_BASEUNIT_H_
