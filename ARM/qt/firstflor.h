#ifndef FIRSTFLOR_H
#define FIRSTFLOR_H

#include <QDialog>


namespace Ui {
class firstFlor;
}

class firstFlor : public QDialog
{
    Q_OBJECT

public:
    explicit firstFlor(QWidget *parent = nullptr);
    ~firstFlor();

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::firstFlor *ui;

};

#endif // FIRSTFLOR_H
