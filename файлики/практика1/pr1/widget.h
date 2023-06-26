#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <cmath>
#include <oneaxis.h>
#include <ggraph.h>
#include <fgraph.h>

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
    static double f(double x);
    static double g(double x);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
