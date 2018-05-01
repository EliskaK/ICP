#include "textclass.h"
#include "qscheme.h"
#include "wire.h"

Textclass::Textclass(QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

QVariant Textclass::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedHasChanged){
        //emit selectedChange(this);
        if(port != NULL){
            port->setRect(x()+70,y(),7,7);
            Wire* wire = port->getWire();
            if(wire != NULL){
                wire->updatePos();
            }
         }
    }
    return value;
}

void Textclass::addPort(Port * port){
    this->port = port;
}

void Textclass::focusOutEvent(QFocusEvent *event)
{
    setTextInteractionFlags(Qt::NoTextInteraction);
    emit lostFocus(this);
    QGraphicsTextItem::focusOutEvent(event);
}

void Textclass::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if (textInteractionFlags() == Qt::NoTextInteraction)
        setTextInteractionFlags(Qt::TextEditorInteraction);
    QGraphicsTextItem::mouseDoubleClickEvent(event);
}
