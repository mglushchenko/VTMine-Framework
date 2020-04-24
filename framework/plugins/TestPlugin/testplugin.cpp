/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/


#include "testplugin.h"


namespace vtmine {

TestPlugin::TestPlugin()
{
}

bool TestPlugin::activate(const vtmine::IFramework* frmw) const
{
    char* argv[] = { NULL };
    int argc = 0;

    QApplication app(argc, argv);
    //_plugin = new QApplication(argc, argv);
    QPushButton button("hello");
    button.show();

    return app.exec();
}

bool TestPlugin::deactivate()
{
   // _plugin->exit();
    return true;
}

} // namespace vtmine
