#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    this->setFixedSize(QSize(1024, 768));
    ui->setupUi(this);
    srand(time(NULL));

}

Widget::~Widget()
{

    delete ui;
}

struct Point {
    int x;
    int y;
    int hitboxX1;
    int hitboxX2;
    int hitboxY1;
    int hitboxY2;
    Point (int x1, int y1, int hx1, int hy1, int hx2, int hy2) {
        x = x1;
        y = y1;
        hitboxX1 = hx1;
        hitboxY1 = hy1;
        hitboxX2 = hx2;
        hitboxY2 = hy2;
    }
};

int score = 0;
int lifes = 10;
int bestScore = 0;
int thiefX = -1;
int thiefY = -1;
int position = 0;
bool thiefEnabled = false;
bool bestScoreEnabled = false;
bool isActiveFrame = true;
bool isEnd = false;
bool isStarted = false;
QTimer* timer;
QTimer* breakTimer;
QPainter canv;

Point points[5] = {Point(-70, 300, 0, 300, 60, 550), Point(944, 350, 970, 350, 1024, 610),Point(150, 260, 180, 260, 300, 500),Point(350, 150, 100, 600, 300, 768),Point(400, 320, 650, 480, 800, 768)};

void Widget::paintEvent(QPaintEvent *event) {
    canv.begin(this);
    drawBackgroud(canv);
    if (thiefEnabled && position == 3) {
        canv.save();
        canv.rotate(45);
        canv.scale(1.5, 1.5);
        drawThief(canv, thiefX, thiefY);
        canv.restore();
    } else if (thiefEnabled && position == 4) {
        canv.save();
        canv.scale(1.5, 1.5);
        drawThief(canv, thiefX, thiefY);
        canv.restore();
    } else if (thiefEnabled) {
        drawThief(canv, thiefX, thiefY);
    }

    canv.setPen(QPen(Qt::red, 10));
    canv.drawPoint(points[position].hitboxX1, points[position].hitboxY1);
    canv.drawPoint(points[position].hitboxX2, points[position].hitboxY2);

    drawUI(canv);
    if (isEnd) {
        if (score > bestScore) {
            bestScore = score;
        }
        canv.setBrush(QColor(0, 0, 0, 100));
        QFont font;
        font.setFamily("Segoe UI");
        font.setPixelSize(50);
        font.setBold(true);
        canv.setFont(font);
        canv.drawRect(0, 0, width(), height());
        canv.drawText(380, 380, "Score: " + QString::number(score));
        canv.drawText(380, 480, "Best Score: " + QString::number(bestScore));
        isStarted = false;
    }
    canv.end();
    if (isActiveFrame) {
        timer = new QTimer(this);
        timer->setSingleShot(true);
        timer->setInterval(1000 + rand()%1100);
        connect(timer, SIGNAL(timeout()), this, SLOT(myTimerEvent()));
        timer->start();
    }
}

void Widget::drawBackgroud(QPainter &canv) {
    QRectF rect(0, 0, width(), height());
    canv.drawImage(rect, QImage("C:\\Users\\Max\\Documents\\8task3\\background.png"));
}

void Widget::drawThief(QPainter &canv, int x, int y) {
    canv.setPen(QPen(Qt::transparent));
    canv.setBrush(QBrush(QColor(255, 194, 235)));
    canv.drawEllipse(x+50, y, 60, 60);
    canv.setBrush(QBrush(Qt::black));
    canv.drawChord(x+50, y, 60, 60, 30*16, 135*16);
    canv.setPen(QPen(Qt::black, 4));
    canv.drawPoint(x+90, y+25);
    canv.setPen(QPen(Qt::transparent));
    canv.drawEllipse(x+50, y+60, 60, 120);
    canv.setPen(QPen(Qt::black, 10));
    canv.drawLine(x+50, y+80, x+20, y+130);
    canv.drawLine(x+110, y+80, x+140, y+130);
    canv.drawLine(x+95, y+180, x+110, y+240);
    canv.drawLine(x+65, y+180, x+50, y+240);
    canv.setPen(QPen(QColor(150, 75, 0), 10));
    canv.drawLine(x+110, y+242, x+120, y+242);
    canv.drawLine(x+50, y+242, x+40, y+242);
    canv.setBrush(QBrush(QColor(255, 194, 235)));
    canv.setPen(QPen(Qt::transparent));
    canv.drawEllipse(x+10, y+120, 20, 20);
    canv.drawEllipse(x+130, y+120, 20, 20);

}

void Widget::drawUI(QPainter &canv) {
    QFont font;
    font.setFamily("Segoe UI");
    font.setPixelSize(20);
    font.setBold(true);
    canv.setPen(Qt::white);
    canv.drawText(5, 15, "Score: " + QString::number(score));
    canv.drawText(5, 30, "Lifes: " + QString::number(lifes));
    if (bestScoreEnabled) {
        canv.drawText(5, 45, "Best Score: " + QString::number(bestScore));
    }
}

void Widget::myTimerEvent() {
    isStarted = true;
    thiefEnabled = false;
    isActiveFrame = false;
    repaint();
    position = (position+(1+std::rand()%4))%5;
    thiefX = points[position].x;
    thiefY = points[position].y;
    thiefEnabled = true;
    isActiveFrame = true;
    breakTimer = new QTimer(this);
    breakTimer->setSingleShot(true);
    breakTimer->setInterval(200+rand()%700);
    connect(breakTimer, SIGNAL(timeout()), this, SLOT(repaint()));
    breakTimer->start();
}

void Widget::mousePressEvent(QMouseEvent *event) {
    if (isStarted && event->button() == Qt::LeftButton) {
        int x = event->position().x();
        int y = event->position().y();
        if (thiefEnabled &&
                x >= points[position].hitboxX1 &&
                x <= points[position].hitboxX2 &&
                y >= points[position].hitboxY1 &&
                y <= points[position].hitboxY2) {
            score++;
            thiefEnabled = false;
        } else {
            lifes--;
        }
        timer->stop();
        breakTimer->stop();
        if (lifes <= 0) {
            isEnd = true;
            isActiveFrame = false;
        }
        repaint();


    } else if (isEnd && event->button() == Qt::LeftButton) {
        isEnd = false;
        isStarted = false;
        thiefEnabled = false;
        bestScoreEnabled = true;
        isActiveFrame = true;
        score = 0;
        lifes = 10;
        repaint();
    }
}
