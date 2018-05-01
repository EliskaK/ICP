#include "block.h"
#include "wire.h"
#include <QDebug>

Block::Block(block_type type, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    this->type = type;
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
  return type;
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

void Block::portsChange(){
    double image = (double)myPixmap.height(); //velikost obrazku
    double space = image / (ports.count());
    for (int i = 1; i < ports.count()+1; i++){
        Port *port = ports[i-1];

        if (port->isOutput() == false){
            port->setRect(x()+(i*space),y()+2,10,10);
        } else{
            port->setRect(x()+(image/2),y()+image-11,10,10);
        }
    }
}

int Block::getSizeofBlock(){
    return this->myPixmap.height();
}
