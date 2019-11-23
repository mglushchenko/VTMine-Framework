#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include "framework_def_impl.h"
#include "app_starter.h"

int main(int argc, char *argv[])
{
    using namespace vtmine;

    AppStarter appStarter;
    return appStarter.run(argc, argv);

//    QApplication app(argc, argv);
//    QPushButton button("hello");
//    button.show();

//    return app.exec();
}

