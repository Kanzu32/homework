#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <set>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    std::vector<QString> targetArr = {"б", "в", "г", "д", "ж", "з", "й", "л", "м", "н", "р"};
    std::vector<QString> arr;
    std::multiset<QString> set;
    QStringList list = text.split(' ');
    for (QString str : list) {
        for (QString target : targetArr) {
            if (str.contains(target)) {
                set.insert(target);
            }
        }
    }
    ui->textEdit_2->clear();
    for (QString target : targetArr) {
        if (set.count(target) > 1) {
            ui->textEdit_2->append(" " + target);
        }
    }
}

