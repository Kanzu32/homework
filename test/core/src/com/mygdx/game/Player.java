package com.mygdx.game;

public class Player {
    int x, y;
    int moveRange;
    {
        moveRange = 1;
    }

    public Player(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public Player() {
        this.x = 1;
        this.y = 1;
    }
}
