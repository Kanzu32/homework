#include "form.h"
#include "./ui_form.h"

form::form(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::form)
{
    ui->setupUi(this);
}

form::~form()
{
    delete ui;
}

void form::on_pushButton_clicked() {
    QString str = ui->lineEdit->text();
    ui -> listWidget -> insertItem(0, str);
    ui -> lineEdit -> setText("");
    ui -> label_8 -> setText(str);
}

void form::on_pushButton_3_clicked() {
    if (ui -> listWidget -> count()) {
        QString str = ui -> listWidget -> item(0) -> text();
        ui -> listWidget -> takeItem(0);
        ui -> lineEdit -> setText("");
        ui -> label_9 -> setText(str);
    }
}

void form::on_pushButton_2_clicked() {
    QString str = ui->lineEdit->text();
    ui -> textEdit -> append(str);
    ui -> lineEdit -> setText("");
    ui -> label_10 -> setText(str);
}

void form::on_pushButton_4_clicked() {
    if (ui -> textEdit -> toPlainText() != ""){
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.select(QTextCursor::LineUnderCursor);
        QString str = cursor.selectedText();
        cursor.removeSelectedText();
        cursor.deletePreviousChar();
        ui->textEdit->setTextCursor(cursor);
        ui -> lineEdit -> setText("");
        ui -> label_11 -> setText(str);
    }
}


