#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtTesting.h"

class QtTesting : public QWidget
{
    Q_OBJECT

public:
	QtTesting(QWidget *parent = Q_NULLPTR);

public slots:
	void on_pushButton_clicked();

private:
    Ui::QtTestingClass ui;
	bool m_bIsPressed;
};
