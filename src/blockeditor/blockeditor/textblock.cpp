#include "textblock.h"
#include "qscheme.h"

Textblock::Textblock(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}
