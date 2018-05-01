#include "qscheme.h"
#include "port.h"
#include "wire.h"

#include <QGraphicsSceneMouseEvent>
#include <QDebug>

Qscheme::Qscheme(QObject *parent) : QGraphicsScene(parent)
{
    this->mode = Moveblock;
    type = sum;
    myLineColor = Qt::black;
    this->inputs = 2; //defaultne
}

void Qscheme::setMode(Mode mode){
    this->mode = mode;
}

Mode Qscheme::getMode(){
    return this->mode;
}

void Qscheme::setBlockType(block_type typ){
    this->type = typ;
}

void Qscheme::setInputs(int cnt){
    this->inputs = cnt;
}

void Qscheme::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
    if (mouseEvent->button() != Qt::LeftButton)
            return;
    if(mode == Addblock){
        Block *blok = new Block(type);
        addItem(blok);
        blok->setPos(mouseEvent->scenePos());

        double image = (double) blok->getSizeofBlock();
        double margin = (double) (image / (inputs+1));
        for(int i = 1; i < inputs+1; i++){
            Port *port = new Port(QPointF(mouseEvent->scenePos().x()+(i*margin),mouseEvent->scenePos().y()+2),false);
            addItem(port);
            blok->addPort(port);
        }
        Port *port = new Port(QPointF(mouseEvent->scenePos().x()+(image/2),mouseEvent->scenePos().y()+image-11),true);
        addItem(port);
        blok->addPort(port);
        emit blockAdd(blok);
    }
    else if(mode == Wiremode){
        line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(), mouseEvent->scenePos()));
        line->setPen(QPen(myLineColor,2));
        addItem(line);

    }
   /* else if(mode == Textmode){
        text_block = new Textblock();
        text_block->setZValue(1000.0);
    }*/
    QGraphicsScene::mousePressEvent(mouseEvent);

}

void Qscheme::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent){
    if(mode == Wiremode && line != 0){
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    }
    else if(mode == Moveblock){
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
}

void Qscheme::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent){
    if(line != 0 && mode == Wiremode){
        QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();

        removeItem(line);
        delete line;

        if (startItems.count() > 0 && endItems.count() > 0 &&
            startItems.first()->type() == Port::Type &&
            endItems.first()->type() == Port::Type &&
            startItems.first() != endItems.first() ) {

            Port *startItem = qgraphicsitem_cast<Port *>(startItems.first());
            Port *endItem = qgraphicsitem_cast<Port *>(endItems.first());

            // overeni zda k portu neni pripojen jiny propoj (ke kazdemu muze byt jen jeden
            if(startItem->getWire()== NULL && endItem->getWire() == NULL) {
                if(checkPortisOK(startItem, endItem)) {
                    Wire *wire = new Wire(startItem, endItem);
                    startItem->addWire(wire);
                    endItem->addWire(wire);
                    wire->setZValue(1000.0);
                    addItem(wire);
                    wire->updatePos();
                 }
            }
        }
    }
    line = 0;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

bool Qscheme::checkPortisOK(Port* s, Port* e){
    if((s->isOutput() == false && e->isOutput() == true)||(s->isOutput() == true && e->isOutput() == false)) {
        return true;
    }
    else
        return false;
}

