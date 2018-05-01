#ifndef WIRE_H
#define WIRE_H

#include <QObject>
#include <QWidget>
#include "block.h"
//#include <QGraphicsLineItem>
class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;

class Port;

class Wire : public QGraphicsLineItem{
public:
    Wire (Port* fromblock, Port* toblock, QGraphicsItem *parent = 0);
    void updatePos();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,QWidget *);
private:
    Port* mystart;
    Port* myend;

};

#endif // WIRE_H
