#ifndef GGRAPH_H
#define GGRAPH_H

#include <QWidget>
#include <QPainter>
#include <cmath>
#include <widget.h>

namespace Ui {
class GGraph;
}

class GGraph : public QWidget
{
    Q_OBJECT

public:
    explicit GGraph(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~GGraph();

private:
    Ui::GGraph *ui;
};

#endif // GGRAPH_H
