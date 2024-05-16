#include "secondflor.h"
#include "ui_secondflor.h"
#include "secondwindow.h"
#include "hotel.h"

secondFlor::secondFlor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondFlor)
{
    ui->setupUi(this);
}

secondFlor::~secondFlor()
{
    delete ui;
}

void secondFlor::on_pushButton_11_clicked()
{
    hide();
    SecondWindow window8;
    window8.setModal(true);
    window8.exec();
}


void secondFlor::on_pushButton_12_clicked()
{
    hide();
    hotel window9;
    window9.setModal(true);
    window9.exec();
}

