#include "vipone.h"
#include "ui_vipone.h"
#include <QPixmap>
#include "fourthflor.h"
#include "hotel.h"
#include "secondwindow.h"
#include <QMessageBox>

VipOne::VipOne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VipOne)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/VipOne.jpg");
    int w = ui->img->width();
    int h = ui->img->height();

    ui->img->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

VipOne::~VipOne()
{
    delete ui;
}

void VipOne::on_pushButton_clicked()
{
    hide();
    SecondWindow window1;
    window1.setModal(true);
    window1.exec();
}


void VipOne::on_pushButton_3_clicked()
{
    hide();
    hotel window1;
    window1.setModal(true);
    window1.exec();
}


void VipOne::on_pushButton_2_clicked()
{
    hide();
    fourthFlor window1;
    window1.setModal(true);
    window1.exec();
}


void VipOne::on_pushButton_4_clicked()
{
    if(ui->checkBox->isChecked()){
        QMessageBox::about(this, "Окно бронирования","Вы успешно забронировали номер, перейдите в информацию о гостях и заполните данные");
    }
    else{
        QMessageBox::about(this, "Окно бронирования", "Выберете другой номер для бронирования");
    }
}

