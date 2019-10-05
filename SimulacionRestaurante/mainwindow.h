#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Restaurante.h"
#include "GUIMensaje.h"
#include "ThreadDatos.h"
#include "ThreadMensaje.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    ColaMensajes * mensajes = new ColaMensajes();
    ThreadMensaje * threadMensaje = new ThreadMensaje();
    ThreadDatos * threadDatos = new ThreadDatos();
    Restaurante * restaurante = new Restaurante(7,4,"Rostipollos",8,8,7,8,80,
                                                9,9,70,10,10,50,5,mensajes);

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showData(int i);

private slots:

    void on_pushButton_clicked();

    void on_Mesero1_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
