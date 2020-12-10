
#include "classemploye.h"
#include "ui_employe.h"
#include <QtSql>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QTableWidget>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QMessageBox>

classemploye::classemploye()
{
id="";
password="";
nom="";
prenom="";
CIN=0;
tel=0;
mail="";
score=0;
departement="";
}

classemploye::classemploye(QString id,QString password,QString nom,QString prenom,long int CIN,long int tel,QString mail,int score,QString departement)
{
    this->id=id;
    this->password=password;
    this->nom=nom;
    this->prenom=prenom;
    this->CIN=CIN;
    this->tel=tel;
    this->mail=mail;
    this->score=score;
    this->departement=departement;

}

classemploye::~classemploye(){}
bool classemploye::Ajouter_Employe(QString nom,QString prenom,int tel,int CIN,QString mail,QString departement)
{
  QSqlQuery *inserer=new QSqlQuery(QSqlDatabase::defaultConnection);







  inserer->prepare("INSERT INTO EMPLOYE (nom,prenom,tel,CIN,mail,departement) VALUES(?,?,?,?,?,?) ");
  inserer->addBindValue(nom);
  inserer->addBindValue(prenom);
  inserer->addBindValue(tel);
  inserer->addBindValue(CIN);
  inserer->addBindValue(mail);
  inserer->addBindValue(departement);

    if (inserer->exec())
        {

        qDebug()<<"done";

            return true ;
        }

    else
        {
             qDebug()<<"done";
             return false ;
        }

}
void classemploye::Afficher_Employe(QTableWidget *page)
{
    QSqlQuery *afficher=new QSqlQuery(QSqlDatabase::defaultConnection);

         afficher->prepare("select * from employe");


         if (afficher->exec())
         {
             qDebug()<<"done";
             int i=0;


                         while (afficher->next()==true)
                         {
                         page->setRowCount(i+1);


                           QString nom = afficher->value(0).toString();
                           page->setItem(i,0,new QTableWidgetItem(nom));

                           QString prenom = afficher->value(1).toString();
                           page->setItem(i,1,new QTableWidgetItem(prenom));

                           QString CIN = afficher->value(3).toString();
                           page->setItem(i,3,new QTableWidgetItem(CIN));

                           QString phone = afficher->value(2).toString();
                           page->setItem(i,2,new QTableWidgetItem(phone));

                           QString mail = afficher->value(4).toString();
                           page->setItem(i,4,new QTableWidgetItem(mail));

                           QString departement = afficher->value(5).toString();
                           page->setItem(i,5,new QTableWidgetItem(departement));

                           QString score = afficher->value(6).toString();
                           page->setItem(i,6,new QTableWidgetItem(score));


                                i++;
                          }

         }

}

void classemploye::Supprimer_Employe()
{
    QSqlQuery supprimer ;
    supprimer.prepare("DELETE from EMPLOYE where CIN= ?");
    supprimer.bindValue(0, QString::number(CIN));
    supprimer.exec();
}

void classemploye::Modifier_Employe(QString cin_amodifier)
{
    QSqlQuery modifier ;



           modifier.prepare("UPDATE EMPLOYE SET nom =?,prenom=?,tel=?,CIN=?,mail=?,departement=? WHERE CIN= '"+cin_amodifier+"'");
           modifier.bindValue(0,(nom));
           modifier.bindValue(1,(prenom));
           modifier.bindValue(2,QString::number(tel));
           modifier.bindValue(3,QString::number(CIN));
           modifier.bindValue(4,(mail));
           modifier.bindValue(5,(departement));

           modifier.exec();
}
void classemploye::Rechercher_Employe(QString item_recherche,int type,QTableWidget *page)
{
    QSqlQuery rechercher;



           if(type==1)
          rechercher.exec("SELECT * FROM EMPLOYE where CIN LIKE'%"+item_recherche+"%'");

          else if(type==2)
          rechercher.exec("SELECT * FROM EMPLOYE where prenom LIKE'%"+item_recherche+"%'");


           else if(type==3)
          rechercher.exec("SELECT * FROM EMPLOYE where departement LIKE'%"+item_recherche+"%'");
        int i=0;



                      while (rechercher.next()) {

                          QString nom = rechercher.value(0).toString();
                          page->setItem(i,0,new QTableWidgetItem(nom));

                          QString prenom = rechercher.value(1).toString();
                          page->setItem(i,1,new QTableWidgetItem(prenom));

                          QString CIN = rechercher.value(3).toString();
                          page->setItem(i,3,new QTableWidgetItem(CIN));

                          QString phone = rechercher.value(2).toString();
                          page->setItem(i,2,new QTableWidgetItem(phone));

                          QString mail = rechercher.value(4).toString();
                          page->setItem(i,4,new QTableWidgetItem(mail));

                          QString departement = rechercher.value(5).toString();
                          page->setItem(i,5,new QTableWidgetItem(departement));

                          QString score = rechercher.value(6).toString();
                          page->setItem(i,6,new QTableWidgetItem(score));


                                i++;
                         }
}
void classemploye::Imprimer_Employe()
{
    this->printer= new QPrinter();
       QPrintDialog * printer_dialog =new QPrintDialog(printer);
       if (printer_dialog->exec() == QDialog::Accepted)
       {QPainter *painter = new QPainter(printer);}
}




void classemploye::Top_Employe(QTableWidget *page)
{
    QSqlQuery *topemploye=new QSqlQuery(QSqlDatabase::defaultConnection);

         topemploye->prepare("select * from ( select * from EMPLOYE order by score desc ) where ROWNUM <= 3");


         if (topemploye->exec())
         {
             qDebug()<<"done";
             int i=0;


                         while (topemploye->next()==true)
                         {
                         page->setRowCount(3);


                           QString nom = topemploye->value(0).toString();
                           page->setItem(i,0,new QTableWidgetItem(nom));

                           QString prenom = topemploye->value(1).toString();
                           page->setItem(i,1,new QTableWidgetItem(prenom));

                           QString CIN = topemploye->value(3).toString();
                           page->setItem(i,3,new QTableWidgetItem(CIN));

                           QString phone = topemploye->value(2).toString();
                           page->setItem(i,2,new QTableWidgetItem(phone));

                           QString mail = topemploye->value(4).toString();
                           page->setItem(i,4,new QTableWidgetItem(mail));

                           QString departement = topemploye->value(5).toString();
                           page->setItem(i,5,new QTableWidgetItem(departement));

                           QString score = topemploye->value(6).toString();
                           page->setItem(i,6,new QTableWidgetItem(score));



                                i++;
                          }

         }

}


