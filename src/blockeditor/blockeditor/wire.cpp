#include "wire.h"

#include <math.h>

#include <QPen>
#include <QPainter>
#include <QDebug>

#include <QLineF>

Wire::Wire(Port* fromblock, Port* toblock, QGraphicsItem *parent) : QGraphicsLineItem(parent)
{
    mystart = fromblock;
    myend = toblock;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

void Wire::updatePos(){
    QLineF line(QPointF(mystart->boundingRect().topLeft().x(),mystart->boundingRect().topLeft().y()), QPointF(myend->boundingRect().topLeft().x(),myend->boundingRect().topLeft().y()));
    setLine(line);
}

QRectF Wire::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

void Wire::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::black);
    painter->setPen(QPen(Qt::black,2));
    painter->drawLine(QPointF(mystart->boundingRect().topLeft().x()+5.0,mystart->boundingRect().topLeft().y()+5.0), QPointF(myend->boundingRect().topLeft().x()+5.0,myend->boundingRect().topLeft().y()+5.0));

}
