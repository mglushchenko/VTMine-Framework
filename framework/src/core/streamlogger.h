/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework stream logger.
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      19.02.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Stream logger.
 *
 ******************************************************************************/

#ifndef VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_ISTREAMLOGGER_H_
#define VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_ISTREAMLOGGER_H_


#include <iostream>
#include <fstream>

#include "logger.h"


namespace vtmine {

class StreamLogger: public ILogger
{
public:
    /** \brief Stream logger constructor.
     * \param settings -- configuration details.
     * \param out -- output stream.
     */
    StreamLogger(const FrameworkSettings* settings, std::ofstream* out);

    /** \brief Stream logger constructor with no output stream parameter.
     * \param settings -- configuration details.
     */
    StreamLogger(const FrameworkSettings* settings);

    /// Stream logger destructor.
    ~StreamLogger() override { }

    /// Opens output stream.
    void open() override {}

    /// Closes output stream.
    void close() override { }

    /** \brief Checks whether the log is ready for use.
     * \return True if output stream is open.
     */
    bool isReady() override { return _out->is_open(); }

    virtual int reportEvent (const char* unitName, const char* text,
               LogLevel eventType = LogLevel::INFO, unsigned int errorCode = 0) override;

protected:
    std::ofstream* _out = nullptr;
};

} // namespace vtmine

#endif // VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_ISTREAMLOGGER_H_
