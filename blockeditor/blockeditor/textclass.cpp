#include "textclass.h"
#include "qscheme.h"
#include "wire.h"

#include <QRectF>
#include <QPainter>
#include <QDebug>

Textclass::Textclass(QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    //setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

QVariant Textclass::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedHasChanged){
        if(port != NULL){
            Port* temp;
            temp = port;
            temp->setRect(x()+70,y(),7,7);
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

void Textclass::setValue(){
    QString string = this->toPlainText();
    port_value = string.toDouble();
    setValtoPort();
}

double Textclass::getValue(){
    return this->port_value;
}

void Textclass::setValtoPort(){
    qDebug() << "portval" <<port_value;
    port->setVal(port_value);
}


void Textclass::focusOutEvent(QFocusEvent *event)
{
    setTextInteractionFlags(Qt::NoTextInteraction);
    emit lostFocus(this);
    QGraphicsTextItem::focusOutEvent(event);
    setValue();
}

void Textclass::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if (textInteractionFlags() == Qt::NoTextInteraction)
        setTextInteractionFlags(Qt::TextEditorInteraction);
    QGraphicsTextItem::mouseDoubleClickEvent(event);
}
