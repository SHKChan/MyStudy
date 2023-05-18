#include "StudentScoreDBDlg.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentScoreDBDlg w;
    w.show();
    return a.exec();
}
