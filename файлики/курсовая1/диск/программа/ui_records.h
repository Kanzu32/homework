/********************************************************************************
** Form generated from reading UI file 'records.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDS_H
#define UI_RECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Records
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *backButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Records)
    {
        if (Records->objectName().isEmpty())
            Records->setObjectName(QString::fromUtf8("Records"));
        Records->resize(990, 662);
        Records->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 47, 51);"));
        verticalLayout = new QVBoxLayout(Records);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_2 = new QFrame(Records);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(100, 100));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Press Start 2P"));
        font.setPointSize(36);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(244, 226, 66);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Press Start 2P"));
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(244, 226, 66);"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);


        verticalLayout->addWidget(frame_2);

        frame = new QFrame(Records);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(0, 75));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        oneButton = new QPushButton(frame);
        oneButton->setObjectName(QString::fromUtf8("oneButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(oneButton->sizePolicy().hasHeightForWidth());
        oneButton->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Press Start 2P"));
        font2.setPointSize(20);
        oneButton->setFont(font2);
        oneButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        horizontalLayout->addWidget(oneButton);

        twoButton = new QPushButton(frame);
        twoButton->setObjectName(QString::fromUtf8("twoButton"));
        sizePolicy2.setHeightForWidth(twoButton->sizePolicy().hasHeightForWidth());
        twoButton->setSizePolicy(sizePolicy2);
        twoButton->setFont(font2);
        twoButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));

        horizontalLayout->addWidget(twoButton);

        backButton = new QPushButton(frame);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        sizePolicy2.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Press Start 2P"));
        font3.setPointSize(20);
        font3.setKerning(true);
        backButton->setFont(font3);
        backButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(74, 80, 86);\n"
"	color: rgb(216, 216, 216);\n"
"}\n"
"QPushButton:hover:!pressed  {\n"
"	background-color: rgb(244, 226, 66);\n"
"	color: rgb(43, 43, 43);\n"
"}"));
        backButton->setAutoDefault(false);
        backButton->setFlat(false);

        horizontalLayout->addWidget(backButton);


        verticalLayout->addWidget(frame);

        tableWidget = new QTableWidget(Records);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy3);
        QFont font4;
        font4.setPointSize(12);
        tableWidget->setFont(font4);
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"	color: rgb(216, 216, 216);\n"
"    gridline-color: #fffff8;\n"
"}\n"
"\n"
"\n"
"\n"
"QHeaderView::section {\n"
"	color: rgb(216, 216, 216);\n"
"    background-color: rgb(35, 37, 40);\n"
"	gridline-color: #fffff8;\n"
"    padding: 4px;\n"
"    font-size: 14pt;\n"
"}\n"
""));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setCornerButtonEnabled(false);

        verticalLayout->addWidget(tableWidget);

        QWidget::setTabOrder(oneButton, twoButton);
        QWidget::setTabOrder(twoButton, backButton);

        retranslateUi(Records);

        backButton->setDefault(false);


        QMetaObject::connectSlotsByName(Records);
    } // setupUi

    void retranslateUi(QWidget *Records)
    {
        Records->setWindowTitle(QCoreApplication::translate("Records", "Records", nullptr));
        label->setText(QCoreApplication::translate("Records", "PAC-MAN", nullptr));
        label_2->setText(QCoreApplication::translate("Records", "LEADERBOARD", nullptr));
        oneButton->setText(QCoreApplication::translate("Records", "1 PLAYER", nullptr));
        twoButton->setText(QCoreApplication::translate("Records", "2 PLAYERS", nullptr));
        backButton->setText(QCoreApplication::translate("Records", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Records: public Ui_Records {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDS_H
