#ifndef QTCREATORDIALOG_H
#define QTCREATORDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QtCreatorDialog; }
QT_END_NAMESPACE

class QtCreatorDialog : public QDialog
{
    Q_OBJECT

public:
    QtCreatorDialog(QWidget *parent = nullptr);
    ~QtCreatorDialog();

private:
    Ui::QtCreatorDialog *ui;
};
#endif // QTCREATORDIALOG_H
