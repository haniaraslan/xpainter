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
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawArea
{
public:
    QOpenGLWidget *openGLWidget;

    void setupUi(QWidget *DrawArea)
    {
        if (DrawArea->objectName().isEmpty())
            DrawArea->setObjectName(QString::fromUtf8("DrawArea"));
        DrawArea->resize(1088, 577);
        openGLWidget = new QOpenGLWidget(DrawArea);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(280, 210, 300, 200));

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
