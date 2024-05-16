#ifndef HOTEL_H
#define HOTEL_H

#include <QDialog>

namespace Ui {
class hotel;
}

class hotel : public QDialog
{
    Q_OBJECT

public:
    explicit hotel(QWidget *parent = nullptr);
    ~hotel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::hotel *ui;
};

#endif // HOTEL_H
