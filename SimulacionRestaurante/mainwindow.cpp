#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    restaurante->threadRestaurante.__init__(restaurante->entrada,ui->ListLogRestaurante,&restaurante->mutexEntrada,ui->contadorEntrada,this->mensajes);
    this->threadMensaje->__init__(this->mensajes,ui->ListLogRestaurante);
    qDebug()<<"Creado";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"comienzo de simulacion";
    restaurante->threadRestaurante.start();
    restaurante->iniciarThreadMeseros(ui->ListLogRestaurante);
    restaurante->iniciarThreadCocineros(ui->ListLogRestaurante);
    this->threadMensaje->start();

}

