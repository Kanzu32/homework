/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *exitButton;
    QPushButton *continueButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(481, 271);
        SettingsDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 47, 51);"));
        groupBox = new QGroupBox(SettingsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 141, 101));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setEnabled(true);
        radioButton->setGeometry(QRect(0, 0, 141, 51));
        QFont font;
        font.setPointSize(12);
        radioButton->setFont(font);
        radioButton->setStyleSheet(QString::fromUtf8("color: rgb(216, 216, 216);"));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setEnabled(true);
        radioButton_2->setGeometry(QRect(0, 50, 141, 51));
        radioButton_2->setFont(font);
        radioButton_2->setStyleSheet(QString::fromUtf8("color: rgb(216, 216, 216);"));
        exitButton = new QPushButton(SettingsDialog);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(250, 210, 201, 41));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));
        continueButton = new QPushButton(SettingsDialog);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setGeometry(QRect(20, 210, 211, 41));
        continueButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));
        lineEdit = new QLineEdit(SettingsDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(190, 30, 261, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(216, 216, 216);\n"
"border: 2px solid gray;"));
        lineEdit->setMaxLength(10);
        lineEdit_2 = new QLineEdit(SettingsDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(190, 90, 261, 41));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	color: rgb(216, 216, 216);\n"
"	border: 2px solid gray;\n"
"}\n"
" QLineEdit:disabled {\n"
"     background: rgb(132, 132, 132);\n"
"}"));
        lineEdit_2->setMaxLength(10);
        groupBox_2 = new QGroupBox(SettingsDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 140, 431, 65));
        groupBox_2->setStyleSheet(QString::fromUtf8("color: rgb(216, 216, 216);\n"
"border: none;"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(groupBox_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setStyleSheet(QString::fromUtf8(""));
        splitter->setOrientation(Qt::Horizontal);
        radioButton_5 = new QRadioButton(splitter);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setStyleSheet(QString::fromUtf8("color: rgb(216, 216, 216);"));
        radioButton_5->setChecked(true);
        splitter->addWidget(radioButton_5);
        radioButton_6 = new QRadioButton(splitter);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(radioButton_6->sizePolicy().hasHeightForWidth());
        radioButton_6->setSizePolicy(sizePolicy1);
        radioButton_6->setStyleSheet(QString::fromUtf8("color: rgb(216, 216, 216);"));
        splitter->addWidget(radioButton_6);
        radioButton_7 = new QRadioButton(splitter);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(radioButton_7->sizePolicy().hasHeightForWidth());
        radioButton_7->setSizePolicy(sizePolicy2);
        radioButton_7->setStyleSheet(QString::fromUtf8("color: rgb(216, 216, 216);"));
        splitter->addWidget(radioButton_7);

        verticalLayout->addWidget(splitter);


        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Dialog", nullptr));
        groupBox->setTitle(QString());
        radioButton->setText(QCoreApplication::translate("SettingsDialog", "1 Player", nullptr));
        radioButton_2->setText(QCoreApplication::translate("SettingsDialog", "2 Players", nullptr));
        exitButton->setText(QCoreApplication::translate("SettingsDialog", "EXIT", nullptr));
        continueButton->setText(QCoreApplication::translate("SettingsDialog", "CONTINUE", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("SettingsDialog", "PL1 NAME", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("SettingsDialog", "PL2 NAME", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SettingsDialog", "Difficulty", nullptr));
        radioButton_5->setText(QCoreApplication::translate("SettingsDialog", "Easy", nullptr));
        radioButton_6->setText(QCoreApplication::translate("SettingsDialog", "Medium", nullptr));
        radioButton_7->setText(QCoreApplication::translate("SettingsDialog", "Hard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
