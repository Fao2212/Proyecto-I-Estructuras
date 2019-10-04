#include "mainwindow.h"
#include "QDebug"
#include <QApplication>
#include "Globals.h"
#include "Menu.h"
#include "TablaPlatos.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
