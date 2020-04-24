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
 *  Plugin test implementation.
 *
 ******************************************************************************/

#ifndef VTMINE_FRAMEWORK_PLUGINS_TESTPLUGIN_H_
#define VTMINE_FRAMEWORK_PLUGINS_TESTPLUGIN_H_


#include <QApplication>
#include <QPushButton>
#include <QWidget>

#include "TestPlugin_global.h"
#include "../../src/core/iplugin.h"
#include "../../src/core/framework.h"


namespace vtmine {

class TESTPLUGIN_EXPORT TestPlugin: public QObject, public IPlugin
{
    Q_OBJECT
    Q_INTERFACES(vtmine::IPlugin)

public:
    TestPlugin();

    ~TestPlugin() override {}

    bool activate(const vtmine::IFramework* frmw) const override;

    bool deactivate() override;

protected:
    //QApplication* _plugin;
};

} // namespace vtmine

#endif // VTMINE_FRAMEWORK_PLUGINS_TESTPLUGIN_H_
