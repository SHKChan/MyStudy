#pragma once

#include <QtWidgets/QDialog>
#include "ui_StudentScoreDBDlg.h"
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

class StudentScoreDBDlg : public QDialog
{
    Q_OBJECT

public:
    StudentScoreDBDlg(QWidget *parent = Q_NULLPTR);

private:
	void preSetDB();
	void showDB2View(QString str = "SELECT * FROM Scores");

private slots:
	void on_sortButton_clicked();
	void on_insertButton_clicked();
	void on_editButton_clicked();
	void on_deleteButton_clicked();

private:
    Ui::StudentScoreDBDlgClass ui;
	QSqlDatabase m_db;
	QSqlQueryModel m_model;
};
