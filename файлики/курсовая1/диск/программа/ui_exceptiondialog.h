/********************************************************************************
** Form generated from reading UI file 'exceptiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCEPTIONDIALOG_H
#define UI_EXCEPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ExceptionDialog
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *ExceptionDialog)
    {
        if (ExceptionDialog->objectName().isEmpty())
            ExceptionDialog->setObjectName(QString::fromUtf8("ExceptionDialog"));
        ExceptionDialog->resize(450, 198);
        ExceptionDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 47, 51);"));
        pushButton = new QPushButton(ExceptionDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 140, 211, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));
        label = new QLabel(ExceptionDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 401, 61));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(216, 216, 216);"));

        retranslateUi(ExceptionDialog);

        QMetaObject::connectSlotsByName(ExceptionDialog);
    } // setupUi

    void retranslateUi(QDialog *ExceptionDialog)
    {
        ExceptionDialog->setWindowTitle(QCoreApplication::translate("ExceptionDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ExceptionDialog", "OK", nullptr));
        label->setText(QCoreApplication::translate("ExceptionDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExceptionDialog: public Ui_ExceptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCEPTIONDIALOG_H
