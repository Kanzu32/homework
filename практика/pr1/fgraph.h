#ifndef FGRAPH_H
#define FGRAPH_H

#include <QWidget>
#include <QPainter>
#include <cmath>
#include <widget.h>

namespace Ui {
class FGraph;
}

class FGraph : public QWidget
{
    Q_OBJECT

public:
    explicit FGraph(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~FGraph();

private:
    Ui::FGraph *ui;
};

#endif // FGRAPH_H
