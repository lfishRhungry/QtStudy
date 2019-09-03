/********************************************************************************
** Form generated from reading UI file 'smalwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMALWIDGET_H
#define UI_SMALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smalWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *smalWidget)
    {
        if (smalWidget->objectName().isEmpty())
            smalWidget->setObjectName(QString::fromUtf8("smalWidget"));
        smalWidget->resize(375, 41);
        horizontalLayout = new QHBoxLayout(smalWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spinBox = new QSpinBox(smalWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);

        horizontalSlider = new QSlider(smalWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);


        retranslateUi(smalWidget);

        QMetaObject::connectSlotsByName(smalWidget);
    } // setupUi

    void retranslateUi(QWidget *smalWidget)
    {
        smalWidget->setWindowTitle(QCoreApplication::translate("smalWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class smalWidget: public Ui_smalWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALWIDGET_H
