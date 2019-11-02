#include <QApplication>
#include <QPushButton>
#include <QWidget>

namespace vtmine
{

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton button("hello");
    button.show();
    return app.exec();
}

} // namespace vtmine
