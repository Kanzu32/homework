/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *playButton;
    QPushButton *recordsButton;
    QPushButton *settingsButton;
    QPushButton *helpButton;
    QPushButton *exitButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 740);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 47, 51);"));
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_3 = new QFrame(Widget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(0, 0));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(194, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        frame = new QFrame(frame_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 200));
        QFont font;
        font.setFamily(QString::fromUtf8("Press Start 2P"));
        font.setPointSize(36);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(244, 226, 66);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        playButton = new QPushButton(frame);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setMinimumSize(QSize(300, 80));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Press Start 2P"));
        font1.setPointSize(20);
        playButton->setFont(font1);
        playButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        verticalLayout->addWidget(playButton);

        recordsButton = new QPushButton(frame);
        recordsButton->setObjectName(QString::fromUtf8("recordsButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(recordsButton->sizePolicy().hasHeightForWidth());
        recordsButton->setSizePolicy(sizePolicy1);
        recordsButton->setMinimumSize(QSize(300, 80));
        recordsButton->setFont(font1);
        recordsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        verticalLayout->addWidget(recordsButton);

        settingsButton = new QPushButton(frame);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));
        settingsButton->setMinimumSize(QSize(300, 80));
        settingsButton->setFont(font1);
        settingsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        verticalLayout->addWidget(settingsButton);

        helpButton = new QPushButton(frame);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setMinimumSize(QSize(300, 80));
        helpButton->setFont(font1);
        helpButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        verticalLayout->addWidget(helpButton);

        exitButton = new QPushButton(frame);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setMinimumSize(QSize(300, 80));
        exitButton->setFont(font1);
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        verticalLayout->addWidget(exitButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(frame);

        horizontalSpacer_3 = new QSpacerItem(194, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(frame_3);

        frame_2 = new QFrame(Widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy2);
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(704, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_2->addWidget(frame_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Menu", nullptr));
        label->setText(QCoreApplication::translate("Widget", "PAC-MAN", nullptr));
        playButton->setText(QCoreApplication::translate("Widget", "PLAY", nullptr));
        recordsButton->setText(QCoreApplication::translate("Widget", "RECORDS", nullptr));
        settingsButton->setText(QCoreApplication::translate("Widget", "SETTINGS", nullptr));
        helpButton->setText(QCoreApplication::translate("Widget", "HELP", nullptr));
        exitButton->setText(QCoreApplication::translate("Widget", "EXIT", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
