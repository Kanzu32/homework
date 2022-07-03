#ifndef ONEAXIS_H
#define ONEAXIS_H

#include <QWidget>
#include <QPainter>
#include <cmath>
#include <widget.h>

namespace Ui {
class OneAxis;
}

class OneAxis : public QWidget
{
    Q_OBJECT

public:
    explicit OneAxis(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~OneAxis();

private:
    Ui::OneAxis *ui;
};

#endif // ONEAXIS_H
