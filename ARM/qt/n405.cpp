#include "n405.h"
#include "ui_n405.h"
#include <QPixmap>
#include "secondwindow.h"
#include "fourthflor.h"
#include "hotel.h"
#include <QMessageBox>


N405::N405(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::N405)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/405.jpg");
    int w = ui->img->width();
    int h = ui->img->height();

    ui->img->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}


N405::~N405()
{
    delete ui;
}


void N405::on_pushButton_6_clicked()
{
    hide();
    SecondWindow window;
    window.setModal(true);
    window.exec();
}


void N405::on_pushButton_7_clicked()
{
    hide();
    hotel window1;
    window1.setModal(true);
    window1.exec();
}




void N405::on_pushButton_8_clicked()
{
    hide();
    fourthFlor window3;
    window3.setModal(true);
    window3.exec();
}


void N405::on_pushButton_5_clicked()
{
    if(ui->checkBox->isChecked()){
        QMessageBox::about(this, "Окно бронирования","Вы успешно забронировали номер, перейдите в информацию о гостях и заполните данные");
    }
    else{
        QMessageBox::about(this, "Окно бронирования", "Выберете другой номер для бронирования");
    }
}

