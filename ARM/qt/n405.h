#ifndef N405_H
#define N405_H

#include <QDialog>

namespace Ui {
class N405;
}

class N405 : public QDialog
{
    Q_OBJECT

public:
    explicit N405(QWidget *parent = nullptr);
    ~N405();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::N405 *ui;
};

#endif // N405_H
