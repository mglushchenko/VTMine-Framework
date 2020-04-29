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

class IStreamLogger: public ILogger {       // TODO: rename → StreamLogger
public:
    /**
     *  \brief Stream logger constructor.               // TODO: ← везде разобраться с выравниванием комментов
     *  \param settings -- configuration details.
     *  \param out -- output stream.
     */
    IStreamLogger(const FrameworkSettings* settings, std::ofstream* out);

    /**
     *  \brief Stream logger constructor with no output stream parameter.
     * \param settings -- configuration details.
     */
    IStreamLogger(const FrameworkSettings* settings);

    /// Stream logger destructor.
    virtual ~IStreamLogger() override { delete _out; }      // TODO: здесь НЕ удаляем, удаляем там, где создали (RAII)


    /// Opens output stream.
    virtual void open() override {}

    /// Closes output stream.
    virtual void close() override { _out->close(); }

    /**
     * \brief Checks whether the log is ready for use.
     * \return True if output stream is open.
     */
    virtual bool isReady() override { return _out->is_open(); }

    int reportEvent (const char* unitName, const char* text,
               LogLevel eventType = LogLevel::INFO, unsigned int errorCode = 0) override;

protected:
    std::ofstream* _out = nullptr;      // TODO: этот объект не управляет временем жизни указателя!
                                        // см. идиому RAII
};

} // namespace vtmine

#endif // VTMINE_FRAMEWORK_CORE_PLUGINMANAGER_ISTREAMLOGGER_H_
