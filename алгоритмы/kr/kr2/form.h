#ifndef FORM_H
#define FORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class form; }
QT_END_NAMESPACE

class form : public QMainWindow
{
    Q_OBJECT

public:
    form(QWidget *parent = nullptr);
    ~form();

private:
    Ui::form *ui;

private slots:
    void on_pushButton_clicked();

};



#endif // FORM_H
