/********************************************************************************
** Form generated from reading UI file 'drawarea.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWAREA_H
#define UI_DRAWAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawArea
{
public:
    QDockWidget *sideDock;
    QWidget *dockWidgetContents;

    void setupUi(QWidget *DrawArea)
    {
        if (DrawArea->objectName().isEmpty())
            DrawArea->setObjectName(QString::fromUtf8("DrawArea"));
        DrawArea->resize(1088, 577);
        sideDock = new QDockWidget(DrawArea);
        sideDock->setObjectName(QString::fromUtf8("sideDock"));
        sideDock->setGeometry(QRect(800, 0, 200, 500));
        sideDock->setMaximumSize(QSize(200, 524287));
        sideDock->setStyleSheet(QString::fromUtf8("background-color: rgb(159, 159, 159);"));
        sideDock->setFloating(false);
        sideDock->setAllowedAreas(Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockWidgetContents->setMaximumSize(QSize(200, 16777215));
        sideDock->setWidget(dockWidgetContents);

        retranslateUi(DrawArea);

        QMetaObject::connectSlotsByName(DrawArea);
    } // setupUi

    void retranslateUi(QWidget *DrawArea)
    {
        DrawArea->setWindowTitle(QCoreApplication::translate("DrawArea", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawArea: public Ui_DrawArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWAREA_H
