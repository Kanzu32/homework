#ifndef RECORDS_H
#define RECORDS_H

#include <QWidget>
#include <QTableWidget>
#include <QFile>
#include <QTextStream>
#include <QStandardItemModel>

namespace Ui {
class Records;
}

class Records : public QWidget
{
    Q_OBJECT

public:
    explicit Records(QWidget *parent = nullptr);
    void fill1player();
    void fill2players();
    bool twoPlayersMode = false;
    QStandardItemModel* model;
    QTableWidget* table;
    ~Records();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Records *ui;
};

#endif // RECORDS_H
