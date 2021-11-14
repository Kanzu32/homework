package com.mygdx.game;

public class Map {
    int width, height;
    int tileSize = 100;

    public Map(int width, int height) {
        this.width = width;
        this.height = height;
    }
    public Map() {
        this.width = 9;
        this.height = 9;
    }
}
