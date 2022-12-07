#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    int id = QFontDatabase::addApplicationFont(":/fonts/font.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font = QFont(family);
    QWidget::showFullScreen();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    Game* game = new Game();
    game->show();
    this->close();
}


void Widget::on_pushButton_3_clicked()
{
    qApp->exit();
}


void Widget::on_pushButton_2_clicked()
{
    Settings* settings = new Settings();
    settings->show();
    this->close();
}


void Widget::on_pushButton_4_clicked()
{
    Records* records = new Records();
    records->show();
    this->close();
}
