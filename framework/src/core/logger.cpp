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

ILogger::ILogger(const FrameworkSettings* settings)
{
    for (int i = 0; i < 4; ++i)
        if (settings->getOutputLevel() == eventTypes[i])
            _outputLvl = i;
}

} // namespace vtmine
