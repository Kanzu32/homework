#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QFileDialog>
#include <QDebug>
#include <QKeyEvent>
#include <QSettings>

#include <level.h>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    QPixmap *spriteMap;
    const int spriteSize = 16;
    int frame = 0;
    int animationSpeed = 150;
    QTimer *animationTimer;
    Level level;
    int lives;
    int p1leftkey;
    int p1downkey;
    int p1rightkey;
    int p1upkey;
    int p2leftkey;
    int p2downkey;
    int p2rightkey;
    int p2upkey;
    int playerSpeed = 2;
    int** map;
    ~Game();

private slots:
    void nextFrame();

private:
    void keyPressEvent(QKeyEvent *event) override;
    Ui::Game *ui;
};

#endif // GAME_H
