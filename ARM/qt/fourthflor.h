#ifndef FOURTHFLOR_H
#define FOURTHFLOR_H

#include <QDialog>


namespace Ui {
class fourthFlor;
}

class fourthFlor : public QDialog
{
    Q_OBJECT

public:
    explicit fourthFlor(QWidget *parent = nullptr);
    ~fourthFlor();
private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();


private:
    Ui::fourthFlor *ui;
};

#endif // FOURTHFLOR_H
