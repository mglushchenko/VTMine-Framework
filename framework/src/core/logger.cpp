/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/


#include <iostream>

#include "logger.h"
#include "vtmexception.h"


namespace vtmine {

// maybe add an ofstream parameter?
Logger::Logger(const vtmine::FrameworkSettings &settings)   // TODO: кодстайл
{                    // ^ префикс не нужен

}

int Logger::reportEvent(const char *unitName, int eventType,
//                                              ^ LogLevel
                        const char *catName, const char *subCatName, const char *text) // text → msg
                        //         ^ кодстайл
                        // unitName, catName, subCatName — все это заменить одним origin
                        // Добавить unsigned int errorCode

                        // (eventLevel, orig, msg, errorCode = 0)

{
    // TODO: скорее всего, это будет чисто-виртуальной функцией с телом, которое
    // можно было бы вызывать из производных классов (содержащее некоторую общую
    // функциональность)

    if (eventType < 0 || eventType > 3)
        throw VTMException("Invalid event type!");      // TODO: уходит

    std::cout << eventTypes[eventType] << ". " << unitName << "says: " <<
              text << "\n";
    // do we simply keep an event counter and return its value here?
    return 0;
}

} // namespace vtmine
