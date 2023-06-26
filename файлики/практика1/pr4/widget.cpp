#include "widget.h"
#include "ui_widget.h"

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
    const int width = 300;
    const int height = 300;
    int axisX = 350;
    int axisY = 350;
    const int scale = 100;
    const int pointsCount = 80;
    const double step = 2.0/pointsCount;

    QPoint points1[pointsCount];
    int i = 0;
    for (double t = -1; t < 1; t+=step, i++) {
        double x = f(t);
        double y = g(t);
        points1[i] = QPoint(x*scale+axisX, axisY-y*scale);
    }

    drawAxis(canv, axisX, axisY, fmax(fmax(abs(axisX-points1[pointsCount - 1].x()), abs(axisX-points1[0].x())), width),
            fmax(fmax(abs(axisY-points1[pointsCount - 1].y()), abs(axisY-points1[0].y())), height),
            "Параметрически заданная функция", QStringList({"f(x)"}), QList<Qt::GlobalColor>({Qt::red}));
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    canv.setPen(pen);
    canv.drawPolyline(points1, pointsCount);

    canv.end();

}

void Widget::drawAxis(QPainter &canv, int centerX, int centerY, int width, int height, QString name, QStringList legends, QList<Qt::GlobalColor> colors) {
    QPen pen;
    pen.setColor(Qt::black);
    canv.setPen(pen);
    canv.drawLine(centerX-width, centerY, centerX+width, centerY);
    canv.drawLine(centerX, centerY-height, centerX, centerY+height);
    QFont font;
    font.setFamily("Segoe UI");
    font.setPixelSize(20);
    canv.setFont(font);
    canv.drawText(centerX-20, centerY+20, "0");
    canv.drawText(centerX-20, centerY-height+20, "Y");
    canv.drawText(centerX-width+20, centerY+20, "X");
    font.setPixelSize(14);

    canv.drawText(centerX-300, centerY-300, name);
    for (int count = 1; count <= legends.size(); count++) {
        pen.setColor(colors.at(count-1));
        canv.setPen(pen);
        canv.drawText(centerX-300, centerY-300+(18*count), legends.at(count-1));
    }
}

double Widget::f(double t) {
    return exp(-t)*cos(t);
}

double Widget::g(double t) {
    return sin(t);
}
