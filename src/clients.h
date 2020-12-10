#ifndef CLIENTS_H
#define CLIENTS_H
#include "gestclient.h"
#include "detailscb.h"
#include <QMainWindow>
#include <QResizeEvent>
#include "employe.h"
#include "aftersale.h"
#include"raport.h"
#include"produit.h"
#include <qcustomplot.h>
namespace Ui {
class Clients;
}

class Clients : public QMainWindow
{
    Q_OBJECT

public:
    explicit Clients(QWidget *parent = 0);

    ~Clients();


private slots:
    void statistique(QString, QCustomPlot *,QString,QString,QString);
    void chargertable();
    void afficher_detclients(int row);
    void find();
    void ajout();
    void supprimer();
    void modifier();
    void topdf();
    void sendMail();
    void on_lineEdit_editingFinished();
    //*************************************

    //*************************************
    void on_prodbarclient0_clicked();
    void on_chargertabclient0_clicked();
    void on_mailclient0_clicked();
    void on_exportpdfclient0_clicked();
    void on_clienttop3client0_clicked();
    void on_tableWidget_doubleClicked(const QModelIndex &index);
    void on_editclientreturn_clicked();
    void on_statbarclient4_clicked();
    void on_bajout_clicked();
    void on_bmod_clicked();
    void on_bsupp_clicked();

    void on_ret1_clicked();

    void on_employebarclient0_clicked();

    void on_aftersaleclient_clicked();

    void on_statclient1_clicked();

    void on_employeclient_clicked();

    void on_aftersaleclient4_clicked();

    void on_sendemailclient4_clicked();

    void on_refreshstatclient4_clicked();

    void on_clientbarclient0_clicked();

    void on_clientbarclient4_clicked();

    void on_gestclientclient0_clicked();

    //void on_pushButton_2_clicked();

    void on_mailclient2_clicked();

    void on_editclient2_clicked();

    void on_deleteclient2_clicked();

    void on_produitbarclient2_clicked();

    void on_statbarclient2_clicked();

    void on_employebarclient2_clicked();

    void on_clientbarclient2_clicked();

    void on_produitbarclient4_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    //void on_tableWidget_clicked(const QModelIndex &index);

private:
    Ui::Clients *ui;
    DetailsCB *details;
    AddCB *edit;
    eml *edit1;
    Employe *emp;
    aftersale *rec;
    produit *prod;


};

#endif // CLIENTS_H
