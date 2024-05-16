#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "infoaboutpeople.h"
#include "hotel.h"
#include <QMessageBox>
#include <QPixmap>

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/dinaAdmin.jpg");
    int w = ui->img->width();
    int h = ui->img->height();

    ui->img->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    QPixmap pix1(":/resources/img/zvezd.jpg");
    int w1 = ui->img1->width();
    int h1 = ui->img1->height();

    ui->img1->setPixmap(pix1.scaled(w1, h1, Qt::KeepAspectRatio));
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_clicked()
{
    hide();
    InfoAboutPeople window1;
    window1.setModal(true);
    window1.exec();
}


void SecondWindow::on_pushButton_2_clicked()
{
    hide();
    hotel window3;
    window3.setModal(true);
    window3.exec();
}


void SecondWindow::on_pushButton_3_clicked()
{
    QMessageBox::about(this,"Выход","Просто закройте программу)");
}


void SecondWindow::on_pushButton_4_clicked()
{
    QMessageBox::about(this,"Информация о гостинице","Гостиница Мейрон - это изысканное место роскоши и комфорта в самом сердце Москвы. Сочетая в себе элегантный дизайн, высокий уровень сервиса и первоклассные удобства, Мейрон предлагает гостям незабываемый опыт пребывания в столице России.)");
}

