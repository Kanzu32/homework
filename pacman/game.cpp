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
    canv.setViewport(0, 0, canv.viewport().width()*3, canv.viewport().height()*3);
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
                canv.drawPixmap(spriteSize*i, spriteSize*j, *spriteMap, 0, 4*spriteSize, spriteSize, spriteSize);
            }
            canv.drawPixmap(spriteSize*level.p1.getX()+level.p1.movePhase*level.p1.direction.horizontal, spriteSize*level.p1.getY()+level.p1.movePhase*level.p1.direction.vertical, *spriteMap, frame*spriteSize, 0, spriteSize, spriteSize);
            canv.drawPixmap(spriteSize*level.p2.getX()+level.p2.movePhase*level.p2.direction.horizontal, spriteSize*level.p2.getY()+level.p2.movePhase*level.p2.direction.vertical, *spriteMap, (3+frame)*spriteSize, 0, spriteSize, spriteSize);
        }
    }

    canv.end();

}

void Game::nextFrame() {
    frame++;
    if (level.p1.direction.horizontal != 0 || level.p1.direction.vertical != 0) {
        level.p1.movePhase += level.p1.playerSpeed;
        if (level.p1.movePhase >= spriteSize/2) {
            level.p1.movePhase = -level.p1.movePhase;
            level.p1.move();
        }
        if (map[level.p1.getX()+level.p1.direction.horizontal][level.p1.getY()+level.p1.direction.vertical] == 1 && level.p1.movePhase == 0) {
            level.p1.direction.horizontal = 0;
            level.p1.direction.vertical = 0;
        }
        if (map[level.p1.getX()+level.p1.memoryDirection.horizontal][level.p1.getY()+level.p1.memoryDirection.vertical] != 1 && level.p1.movePhase == 0 && (level.p1.memoryDirection.horizontal != 0 || level.p1.memoryDirection.vertical != 0)) {
            level.p1.direction.horizontal = level.p1.memoryDirection.horizontal;
            level.p1.direction.vertical = level.p1.memoryDirection.vertical;
        }
    }
    if (level.p2enabled && (level.p2.direction.horizontal != 0 || level.p2.direction.vertical != 0)) {
        level.p2.movePhase += level.p2.playerSpeed;
        if (level.p2.movePhase >= spriteSize/2) {
            level.p2.movePhase = -level.p2.movePhase;
            level.p2.move();
        }
        if (map[level.p2.getX()+level.p2.direction.horizontal][level.p2.getY()+level.p2.direction.vertical] == 1 && level.p2.movePhase == 0) {
            level.p2.direction.horizontal = 0;
            level.p2.direction.vertical = 0;
        }
        if (map[level.p2.getX()+level.p2.memoryDirection.horizontal][level.p2.getY()+level.p2.memoryDirection.vertical] != 1 && level.p2.movePhase == 0 && (level.p2.memoryDirection.horizontal != 0 || level.p2.memoryDirection.vertical != 0)) {
            level.p2.direction.horizontal = level.p2.memoryDirection.horizontal;
            level.p2.direction.vertical = level.p2.memoryDirection.vertical;
        }
    }
    frame = frame%3;
    repaint();
}

void Game::keyPressEvent(QKeyEvent *event) {
    int key = event->key();
    if (key == p1leftkey && (level.p1.direction.horizontal == 0 ||level.p1.direction.horizontal == 1)) {
        if (map[level.p1.getX()-1][level.p1.getY()] == 1 || level.p1.movePhase != 0) {
            level.p1.memoryDirection = Direction(-1, 0);
        } else {
            level.p1.direction.horizontal = -1;
            level.p1.direction.vertical = 0;
            level.p1.memoryDirection.horizontal = 0;
            level.p1.memoryDirection.vertical = 0;
            level.p1.movePhase = -level.p1.movePhase;
        }
    }
    else if (key == p1downkey && (level.p1.direction.vertical == 0 ||level.p1.direction.vertical == -1)) {
        if (map[level.p1.getX()][level.p1.getY()+1] == 1 || level.p1.movePhase != 0) {
            level.p1.memoryDirection = Direction(0, 1);
        } else {
            level.p1.direction.horizontal = 0;
            level.p1.direction.vertical = 1;
            level.p1.memoryDirection.horizontal = 0;
            level.p1.memoryDirection.vertical = 0;
            level.p1.movePhase = -level.p1.movePhase;
        }
    }
    else if (key == p1rightkey && (level.p1.direction.horizontal == 0 ||level.p1.direction.horizontal == -1)) {
        if (map[level.p1.getX()+1][level.p1.getY()] == 1 || level.p1.movePhase != 0) {
            level.p1.memoryDirection = Direction(1, 0);
        } else {
            level.p1.direction.horizontal = 1;
            level.p1.direction.vertical = 0;
            level.p1.memoryDirection.horizontal = 0;
            level.p1.memoryDirection.vertical = 0;
            level.p1.movePhase = -level.p1.movePhase;
        }
    }
    else if (key == p1upkey && (level.p1.direction.vertical == 0 ||level.p1.direction.vertical == 1)) {
        if (map[level.p1.getX()][level.p1.getY()-1] == 1 || level.p1.movePhase != 0) {
            level.p1.memoryDirection = Direction(0, -1);
        } else {
            level.p1.direction.horizontal = 0;
            level.p1.direction.vertical = -1;
            level.p1.memoryDirection.horizontal = 0;
            level.p1.memoryDirection.vertical = 0;
            level.p1.movePhase = -level.p1.movePhase;
        }
    }
    else if (key == p2leftkey && level.p2enabled && (level.p2.direction.horizontal == 0 ||level.p2.direction.horizontal == 1)) {
        if (map[level.p2.getX()-1][level.p2.getY()] == 1 || level.p2.movePhase != 0) {
            level.p2.memoryDirection = Direction(-1, 0);
        } else {
            level.p2.direction.horizontal = -1;
            level.p2.direction.vertical = 0;
            level.p2.memoryDirection.horizontal = 0;
            level.p2.memoryDirection.vertical = 0;
            level.p2.movePhase = -level.p2.movePhase;
        }
    }
    else if (key == p2downkey && level.p2enabled && (level.p2.direction.vertical == 0 ||level.p2.direction.vertical == -1)) {
        if (map[level.p2.getX()][level.p2.getY()+1] == 1 || level.p2.movePhase != 0) {
            level.p2.memoryDirection = Direction(0, 1);
        } else {
            level.p2.direction.horizontal = 0;
            level.p2.direction.vertical = 1;
            level.p2.memoryDirection.horizontal = 0;
            level.p2.memoryDirection.vertical = 0;
            level.p2.movePhase = -level.p2.movePhase;
        }
    }
    else if (key == p2rightkey && level.p2enabled && (level.p2.direction.horizontal == 0 ||level.p2.direction.horizontal == -1)) {
        if (map[level.p2.getX()+1][level.p2.getY()] == 1 || level.p2.movePhase != 0) {
            level.p2.memoryDirection = Direction(1, 0);
        } else {
            level.p2.direction.horizontal = 1;
            level.p2.direction.vertical = 0;
            level.p2.memoryDirection.horizontal = 0;
            level.p2.memoryDirection.vertical = 0;
            level.p2.movePhase = -level.p2.movePhase;
        }
    }
    else if (key == p2upkey && level.p2enabled && (level.p2.direction.vertical == 0 ||level.p2.direction.vertical == 1)) {
        if (map[level.p2.getX()][level.p2.getY()-1] == 1 || level.p2.movePhase != 0) {
            level.p2.memoryDirection = Direction(0, -1);
        } else {
            level.p2.direction.horizontal = 0;
            level.p2.direction.vertical = -1;
            level.p2.memoryDirection.horizontal = 0;
            level.p2.memoryDirection.vertical = 0;
            level.p2.movePhase = -level.p2.movePhase;
        }
    }
}
