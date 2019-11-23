#ifndef APPSTARTER_H
#define APPSTARTER_H

#include "framework_def_impl.h"
#include "cmd_line_params.h"
#include<iostream>
#include<memory>

namespace vtmine
{
class AppStarter
{
public:
    AppStarter()
    :  _frmw(nullptr)
    {
    }

    // запуск с обратчиком исключений последнего уровня
    int run(int argc, char *argv[]);

    // основная логика
    int main(int argc, char *argv[]);

// protected methods
protected:
    void makeDefFramework(int argc, char* argv[]);   // параметры создания фреймворка — пока не опрд.

    void reportException(const char* what, const char* capt);

// protected fields
protected:
    FrameworkDefImpl* _frmw;
    CmdLineParams _cmdlParams;

}; // class AppStarter
} // namespace vtmine

#endif // APPSTARTER_H
