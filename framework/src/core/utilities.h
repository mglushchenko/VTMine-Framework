/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
******************************************************************************/


#ifndef VTMINE_FRAMEWORK_CORE_FRAMEWORK_UTILITIES_H_
#define VTMINE_FRAMEWORK_CORE_FRAMEWORK_UTILITIES_H_


#include <vector>
#include <QPluginLoader>

namespace vtmine {
    using UByte = unsigned char;
    using PluginLoadersList = std::vector<QPluginLoader*>;
} // namespace vtmine

#endif // VTMINE_FRAMEWORK_CORE_FRAMEWORK_UTILITIES_H_
