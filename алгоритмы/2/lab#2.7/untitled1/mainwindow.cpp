#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>

QString infilename = "";
QString outfilename = "";

QString alph1 = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
QString alph2 = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";


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
    if (infilename == "" || outfilename == "") {
        return;
    }

    QFile inFile(infilename);
    inFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QFile outFile(outfilename);
    outFile.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream in(&inFile);
    QTextStream out(&outFile);

    QString str = in.readAll();
    int k = ui -> spinBox ->value();
    int pos;
    for (int i = 0; i < str.size(); i++) {
        pos = alph1.indexOf(str[i], 0, Qt::CaseSensitive);
        if (pos != -1) {
            str[i] = alph1[(33+pos+k)%33];
            continue;
        }
        pos = alph2.indexOf(str[i], 0, Qt::CaseSensitive);
        if (pos != -1) {
            str[i] = alph2[(33+pos+k)%33];
            continue;
        }

    }

    out << str;

}


void MainWindow::on_pushButton_2_clicked()
{
    infilename = QFileDialog::getOpenFileName(this, "Choose In File");
    ui -> label_4->setText(infilename);
}




void MainWindow::on_pushButton_3_clicked()
{
    outfilename = QFileDialog::getOpenFileName(this, "Choose Out File");
    ui -> label_5->setText(outfilename);
}

