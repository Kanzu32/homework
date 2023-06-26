#include "ggraph.h"
#include "ui_ggraph.h"

GGraph::GGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GGraph)
{
    ui->setupUi(this);
}

GGraph::~GGraph()
{
    delete ui;
}

void GGraph::paintEvent(QPaintEvent *event) {
    QPainter canv(this);
    const int width = 300;
    const int height = 300;
    const double pi = 3.141592653;
    int axisX = 350;
    int axisY = 350;
    const int scale = 80;
    const int pointsCount = 300;
    const double step = pi*2/ (pointsCount-1);

    QPoint points2[pointsCount];
    int i = 0;

    for (double x = -pi; x < pi; x+=step, i++) {
        double y2 = Widget::g(x);

        points2[i] = QPoint(x*scale+axisX, axisY-y2*scale);
    }

    Widget::drawAxis(canv, axisX, axisY, fmax(fmax(abs(axisX-points2[pointsCount - 1].x()), abs(axisX-points2[0].x())), width),
            fmax(fmax(abs(axisY-points2[pointsCount - 1].y()), abs(axisY-points2[0].y())), height),
            "График G", QStringList({"g(x)"}), QList<Qt::GlobalColor>({Qt::blue}));
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    canv.setPen(pen);
    canv.drawPolyline(points2, pointsCount);

    canv.end();

}
