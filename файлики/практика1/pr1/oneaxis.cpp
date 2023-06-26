#include "oneaxis.h"
#include "ui_oneaxis.h"

OneAxis::OneAxis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OneAxis)
{
    ui->setupUi(this);
}

OneAxis::~OneAxis()
{
    delete ui;
}

void OneAxis::paintEvent(QPaintEvent *event) {
    QPainter canv(this);
    const int width = 300;
    const int height = 300;
    const double pi = 3.141592653;
    int axisX = 350;
    int axisY = 350;
    const int scale = 80;
    const int pointsCount = 300;
    const double step = pi*2/ (pointsCount-1);

    QPoint points1[pointsCount];
    QPoint points2[pointsCount];
    int i = 0;

    for (double x = -pi; x < pi; x+=step, i++) {
        double y1 = Widget::f(x);
        double y2 = Widget::g(x);

        points1[i] = QPoint(x*scale+axisX, axisY-y1*scale);
        points2[i] = QPoint(x*scale+axisX, axisY-y2*scale);
    }

    Widget::drawAxis(canv, axisX, axisY, fmax(fmax(abs(axisX-points1[pointsCount - 1].x()), abs(axisX-points1[0].x())), width),
            fmax(fmax(abs(axisY-points1[pointsCount - 1].y()), abs(axisY-points1[0].y())), height),
            "Одна ось", QStringList({"f(x)", "g(x)"}), QList<Qt::GlobalColor>({Qt::red, Qt::blue}));
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
