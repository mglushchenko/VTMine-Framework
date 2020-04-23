/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework application starter.
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      09.02.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Application starter.
 *
 ******************************************************************************/

#ifndef VTMINE_FRAMEWORK_CORE_APPSTARTER_H_
#define VTMINE_FRAMEWORK_CORE_APPSTARTER_H_


#include <iostream>
#include <memory>

#include "framework_def_impl.h"
#include "cmd_line_params.h"


namespace vtmine {

/***************************************************************************//**
 *  Class that starts the app and initializes the framework.
 ******************************************************************************/
class AppStarter {
public:
    /// No-arguments default constructor.
    AppStarter()
        :  _frmw(nullptr)
    {
    }

    /// Class destructor.
    ~AppStarter()
    {
        delete _frmw;
    }

    /** \brief Last-resort exception handling.
     *  \param argc -- number of cmd arguments.
     *  \param argv -- cmd arguments.
     *  \return Error code (0 in case of success).
     */
    int run(int argc, char *argv[]);

    /** \brief Main app starter.
     *  Params and the return value are the same as in run().
     */
    int main(int argc, char *argv[]);

protected:
    /** \brief Factory method for a framework instance. Initializes _frmw field.
     *  \param argc -- number of cmd arguments.
     *  \param argv -- cmd arguments.
     */
    void makeDefFramework(int argc, char* argv[]);

    /** \brief Displays a message about an exception.
     *  \param what -- error description.
     *  \param capt -- exception source.
     */
    void reportException(const char* what, const char* capt);

protected:
    /// Framework object.
    FrameworkDefImpl* _frmw;

    /// Framework parameters parsed from command line arguments.
    CmdLineParams _cmdlParams;

}; // class AppStarter

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_APPSTARTER_H_
