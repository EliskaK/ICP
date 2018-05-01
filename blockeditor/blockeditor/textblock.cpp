#include "textblock.h"

#include <QDoubleSpinBox>
#include <QLabel>
#include <QVBoxLayout>

Textblock1::Textblock1(QWidget *parent) : QWidget(parent)
{
    spin_input = new QDoubleSpinBox(this);
    m_label = new QLabel(this);
}

void Textblock1::mouseDoubleClickEvent(QMouseEvent *event){

}

void Textblock1::mousePressEvent(QMouseEvent *event){

}
void Textblock1::loseFocus(){

}
