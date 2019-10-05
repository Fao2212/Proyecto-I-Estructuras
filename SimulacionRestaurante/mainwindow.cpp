#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Mesero.h"
#include "ListaSimple.h"
#include "Nodo.h"
#include "Peticion.h"
#include "ThreadDatos.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    restaurante->threadRestaurante.__init__(restaurante->entrada,ui->ListLogRestaurante,ui->contadorEntrada,this->mensajes);
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
    restaurante->iniciarThreadMeseros();
    restaurante->iniciarThreadCocineros();
    this->threadMensaje->start();
    restaurante->threadRestaurante.start();

}

//CREAR VARIOS FORMS CON EL FORMATO DE CADA BOTON QUE SUSTITUYA EL COSO DE TABLAS Y CAMBIE LOS VALORES
//UNO PARA MESERO UNO PARA COCINER.... Y QUE AL TOCAR EL BOTON SE IMPRIMA EL ESTADO DEL HILO
//LAS ESSTRUCTURAS VAN A MOSTRAR LOS ACTORES QUE TENGAN.SE SUSTITYUYE EL TAB ORIGINAL POR UNO NUEVO CON LOS VALORES
//QUE SE LE QUIERA PASAR

void MainWindow::on_Mesero1_clicked()
{
    this->threadDatos->__init__(this->restaurante,ui->labelStatus);
    this->threadDatos->start();
}

void MainWindow ::showData(int i){

    ui->labelStatus->setText(restaurante->meseros->indexSearch(i)->dato->mostrarCola(i));

}

void MainWindow::on_pushButton_3_clicked()
{
    this->threadDatos->__init__(this->restaurante,ui->labelStatus);
    this->threadDatos->start();
}
