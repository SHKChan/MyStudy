#include "ClientDlg.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientDlg w;
    w.show();
    return a.exec();
}
