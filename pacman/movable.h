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
    int memAnim;
    Direction direction;

public:
    void move(int h, int w) {
        this->x += direction.horizontal;
        this->y += direction.vertical;

        if (this->x <= 0) {
            this->x = w-1;
        } else if (this->x >= w-1) {
            this->x = 0;
        }

        if (this->y <= 0) {
            this->y = h-1;
        } else if (this->y >= h-1) {
            this->y = 0;
        }
    };
    int getX() {return x;};
    int getY() {return y;};
    void setDir(int h, int v) {
        this->direction.horizontal = h;
        this->direction.vertical = v;
    };
    void setDir(Direction dir) {
        this->direction = dir;
    };
    int getH() {return this->direction.horizontal;};
    int getV() {return this->direction.vertical;};
    Direction getDir() {return this->direction;};
    int getAnimDir() {
        if (direction.horizontal == -1) {
            memAnim = 2;
            return 2;
        }
        else if (direction.horizontal == 1) {
            memAnim = 0;
            return 0;
        }
        else if (direction.vertical == -1) {
            memAnim = 3;
            return 3;
        }
        else if (direction.vertical == 1) {
            memAnim = 1;
            return 1;
        }
        else { return memAnim; };
    }
    Movable() {direction.horizontal = 0; direction.vertical = 0; memAnim = 0;};
    Movable(int x, int y)  {
        this->x = x;
        this->y = y;
        direction.horizontal = 0;
        direction.vertical = 0;
        memAnim = 0;
    };
};

class Player: public Movable {
private:
    Direction memoryDirection;
public:
    int movePhase;
    int playerSpeed;

    void setMDir(int h, int v) {
        this->memoryDirection.horizontal = h;
        this->memoryDirection.vertical = v;
    };
    void setMDir(Direction dir) {
        this->memoryDirection = dir;
    };
    int getMH() {return this->memoryDirection.horizontal;};
    int getMV() {return this->memoryDirection.vertical;};
    Direction getMDir() {return this->memoryDirection;};

    Player() {
        direction.horizontal = 0;
        direction.vertical = 0;
        memoryDirection.horizontal = 0;
        memoryDirection.vertical = 0;
        x = 0;
        y = 0;
        movePhase = 0;
        playerSpeed = 1;
    }

    Player(int x, int y): Player() {
        this->x = x;
        this->y = y;
    }

    Player(int x, int y, int h, int v): Player(x, y) {
        this->setDir(h, v);
    }

    Player(int x, int y, Direction dir): Player(x, y) {
        this->setDir(dir);
    }

};

class Enemy: public Movable {

};



#endif // MOVABLE_H
