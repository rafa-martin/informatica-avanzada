#include "mainwindow.h"

#include <QApplication>


//hola soy pilar
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
