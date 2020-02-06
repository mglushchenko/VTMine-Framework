#ifndef VTMINE_FRAMEWORK_SRC_CORE_APPSTARTER_H_
#define VTMINE_FRAMEWORK_SRC_CORE_APPSTARTER_H_

#include "framework_def_impl.h"
#include "cmd_line_params.h"
#include<iostream>
#include<memory>

namespace vtmine {
/**
 * @brief Class that starts the app and initializes the framework.
 */
class AppStarter
{
public:
    /**
     * @brief No-arguments default constructor.
     */
    AppStarter()
    :  _frmw(nullptr)
    {
    }

    /**
     * @brief Last-resort exception handling.
     * @param argc -- number of cmd arguments.
     * @param argv -- cmd arguments.
     * @return Error code (0 in case of success).
     */
    int run(int argc, char *argv[]);

    /**
     * @brief Main app starter.
     * @param argc -- number of cmd arguments.
     * @param argv -- cmd arguments.
     * @return Error code (0 in case of success).
     */
    int main(int argc, char *argv[]);

// protected methods
protected:
    /**
     * @brief Factory for a framework instance. Initializes _frmw field.
     * @param argc -- number of cmd arguments.
     * @param argv -- cmd arguments.
     */
    void makeDefFramework(int argc, char* argv[]);   // параметры создания фреймворка — пока не опрд.

    /**
     * @brief Displays a message about an exception.
     * @param what -- error description.
     * @param capt -- exception source.
     */
    void reportException(const char* what, const char* capt);

// protected fields
protected:
    /**
     * @brief Framework object.
     */
    FrameworkDefImpl* _frmw;
    /**
     * @brief Framework parameters parsed from command line arguments.
     */
    CmdLineParams _cmdlParams;

}; // class AppStarter
} // namespace vtmine

#endif // VTMINE_FRAMEWORK_SRC_CORE_APPSTARTER_H_
