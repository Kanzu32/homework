#ifndef MOVABLE_H
#define MOVABLE_H

class Direction {
public:
    short horizontal;
    short vertical;
    Direction(int h, int v) {
        this->horizontal = h;
        this->vertical = v;
    }
    Direction() {
        this->horizontal = 0;
        this->vertical = 0;
    }
};

class Movable
{
protected:
    int x;
    int y;
    int realX;
    int realY;

public:
    Direction direction;
    void move() {
        this->x += direction.horizontal;
        this->y += direction.vertical;
    };
    int getX() {return x;};
    int getY() {return y;};
    Movable() {direction.horizontal = 0; direction.vertical = 0;};
    Movable(int x, int y) {
        Movable();
        this->x = x;
        this->y = y;
        direction.horizontal = 0;
        direction.vertical = 0;
    };
};

class Player: public Movable {
public:
    Direction memoryDirection;
    int movePhase;
    int playerSpeed;

    Player(int x, int y) {
        this->x = x;
        this->y = y;
        direction.horizontal = 0;
        direction.vertical = 0;
        memoryDirection.horizontal = 0;
        memoryDirection.vertical = 0;
        movePhase = 0;
        playerSpeed = 2;
    }
    Player() {
        direction.horizontal = 0;
        direction.vertical = 0;
        memoryDirection.horizontal = 0;
        memoryDirection.vertical = 0;
        x = 0;
        y = 0;
        movePhase = 0;
        playerSpeed = 2;
    }
};

class Enemy: public Movable {

};



#endif // MOVABLE_H
