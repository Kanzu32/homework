#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    mode = true;
    ui->setupUi(this);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_radioButton_clicked()
{
    ui->lineEdit_2->setEnabled(false);
    mode = false;
}


void SettingsDialog::on_radioButton_2_clicked()
{
    ui->lineEdit_2->setEnabled(true);
    mode = true;
}


void SettingsDialog::on_pushButton_2_clicked()
{
    this->reject();
}


void SettingsDialog::on_pushButton_clicked()
{
    pl2name = ui->lineEdit_2->text();
    pl1name = ui->lineEdit->text();
    this->accept();
}

void SettingsDialog::getSettings(bool& m, QString& p1, QString& p2) {
    m = this->mode;
    p1 = this->pl1name;
    p2 = this->pl2name;
}
