#ifndef LEVEL_H
#define LEVEL_H

#include <QString>
#include <QDebug>
#include <QFile>
#include <movable.h>

class Level
{
private:
    int h;
    int w;
    int** map;
public:
    Player p1;
    Player p2;
    bool p2enabled;
    int p1Score;
    int p2Score;
    int score;
    int getWidth() {return w;};
    int getHeight() {return h;};
    int** getMap() {return map;};

    Level(QString filename) {
        this->p2enabled = false;
        QFile file(filename);
        file.open(QIODevice::ReadOnly);
        QString data;
        data = file.readAll();
        QStringList splited = data.split('|');
        this->w = QString(splited.at(0)).toInt();
        this->h = QString(splited.at(1)).toInt();
        QString lvlMap = splited.at(2);
        lvlMap.remove('\r');
        lvlMap.remove('\n');
        map = new int*[w];
        for (int i = 0; i < this->w; i++) {
            this->map[i] = new int[h];
            for (int j = 0; j < this->h; j++) {

                this->map[i][j] = QString(lvlMap.at(i+j*w)).toInt();
                if (this->map[i][j] == 4) {
                    this->p1 = Player(i, j);
                    this->map[i][j] = 0;
                } else if (this->map[i][j] == 5) {
                    ;
                } else if (this->map[i][j] == 6) {
                    this->p2enabled = true;
                    this->p2 = Player(i, j);
                    this->map[i][j] = 0;
                }
            }
        }
        score = 0;
        p1Score = 0;
        p2Score = 0;
    }

    Level() {h = 0; w = 0;};
};

#endif // LEVEL_H
