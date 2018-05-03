#include "block.h"
#include "wire.h"
#include <QDebug>

Block::Block(block_type type, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    this->blocktype = type;
    if(type == sum){
        myPixmap = QPixmap(":/img/images/sum.png");
        setPixmap(myPixmap);
    }
    else if(type == sub){
        myPixmap = QPixmap(":/img/images/sub.png");
        setPixmap(myPixmap);
    }
    else if(type == mul){
        myPixmap = QPixmap(":/img/images/mul.png");
        setPixmap(myPixmap);
    }
    else if(type == idiv){
        myPixmap = QPixmap(":/img/images/idiv.png");
        setPixmap(myPixmap);
    }
    else if(type == lt){
        myPixmap = QPixmap(":/img/images/lt.png");
        setPixmap(myPixmap);
    }
    else if(type == gt){
        myPixmap = QPixmap(":/img/images/gt.png");
        setPixmap(myPixmap);
    }
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}
block_type Block::get_type_of_block(){
  return blocktype;
}

QVariant Block::itemChange(GraphicsItemChange change, const QVariant &value){
    if(change == QGraphicsItem::ItemPositionChange){
        portsChange();
        foreach (Port *port, ports) {
            Wire *wire = port->getWire();
            if(wire != NULL){
                wire->updatePos();
            }
        }
    }
    return value;
}

void Block::addPort(Port * port){
    ports.append(port);
}

QList<Port*> Block::getPorts(){
    return ports;
}

void Block::portsChange(){
    double image = (double)getSizeofBlock(); //velikost obrazku
    double space = image / (ports.count());
    for (int i = 1; i < ports.count()+1; i++){
        Port *port = ports[i-1];

        if (port->isOutput() == false){
            port->setRect(x(),y()+(i*space)-2,7,7);
        } else{
            port->setRect(x()+image-6,y()+(image/2)-3,7,7);
        }
    }
}

int Block::getSizeofBlock(){
    return this->myPixmap.height();
}

void Block::calculate(){
    block_type typ = this->get_type_of_block();
    valFromPort();
    if(typ == sum){
        double temp = 0.0;
        foreach (double val, values) {
            temp = temp + val;
        }
    }
}

void Block::valFromPort(){
   foreach (Port* port, this->ports) {
       values.append(port->getVal());
    }
   qDebug() << "values in block" << values;

}

void Block::removeBlockports(){
    qDeleteAll(ports.begin(), ports.end());
    ports.clear();
}
