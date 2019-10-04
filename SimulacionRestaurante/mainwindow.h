#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Restaurante.h"
#include "GUIMensaje.h"
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
    Restaurante * restaurante = new Restaurante(17,8,"Rostipollos",10,20,10,20,10,
                                                20,10,20,10,20,10,5,mensajes);

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
