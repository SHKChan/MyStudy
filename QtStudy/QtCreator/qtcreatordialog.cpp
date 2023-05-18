#include "qtcreatordialog.h"
#include "ui_qtcreatordialog.h"

QtCreatorDialog::QtCreatorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QtCreatorDialog)
{
    ui->setupUi(this);
}

QtCreatorDialog::~QtCreatorDialog()
{
    delete ui;
}

