/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework logger.
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      19.02.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Base logger interface.
 *
 ******************************************************************************/

#ifndef VTMINE_FRAMEWORK_CORE_LOGGER_H_
#define VTMINE_FRAMEWORK_CORE_LOGGER_H_


#include "framework_settings.h"
//#include "utilities.h"

namespace vtmine {

// TODO: перенести вложенным классом внутрь ILogger
enum class LogLevel: unsigned char
{
    INFO = 0,
    WARNING,
    EXCEPTION,
    CRITICAL
};

/***************************************************************************//**
 *  Default logger.
 ******************************************************************************/
class ILogger {

public:


//    // Комент, что все три нижележащие тип и две константы д.б. согласованы.

//    enum class LogLevel : unsigned char
//    {
//        INFO = 0,
//        WARNING,
//        EXCEPTION,
//        CRITICAL
//    };

//    const UByte EVENT_TYPES_NUM = 4;

//    /// Event types. Reflects the LogLevel enum.
//    const char* EVENT_TYPES[EVENT_TYPES_NUM] = { "INFO", "WARNING", "EXCEPTION", "CRITICAL" };


public:
    /**
     *  \brief Logger constructor.
     *  \param settings -- configuration details.
     */
    ILogger(const FrameworkSettings* settings);

    /// Virtual destructor.
    virtual ~ILogger() {}

    /// Opens log output stream.
    virtual void open() = 0;

    /// Closes log output stream.
    virtual void close() = 0;

    /// Checks whether the log is ready for use.
    virtual bool isReady() = 0;

    /**
     * \brief Adds a message to the log.
     * \param unitName -- message source.
     * \param eventType -- event type (info, warning, etc.)
     * \param text -- message contents.
     * \return Event ID.
     */
    virtual int reportEvent(const char* unitName,
                            const char* text,
                            LogLevel eventType = LogLevel::INFO,
                            unsigned int errorCode = 0) = 0;

protected:
    /// Event types. Reflects the LogLevel enum.
    const char* eventTypes[4] = {"INFO", "WARNING", "EXCEPTION", "CRITICAL"};


    /// Minimum output level, defaults to INFO.
    int _outputLvl = 0;                             // TODO: сделать getter под него
};

// TODO: либо это ^^^ не интерфейс, а просто Logger, либо расщеплять на ILogger
// без _outputLvl, и делать еще один промежуточный класс BaseLogger чисто для
// хранения _outputLvl


} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_LOGGER_H_
