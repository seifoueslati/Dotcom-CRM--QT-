#ifndef AFTERSALE_H
#define AFTERSALE_H
#include <QMainWindow>
#include<QDebug>
#include<QSystemTrayIcon>
#include <iostream>

namespace Ui {
class aftersale;
}

class aftersale : public QMainWindow
{
    Q_OBJECT

public:
    explicit aftersale(QWidget *parent = 0);
    ~aftersale();
    void afficher();
    QString afficher_date();
    void pdf(QString );
    void notification();
    void statistique();
   void on_pushButton_8_clicked();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_pressed();

    void on_pushButton_8_pressed();

    void on_recherche_textChanged(const QString &arg1);


private:
    Ui::aftersale *ui;
    QSystemTrayIcon *n;
};

#endif // AFTERSALE_H
