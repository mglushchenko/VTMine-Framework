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


namespace vtmine {

/***************************************************************************//**
 *  Default logger.
 ******************************************************************************/
class Logger {
public:
    virtual ~Logger() {}
    virtual void open();
    virtual void close();
};

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_LOGGER_H_
