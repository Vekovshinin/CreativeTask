#ifndef VIPONE_H
#define VIPONE_H

#include <QDialog>

namespace Ui {
class VipOne;
}

class VipOne : public QDialog
{
    Q_OBJECT

public:
    explicit VipOne(QWidget *parent = nullptr);
    ~VipOne();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::VipOne *ui;
};

#endif // VIPONE_H
