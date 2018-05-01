#include "qblockeditor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QBlockEditor w;
    w.show();

    return app.exec();
}
