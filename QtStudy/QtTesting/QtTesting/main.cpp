#include "QtTesting.h"
#include <QtWidgets/QApplication>
#include <QpushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtTesting w;
    w.show();
    return a.exec();
}
