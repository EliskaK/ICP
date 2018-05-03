#ifndef PORT_H
#define PORT_H

#include <QGraphicsEllipseItem>
//#include "wire.h"
class Wire;
class Port : public QGraphicsEllipseItem
{
public:
    Port(QPointF position, bool Output, QGraphicsItem *parent = 0);
    void setVal(double value);
    bool isOutput();
    Wire* getWire();
    bool isValueSet();
    void addWire(Wire* wire);
    double getVal();

private:
    double val;
    Wire *wire;
    bool output;
    bool valueSet;
};

#endif // PORT_H
