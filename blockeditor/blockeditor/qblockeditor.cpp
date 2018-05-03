#include "qblockeditor.h"
#include "block.h"
#include "qscheme.h"
#include "ui_qblockeditor.h"
#include "textclass.h"

#include <QtCore>

#include <QDebug>
QBlockEditor::QBlockEditor(QWidget *parent) : QMainWindow(parent)
{
    createActions();
    createMenu();
    scheme = new Qscheme(this);
    // nastaveni okna:
    scheme->setSceneRect(QRectF(0, 0, 900, 600));
    setWindowTitle("Block Editor 2018");
    setWindowIcon(QIcon(":/img/images/blockeditor.png"));

    connect(scheme, SIGNAL(blockAdd(Block*)), this, SLOT(blockAdd(Block*)));
    connect(scheme, SIGNAL(textAdd(QGraphicsItem*)), this, SLOT(textAdd(QGraphicsItem*)));
    setUpTools(); //tool boxes
    createToolbar();

    QGraphicsView *view = new QGraphicsView(scheme);
    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(tool);
    layout->addWidget(view);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);
}
/*
QBlockEditor::~QBlockEditor()
{
    delete ui;
}*/
void QBlockEditor::createToolbar(){
    toolbar = addToolBar(tr("Edit"));

    wirebtn = new QToolButton;
    wirebtn->setCheckable(true);
    wirebtn->setIcon(QIcon(":/img/images/wire.png"));

    movebtn = new QToolButton;
    movebtn->setCheckable(true);
    movebtn->setChecked(true);
    movebtn->setIcon((QIcon(":/img/images/move.png")));

    pointerTypeGroup = new QButtonGroup(this);
    pointerTypeGroup->addButton(wirebtn, Wiremode);
    pointerTypeGroup->addButton(movebtn, Moveblock);
    connect(pointerTypeGroup, SIGNAL(buttonClicked(int)), this, SLOT(pointerGroupclicked(int)));

    toolbar->addWidget(wirebtn);
    toolbar->addWidget(movebtn);
    toolbar->addAction(eraseAction);
    toolbar->addAction(playAction);
    toolbar->addAction(stepAction);
}
void QBlockEditor::pointerGroupclicked(int){
    scheme->setMode(Mode(pointerTypeGroup->checkedId()));
}
void QBlockEditor::setUpTools(){ // levy panel
    btn_group = new QButtonGroup(this);
    connect(btn_group, SIGNAL(buttonClicked(int)), this, SLOT(btn_groupClick(int)));
    QGridLayout *grid = new QGridLayout();
    // jednotliva tlacitka s bloky
    grid->addWidget(createBlockButton("sum",sumbtn),0,0);
    grid->addWidget(createBlockButton("sub",subbtn),1,0);
    grid->addWidget(createBlockButton("mul",mulbtn),2,0);
    grid->addWidget(createBlockButton("idiv",idivbtn),3,0);
    grid->addWidget(createBlockButton("lt",ltbtn),4,0);
    grid->addWidget(createBlockButton("gt",gtbtn),5,0);
    grid->addWidget(createBlockButton("text",text),6,0);

    // Tool box Možnosti - počet inputů bloku
    QGridLayout *optgrid = new QGridLayout();
    QLabel *spinboxlayout = new QLabel();
    spinboxlayout->setText("Počet inputů:");

    optgrid->addWidget(spinboxlayout);
    optgrid->addWidget(createOption());
    optgrid->setRowStretch(2, 5);

    QWidget *itemWidget = new QWidget;
    itemWidget->setLayout(grid);
    QWidget *optionsWidget = new QWidget;
    optionsWidget->setLayout(optgrid);

    tool = new QToolBox;
    //tool->setMinimumWidth(itemWidget->sizeHint().width());
    tool->addItem(itemWidget, tr("Bloky"));
    tool->addItem(optionsWidget, tr("Možnosti"));
}

void QBlockEditor::btn_groupClick(int id){
    qDebug() << "button click: " << id;
    if(id == text){
        scheme->setMode(Textmode);
    }
    else{
        scheme->setMode(Addblock); // bude se vytvaret novy blok do schematu
        scheme->setBlockType(block_type(id));
    }
}

QAbstractButton *QBlockEditor::createBlockButton(const QString &popis, int type){
    QToolButton *btn = new QToolButton;
    btn->setIcon(QIcon(":/img/images/"+popis+".png"));
    btn->setIconSize(QSize(50,50));
    btn->setCheckable(true);
    btn_group->addButton(btn, int(type));

    return btn;
}
QWidget *QBlockEditor::createOption(){
    QSpinBox *spinbox = new QSpinBox();
    spinbox->setRange(1,10); // omezeni poctu portu
    spinbox->setValue(2);
    connect(spinbox, SIGNAL(valueChanged(int)), scheme, SLOT(setInputs(int)));
    return spinbox;
}
void QBlockEditor::blockAdd(Block *block){
    pointerTypeGroup->button(int(Moveblock))->setChecked(true);
    scheme->setMode(Mode(pointerTypeGroup->checkedId()));
    btn_group->button(int(block->get_type_of_block()))->setChecked(false);
}

void QBlockEditor::createActions(){
    newAction = new QAction(tr("Nový"), this);
    connect(newAction, SIGNAL(triggered()), this, SLOT(newfile()));

    openAction = new QAction(tr("Otevřít"), this);
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(tr("Uložit"), this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    aboutAction = new QAction(tr("O programu"), this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));


    eraseAction = new QAction(QIcon(":/img/images/erase.png"), tr("Smazat"), this);
    connect(eraseAction, SIGNAL(triggered()), this, SLOT(eraseblock()));


    playAction = new QAction(QIcon(":/img/images/play.png"), tr("Spustit"), this);
    connect(playAction, SIGNAL(triggered()), this, SLOT(calc()));
    stepAction = new QAction(QIcon(":/img/images/step.png"), tr("Krok"), this);
    connect(stepAction, SIGNAL(triggered()), this, SLOT(step_calc()));

}
void QBlockEditor::createMenu(){
    Soubor = menuBar()->addMenu("Soubor");
    Soubor->addAction(newAction);
    Soubor->addAction(openAction);
    Soubor->addAction(saveAction);

    Info = menuBar()->addMenu("Info");
    Info->addAction(aboutAction);

}
void QBlockEditor::textAdd(QGraphicsItem *){
     btn_group->button(int(text))->setChecked(false);
     scheme->setMode(Mode(pointerTypeGroup->checkedId()));
}
void QBlockEditor::calc(){
    qDebug() << "calc";

}
void QBlockEditor::step_calc(){

}
void QBlockEditor::newfile(){
    // TODO
    qDebug() << "new";
}
void QBlockEditor::save(){
    // TODO
    qDebug() << "save";
}
void QBlockEditor::open(){
    //TODO
    qDebug() << "open";
}

void QBlockEditor::eraseblock(){
    // TODO
    qDebug() << "erase";
    if(scheme->selectedItems().count()){
        //if(scheme->selectedItems().first()->type() == Block::Type){
            Block* b = qgraphicsitem_cast<Block*>(scheme->selectedItems().first());
            //b->removeBlockports();
            delete b;
        //}
    }

}

void QBlockEditor::about(){
    QMessageBox::about(this, tr("O aplikaci Block Editor"),
                tr("Aplikace <b>Block Editor</b> je projekt do předmětu ICP. "
                   "Aplikace slouží k návrhu a editaci blokových schémat.<br>"
                   "<br>Autoři: Eliška Kadlecová a Daniel Doubek"));
}

