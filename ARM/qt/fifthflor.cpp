#include "fifthflor.h"
#include "ui_fifthflor.h"
#include "secondwindow.h"
#include "hotel.h"

fifthFlor::fifthFlor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fifthFlor)
{
    ui->setupUi(this);
}

fifthFlor::~fifthFlor()
{
    delete ui;
}

void fifthFlor::on_pushButton_11_clicked()
{
    hide();
    SecondWindow window8;
    window8.setModal(true);
    window8.exec();
}


void fifthFlor::on_pushButton_12_clicked()
{
    hide();
    hotel window9;
    window9.setModal(true);
    window9.exec();
}

