#include "hotel.h"
#include "ui_hotel.h"
#include <QPixmap>
#include "firstflor.h"
#include "secondflor.h"
#include "thirdflor.h"
#include "fourthflor.h"
#include "fifthflor.h"

hotel::hotel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotel)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/9b68944b.jpg");
    int w = ui->img->width();
    int h = ui->img->height();

    ui->img->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

hotel::~hotel()
{
    delete ui;
}

void hotel::on_pushButton_clicked()
{
    if (ui->radioButton->isChecked()){
        hide();
        firstFlor window4;
        window4.setModal(true);
        window4.exec();
    }
    if (ui->radioButton_2->isChecked()){
        hide();
        secondFlor window5;
        window5.setModal(true);
        window5.exec();
    }
    if (ui->radioButton_3->isChecked()){
        hide();
        thirdFlor window6;
        window6.setModal(true);
        window6.exec();
    }
    if (ui->radioButton_4->isChecked()){
        hide();
        fourthFlor window7;
        window7.setModal(true);
        window7.exec();
    }
    if (ui->radioButton_5->isChecked()){
        hide();
        fifthFlor window8;
        window8.setModal(true);
        window8.exec();
    }

}

