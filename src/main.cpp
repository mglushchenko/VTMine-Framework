#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include "MainWorker.h"

//namespace vtmine
//{

int main(int argc, char *argv[])
{
    // костыль!
    using namespace vtmine;

    QApplication app(argc, argv);
    QPushButton button("hello");
    button.show();

    MainWorker* framework(MainWorker::getInstance());
    return app.exec();
}

//} // namespace vtmine
