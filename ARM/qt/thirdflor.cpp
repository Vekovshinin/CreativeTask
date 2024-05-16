#include "thirdflor.h"
#include "ui_thirdflor.h"
#include "secondwindow.h"
#include "hotel.h"

thirdFlor::thirdFlor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdFlor)
{
    ui->setupUi(this);
}

thirdFlor::~thirdFlor()
{
    delete ui;
}

void thirdFlor::on_pushButton_11_clicked()
{
    hide();
    SecondWindow window8;
    window8.setModal(true);
    window8.exec();
}


void thirdFlor::on_pushButton_12_clicked()
{
    hide();
    hotel window9;
    window9.setModal(true);
    window9.exec();
}

