#include "login.h"
#include "ui_login.h"
#include <QString>
#include <QApplication>
#include <QGuiApplication>
#include <QMessageBox>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/login");
       ui->BG_Aceuil->setPixmap(pix.scaled(800,800,Qt::KeepAspectRatio));
}

void login::verifier()
{

    c=new Clients(this);
    QString cin;
    cin=ui->Login->text();
    QString pass;
    pass=ui->MDP->text();
    QSqlQuery query1;
    QSqlQuery query2;
    query1.prepare("SELECT * FROM EMPLOYE where CIN='"+cin+"' and PASSWORD='"+pass+"'");
    query2.prepare("UPDATE EMPLOYE SET STATUS =1 where CIN='"+cin+"'");
    int nbr=0;
    query1.exec();
    if(query1.next())
    nbr=1;
    if(nbr==0)
    {
        QMessageBox msgBox;
        msgBox.setText("verifier LOGIN et PASSWORD");
        msgBox.exec();
   }
    else
    {
        query2.exec();
        c->show();
    }
}

login::~login()
{
    delete ui;
}

void login::on_Login_But_clicked()
{
    QSqlQuery query;
    query.exec("update EMPLOYE set STATUS='0'");
    verifier();
}
