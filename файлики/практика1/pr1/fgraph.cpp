#include "fgraph.h"
#include "ui_fgraph.h"

FGraph::FGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FGraph)
{
    ui->setupUi(this);
}

FGraph::~FGraph()
{
    delete ui;
}

void FGraph::paintEvent(QPaintEvent *event) {
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
    int i = 0;

    for (double x = -pi; x < pi; x+=step, i++) {
        double y1 = Widget::f(x);

        points1[i] = QPoint(x*scale+axisX, axisY-y1*scale);
    }

    Widget::drawAxis(canv, axisX, axisY, fmax(fmax(abs(axisX-points1[pointsCount - 1].x()), abs(axisX-points1[0].x())), width),
            fmax(fmax(abs(axisY-points1[pointsCount - 1].y()), abs(axisY-points1[0].y())), height),
            "График F", QStringList({"f(x)"}), QList<Qt::GlobalColor>({Qt::red}));
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);

    canv.setPen(pen);
    canv.drawPolyline(points1, pointsCount);

    canv.end();

}
