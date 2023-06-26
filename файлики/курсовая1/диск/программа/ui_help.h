/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *rusButton;
    QPushButton *engButton;
    QPushButton *backButton;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QString::fromUtf8("Help"));
        Help->resize(935, 656);
        Help->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 47, 51);"));
        verticalLayout = new QVBoxLayout(Help);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(Help);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rusButton = new QPushButton(frame);
        rusButton->setObjectName(QString::fromUtf8("rusButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rusButton->sizePolicy().hasHeightForWidth());
        rusButton->setSizePolicy(sizePolicy1);
        rusButton->setMinimumSize(QSize(0, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("Press Start 2P"));
        font.setPointSize(20);
        rusButton->setFont(font);
        rusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        horizontalLayout->addWidget(rusButton);

        engButton = new QPushButton(frame);
        engButton->setObjectName(QString::fromUtf8("engButton"));
        sizePolicy1.setHeightForWidth(engButton->sizePolicy().hasHeightForWidth());
        engButton->setSizePolicy(sizePolicy1);
        engButton->setMinimumSize(QSize(0, 60));
        engButton->setFont(font);
        engButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        horizontalLayout->addWidget(engButton);

        backButton = new QPushButton(frame);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        sizePolicy1.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy1);
        backButton->setMinimumSize(QSize(0, 60));
        backButton->setFont(font);
        backButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        horizontalLayout->addWidget(backButton);


        verticalLayout->addWidget(frame);

        textBrowser = new QTextBrowser(Help);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(Help);

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QWidget *Help)
    {
        Help->setWindowTitle(QCoreApplication::translate("Help", "Help", nullptr));
        rusButton->setText(QCoreApplication::translate("Help", "\320\240\320\243\320\241\320\241\320\232\320\230\320\231", nullptr));
        engButton->setText(QCoreApplication::translate("Help", "ENGLISH", nullptr));
        backButton->setText(QCoreApplication::translate("Help", "BACK", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; color:#d8d8d8;\">[Main menu]</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#d8d8d8;\">Click PLAY to start the game for the intended players, level and the level itself.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#d8d8d8;\">Click SETTINGS "
                        "to customize the controls and select the lives of the players.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#d8d8d8;\">Click RECORDS to view the table of records</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; color:#d8d8d8;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; color:#d8d8d8;\">[Controls]</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#d8d8d8;\">Character control settings are in SETTINGS.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bl"
                        "ock-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#d8d8d8;\">Press ESC during game to exit to main menu.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; color:#d8d8d8;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; color:#d8d8d8;\">[Music controls]</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#d8d8d8;\">F1 - pause</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#d8d8d8;\">F2 - volume down</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0p"
                        "x; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#d8d8d8;\">F3 - increase volume</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#d8d8d8;\">F4 - previous track</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#d8d8d8;\">F5 - next track</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; color:#d8d8d8;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#d8d8d8;\">Levels folder at the root of game files &quot;level&quot;, &quot;music&quot; folder contains background music. supported formats: MP3 "
                        "and WAV.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
