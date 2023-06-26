/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

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

class Ui_Game
{
public:
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QPushButton *againButton;
    QPushButton *recordsButton;
    QPushButton *menuButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(976, 665);
        Game->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 47, 51);"));
        verticalLayout_4 = new QVBoxLayout(Game);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        frame_5 = new QFrame(Game);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 47, 51);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        frame_4 = new QFrame(frame_5);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setMinimumSize(QSize(0, 100));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(275, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        label = new QLabel(frame_4);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(350, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("Press Start 2P"));
        font.setPointSize(48);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(244, 226, 66);"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_6 = new QSpacerItem(275, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_3->addWidget(frame_4);

        frame_3 = new QFrame(frame_5);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(0, 50));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(378, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Press Start 2P"));
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(216, 216, 216);"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(378, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_3->addWidget(frame_3);

        frame_2 = new QFrame(frame_5);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(265, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        frame = new QFrame(frame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        againButton = new QPushButton(frame);
        againButton->setObjectName(QString::fromUtf8("againButton"));
        sizePolicy1.setHeightForWidth(againButton->sizePolicy().hasHeightForWidth());
        againButton->setSizePolicy(sizePolicy1);
        againButton->setMinimumSize(QSize(350, 60));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Press Start 2P"));
        font2.setPointSize(28);
        againButton->setFont(font2);
        againButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        verticalLayout_2->addWidget(againButton);

        recordsButton = new QPushButton(frame);
        recordsButton->setObjectName(QString::fromUtf8("recordsButton"));
        recordsButton->setMinimumSize(QSize(350, 60));
        recordsButton->setFont(font2);
        recordsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        verticalLayout_2->addWidget(recordsButton);

        menuButton = new QPushButton(frame);
        menuButton->setObjectName(QString::fromUtf8("menuButton"));
        menuButton->setMinimumSize(QSize(350, 60));
        menuButton->setFont(font2);
        menuButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        verticalLayout_2->addWidget(menuButton);


        horizontalLayout_2->addWidget(frame);

        horizontalSpacer_2 = new QSpacerItem(265, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(frame_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addWidget(frame_5);


        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Game", nullptr));
        label->setText(QCoreApplication::translate("Game", "WIN", nullptr));
        label_2->setText(QCoreApplication::translate("Game", "TextLabel", nullptr));
        againButton->setText(QCoreApplication::translate("Game", "AGAIN", nullptr));
        recordsButton->setText(QCoreApplication::translate("Game", "RECORDS", nullptr));
        menuButton->setText(QCoreApplication::translate("Game", "MENU", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
