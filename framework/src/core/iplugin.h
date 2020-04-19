/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework application starter.
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      09.04.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Framework settings.
 *
 ******************************************************************************/

#ifndef VTMINE_FRAMEWORK_CORE_FRAMEWORK_IPLUGIN_H
#define VTMINE_FRAMEWORK_CORE_FRAMEWORK_IPLUGIN_H


#include <string>
#include <QtPlugin>

#include "framework.h"


namespace vtmine {

/***************************************************************************//**
 *  Base plugin interface.
 ******************************************************************************/
class IPlugin
{

    // TODO: не понятно, должен ли этот интерфейс быть Q_OBJECT ?!?!

public:
    /// Default constructor.
    IPlugin();

    // TODO: виртуальный деструктор?


    bool registerItself(IFramework* frmw);

    /// ID Getter.
    std::string getID() const { return _id; }   // TODO: переделать на QString
private:                                        // TODO: ← protected
    /// Plugin's unique ID.
    std::string _id;


    // TODO: список состояний плагинов:
    // enum class State { loaded, active };
};




} // namespace vtmine

Q_DECLARE_INTERFACE(vtmine::IPlugin, "ru.xidv.vtminec.splugin.IPlugin/0.1")

#endif // VTMINE_FRAMEWORK_CORE_FRAMEWORK_IPLUGIN_H
