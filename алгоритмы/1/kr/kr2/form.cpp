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
    int n;
    double sm = 0;
    n = (ui -> lineEdit -> text()).toInt();

    for (int i = 1; i <= n; i++) {
        sm += 1.0/i;
    }

    QString str = QString::number(sm);

    ui -> label_3 -> setText(str);

}

