#include "ServerDlg.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerDlg w;
    w.show();
    return a.exec();
}
