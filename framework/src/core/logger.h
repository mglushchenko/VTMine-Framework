/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework application starter.
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      19.02.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Logger.
 *
 ******************************************************************************/

#ifndef VTMINE_FRAMEWORK_CORE_LOGGER_H_
#define VTMINE_FRAMEWORK_CORE_LOGGER_H_


#include "framework_settings.h"

// ?: how to access the logger from other framework components?


// Разбить логгер на интерфейсную часть (модуль ilogger) и сделать одну из возможных
// реализаций — на основе текстового файла (модуль i) через промежуточный "стримовый"
// логгер:
// ILogger      ←  IStreamLogger ← ITextFileLogger
//  ^ интерфейс     ^ реализация    ^ реализация с текстовым файлов в роли стрима
//                    со стримом      передавать в базовый класс объект файлстрим,
//                    конструктор,    после того, как он будет готов
//              получ объект стрима


namespace vtmine {

namespace LoggerCodes {
    const int EVTYPE_INFO       = 0;          ///< Default event type
    const int EVTYPE_WARNING    = 1;          ///< Warning event type
    const int EVTYPE_EXCEPTION  = 2;          ///< Exception event type
    const int EVTYPE_CRITICAL   = 3;          ///< Critical error event type
}; // namespace LoggerCodes


// TODO: переделать на это с LoggerCodes
enum class LogLevel : unsigned char {

};



/***************************************************************************//**
 *  Default logger. ← TODO: ILogger — интерфейс
 ******************************************************************************/
class Logger {
public:
    Logger(const FrameworkSettings& settings);
    virtual ~Logger() {}
    virtual void open() = 0;
    virtual void close() = 0;
    virtual bool isReady() = 0;

    // ?: what do parameters catName and subCatName represent?
    virtual int reportEvent(const char* unitName, int eventType,
            const char* catName, const char* subCatName, const char* text) = 0;

private: // TODO: ← protected!!!!

    // TODO: в комментарии обязательно указатель, что последовательность строк
    // должна полностью relects последовательность тегов в LogLevel
    const char* eventTypes[4] = {"INFO", "WARNING", "EXCEPTION", "CRITICAL"};
};

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_LOGGER_H_
