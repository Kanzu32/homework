#include "records.h"
#include "ui_records.h"
#include <QDebug>
Records::Records(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Records)
{
    ui->setupUi(this);
    QWidget::showFullScreen();
    table = ui->tableWidget;
    model = new QStandardItemModel();
    fill1player();
}

Records::~Records()
{
    delete ui;
}

void Records::fill1player() {
    table->setRowCount(0);
    QString endPath = QCoreApplication::applicationDirPath() + "/records/records1player.txt";
    QFile file(endPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    int i = 0;
    table->setColumnCount(4);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Map"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Score"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Time"));
    while (!in.atEnd()) {
        table->setRowCount(table->rowCount()+1);
        QString data = in.readLine();
        QStringList splited = data.split('|');
        if (splited.size() < 4) {
            break;
        }
        table->setItem(i, 0, new QTableWidgetItem(splited.at(0)));
        table->setItem(i, 1, new QTableWidgetItem(splited.at(1)));
        table->setItem(i, 2, new QTableWidgetItem(splited.at(2)));
        table->setItem(i, 3, new QTableWidgetItem(splited.at(3)));
        i++;
    }
    file.close();
}

void Records::fill2players() {
    table->setRowCount(0);
    QString endPath = QCoreApplication::applicationDirPath() + "/records/records2players.txt";
    QFile file(endPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    int i = 0;
    table->setColumnCount(6);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Map"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("1 Pl Name"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("2 Pl Name"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("1 Pl Score"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("2 Pl Score"));
    table->setHorizontalHeaderItem(5, new QTableWidgetItem("Time"));
    while (!in.atEnd()) {
        table->setRowCount(table->rowCount()+1);
        QString data = in.readLine();
        QStringList splited = data.split('|');
        if (splited.size() < 6) {
            break;
        }
        table->setItem(i, 0, new QTableWidgetItem(splited.at(0)));
        table->setItem(i, 1, new QTableWidgetItem(splited.at(1)));
        table->setItem(i, 2, new QTableWidgetItem(splited.at(2)));
        table->setItem(i, 3, new QTableWidgetItem(splited.at(3)));
        table->setItem(i, 4, new QTableWidgetItem(splited.at(4)));
        table->setItem(i, 5, new QTableWidgetItem(splited.at(5)));
        i++;
    }
    file.close();
}

void Records::on_pushButton_clicked()
{
    fill1player();
}


void Records::on_pushButton_2_clicked()
{
    fill2players();
}

