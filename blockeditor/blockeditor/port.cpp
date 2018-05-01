#include <QBrush>
#include "port.h"


Port::Port(QPointF position, bool Output,QGraphicsItem *parent) : QGraphicsEllipseItem(parent) {
    setRect(position.x(), position.y(),10,10);
    wire = NULL;
    QBrush brush(Qt::gray);
    setBrush(brush);
    this->output = Output;
}
Wire* Port::getWire(){
    return this->wire;
}
bool Port::isOutput(){
    return output;
}
void Port::setVal(double value){
    this->val = value;
}
bool Port::isValueSet(){
    return valueSet;
}
void Port::addWire(Wire *wire){
    this->wire = wire;
}
