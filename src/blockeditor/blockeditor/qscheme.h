#ifndef SCHEME_H
#define SCHEME_H
#include <QGraphicsScene>
#include "block.h"
#include "port.h"
#include "textblock.h"
enum Mode {Addblock, Moveblock, Wiremode, Textmode};
class Qscheme : public QGraphicsScene
{
    Q_OBJECT
public:

   Qscheme(){}
   Qscheme(QObject *parent);
   virtual ~Qscheme(){}
   Mode getMode();
   bool checkPortisOK(Port* s, Port* e);
private:
    Mode mode;
    block_type type;
    QGraphicsLineItem *line;
    QColor myLineColor;
    int inputs;
    Textblock *text_block;
public slots:
    void setMode(Mode mode);
    void setBlockType(block_type typ);
    void setInputs(int cnt);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
signals:
    void blockAdd(Block *block);
};

#endif // SCHEME_H
