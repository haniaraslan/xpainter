/********************************************************************************
** Form generated from reading UI file 'paint3d.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINT3D_H
#define UI_PAINT3D_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Paint3D
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionPenColor;
    QAction *actionPenWidth;
    QAction *actionClearScreen;
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actiontest;
    QAction *actionPen;
    QAction *actionMarker;
    QAction *actionEraser;
    QAction *actionOilBrush;
    QAction *actionWaterColorBrush;
    QAction *actionUndo;
    QAction *actionSaveAs;
    QAction *actionRedo;
    QAction *actionPrint;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *menuSaveAs;
    QMenu *menuOptions;
    QMenu *menuHelp;
    QMenu *menuBrushes;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Paint3D)
    {
        if (Paint3D->objectName().isEmpty())
            Paint3D->setObjectName(QString::fromUtf8("Paint3D"));
        Paint3D->resize(1094, 540);
        actionOpen = new QAction(Paint3D);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionExit = new QAction(Paint3D);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionPenColor = new QAction(Paint3D);
        actionPenColor->setObjectName(QString::fromUtf8("actionPenColor"));
        actionPenWidth = new QAction(Paint3D);
        actionPenWidth->setObjectName(QString::fromUtf8("actionPenWidth"));
        actionClearScreen = new QAction(Paint3D);
        actionClearScreen->setObjectName(QString::fromUtf8("actionClearScreen"));
        actionAbout = new QAction(Paint3D);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAboutQt = new QAction(Paint3D);
        actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
        actiontest = new QAction(Paint3D);
        actiontest->setObjectName(QString::fromUtf8("actiontest"));
        actionPen = new QAction(Paint3D);
        actionPen->setObjectName(QString::fromUtf8("actionPen"));
        actionMarker = new QAction(Paint3D);
        actionMarker->setObjectName(QString::fromUtf8("actionMarker"));
        actionEraser = new QAction(Paint3D);
        actionEraser->setObjectName(QString::fromUtf8("actionEraser"));
        actionOilBrush = new QAction(Paint3D);
        actionOilBrush->setObjectName(QString::fromUtf8("actionOilBrush"));
        actionWaterColorBrush = new QAction(Paint3D);
        actionWaterColorBrush->setObjectName(QString::fromUtf8("actionWaterColorBrush"));
        actionUndo = new QAction(Paint3D);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon1);
        actionSaveAs = new QAction(Paint3D);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAs->setIcon(icon2);
        actionRedo = new QAction(Paint3D);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon3);
        actionPrint = new QAction(Paint3D);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon4);
        centralwidget = new QWidget(Paint3D);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Paint3D->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Paint3D);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1094, 26));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
        menuSaveAs = new QMenu(fileMenu);
        menuSaveAs->setObjectName(QString::fromUtf8("menuSaveAs"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuBrushes = new QMenu(menubar);
        menuBrushes->setObjectName(QString::fromUtf8("menuBrushes"));
        Paint3D->setMenuBar(menubar);
        statusbar = new QStatusBar(Paint3D);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Paint3D->setStatusBar(statusbar);
        toolBar = new QToolBar(Paint3D);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Paint3D->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(fileMenu->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuBrushes->menuAction());
        fileMenu->addAction(actionOpen);
        fileMenu->addAction(menuSaveAs->menuAction());
        fileMenu->addSeparator();
        fileMenu->addAction(actionExit);
        menuOptions->addAction(actionPenColor);
        menuOptions->addAction(actionPenWidth);
        menuOptions->addSeparator();
        menuOptions->addAction(actionClearScreen);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        menuBrushes->addAction(actionPen);
        menuBrushes->addAction(actionMarker);
        menuBrushes->addAction(actionOilBrush);
        menuBrushes->addAction(actionEraser);
        menuBrushes->addAction(actionWaterColorBrush);
        toolBar->addAction(actionOpen);
        toolBar->addSeparator();
        toolBar->addAction(actionSaveAs);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addSeparator();
        toolBar->addAction(actionRedo);
        toolBar->addSeparator();
        toolBar->addAction(actionPrint);
        toolBar->addSeparator();

        retranslateUi(Paint3D);

        QMetaObject::connectSlotsByName(Paint3D);
    } // setupUi

    void retranslateUi(QMainWindow *Paint3D)
    {
        Paint3D->setWindowTitle(QCoreApplication::translate("Paint3D", "Paint3D", nullptr));
        actionOpen->setText(QCoreApplication::translate("Paint3D", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("Paint3D", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("Paint3D", "Exit", nullptr));
        actionPenColor->setText(QCoreApplication::translate("Paint3D", "Pen Color..", nullptr));
        actionPenWidth->setText(QCoreApplication::translate("Paint3D", "Pen Width..", nullptr));
        actionClearScreen->setText(QCoreApplication::translate("Paint3D", "Clear Screen..", nullptr));
#if QT_CONFIG(shortcut)
        actionClearScreen->setShortcut(QCoreApplication::translate("Paint3D", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("Paint3D", "About..", nullptr));
        actionAboutQt->setText(QCoreApplication::translate("Paint3D", "About Qt..", nullptr));
        actiontest->setText(QCoreApplication::translate("Paint3D", "test", nullptr));
        actionPen->setText(QCoreApplication::translate("Paint3D", "Pen", nullptr));
        actionMarker->setText(QCoreApplication::translate("Paint3D", "Marker", nullptr));
        actionEraser->setText(QCoreApplication::translate("Paint3D", "Eraser", nullptr));
        actionOilBrush->setText(QCoreApplication::translate("Paint3D", "Oil Brush", nullptr));
        actionWaterColorBrush->setText(QCoreApplication::translate("Paint3D", "Watercolor Brush", nullptr));
        actionUndo->setText(QCoreApplication::translate("Paint3D", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("Paint3D", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveAs->setText(QCoreApplication::translate("Paint3D", "Save as", nullptr));
#if QT_CONFIG(shortcut)
        actionSaveAs->setShortcut(QCoreApplication::translate("Paint3D", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("Paint3D", "Redo", nullptr));
#if QT_CONFIG(tooltip)
        actionRedo->setToolTip(QCoreApplication::translate("Paint3D", "Redo", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("Paint3D", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPrint->setText(QCoreApplication::translate("Paint3D", "Print", nullptr));
#if QT_CONFIG(tooltip)
        actionPrint->setToolTip(QCoreApplication::translate("Paint3D", "Print", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPrint->setShortcut(QCoreApplication::translate("Paint3D", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        fileMenu->setTitle(QCoreApplication::translate("Paint3D", "File", nullptr));
        menuSaveAs->setTitle(QCoreApplication::translate("Paint3D", "Save As", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("Paint3D", "Options", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("Paint3D", "Help", nullptr));
        menuBrushes->setTitle(QCoreApplication::translate("Paint3D", "Brushes", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Paint3D", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Paint3D: public Ui_Paint3D {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINT3D_H
