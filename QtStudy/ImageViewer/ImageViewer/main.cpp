#include "ImageViewerDlg.h"
#include <QtWidgets/QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageViewerDlg w;
	a.setStyle(QStyleFactory::create("windows"));
    w.show();
    return a.exec();
}
