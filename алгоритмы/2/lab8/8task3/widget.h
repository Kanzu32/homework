#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include <QMouseEvent>
#include<QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
private slots:
    void myTimerEvent();

public:
    Widget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void drawThief(QPainter &canv, int x, int y);
    void drawBackgroud(QPainter &canv);
    void drawUI(QPainter &canv);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
