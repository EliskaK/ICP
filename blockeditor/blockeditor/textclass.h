#ifndef TEXTCLASS_H
#define TEXTCLASS_H

#include <QGraphicsTextItem>
#include <QPen>
#include "port.h"

class QFocusEvent;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsSceneMouseEvent;

class Textclass : public QGraphicsTextItem
{
    Q_OBJECT

public:
    enum { Type = UserType + 3 };

    Textclass(QGraphicsItem *parent = 0);
    ~Textclass(){
        delete port;
    }
    int type() const override { return Type; }
    void addPort(Port * port);
    void setValue();
    double getValue();
    void setValtoPort();

signals:
    void lostFocus(Textclass *textblock);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    void focusOutEvent(QFocusEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    //QRectF boundingRect() const;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget * widget);
private:
    Port* port;
    double port_value;
};

#endif // TEXTCLASS_H
