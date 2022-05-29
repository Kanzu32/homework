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

void Widget::paintEvent(QPaintEvent *event) {
    QPainter canv(this);
    QBrush brush;
    QPen pen;
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    pen.setColor(Qt::black);
    pen.setWidth(3);
    canv.setBrush(brush);
    canv.setPen(pen);
    canv.drawEllipse(125, 90, 50, 20);
    canv.drawRoundedRect(100, 100, 100, 400, 20, 20);


    for (int i = 0; i < 4; i++) {
        drawCircleFragment(canv, 120, 180+(80*i));
    }
    canv.setBrush(QBrush(Qt::red));
    canv.drawRect(120, 120, 30, 40);
    canv.drawRect(150, 120, 30, 40);

    canv.setPen(QPen(Qt::white));
    QFont font;
    font.setFamily("Segoe UI");
    font.setPixelSize(30);
    font.setBold(true);
    canv.setFont(font);
    canv.drawText(127, 150, "0");
    canv.drawText(157, 150, "1");
    canv.setBrush(QBrush(Qt::gray));
    canv.setPen(pen);

    QPainterPath path;
    path.moveTo(150, 90);
    QPointF p1(150, 90);
    QPointF p2(300, 0);
    QPointF p3(300, 350);
    path.cubicTo(p1, p2, p3);
    canv.setBrush(Qt::transparent);
    canv.drawPath(path);
    canv.setBrush(QBrush(Qt::gray));
    canv.drawChord(280, 350, 40, 50, -30*16, 240*16);

    canv.drawLine(290, 390, 290, 400);
    canv.drawLine(310, 390, 310, 400);

    canv.end();
}


void Widget::drawCircleFragment(QPainter &canv, int x, int y) {
    canv.setBrush(QBrush(Qt::gray));
    canv.drawEllipse(x, y, 60, 60);
    canv.setBrush(QBrush(Qt::yellow));
    canv.drawEllipse(x+35, y+15, 10, 10);
    canv.drawEllipse(x+15, y+35, 10, 10);
}
