/********************************************************************************
** Form generated from reading UI file 'mainframe.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainFrame
{
public:

    void setupUi(QWidget *MainFrame)
    {
        if (MainFrame->objectName().isEmpty())
            MainFrame->setObjectName(QString::fromUtf8("MainFrame"));
        MainFrame->resize(400, 300);

        retranslateUi(MainFrame);

        QMetaObject::connectSlotsByName(MainFrame);
    } // setupUi

    void retranslateUi(QWidget *MainFrame)
    {
        MainFrame->setWindowTitle(QCoreApplication::translate("MainFrame", "MainFrame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainFrame: public Ui_MainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFRAME_H
