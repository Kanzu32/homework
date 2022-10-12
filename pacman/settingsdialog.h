#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <widget.h>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    bool mode;
    QString pl1name;
    QString pl2name;
    void getSettings(bool& mode, QString& p1, QString& p2);
    ~SettingsDialog();
private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
