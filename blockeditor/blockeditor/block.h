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
    enum { Type = UserType + 15};
    Block(block_type type, QGraphicsItem * parent = 0);
    ~Block(){
        for (int i = 0; i<ports.size();i++){
            Port* p = ports[i];
            delete p;
        }
    }
    block_type get_type_of_block();
    void addPort(Port * port);
    void portsChange();
    int getSizeofBlock();
    void calculate();
    void valFromPort();

    void removeBlockports();

    QList<Port*> getPorts();

    int type() const Q_DECL_OVERRIDE {return Type;}
protected:
    block_type blocktype;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
private:
    QPixmap myPixmap;
    QList<Port*> ports;
    QList<double> values;

};

#endif // BLOCK_H
