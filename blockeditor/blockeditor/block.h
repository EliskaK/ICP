#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

//#include "wire.h"
#include "port.h"

class Port;

enum block_type {sum, sub, mul, idiv, lt, gt};
class Block : public QGraphicsPixmapItem
{
public:
    Block(block_type type, QGraphicsItem * parent = 0);
    block_type get_type_of_block();
    void addPort(Port * port);
    void portsChange();
    int getSizeofBlock();
protected:
    block_type type;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
private:
    QPixmap myPixmap;
    QList<Port*> ports;

};

#endif // BLOCK_H
