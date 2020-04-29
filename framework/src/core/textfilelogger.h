/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework text file logger.
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      19.02.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Text file logger.
 *
 ******************************************************************************/


#ifndef VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_ITEXTFILELOGGER_H_
#define VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_ITEXTFILELOGGER_H_


#include <string>
#include <iostream>
#include <fstream>

#include "streamlogger.h"


namespace vtmine {

class ITextFileLogger: public IStreamLogger     // TODO: ITextFileLogger → TextFileLogger
{
public:
    /**
     * \brief Text file logger constructor.
     * \param settings -- configuration details.
     */
    ITextFileLogger(const FrameworkSettings* settings);

    // TODO: деструктор, и он же удаляет _out (RAII)

    /// Opens log file.
    virtual void open() override
    {
        _out = new std::ofstream(_logFileName);
    }

protected:
    /// Log file name.
    std::string _logFileName;
};

} // namespace vtmine

#endif // VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_ITEXTFILELOGGER_H_
