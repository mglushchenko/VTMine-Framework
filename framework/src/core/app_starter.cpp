/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/

#include "app_starter.h"


namespace vtmine {


int AppStarter::main(int argc, char *argv[])
{
    makeDefFramework(argc, argv);
    return 0;
}


int AppStarter::run(int argc, char *argv[])
{
    int res = -1;

    // main app exception handler
    try {
        res = main(argc, argv);
    }
    catch (const std::exception& e)
    {
        reportException(e.what(), "Last STD Exception Handler");
    }
    catch (...)
    {
        reportException("UNKNOWN_EXCEPTION", "Last Exception Handler");
    }

    return res;
}


void AppStarter::reportException(const char* what, const char* capt)
{
    std::cerr << "Module " << capt << " asserts: " << what;

   // потом здесь можно будет навернуть логику,
   // которая переназначит вывод в другой объект
}


// TODO: add 'capt' parameter of reportException
void AppStarter::makeDefFramework(int argc, char* argv[])
{
    _cmdlParams.parse(argc, argv);
    if(_frmw)
    {
        reportException("Critical error: "
                        "framework has been already created", "");
    }


    // TODO: последовательность действи!


    _frmw = new FrameworkDefImpl();
    // TODO: init method (pass _cmdlParams&)

    if (_cmdlParams.getConfigFileName().empty())
        reportException("No configuration file present", "");   // TODO: здесь должен быть throw, а ловить и репортить не здесь, а вовне!
}


} // namespace vtmine
