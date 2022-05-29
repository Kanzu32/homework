#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void drawAxis(QPainter &canv, int centerX, int centerY);
    double f(double x);
    double g(double y);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
