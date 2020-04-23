/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework plugin interface.
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      09.04.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Plugin interface.
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
public:
    /// Default constructor.
    IPlugin();

    /**
     * \brief Activates plugin.
     * \param frmw -- owner framework object.
     * \return True in case of success.
     */
    bool activate(const IFramework* frmw) const;

    /**
     * \brief Deactivates plugin.
     * \return True in case of success.
     */
    bool deactivate();

    /// ID Getter.
    QString getID() const { return _id; }


    /// Plugin states.
    enum class State { loaded, active };

protected:
    /// Plugin's unique ID.
    QString _id;
};

} // namespace vtmine

Q_DECLARE_INTERFACE(vtmine::IPlugin, "ru.xidv.vtminec.splugin.IPlugin/0.1")

#endif // VTMINE_FRAMEWORK_CORE_FRAMEWORK_IPLUGIN_H
