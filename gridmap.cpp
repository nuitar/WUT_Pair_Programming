
#include "gridmap.h"
#include <QColor>
#include <QPalette>
#include <QPointF>

gridMap::gridMap(QWidget *parent)
    : QWidget(parent)
{
    this->minGap = 4;
    this->maxGap = 14;
    this->gap = 20;
    this->startX = this->width() / 2;
    this->startY = this->height() / 2;
    this->darkPen = QPen(QColor(200, 200, 200));
    this->darkPen.setWidth(1);
    this->setBackgroundColor();
    connect(this, &gridMap::updateNext, [=] {
        logic.NextState();
        this->update();
        });
    connect(this, &gridMap::random, [=] {
        logic.Random();
        this->update();
        });
    connect(this, &gridMap::reset, [=] {
        logic.Reset();
        this->update();
        });
    this->setFixedSize(1000, 520);
}

gridMap::~gridMap()
{

}

void gridMap::setBackgroundColor()
{
    QPalette palette;
    palette.setColor(QPalette::ColorRole::Window, QColor(140, 140, 140));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}

void gridMap::drawRowLines(QPainter *painter)
{
    float biggerY = this->startY;
    float smallerY = this->startY;

    painter->setPen(this->darkPen);

    while (true)
    {
        painter->drawLine(QPointF(0.0, biggerY), QPointF(this->width(), biggerY));
        painter->drawLine(QPointF(0.0, smallerY), QPointF(this->width(), smallerY));
        biggerY += this->gap;
        smallerY -= this->gap;
        if (smallerY <= 0 || biggerY >= this->height())
        {
            break;
        }
        painter->setPen(this->darkPen);
    }

}

void gridMap::drawColLines(QPainter *painter)
{
    float biggerX = this->startX;
    float smallerX = this->startX;

    painter->setPen(this->darkPen);

    while (true)
    {
        painter->drawLine(QPointF(biggerX, 0.0), QPointF(biggerX, this->height()));
        painter->drawLine(QPointF(smallerX, 0.0), QPointF(smallerX, this->height()));
        biggerX += this->gap;
        smallerX -= this->gap;
        if (smallerX <= 0 || biggerX >= this->width())
        {
            break;
        }
        painter->setPen(this->darkPen);

    }

}

void gridMap::drawCell(QPainter *painter)
{

    int l = this->gap;
    QColor c(231, 250, 65);
    painter->setPen(QPen(c));
    painter->setBrush(QBrush(c));
    vector<MyPoint> truePoints = logic.GetTruePoint();
    for(MyPoint p:truePoints)
         painter->drawRect(p.y * this->gap, p.x * this->gap, l, l);

}

void gridMap::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    this->drawCell(&painter);

    this->drawRowLines(&painter);
    this->drawColLines(&painter);

}

void gridMap::wheelEvent(QWheelEvent *event)
{
    QWidget::wheelEvent(event);
//    if (event->angleDelta().y() > 0)
//    {
//        this->gap += 0.1;
//    }
//    else if (event->angleDelta().y() < 0)
//    {
//        this->gap -= 0.1;
//    }

//    if (this->gap >= this->maxGap)
//    {
//        this->gap = this->minGap;
//    }
//    else if (this->gap <= this->minGap)
//    {
//        this->gap = this->maxGap;
//    }

    this->update();
}

void gridMap::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    this->startX = this->width() / 2;
    this->startY = this->height() / 2;
    this->update();
}

void gridMap::mousePressEvent(QMouseEvent *event)
{
    QPainter painter(this);
    QPoint p = event->pos();
    int x = p.x() / this->gap, y = p.y() / this->gap ;
    //y x 是窗体中的坐标与矩阵相反

    MyPoint pressPoint = { y,x };
    logic.Click(pressPoint);
    this->update();
}
