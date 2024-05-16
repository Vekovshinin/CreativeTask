#ifndef FIFTHFLOR_H
#define FIFTHFLOR_H

#include <QDialog>


namespace Ui {
class fifthFlor;
}

class fifthFlor : public QDialog
{
    Q_OBJECT

public:
    explicit fifthFlor(QWidget *parent = nullptr);
    ~fifthFlor();

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::fifthFlor *ui;

};

#endif // FIFTHFLOR_H
