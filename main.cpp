#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <mainwindow/mainwindow.h>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow* win  = new MainWindow();
    win->show();


    return app.exec();
}