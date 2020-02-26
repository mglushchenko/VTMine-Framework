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
 *  Base framework implementation.
 *
 ******************************************************************************/

#ifndef VTMINE_FRAMEWORK_CORE_FRAMEWORK_H_
#define VTMINE_FRAMEWORK_CORE_FRAMEWORK_H_


namespace vtmine {

/***************************************************************************//**
 *  An base interface for framework implementations.
 ******************************************************************************/
class IFramework {
public:
    /// Virtual destructor.
    virtual ~IFramework() {}
};

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_FRAMEWORK_H_
