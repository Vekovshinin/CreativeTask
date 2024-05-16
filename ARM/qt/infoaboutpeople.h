#ifndef INFOABOUTPEOPLE_H
#define INFOABOUTPEOPLE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class InfoAboutPeople;
}

class InfoAboutPeople : public QDialog
{
    Q_OBJECT

public:
    explicit InfoAboutPeople(QWidget *parent = nullptr);
    ~InfoAboutPeople();

private slots:
    void on_pushButton_4_clicked();

    void on_pushZ_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

private:
    Ui::InfoAboutPeople *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    int row;

};

#endif // INFOABOUTPEOPLE_H
