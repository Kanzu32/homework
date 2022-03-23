#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
    QString text;
    QString tmp;
    QVector<QString> arr;
    int start = 0;
    text = ui->textEdit->toPlainText();
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.' || i == text.length()-1) {
            tmp = text.mid(start, i-start+1);
            if (!tmp.isEmpty()) {
                arr.append(tmp);
            }
            start = i+1;
        }
    }
    for (int x = 0; x < arr.length()-1; x++) {
        for (int i = 0; i < arr.length()-x-1; i++) {
            if (arr[i].compare(arr[i+1]) > 0) {
                swap(arr[i], arr[i+1]);
            }
        }
    }

    for (QString item : arr) {
        ui->textEdit_2->append(item);
    }

}

