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
 *  Framework settings.
 *
 ******************************************************************************/


#ifndef VTMINE_FRAMEWORK_CORE_FRAMEWORK_SETTINGS_H
#define VTMINE_FRAMEWORK_CORE_FRAMEWORK_SETTINGS_H


#include <string>
#include <vector>


namespace vtmine {

/***************************************************************************//**
 *  Represents framework settings obtained from configuration parameters.
 ******************************************************************************/
class FrameworkSettings {
public:
    /** \brief Framework settings contructor.
     * @param plugins -- names of plugin files.
     */
    FrameworkSettings(std::vector<std::string> plugins);

private:
    /// Plugin files.
    std::vector<std::string> _plugins;
}; // class FrameworkSettings

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_FRAMEWORK_SETTINGS_H
