#include <QApplication>
#include "LoginDlg.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	LoginDlg loginDlg("admin", "admin");
	loginDlg.show();

	return app.exec();
}
