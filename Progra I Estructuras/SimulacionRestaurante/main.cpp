#include "mainwindow.h"
#include "QDebug"
#include <QApplication>
#include "Mesa.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
