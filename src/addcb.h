#ifndef ADDCB_H
#define ADDCB_H

#include <QDialog>

namespace Ui {
class AddCB;
}

class AddCB : public QDialog
{
    Q_OBJECT

public:
    explicit AddCB(QWidget *parent = 0);
    ~AddCB();

private slots:
    void sendMail();
    void mailSent(QString);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::AddCB *ui;
};

#endif // ADDCB_H
