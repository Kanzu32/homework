#include "widget.h"
#include "./ui_widget.h"

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

double Widget::f(double x) {
    return 2*pow(x, 3)-abs(cos(x));
}

double Widget::g(double x) {
    return cosh(x)-abs(x);
}

void Widget::paintEvent(QPaintEvent *event) {
    const double pi = 3.141592653;
    const int centerX = 300;
    const int centerY = 300;
    const int pointsCount = 300;
    const int scaleX = 100;
    const int scaleY = 100;
    const double step = pi/ (pointsCount-1);
    QPainter canv(this);
    drawAxis(canv, centerX, centerY);

    QPoint points1[pointsCount];
    QPoint points2[pointsCount];
    int i = 0;
    for (double x = -pi/2; x <= pi/2; x+=step, i++) {
        double y1 = f(x);
        double y2 = g(x);
        points1[i] = QPoint(x*scaleX+centerX, centerY-y1*scaleY);
        points2[i] = QPoint(x*scaleX+centerX, centerY-y2*scaleY);
    }
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);

    canv.setPen(pen);
    canv.drawPolyline(points1, pointsCount);
    pen.setColor(Qt::blue);
    canv.setPen(pen);
    canv.drawPolyline(points2, pointsCount);

    canv.end();
}


void Widget::drawAxis(QPainter &canv, int centerX, int centerY) {
    canv.drawLine(0, centerY, width(), centerY);
    canv.drawLine(centerX, 0, centerX, height());
    QFont font;
    font.setFamily("Segoe UI");
    font.setPixelSize(20);
    canv.setFont(font);
    canv.drawText(centerX-20, centerY+20, "0");
    canv.drawText(centerX-20, 20, "Y");
    canv.drawText(width()-20, centerY+20, "X");
}


