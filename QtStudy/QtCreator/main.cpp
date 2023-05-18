#include "qtcreatordialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtCreatorDialog w;
    w.show();
    return a.exec();
}
