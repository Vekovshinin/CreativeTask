#ifndef THIRDFLOR_H
#define THIRDFLOR_H

#include <QDialog>

namespace Ui {
class thirdFlor;
}

class thirdFlor : public QDialog
{
    Q_OBJECT

public:
    explicit thirdFlor(QWidget *parent = nullptr);
    ~thirdFlor();

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::thirdFlor *ui;
};

#endif // THIRDFLOR_H
