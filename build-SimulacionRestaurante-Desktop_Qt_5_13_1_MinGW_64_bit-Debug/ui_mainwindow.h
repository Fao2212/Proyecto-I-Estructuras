/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QListWidget *ListLogRestaurante;
    QWidget *widget;
    QFrame *FrameMesas;
    QLabel *label_6;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Mesa1;
    QPushButton *Mesa2;
    QPushButton *Mesa3;
    QPushButton *Mesa4;
    QPushButton *Mesa5;
    QPushButton *Mesa6;
    QPushButton *Mesa7;
    QPushButton *Mesa8;
    QPushButton *Mesa9;
    QPushButton *Mesa10;
    QPushButton *Mesa11;
    QPushButton *Mesa12;
    QPushButton *Mesa13;
    QPushButton *Mesa14;
    QPushButton *Mesa15;
    QPushButton *Mesa16;
    QPushButton *Mesa17;
    QPushButton *Mesa18;
    QPushButton *Mesa19;
    QPushButton *Mesa20;
    QFrame *FrameMeseros;
    QLabel *label_5;
    QWidget *layoutWidget1;
    QGridLayout *gridMeseros;
    QPushButton *Mesero7;
    QPushButton *Mesero12;
    QPushButton *Mesero13;
    QPushButton *Mesero8;
    QPushButton *Mesero14;
    QPushButton *Mesero10;
    QPushButton *Mesero18;
    QPushButton *Mesero3;
    QPushButton *Mesero15;
    QPushButton *Mesero16;
    QPushButton *Mesero19;
    QPushButton *Mesero17;
    QPushButton *Mesero20;
    QPushButton *Mesero1;
    QPushButton *Mesero4;
    QPushButton *Mesero2;
    QPushButton *Mesero9;
    QPushButton *Mesero5;
    QPushButton *Mesero6;
    QPushButton *Mesero11;
    QFrame *FrameCocinas;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QFrame *FrameLavaplatos;
    QLabel *label_2;
    QPushButton *pushButton_6;
    QFrame *FrameCaja;
    QLabel *label_3;
    QPushButton *pushButton_7;
    QFrame *FrameEntrada;
    QLabel *label_4;
    QPushButton *pushButton_8;
    QLabel *label_7;
    QLabel *contadorEntrada;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QFrame *FramePropiedades;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1237, 681);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 951, 621));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        ListLogRestaurante = new QListWidget(frame);
        ListLogRestaurante->setObjectName(QString::fromUtf8("ListLogRestaurante"));
        ListLogRestaurante->setGeometry(QRect(20, 510, 911, 101));
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 40, 891, 451));
        FrameMesas = new QFrame(widget);
        FrameMesas->setObjectName(QString::fromUtf8("FrameMesas"));
        FrameMesas->setGeometry(QRect(40, 210, 641, 211));
        FrameMesas->setFrameShape(QFrame::StyledPanel);
        FrameMesas->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(FrameMesas);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 10, 55, 16));
        layoutWidget = new QWidget(FrameMesas);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(13, 40, 611, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Mesa1 = new QPushButton(layoutWidget);
        Mesa1->setObjectName(QString::fromUtf8("Mesa1"));
        Mesa1->setMinimumSize(QSize(0, 38));
        Mesa1->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa1, 0, 0, 1, 1);

        Mesa2 = new QPushButton(layoutWidget);
        Mesa2->setObjectName(QString::fromUtf8("Mesa2"));
        Mesa2->setEnabled(false);
        Mesa2->setMinimumSize(QSize(0, 38));
        Mesa2->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa2, 0, 1, 1, 1);

        Mesa3 = new QPushButton(layoutWidget);
        Mesa3->setObjectName(QString::fromUtf8("Mesa3"));
        Mesa3->setEnabled(false);
        Mesa3->setMinimumSize(QSize(0, 38));
        Mesa3->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa3, 0, 2, 1, 1);

        Mesa4 = new QPushButton(layoutWidget);
        Mesa4->setObjectName(QString::fromUtf8("Mesa4"));
        Mesa4->setEnabled(false);
        Mesa4->setMinimumSize(QSize(0, 38));
        Mesa4->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa4, 0, 3, 1, 1);

        Mesa5 = new QPushButton(layoutWidget);
        Mesa5->setObjectName(QString::fromUtf8("Mesa5"));
        Mesa5->setEnabled(false);
        Mesa5->setMinimumSize(QSize(0, 38));
        Mesa5->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa5, 0, 4, 1, 1);

        Mesa6 = new QPushButton(layoutWidget);
        Mesa6->setObjectName(QString::fromUtf8("Mesa6"));
        Mesa6->setEnabled(false);
        Mesa6->setMinimumSize(QSize(0, 38));
        Mesa6->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa6, 0, 5, 1, 1);

        Mesa7 = new QPushButton(layoutWidget);
        Mesa7->setObjectName(QString::fromUtf8("Mesa7"));
        Mesa7->setEnabled(false);
        Mesa7->setMinimumSize(QSize(0, 38));
        Mesa7->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa7, 0, 6, 1, 1);

        Mesa8 = new QPushButton(layoutWidget);
        Mesa8->setObjectName(QString::fromUtf8("Mesa8"));
        Mesa8->setEnabled(false);
        Mesa8->setMinimumSize(QSize(0, 38));
        Mesa8->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa8, 0, 7, 1, 1);

        Mesa9 = new QPushButton(layoutWidget);
        Mesa9->setObjectName(QString::fromUtf8("Mesa9"));
        Mesa9->setEnabled(false);
        Mesa9->setMinimumSize(QSize(0, 38));
        Mesa9->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa9, 0, 8, 1, 1);

        Mesa10 = new QPushButton(layoutWidget);
        Mesa10->setObjectName(QString::fromUtf8("Mesa10"));
        Mesa10->setEnabled(false);
        Mesa10->setMinimumSize(QSize(0, 38));
        Mesa10->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa10, 0, 9, 1, 1);

        Mesa11 = new QPushButton(layoutWidget);
        Mesa11->setObjectName(QString::fromUtf8("Mesa11"));
        Mesa11->setEnabled(false);
        Mesa11->setMinimumSize(QSize(0, 38));
        Mesa11->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa11, 1, 0, 1, 1);

        Mesa12 = new QPushButton(layoutWidget);
        Mesa12->setObjectName(QString::fromUtf8("Mesa12"));
        Mesa12->setEnabled(false);
        Mesa12->setMinimumSize(QSize(0, 38));
        Mesa12->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa12, 1, 1, 1, 1);

        Mesa13 = new QPushButton(layoutWidget);
        Mesa13->setObjectName(QString::fromUtf8("Mesa13"));
        Mesa13->setEnabled(false);
        Mesa13->setMinimumSize(QSize(0, 38));
        Mesa13->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa13, 1, 2, 1, 1);

        Mesa14 = new QPushButton(layoutWidget);
        Mesa14->setObjectName(QString::fromUtf8("Mesa14"));
        Mesa14->setEnabled(false);
        Mesa14->setMinimumSize(QSize(0, 38));
        Mesa14->setStyleSheet(QString::fromUtf8(""));
        Mesa14->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa14, 1, 3, 1, 1);

        Mesa15 = new QPushButton(layoutWidget);
        Mesa15->setObjectName(QString::fromUtf8("Mesa15"));
        Mesa15->setEnabled(false);
        Mesa15->setMinimumSize(QSize(0, 38));
        Mesa15->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa15, 1, 4, 1, 1);

        Mesa16 = new QPushButton(layoutWidget);
        Mesa16->setObjectName(QString::fromUtf8("Mesa16"));
        Mesa16->setEnabled(false);
        Mesa16->setMinimumSize(QSize(0, 38));
        Mesa16->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        Mesa16->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa16, 1, 5, 1, 1);

        Mesa17 = new QPushButton(layoutWidget);
        Mesa17->setObjectName(QString::fromUtf8("Mesa17"));
        Mesa17->setEnabled(false);
        Mesa17->setMinimumSize(QSize(0, 38));
        Mesa17->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa17, 1, 6, 1, 1);

        Mesa18 = new QPushButton(layoutWidget);
        Mesa18->setObjectName(QString::fromUtf8("Mesa18"));
        Mesa18->setEnabled(false);
        Mesa18->setMinimumSize(QSize(0, 38));
        Mesa18->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa18, 1, 7, 1, 1);

        Mesa19 = new QPushButton(layoutWidget);
        Mesa19->setObjectName(QString::fromUtf8("Mesa19"));
        Mesa19->setEnabled(false);
        Mesa19->setMinimumSize(QSize(0, 38));
        Mesa19->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa19, 1, 8, 1, 1);

        Mesa20 = new QPushButton(layoutWidget);
        Mesa20->setObjectName(QString::fromUtf8("Mesa20"));
        Mesa20->setEnabled(false);
        Mesa20->setMinimumSize(QSize(0, 38));
        Mesa20->setIconSize(QSize(30, 29));

        gridLayout->addWidget(Mesa20, 1, 9, 1, 1);

        FrameMeseros = new QFrame(widget);
        FrameMeseros->setObjectName(QString::fromUtf8("FrameMeseros"));
        FrameMeseros->setGeometry(QRect(20, 70, 691, 121));
        FrameMeseros->setFrameShape(QFrame::StyledPanel);
        FrameMeseros->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(FrameMeseros);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 10, 55, 16));
        layoutWidget1 = new QWidget(FrameMeseros);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 20, 601, 101));
        gridMeseros = new QGridLayout(layoutWidget1);
        gridMeseros->setObjectName(QString::fromUtf8("gridMeseros"));
        gridMeseros->setHorizontalSpacing(2);
        gridMeseros->setVerticalSpacing(1);
        gridMeseros->setContentsMargins(0, 0, 0, 0);
        Mesero7 = new QPushButton(layoutWidget1);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(Mesero7);
        Mesero7->setObjectName(QString::fromUtf8("Mesero7"));
        Mesero7->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/030-waiter.png"), QSize(), QIcon::Normal, QIcon::Off);
        Mesero7->setIcon(icon);
        Mesero7->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero7, 0, 6, 1, 1);

        Mesero12 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero12);
        Mesero12->setObjectName(QString::fromUtf8("Mesero12"));
        Mesero12->setEnabled(false);
        Mesero12->setIcon(icon);
        Mesero12->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero12, 1, 1, 1, 1);

        Mesero13 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero13);
        Mesero13->setObjectName(QString::fromUtf8("Mesero13"));
        Mesero13->setEnabled(false);
        Mesero13->setIcon(icon);
        Mesero13->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero13, 1, 2, 1, 1);

        Mesero8 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero8);
        Mesero8->setObjectName(QString::fromUtf8("Mesero8"));
        Mesero8->setEnabled(false);
        Mesero8->setIcon(icon);
        Mesero8->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero8, 0, 7, 1, 1);

        Mesero14 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero14);
        Mesero14->setObjectName(QString::fromUtf8("Mesero14"));
        Mesero14->setEnabled(false);
        Mesero14->setStyleSheet(QString::fromUtf8(""));
        Mesero14->setIcon(icon);
        Mesero14->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero14, 1, 3, 1, 1);

        Mesero10 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero10);
        Mesero10->setObjectName(QString::fromUtf8("Mesero10"));
        Mesero10->setEnabled(false);
        Mesero10->setIcon(icon);
        Mesero10->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero10, 0, 9, 1, 1);

        Mesero18 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero18);
        Mesero18->setObjectName(QString::fromUtf8("Mesero18"));
        Mesero18->setEnabled(false);
        Mesero18->setIcon(icon);
        Mesero18->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero18, 1, 7, 1, 1);

        Mesero3 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero3);
        Mesero3->setObjectName(QString::fromUtf8("Mesero3"));
        Mesero3->setEnabled(false);
        Mesero3->setIcon(icon);
        Mesero3->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero3, 0, 2, 1, 1);

        Mesero15 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero15);
        Mesero15->setObjectName(QString::fromUtf8("Mesero15"));
        Mesero15->setEnabled(false);
        Mesero15->setIcon(icon);
        Mesero15->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero15, 1, 4, 1, 1);

        Mesero16 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero16);
        Mesero16->setObjectName(QString::fromUtf8("Mesero16"));
        Mesero16->setEnabled(false);
        Mesero16->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        Mesero16->setIcon(icon);
        Mesero16->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero16, 1, 5, 1, 1);

        Mesero19 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero19);
        Mesero19->setObjectName(QString::fromUtf8("Mesero19"));
        Mesero19->setEnabled(false);
        Mesero19->setIcon(icon);
        Mesero19->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero19, 1, 8, 1, 1);

        Mesero17 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero17);
        Mesero17->setObjectName(QString::fromUtf8("Mesero17"));
        Mesero17->setEnabled(false);
        Mesero17->setIcon(icon);
        Mesero17->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero17, 1, 6, 1, 1);

        Mesero20 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero20);
        Mesero20->setObjectName(QString::fromUtf8("Mesero20"));
        Mesero20->setEnabled(false);
        Mesero20->setIcon(icon);
        Mesero20->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero20, 1, 9, 1, 1);

        Mesero1 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero1);
        Mesero1->setObjectName(QString::fromUtf8("Mesero1"));
        Mesero1->setIcon(icon);
        Mesero1->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero1, 0, 0, 1, 1);

        Mesero4 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero4);
        Mesero4->setObjectName(QString::fromUtf8("Mesero4"));
        Mesero4->setEnabled(false);
        Mesero4->setIcon(icon);
        Mesero4->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero4, 0, 3, 1, 1);

        Mesero2 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero2);
        Mesero2->setObjectName(QString::fromUtf8("Mesero2"));
        Mesero2->setEnabled(false);
        Mesero2->setIcon(icon);
        Mesero2->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero2, 0, 1, 1, 1);

        Mesero9 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero9);
        Mesero9->setObjectName(QString::fromUtf8("Mesero9"));
        Mesero9->setEnabled(false);
        Mesero9->setIcon(icon);
        Mesero9->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero9, 0, 8, 1, 1);

        Mesero5 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero5);
        Mesero5->setObjectName(QString::fromUtf8("Mesero5"));
        Mesero5->setEnabled(false);
        Mesero5->setIcon(icon);
        Mesero5->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero5, 0, 4, 1, 1);

        Mesero6 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero6);
        Mesero6->setObjectName(QString::fromUtf8("Mesero6"));
        Mesero6->setEnabled(false);
        Mesero6->setIcon(icon);
        Mesero6->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero6, 0, 5, 1, 1);

        Mesero11 = new QPushButton(layoutWidget1);
        buttonGroup->addButton(Mesero11);
        Mesero11->setObjectName(QString::fromUtf8("Mesero11"));
        Mesero11->setEnabled(false);
        Mesero11->setIcon(icon);
        Mesero11->setIconSize(QSize(30, 29));

        gridMeseros->addWidget(Mesero11, 1, 0, 1, 1);

        FrameCocinas = new QFrame(widget);
        FrameCocinas->setObjectName(QString::fromUtf8("FrameCocinas"));
        FrameCocinas->setGeometry(QRect(720, 20, 151, 121));
        FrameCocinas->setFrameShape(QFrame::StyledPanel);
        FrameCocinas->setFrameShadow(QFrame::Raised);
        label = new QLabel(FrameCocinas);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 55, 16));
        pushButton_3 = new QPushButton(FrameCocinas);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 30, 93, 28));
        pushButton_4 = new QPushButton(FrameCocinas);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 60, 93, 28));
        pushButton_5 = new QPushButton(FrameCocinas);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 90, 93, 28));
        FrameLavaplatos = new QFrame(widget);
        FrameLavaplatos->setObjectName(QString::fromUtf8("FrameLavaplatos"));
        FrameLavaplatos->setGeometry(QRect(720, 170, 161, 71));
        FrameLavaplatos->setFrameShape(QFrame::StyledPanel);
        FrameLavaplatos->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(FrameLavaplatos);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 55, 16));
        pushButton_6 = new QPushButton(FrameLavaplatos);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 30, 93, 28));
        FrameCaja = new QFrame(widget);
        FrameCaja->setObjectName(QString::fromUtf8("FrameCaja"));
        FrameCaja->setGeometry(QRect(720, 270, 161, 71));
        FrameCaja->setFrameShape(QFrame::StyledPanel);
        FrameCaja->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(FrameCaja);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 55, 16));
        pushButton_7 = new QPushButton(FrameCaja);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 40, 93, 28));
        FrameEntrada = new QFrame(widget);
        FrameEntrada->setObjectName(QString::fromUtf8("FrameEntrada"));
        FrameEntrada->setGeometry(QRect(720, 370, 161, 71));
        FrameEntrada->setFrameShape(QFrame::StyledPanel);
        FrameEntrada->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(FrameEntrada);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 0, 55, 16));
        pushButton_8 = new QPushButton(FrameEntrada);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(10, 40, 93, 28));
        label_7 = new QLabel(FrameEntrada);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 91, 16));
        contadorEntrada = new QLabel(FrameEntrada);
        contadorEntrada->setObjectName(QString::fromUtf8("contadorEntrada"));
        contadorEntrada->setGeometry(QRect(100, 20, 21, 16));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 0, 81, 61));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(50, 50));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 0, 81, 61));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/video.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(50, 50));
        FramePropiedades = new QFrame(centralwidget);
        FramePropiedades->setObjectName(QString::fromUtf8("FramePropiedades"));
        FramePropiedades->setGeometry(QRect(950, 10, 271, 591));
        FramePropiedades->setStyleSheet(QString::fromUtf8("border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        FramePropiedades->setFrameShape(QFrame::StyledPanel);
        FramePropiedades->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(FramePropiedades);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 251, 581));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1237, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Mesa1->setText(QString());
        Mesa2->setText(QString());
        Mesa3->setText(QString());
        Mesa4->setText(QString());
        Mesa5->setText(QString());
        Mesa6->setText(QString());
        Mesa7->setText(QString());
        Mesa8->setText(QString());
        Mesa9->setText(QString());
        Mesa10->setText(QString());
        Mesa11->setText(QString());
        Mesa12->setText(QString());
        Mesa13->setText(QString());
        Mesa14->setText(QString());
        Mesa15->setText(QString());
        Mesa16->setText(QString());
        Mesa17->setText(QString());
        Mesa18->setText(QString());
        Mesa19->setText(QString());
        Mesa20->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Mesero7->setText(QString());
        Mesero12->setText(QString());
        Mesero13->setText(QString());
        Mesero8->setText(QString());
        Mesero14->setText(QString());
        Mesero10->setText(QString());
        Mesero18->setText(QString());
        Mesero3->setText(QString());
        Mesero15->setText(QString());
        Mesero16->setText(QString());
        Mesero19->setText(QString());
        Mesero17->setText(QString());
        Mesero20->setText(QString());
        Mesero1->setText(QString());
        Mesero4->setText(QString());
        Mesero2->setText(QString());
        Mesero9->setText(QString());
        Mesero5->setText(QString());
        Mesero6->setText(QString());
        Mesero11->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Entrada", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Proximo Grupo:", nullptr));
        contadorEntrada->setText(QString());
        pushButton_2->setText(QString());
        pushButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Status", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Customize", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
