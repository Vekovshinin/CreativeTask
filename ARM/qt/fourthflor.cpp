#include "fourthflor.h"
#include "ui_fourthflor.h"
#include "secondwindow.h"
#include "hotel.h"
#include "vipone.h"
#include "n405.h"

fourthFlor::fourthFlor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fourthFlor)
{
    ui->setupUi(this);
}

fourthFlor::~fourthFlor()
{
    delete ui;
}

void fourthFlor::on_pushButton_6_clicked()
{
    hide();
    SecondWindow window8;
    window8.setModal(true);
    window8.exec();
}


void fourthFlor::on_pushButton_7_clicked()
{
    hide();
    hotel window9;
    window9.setModal(true);
    window9.exec();
}




void fourthFlor::on_pushButton_clicked()
{
    hide();
    VipOne window10;
    window10.setModal(true);
    window10.exec();
}



void fourthFlor::on_pushButton_5_clicked()
{
    hide();
    N405 window7;
    window7.setModal(true);
    window7.exec();
}

