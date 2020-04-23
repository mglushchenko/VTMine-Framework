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
#include "vtmexception.h"


namespace vtmine {


int AppStarter::main(int argc, char* argv[])
{
    makeDefFramework(argc, argv);
    return 0;
}


int AppStarter::run(int argc, char* argv[])
{
    int res = -1;

    // main app exception handler
    try {
        res = main(argc, argv);
    }
    catch (VTMException& e)
    {
        reportException(e.what(), "Framework exception handler");
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
        throw VTMException("Critical error: "
                           "framework has already been created!");
    }

    if (_cmdlParams.getConfigFileName().empty())
        throw VTMException("Configuration file not found!");

    _frmw = new FrameworkDefImpl();
    _frmw->init(_cmdlParams);
}


} // namespace vtmine
