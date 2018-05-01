#ifndef QBLOCKEDITOR_H
#define QBLOCKEDITOR_H

#include <QMainWindow>

#include <QButtonGroup>

#include <QPushButton>

#include <QtWidgets>

#include <QPixmap>

#include "qscheme.h"


namespace Ui {
class QBlockEditor;
}

class QBlockEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit QBlockEditor(QWidget *parent = 0);
    ~QBlockEditor();



private:
    enum{sumbtn, subbtn, mulbtn, idivbtn, ltbtn, gtbtn, text, play, step, erase};
    void setUpTools();
    void createMenu();
    QWidget * createOption();
    void createActions();
    void createToolbar();

    Ui::QBlockEditor *ui;

    QButtonGroup *btn_group;

    QButtonGroup* pointerTypeGroup;

    QAbstractButton *createBlockButton(const QString &popis, int type);

    Qscheme *scheme;

    QToolBox *tool;



    QMenu *Soubor;
    QMenu *Info;

    QAction *aboutAction;
    QAction *saveAction;
    QAction *openAction;
    QAction *newAction;
    QAction *wireAction;
    QAction *eraseAction;
    QAction *playAction;
    QAction *stepAction;

    QToolBar *toolbar;
    QToolButton *wirebtn;
    QToolButton *playbtn;
    QToolButton *stepbtn;
    QToolButton *movebtn;


private slots:
    void btn_groupClick(int id);
    void textAdd(QGraphicsItem *it);
    void blockAdd(Block *block);
    void pointerGroupclicked(int id);
    void eraseblock();

    void about();
    void newfile();
    void open();
    void save();

};

#endif // QBLOCKEDITOR_H
