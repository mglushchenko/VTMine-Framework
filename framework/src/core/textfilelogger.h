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

/***************************************************************************//**
 *  Logger with output to text file.
 ******************************************************************************/
class TextFileLogger: public StreamLogger
{
public:
    /**
     * \brief Text file logger constructor.
     * \param settings -- configuration details.
     */
    TextFileLogger(const FrameworkSettings* settings);

    virtual ~TextFileLogger() override { delete _out; }

    /// Opens log file.
    virtual void open() override;

    virtual void close() override;

protected:
    /// Log file name.
    std::string _logFileName;
};

} // namespace vtmine

#endif // VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_ITEXTFILELOGGER_H_
