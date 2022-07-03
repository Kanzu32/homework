#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter canv(this);
    const int size = 400;
    const double pi = 3.141592653;
    int axisX = 450;
    int axisY = 450;
    int scale = 200;
    const int pointsCount = 100;
    const double step = 0.8/(pointsCount-1);
    const double offset = 0.001;

    QPoint points1[pointsCount];
    QPointF rawPoints[pointsCount];
    int i = 0;
    double maxR = 0;

    for (double a = 0.1; a <= 0.9+offset; a+=step, i++) {
        double r = f(a);
        if (r > maxR) {
            maxR = r;
        }

        double x = cos(a)*r;
        double y = sin(a)*r;
        qInfo() << a << r << x << y << x*scale+axisX << axisY-y*scale << i;

        rawPoints[i] = QPointF(x, y);  //QPoint(x*scale+axisX, axisY-y*scale);
    }
    qInfo() << maxR;
    scale = size/maxR;
    qInfo() << scale;
    for (int n = 0; n < pointsCount; n++) {
        points1[n] = QPoint(rawPoints[n].x()*scale+axisX, axisY-rawPoints[n].y()*scale);
        qInfo() << rawPoints[n].x()*scale+axisX << axisY-rawPoints[n].y()*scale;
    }
    drawAxis(canv, axisX, axisY, size);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);

    canv.setPen(pen);
    canv.drawPolyline(points1, pointsCount);

    canv.end();

}

void Widget::drawAxis(QPainter &canv, int centerX, int centerY, int size) {
    QPen pen;
    pen.setColor(Qt::black);
    canv.setPen(pen);
    canv.drawLine(centerX-size, centerY, centerX+size, centerY);
    canv.drawLine(centerX, centerY-size, centerX, centerY+size);

}

double Widget::f(double x) {
    return pow(x, exp(x));
}
