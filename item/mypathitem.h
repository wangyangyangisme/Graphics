/*************************************************
**版  权：RenGu Company
**文件名: mypathitem.h
**作  者: wey       Version: 1.0       Date: 2016.09.09
**描  述: 用于绘制折线
**Others:
**
**修改历史:
**20161209:wey:
*************************************************/
#ifndef MYPATHITEM_H
#define MYPATHITEM_H

#include <QGraphicsPathItem>
#include <QPainterPath>
#include <QObject>

class MyNodePort;
class MyTextItem;
class MyNodeLine;

#include "../Header.h"

class MyPathItem : public QObject, public QGraphicsPathItem
{
public:
    MyPathItem(QObject * parent = 0,QGraphicsItem * parent1 = 0);
    ~MyPathItem();

    void setStartItem(MyNodeLine * startItem);
    MyNodeLine * getStartItem() const{ return startItem; }
    void setStartItemID(const QString id);

    void setEndItem(MyNodeLine * endItem);
    MyNodeLine * getEndItem() const{ return endItem; }
    void setEndItemID(const QString id);

    void setStartPoint(QPointF startPoint);
    QPointF getStartPoint(){return this->startPosPoint;}

    void setEndPoint(QPointF endPoint);
    QPointF getEndPoint(){return this->endPosPoint;}

    void setStartPointType(PointType type);
    void setEndPointType(PointType type);

    void setProperty(ItemProperty property);
    ItemProperty getProperty(){return this->property;}
    GraphicsType getType(){return this->currItemType;}

    void setPath(const QPainterPath &path);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;

    QList<QPointF> getPathPoints();
    void setPathPoints(QList<QPointF> & points);

    QPainterPath  shape() const;

    void updateCurrItemPos();
    void setLineType(LineType lineType);

    friend QDataStream & operator <<(QDataStream &,MyPathItem * item);
    friend QDataStream & operator >>(QDataStream &,MyPathItem * item);

private:
    void countPathItemPoints();
    void getNewLine();

    MyNodeLine * startItem;
    MyNodeLine * endItem;

    QPointF startPosPoint,endPosPoint; //折线在scene中的位置

    GraphicsType currItemType;
    ItemProperty property;             //保存当前属性
    GraphicsType type;

    QRectF boundRect;                  //包裹的矩形
    QPainterPath painterPath;          //当前路径

    QList<QPointF> points;             //根据起点和终点坐标计算出当前折线的每个关键点(折线点)
};

#endif // MYPATHITEM_H
