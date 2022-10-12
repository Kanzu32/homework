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
    QString p1name;
    QString p2name;
    QString mapName;
    int coinsCount;
    bool p2enabled;
    int p1Score;
    int p2Score;
    int score;
    int getWidth() {return w;};
    int getHeight() {return h;};
    int** getMap() {return map;};

    Level(QString filename, bool mode, QString p1, QString p2) {
        this->coinsCount = 0;
        this->p2enabled = mode;
        this->p1name = p1;
        this->p2name = p2;
        this->mapName = filename.mid(filename.lastIndexOf('/')+1, filename.lastIndexOf('.')-filename.lastIndexOf('/')-1);
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
                } else if (this->map[i][j] == 6 && p2enabled) {
                    this->p2 = Player(i, j);
                    this->map[i][j] = 0;
                } else if (this->map[i][j] == 6 && !p2enabled){
                    this->map[i][j] = 0;
                } else if (this->map[i][j] == 2 || this->map[i][j] == 3) {
                    this->coinsCount++;
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
