/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/


#include <QApplication>
#include <QWidget>
#include <QPushButton>

#include "iplugin.h"


namespace vtmine {

IPlugin::IPlugin()
{

}

bool IPlugin::registerItself(IFramework *frmw)
{
    // TODO: add actual logic
    return true;
}


} // namespace vtmine


