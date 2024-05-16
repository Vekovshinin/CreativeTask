#include "firstflor.h"
#include "ui_firstflor.h"
#include "secondwindow.h"
#include "hotel.h"

firstFlor::firstFlor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::firstFlor)
{
    ui->setupUi(this);
}

firstFlor::~firstFlor()
{
    delete ui;
}

void firstFlor::on_pushButton_11_clicked()
{
    hide();
    SecondWindow window8;
    window8.setModal(true);
    window8.exec();
}


void firstFlor::on_pushButton_12_clicked()
{
    hide();
    hotel window9;
    window9.setModal(true);
    window9.exec();
}

