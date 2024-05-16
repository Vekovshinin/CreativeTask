#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "secondwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/imgpreview.jpg");
    int w = ui->img->width();
    int h = ui->img->height();

    ui->img->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString login = ui->Login->text();
    QString password = ui->Password->text();
    if((login == "1" || login == "Дина" || login == "admin") && (password == "1" || password == "Мейрон" || password == "admin")){
        hide();
        SecondWindow window;
        window.setModal(true);
        window.exec();
    }
    else {
        QMessageBox::warning(this,"Ошибка","Неверный логин или пароль");
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::about(this, "Помощь", "Обратитесь в тех поддержку для сотрудников");
}

