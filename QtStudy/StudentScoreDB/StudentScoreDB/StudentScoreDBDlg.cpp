#include "StudentScoreDBDlg.h"

StudentScoreDBDlg::StudentScoreDBDlg(QWidget *parent)
    : QDialog(parent)
	
{
    ui.setupUi(this);
	//È¥³ý"?", Ìí¼Ó"-"&"¡õ"
	Qt::WindowFlags windowFlag = Qt::Dialog;
	windowFlag |= Qt::WindowMinimizeButtonHint;
	windowFlag |= Qt::WindowMaximizeButtonHint;
	windowFlag |= Qt::WindowCloseButtonHint;
	setWindowFlags(windowFlag);
	preSetDB();
	showDB2View();
}

void StudentScoreDBDlg::preSetDB()
{
	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName("StudentScore.db");
	if (true == m_db.open())
		qDebug("Open database.");
	else
		qDebug("Open database fail!");

	QSqlQuery query;
	QString str = ("CREATE TABLE Scores (\
					ID INT PRIMARY KEY NOT NULL,\
					Name TEXT NOT NULL,\
					Score INT NOT NULL);");
	if (true == query.exec(str))
		qDebug("Create table.");
	else
		qDebug() << str;
}

void StudentScoreDBDlg::showDB2View(QString str)
{
	m_model.setQuery(str);	//Execute command line and save result
	ui.tableViewDB->setModel(&m_model);	//Show model
}

void StudentScoreDBDlg::on_sortButton_clicked()
{
	QString key = ui.keyBox->currentText();
	QString order = ui.orderBox->currentText();
	QString str = QString("SELECT * FROM Scores ORDER BY %1 %2;").arg(key).arg(order);
	showDB2View(str);
}

void StudentScoreDBDlg::on_insertButton_clicked()
{
	qDebug("Preparing INSERT.");
	int id = ui.idEdit->text().toInt();
	if (id <= 0)
	{
		QMessageBox::critical(this, "Error", "Input ID is invalid!");
		qDebug("ID invalid.");
		return;
	}

	QString name = ui.nameEdit->text();
	if (name.isEmpty())
	{
		QMessageBox::critical(this, "Error", "Input Name is invalid!");
		qDebug("Name invalid.");
		return;
	}

	int score = ui.scoreEdit->text().toInt();
	if (score < 0 | score > 100)
	{
		QMessageBox::critical(this, "Error", "Input score is invalid!");
		qDebug("Scoure invalid.");
		return;
	}

	QSqlQuery query;
	query.prepare("INSERT INTO Scores (ID, Name, Score) VALUES(:ID, :Name, :Score);");
	query.addBindValue(id);
	query.addBindValue(name);
	query.addBindValue(score);
	if (true == query.exec())
		qDebug("INSERT ITEM.");
	else
		qDebug("INSERT ITEM fail!");
	showDB2View();
}

void StudentScoreDBDlg::on_editButton_clicked()
{
	qDebug("Preparing UPDATE.");
	QString id = ui.idEdit->text();
	if (id.isEmpty() | id.toInt() < 0)
	{
		QMessageBox::critical(this, "Error", "Input ID is invalid!");
		qDebug("ID invalid.");
		return;
	}

	QString name = ui.nameEdit->text();
	if (name.isEmpty())
	{
		QMessageBox::critical(this, "Error", "Input Name is invalid!");
		qDebug("Name invalid.");
		return;
	}

	QString score = ui.scoreEdit->text();
	if (score.isEmpty() | score.toInt() < 0 | score.toInt() > 100)
	{
		QMessageBox::critical(this, "Error", "Input score is invalid!");
		qDebug("Scoure invalid.");
		return;
	}

	QSqlQuery query;
	query.prepare("UPDATE Scores SET Name=:Name, Score=:Score WHERE ID=:ID;");
	query.addBindValue(name);
	query.addBindValue(score);
	query.addBindValue(id);
	if (true == query.exec())
		qDebug("UPDATE ITEM.");
	else
		qDebug("UPDATE ITEM fail!");
	showDB2View();
}

void StudentScoreDBDlg::on_deleteButton_clicked()
{
	qDebug("Preparing DELETE.");
	int id = ui.idEdit->text().toInt();
	if (id <= 0)
	{
		QMessageBox::critical(this, "Error", "Input ID is invalid!");
		qDebug("ID invalid.");
		return;
	}

	QSqlQuery query;
	query.prepare("DELETE FROM Scores WHERE ID=:ID");
	query.addBindValue(id);

	if (QMessageBox::No == QMessageBox::question(this, "Delete", "Sure to delete?", QMessageBox::Yes | QMessageBox::No))
		return;

	if (true == query.exec())
		qDebug("DELETE ITEM.");
	else
		qDebug("DELETE ITEM fail!");
	showDB2View();
}
