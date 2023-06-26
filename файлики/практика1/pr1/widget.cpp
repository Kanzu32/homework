#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    OneAxis* oneaxis = new OneAxis();
    oneaxis->show();
    FGraph* fgraph = new FGraph();
    GGraph* ggraph = new GGraph();
    fgraph->show();
    ggraph->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter canv(this);
    const int width = 300;
    const int height = 300;
    const double pi = 3.141592653;
    int axisX1 = 350;
    int axisY1 = 350;
    int axisX2 = 1000;
    int axisY2 = 350;
    const int scale = 80;
    const int pointsCount = 300;
    const double step = pi*2/ (pointsCount-1);

    QPoint points1[pointsCount];
    QPoint points2[pointsCount];
    int i = 0;

    for (double x = -pi; x < pi; x+=step, i++) {
        double y1 = f(x);
        double y2 = g(x);

        points1[i] = QPoint(x*scale+axisX1, axisY1-y1*scale);
        points2[i] = QPoint(x*scale+axisX2, axisY2-y2*scale);
    }

    drawAxis(canv, axisX1, axisY1, fmax(fmax(abs(axisX1-points1[pointsCount - 1].x()), abs(axisX1-points1[0].x())), width),
            fmax(fmax(abs(axisY1-points1[pointsCount - 1].y()), abs(axisY1-points1[0].y())), height),
            "График 1", QStringList({"f(x)"}), QList<Qt::GlobalColor>({Qt::red}));
    drawAxis(canv, axisX2, axisY2, fmax(fmax(abs(axisX2-points2[pointsCount - 1].x()), abs(axisX2-points2[0].x())), width),
            fmax(fmax(abs(axisY2-points2[pointsCount - 1].y()), abs(axisY2-points2[0].y())), height),
            "График 2", QStringList({"g(x)"}), QList<Qt::GlobalColor>({Qt::blue}));
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
    return -x*x;
}

double Widget::g(double x) {
    return abs(sin(x)*cos(x));
}
