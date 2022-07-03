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
    const int scale = 30;
    const int pointsCount = 11;

    QPoint points1[pointsCount];
    QPoint points2[pointsCount];
    QPoint points3[pointsCount];
    QPoint points4[pointsCount];
    int i = 0;

    for (double x = -3; x < -1.9; x+=0.1, i++) {
        double y1 = f(x);
        points1[i] = QPoint(x*scale+axisX, axisY-y1*scale);
    }
    i = 0;
    for (double x = -2; x < 1.1; x+=0.3, i++) {
        double y2 = g(x);
        points2[i] = QPoint(x*scale+axisX, axisY-y2*scale);
    }
    i = 0;
    for (double x = 1; x < 3.1; x+=0.2, i++) {
        double y3 = u(x);
        points3[i] = QPoint(x*scale+axisX, axisY-y3*scale);
    }
    i = 0;
    for (double x = 3; x < 4.1; x+=0.1, i++) {
        double y4 = v(x);
        points4[i] = QPoint(x*scale+axisX, axisY-y4*scale);
    }

    drawAxis(canv, axisX, axisY, fmax(fmax(abs(axisX-points1[pointsCount - 1].x()), abs(axisX-points1[0].x())), width),
            fmax(fmax(abs(axisY-points1[pointsCount - 1].y()), abs(axisY-points1[0].y())), height),
            "Кусочно заданная функция", QStringList({"f(x)", "g(x)", "u(x)", "v(x)"}), QList<Qt::GlobalColor>({Qt::red, Qt::blue, Qt::green, Qt::darkYellow}));
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(3);
    pen.setStyle(Qt::DotLine);
    canv.setPen(pen);
    canv.drawPolyline(points1, pointsCount);
    pen.setColor(Qt::blue);
    pen.setStyle(Qt::SolidLine);
    canv.setPen(pen);
    canv.drawPolyline(points2, pointsCount);
    pen.setColor(Qt::green);
    pen.setStyle(Qt::DashDotLine);
    canv.setPen(pen);
    canv.drawPolyline(points3, pointsCount);
    pen.setColor(Qt::darkYellow);
    pen.setStyle(Qt::DashLine);
    canv.setPen(pen);
    canv.drawPolyline(points4, pointsCount);

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

double Widget::f(double x) {
    return 0;
}

double Widget::g(double x) {
    return (x-1)*(x-1);
}

double Widget::u(double x) {
    return cos(pi/2)*x;
}

double Widget::v(double x) {
    return 1-exp(3-x);
}
