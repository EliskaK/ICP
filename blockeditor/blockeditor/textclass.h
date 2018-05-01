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

    int type() const override { return Type; }
    void addPort(Port * port);

signals:
    void lostFocus(Textclass *textblock);
    void selectedChange(QGraphicsItem *item);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    void focusOutEvent(QFocusEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
private:
    Port* port;
};

#endif // TEXTCLASS_H
