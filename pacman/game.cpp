#include "game.h"
#include "ui_game.h"



Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    spriteMap = new QPixmap(":/images/sprites.png");
    QString filename = QFileDialog::getOpenFileName();
    level = Level(filename);
    animationTimer = new QTimer();
    connect(animationTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    animationTimer->start(animationSpeed);
    QWidget::showFullScreen();


    QString Path = QCoreApplication::applicationDirPath();
    QString endPath = Path + "/config/config.ini";
    QFileInfo fileinfo(endPath);
    if (fileinfo.isFile()) {
        QSettings* config = new QSettings(endPath, QSettings::IniFormat);
        lives = config->value("lives", "").toInt();
        p1leftkey = config->value("p1left", "").toInt();
        p1downkey = config->value("p1down", "").toInt();
        p1rightkey = config->value("p1right", "").toInt();
        p1upkey = config->value("p1up", "").toInt();
        p2leftkey = config->value("p2left", "").toInt();
        p2downkey = config->value("p2down", "").toInt();
        p2rightkey = config->value("p2right", "").toInt();
        p2upkey = config->value("p2up", "").toInt();
    }

}

Game::~Game()
{
    delete ui;
}

void Game::paintEvent(QPaintEvent *event) {
    QPainter canv(this);
    canv.setViewport(0, 0, canv.viewport().width()*viewSize, canv.viewport().height()*viewSize);
    canv.fillRect(QRect(0, 0, canv.device()->width(), canv.device()->height()), Qt::GlobalColor::black);
//    canv.drawPixmap(100, 100, *spriteMap, frame*spriteSize, 4*spriteSize, spriteSize, spriteSize);
//    canv.drawPixmap(150, 100, *spriteMap, (2+frame)*spriteSize, 4*spriteSize, spriteSize, spriteSize);
//    canv.drawPixmap(200, 100, *spriteMap, (4+frame)*spriteSize, 4*spriteSize, spriteSize, spriteSize);
//    canv.drawPixmap(250, 100, *spriteMap, (6+frame)*spriteSize, 4*spriteSize, spriteSize, spriteSize);



    map = level.getMap();
    for (int i = 0; i < level.getWidth(); i++) {
        for (int j = 0; j < level.getHeight(); j++) {
            if (map[i][j] == 1) {
                canv.drawPixmap(spriteSize*i, spriteSize*j, *spriteMap, 6*spriteSize, 1*spriteSize, spriteSize, spriteSize);
            } else if (map[i][j] == 2) {
                canv.drawPixmap(spriteSize*i, spriteSize*j, *spriteMap, 6*spriteSize, 0, spriteSize, spriteSize);
            } else if (map[i][j] == 3) {
                canv.drawPixmap(spriteSize*i, spriteSize*j, *spriteMap, 7*spriteSize, 0, spriteSize, spriteSize);
            }else if (map[i][j] == 5) {
                canv.drawPixmap(spriteSize*i, spriteSize*j, *spriteMap, (frame/15)*spriteSize, 4*spriteSize, spriteSize, spriteSize);
            }
            canv.drawPixmap(spriteSize*level.p1.getX()+level.p1.movePhase*level.p1.getH(), spriteSize*level.p1.getY()+level.p1.movePhase*level.p1.getV(), *spriteMap, (frame/10)*spriteSize, 0, spriteSize, spriteSize);
            canv.drawPixmap(spriteSize*level.p2.getX()+level.p2.movePhase*level.p2.getH(), spriteSize*level.p2.getY()+level.p2.movePhase*level.p2.getV(), *spriteMap, (3+frame/10)*spriteSize, 0, spriteSize, spriteSize);
        }
    }
    canv.setPen(Qt::white);
    canv.drawText(10, 10, QString("Player 1: ") + QString::number(level.p1Score));
    canv.drawText(canv.device()->width()/2/viewSize, 10, QString::number(level.score));
    canv.drawText(canv.device()->width()/viewSize-60, 10, QString("Player 2: ") + QString::number(level.p2Score));

    canv.end();

}

void Game::nextFrame() {
    frame++;
    if (level.p1.getH() != 0 || level.p1.getV() != 0) {
        level.p1.movePhase += level.p1.playerSpeed;
        if (level.p1.movePhase >= spriteSize/2) {
            level.p1.movePhase = -level.p1.movePhase;
            level.p1.move();
        }
        if (map[level.p1.getX()+level.p1.getH()][level.p1.getY()+level.p1.getV()] == 1 && level.p1.movePhase == 0) {
            level.p1.setDir(0, 0);
        }
        if (map[level.p1.getX()+level.p1.getMH()][level.p1.getY()+level.p1.getMV()] != 1 && level.p1.movePhase == 0 && (level.p1.getMH() != 0 || level.p1.getMV() != 0)) {
            level.p1.setDir(level.p1.getMH(), level.p1.getMV());
        }
        if (map[level.p1.getX()][level.p1.getY()] == 2) {
            level.getMap()[level.p1.getX()][level.p1.getY()] = 0;
            level.p1Score += 10;
            level.score += 10;
        }
        if (map[level.p1.getX()][level.p1.getY()] == 3) {
            level.getMap()[level.p1.getX()][level.p1.getY()] = 0;
            level.p1Score += 30;
            level.score += 30;
            level.p1.playerSpeed = 2;
            if (timer1->isActive()) {
                timer1->stop();
            }
            connect(timer1, SIGNAL(timeout()), this, SLOT(endBonusPl1()));
            timer1->setSingleShot(true);
            timer1->setInterval(bonusTime);
            timer1->start();
        }
    }
    if (level.p2enabled && (level.p2.getH() != 0 || level.p2.getV() != 0)) {
        level.p2.movePhase += level.p2.playerSpeed;
        if (level.p2.movePhase >= spriteSize/2) {
            level.p2.movePhase = -level.p2.movePhase;
            level.p2.move();
        }
        if (map[level.p2.getX()+level.p2.getH()][level.p2.getY()+level.p2.getV()] == 1 && level.p2.movePhase == 0) {
            level.p2.setDir(0, 0);
        }
        if (map[level.p2.getX()+level.p2.getMH()][level.p2.getY()+level.p2.getMV()] != 1 && level.p2.movePhase == 0 && (level.p2.getMH() != 0 || level.p2.getMV() != 0)) {
            level.p2.setDir(level.p2.getMH(), level.p2.getMV());
        }
        if (map[level.p2.getX()][level.p2.getY()] == 2) {
            level.getMap()[level.p2.getX()][level.p2.getY()] = 0;
            level.p2Score += 10;
            level.score += 10;
        }
        if (map[level.p2.getX()][level.p2.getY()] == 3) {
            level.getMap()[level.p2.getX()][level.p2.getY()] = 0;
            level.p2Score += 30;
            level.score += 30;
            level.p2.playerSpeed = 2;
            if (timer2->isActive()) {
                timer2->stop();
            }
            connect(timer2, SIGNAL(timeout()), this, SLOT(endBonusPl2()));
            timer2->setSingleShot(true);
            timer2->setInterval(bonusTime);
            timer2->start();
        }
    }
    frame = frame%30;
    repaint();
}

void Game::endBonusPl1() {
    qDebug() << "1";
    level.p1.playerSpeed = 1;
}

void Game::endBonusPl2() {
    qDebug() << "2";
    level.p2.playerSpeed = 1;
}

void Game::keyPressEvent(QKeyEvent *event) {
    int key = event->key();
    if (key == p1leftkey && (level.p1.getH() == 0 ||level.p1.getH() == 1)) {
        if (map[level.p1.getX()-1][level.p1.getY()] == 1 || (level.p1.movePhase != 0 && level.p1.getH() != 1)) {
            level.p1.setMDir(-1, 0);
        } else {
            level.p1.setDir(-1, 0);
            level.p1.setMDir(0, 0);
            level.p1.movePhase = -level.p1.movePhase;
        }
    }
    else if (key == p1downkey && (level.p1.getV() == 0 ||level.p1.getV() == -1)) {
        if (map[level.p1.getX()][level.p1.getY()+1] == 1 || (level.p1.movePhase != 0 && level.p1.getV() != -1)) {
            level.p1.setMDir(0, 1);
        } else {
            level.p1.setDir(0, 1);
            level.p1.setMDir(0, 0);
            level.p1.movePhase = -level.p1.movePhase;
        }
    }
    else if (key == p1rightkey && (level.p1.getH() == 0 ||level.p1.getH() == -1)) {
        if (map[level.p1.getX()+1][level.p1.getY()] == 1 || (level.p1.movePhase != 0 && level.p1.getH() != -1)) {
            level.p1.setMDir(1, 0);
        } else {
            level.p1.setDir(1, 0);
            level.p1.setMDir(0, 0);
            level.p1.movePhase = -level.p1.movePhase;
        }
    }
    else if (key == p1upkey && (level.p1.getV() == 0 ||level.p1.getV() == 1)) {
        if (map[level.p1.getX()][level.p1.getY()-1] == 1 || (level.p1.movePhase != 0 && level.p1.getV() != 1)) {
            level.p1.setMDir(0, -1);
        } else {
            level.p1.setDir(0, -1);
            level.p1.setMDir(0, 0);
            level.p1.movePhase = -level.p1.movePhase;
        }
    }
    else if (key == p2leftkey && level.p2enabled && (level.p2.getH() == 0 ||level.p2.getH() == 1)) {
        if (map[level.p2.getX()-1][level.p2.getY()] == 1 || (level.p2.movePhase != 0 && level.p2.getH() != 1)) {
            level.p2.setMDir(-1, 0);
        } else {
            level.p2.setDir(-1, 0);
            level.p2.setMDir(0, 0);
            level.p2.movePhase = -level.p2.movePhase;
        }
    }
    else if (key == p2downkey && level.p2enabled && (level.p2.getV() == 0 ||level.p2.getV() == -1)) {
        if (map[level.p2.getX()][level.p2.getY()+1] == 1 || (level.p2.movePhase != 0 && level.p2.getV() != -1)) {
            level.p2.setMDir(0, 1);
        } else {
            level.p2.setDir(0, 1);
            level.p2.setMDir(0, 0);
            level.p2.movePhase = -level.p2.movePhase;
        }
    }
    else if (key == p2rightkey && level.p2enabled && (level.p2.getH() == 0 ||level.p2.getH() == -1)) {
        if (map[level.p2.getX()+1][level.p2.getY()] == 1 || (level.p2.movePhase != 0 && level.p2.getH() != -1)) {
            level.p2.setMDir(1, 0);
        } else {
            level.p2.setDir(1, 0);
            level.p2.setMDir(0, 0);
            level.p2.movePhase = -level.p2.movePhase;
        }
    }
    else if (key == p2upkey && level.p2enabled && (level.p2.getV() == 0 ||level.p2.getV() == 1)) {
        if (map[level.p2.getX()][level.p2.getY()-1] == 1 || (level.p2.movePhase != 0 && level.p2.getV() != 1)) {
            level.p2.setMDir(0, -1);
        } else {
            level.p2.setDir(0, -1);
            level.p2.setMDir(0, 0);
            level.p2.movePhase = -level.p2.movePhase;
        }
    }
}
