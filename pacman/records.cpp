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
    table->clear();
    table->setSortingEnabled(false);
    table->setRowCount(0);
    QString endPath = QCoreApplication::applicationDirPath() + "/records/records1player.txt";
    QFile file(endPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    int i = 0;
    table->setColumnCount(6);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Map"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Difficulty"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Lives"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Name"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("Score"));
    table->setHorizontalHeaderItem(5, new QTableWidgetItem("Time"));
    while (!in.atEnd()) {
        table->setRowCount(table->rowCount()+1);
        QString data = in.readLine();
        QStringList splited = data.split('|');
        if (splited.size() < 6) {
            break;
        }
        table->setItem(i, 0, new QTableWidgetItem(splited.at(0)));
        switch (splited.at(1).toInt()) {
        case 1:
            table->setItem(i, 1, new QTableWidgetItem("Easy"));
            break;
        case 2:
            table->setItem(i, 1, new QTableWidgetItem("Medium"));
            break;
        case 3:
            table->setItem(i, 1, new QTableWidgetItem("Hard"));
            break;
        default:
            break;
        }
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setData(Qt::DisplayRole, splited.at(2).toInt());
        table->setItem(i, 2, item);
        item = new QTableWidgetItem();
        table->setItem(i, 3, new QTableWidgetItem(splited.at(3)));
        item->setData(Qt::DisplayRole, splited.at(4).toInt());
        table->setItem(i, 4, item);
        item = new QTableWidgetItem();
        item->setData(Qt::DisplayRole, splited.at(5).toFloat());
        table->setItem(i, 5, item);
        i++;
    }
    file.close();
    table->setSortingEnabled(true);
}

void Records::fill2players() {
    table->clear();
    table->setSortingEnabled(false);

    table->setRowCount(0);
    QString endPath = QCoreApplication::applicationDirPath() + "/records/records2players.txt";
    QFile file(endPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    int i = 0;
    table->setColumnCount(8);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Map"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Difficulty"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Lives"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("1 Pl Name"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("2 Pl Name"));
    table->setHorizontalHeaderItem(5, new QTableWidgetItem("1 Pl Score"));
    table->setHorizontalHeaderItem(6, new QTableWidgetItem("2 Pl Score"));
    table->setHorizontalHeaderItem(7, new QTableWidgetItem("Time"));
    while (!in.atEnd()) {
        table->setRowCount(table->rowCount()+1);
        QString data = in.readLine();
        QStringList splited = data.split('|');
        if (splited.size() < 8) {
            break;
        }
        table->setItem(i, 0, new QTableWidgetItem(splited.at(0)));
        switch (splited.at(1).toInt()) {
        case 1:
            table->setItem(i, 1, new QTableWidgetItem("Easy"));
            break;
        case 2:
            table->setItem(i, 1, new QTableWidgetItem("Medium"));
            break;
        case 3:
            table->setItem(i, 1, new QTableWidgetItem("Hard"));
            break;
        default:
            break;
        }
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setData(Qt::DisplayRole, splited.at(2).toInt());
        table->setItem(i, 2, item);
        table->setItem(i, 3, new QTableWidgetItem(splited.at(3)));
        table->setItem(i, 4, new QTableWidgetItem(splited.at(4)));
        item = new QTableWidgetItem();
        item->setData(Qt::DisplayRole, splited.at(5).toInt());
        table->setItem(i, 5, item);
        item = new QTableWidgetItem();
        item->setData(Qt::DisplayRole, splited.at(6).toInt());
        table->setItem(i, 6, item);
        item = new QTableWidgetItem();
        item->setData(Qt::DisplayRole, splited.at(7).toFloat());
        table->setItem(i, 7, item);
        i++;
    }
    file.close();
    table->setSortingEnabled(true);
}

void Records::on_pushButton_clicked()
{
    fill1player();
}


void Records::on_pushButton_2_clicked()
{
    fill2players();
}


void Records::on_pushButton_3_clicked()
{
    Widget* widget = new Widget();
    widget->show();
    this->close();
}

