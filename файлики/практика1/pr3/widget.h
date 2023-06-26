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
    static void drawAxis(QPainter &canv, int centerX, int centerY, int width, int height, QString name, QStringList legends, QList<Qt::GlobalColor> colors);
    double f(double x);
    double g(double x);
    double u(double x);
    double v(double x);
    const double pi = 3.141592653;
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
