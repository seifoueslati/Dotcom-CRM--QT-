#ifndef DETAILSCB_H
#define DETAILSCB_H
#include "addcb.h"
#include "eml.h"
#include <QMainWindow>

namespace Ui {
class DetailsCB;
}

class DetailsCB : public QMainWindow
{
    Q_OBJECT

public:
    explicit DetailsCB(QWidget *parent = 0);
    ~DetailsCB();


private slots:
    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_sendm_clicked();

private:
    Ui::DetailsCB *ui;
    AddCB *edit;
    eml *edit1;

};

#endif // DETAILSCB_H
