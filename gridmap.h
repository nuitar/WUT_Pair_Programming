#ifndef GRIDMAP_H
#define GRIDMAP_H

#include <QWidget>
#include <QWidget>
#include <QPen>
#include <QPainter>
#include <QPaintEvent>
#include <vector>
#include <qtimer.h>
#include "Logic.h"
#include "Global.h"

class gridMap : public QWidget
{
    Q_OBJECT

public:
    gridMap(QWidget *parent = nullptr);
    ~gridMap();

protected:
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    void setBackgroundColor();              // 设置窗口背景颜色
    void drawRowLines(QPainter *painter);   // 绘制横线
    void drawColLines(QPainter *painter);   // 绘制竖线
    void drawCell(QPainter *painter);
    

private:
    int minGap;                              // 最小线间隔
    int maxGap;                              // 最大线间隔
    float gap;                               // 当前线间隔
    float startX;                            // 竖线初始x坐标（从窗口中间开始）
    float startY;                            // 横线初始y坐标（从窗口中间开始）
    QPen darkPen;                            // 粗一点的画笔
    Logic logic;

signals:
    void updateNext();
    void random();
    void reset();
};


#endif // GRIDMAP_H
