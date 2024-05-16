#ifndef SECONDFLOR_H
#define SECONDFLOR_H

#include <QDialog>

namespace Ui {
class secondFlor;
}

class secondFlor : public QDialog
{
    Q_OBJECT

public:
    explicit secondFlor(QWidget *parent = nullptr);
    ~secondFlor();

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::secondFlor *ui;
};

#endif // SECONDFLOR_H
