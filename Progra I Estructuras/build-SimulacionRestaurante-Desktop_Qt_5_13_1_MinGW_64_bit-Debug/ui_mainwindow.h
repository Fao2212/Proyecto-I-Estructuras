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
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
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
    QFrame *FrameMeseros;
    QLabel *label_5;
    QFrame *FrameCocinas;
    QLabel *label;
    QFrame *FrameLavaplatos;
    QLabel *label_2;
    QFrame *FrameCaja;
    QLabel *label_3;
    QFrame *FrameEntrada;
    QLabel *label_4;
    QPushButton *pushButton;
    QFrame *FramePropiedades;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

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
        FrameMesas->setGeometry(QRect(30, 130, 641, 301));
        FrameMesas->setFrameShape(QFrame::StyledPanel);
        FrameMesas->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(FrameMesas);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 10, 55, 16));
        FrameMeseros = new QFrame(widget);
        FrameMeseros->setObjectName(QString::fromUtf8("FrameMeseros"));
        FrameMeseros->setGeometry(QRect(30, 20, 641, 71));
        FrameMeseros->setFrameShape(QFrame::StyledPanel);
        FrameMeseros->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(FrameMeseros);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 10, 55, 16));
        FrameCocinas = new QFrame(widget);
        FrameCocinas->setObjectName(QString::fromUtf8("FrameCocinas"));
        FrameCocinas->setGeometry(QRect(720, 20, 151, 121));
        FrameCocinas->setFrameShape(QFrame::StyledPanel);
        FrameCocinas->setFrameShadow(QFrame::Raised);
        label = new QLabel(FrameCocinas);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 55, 16));
        FrameLavaplatos = new QFrame(widget);
        FrameLavaplatos->setObjectName(QString::fromUtf8("FrameLavaplatos"));
        FrameLavaplatos->setGeometry(QRect(720, 170, 161, 71));
        FrameLavaplatos->setFrameShape(QFrame::StyledPanel);
        FrameLavaplatos->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(FrameLavaplatos);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 55, 16));
        FrameCaja = new QFrame(widget);
        FrameCaja->setObjectName(QString::fromUtf8("FrameCaja"));
        FrameCaja->setGeometry(QRect(720, 270, 161, 71));
        FrameCaja->setFrameShape(QFrame::StyledPanel);
        FrameCaja->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(FrameCaja);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 55, 16));
        FrameEntrada = new QFrame(widget);
        FrameEntrada->setObjectName(QString::fromUtf8("FrameEntrada"));
        FrameEntrada->setGeometry(QRect(720, 370, 161, 71));
        FrameEntrada->setFrameShape(QFrame::StyledPanel);
        FrameEntrada->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(FrameEntrada);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 55, 16));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 10, 93, 28));
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
        frame_2 = new QFrame(tab);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 251, 81));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        stackedWidget = new QStackedWidget(tab);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 80, 251, 471));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
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

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
