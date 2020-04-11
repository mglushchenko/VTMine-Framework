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
Logger::Logger(const vtmine::FrameworkSettings &settings)
{

}

int Logger::reportEvent(const char *unitName, int eventType,
                        const char *catName, const char *subCatName, const char *text)
{
    if (eventType < 0 || eventType > 3)
        throw VTMException("Invalid event type!");

    std::cout << eventTypes[eventType] << ". " << unitName << "says: " <<
              text << "\n";
    // do we simply keep an event counter and return its value here?
    return 0;
}

} // namespace vtmine
