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
    int axisX = 450;
    int axisY = 450;
    double scale = 200.0;
    const int pointsCount = 100;

    const double left = 0.1;
    const double right = 0.9;

    const double step = (right-left)/(pointsCount-1);
    const double offset = 0.001;

    QPoint points1[pointsCount];
    QPointF rawPoints[pointsCount];
    int i = 0;
    double maxR = 0;

    for (double a = left; a <= right+offset; a+=step, i++) {
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
    drawAxis(canv, axisX, axisY, size, maxR);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);

    canv.setPen(pen);
    canv.drawPolyline(points1, pointsCount);

    canv.end();

}

void Widget::drawAxis(QPainter &canv, int centerX, int centerY, int size, double maxR) {
    double coef = sqrt(2)/2;
    QPen pen;
    pen.setColor(Qt::black);
    canv.setPen(pen);
    canv.drawLine(centerX-size, centerY, centerX+size, centerY);
    canv.drawLine(centerX, centerY-size, centerX, centerY+size);
    canv.drawLine(centerX-size*coef, centerY+size*coef, centerX+size*coef, centerY-size*coef);
    canv.drawLine(centerX-size*coef, centerY-size*coef, centerX+size*coef, centerY+size*coef);

    canv.drawEllipse(centerX-size, centerY-size, size*2, size*2);
    canv.drawEllipse(centerX-size*0.75, centerY-size*0.75, size*1.5, size*1.5);
    canv.drawEllipse(centerX-size/2.0, centerY-size/2.0, size, size);
    canv.drawEllipse(centerX-size/4.0, centerY-size/4.0, size/2.0, size/2.0);

    QFont font;
    font.setFamily("Helvetica");
    font.setPixelSize(10);
    canv.setFont(font);

    canv.drawText(centerX+5, centerY-size-2, QString::number(maxR));
    canv.drawText(centerX+5, centerY-size*0.75-2, QString::number(maxR*0.75));
    canv.drawText(centerX+5, centerY-size*0.5-2, QString::number(maxR*0.5));
    canv.drawText(centerX+5, centerY-size*0.25-2, QString::number(maxR*0.25));
    canv.drawText(centerX+5, centerY-2, "0");

    font.setPixelSize(14);
    canv.drawText(centerX+size+20, centerY+3, "0°");
    canv.drawText(centerX-8, centerY-size-20, "90°");
    canv.drawText(centerX-size-20, centerY+3, "180°");
    canv.drawText(centerX-10, centerY+size+20, "270°");

}

double Widget::f(double x) {
    return pow(x, exp(x));
}
