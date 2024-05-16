#include "infoaboutpeople.h"
#include "ui_infoaboutpeople.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include "secondwindow.h"

InfoAboutPeople::InfoAboutPeople(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoAboutPeople)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./info.db");
    if (db.open()){
        qDebug("open");
    }
    else{
        qDebug("no open");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Info(Гость TEXT, Телефон TEXT, Дата_заезда TEXT, Дата_выезда TEXT, Номер INT);");

    model = new QSqlTableModel(this, db);
    model->setTable("Info");
    model->select();

    ui->tableView->setModel(model);

}

InfoAboutPeople::~InfoAboutPeople()
{
    delete ui;
}


void InfoAboutPeople::on_pushButton_4_clicked()
{
    hide();
    SecondWindow window1;
    window1.setModal(true);
    window1.exec();
}




void InfoAboutPeople::on_pushZ_clicked()
{
    model->insertRow(model->rowCount());
}


void InfoAboutPeople::on_pushButton_2_clicked()
{
    model->removeRow(row);
}


void InfoAboutPeople::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}




