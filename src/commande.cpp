#include "commande.h"

Commande::Commande()
{

    /*_________________________________________________Constractors________________________________________________*/

            CinClient=0;
            ReferenceProduit="";
            Test=0;
            DateAchat="";
        }

        Commande::Commande(int Numero,int CinClient,QString ReferenceProduit,int Test,QString DateAchat)
        {
            this->Numero=Numero;
            this->CinClient=CinClient;
            this->ReferenceProduit=ReferenceProduit;
            this->Test=Test;
            this->DateAchat=DateAchat;
        }

    //Commande::~Commande(){}

    //______________________________________________________________________________________________________________//
    /*
     *
     *
     *
     *
     *
     *
     */
    /*____________________________________________________CRUD________________________________________________________*/

        bool Commande::Ajouter()
        {
            QSqlQuery *SQLCommande=new QSqlQuery(QSqlDatabase::defaultConnection);
            QMessageBox Verification;
            Verification.setStandardButtons(QMessageBox::Yes);
            Verification.addButton(QMessageBox::No);
            Verification.setDefaultButton(QMessageBox::No);

            Verification.setWindowTitle("ADD COMMANDE");
            Verification.setText("Are you sure you want to ADD this COMMANDE ?");
            if(Verification.exec() == QMessageBox::Yes)
            {
                SQLCommande->prepare("INSERT INTO COMMANDE (CinClient,ReferenceProduit,Test,DateAchat) VALUES(?,?,?,?) ");
                SQLCommande->addBindValue(CinClient);
                SQLCommande->addBindValue(ReferenceProduit);
                SQLCommande->addBindValue(Test);
                SQLCommande->addBindValue(DateAchat);

                if (SQLCommande->exec())
                  {
                    qDebug()<<"Worked!";
                    return true ;
                  }
                  else
                  {
                    qDebug()<<"Error!";
                    return false ;
                  }
            }
            }



        bool Commande::Afficher(QTableWidget *TableCommande)
        {
            QSqlQuery *SQLCommande=new QSqlQuery(QSqlDatabase::defaultConnection);
            SQLCommande->prepare("select CLIENT.NOM,CLIENT.prenom,CLIENT.CIN,COMMANDE.NUMERO,COMMANDE.ReferenceProduit,COMMANDE.DATEACHAT,COMMANDE.TEST FROM CLIENT INNER JOIN COMMANDE ON(CLIENT.CIN=COMMANDE.CINCLIENT)");

            if (SQLCommande->exec())
            {

                qDebug()<<"Worked!";
                int i=0;

                while (SQLCommande->next()==true)
                {
                  TableCommande->setRowCount(5+i);

                  QString nom = SQLCommande->value(0).toString();
                  TableCommande->setItem(i,0,new QTableWidgetItem(nom));

                  QString prenom = SQLCommande->value(1).toString();
                  TableCommande->setItem(i,1,new QTableWidgetItem(prenom));

                  QString CinClient = SQLCommande->value(2).toString();
                  TableCommande->setItem(i,2,new QTableWidgetItem(CinClient));

                  QString NUMERO = SQLCommande->value(3).toString();
                  TableCommande->setItem(i,3,new QTableWidgetItem(NUMERO));

                  QString ReferenceProduit = SQLCommande->value(4).toString();
                  TableCommande->setItem(i,4,new QTableWidgetItem(ReferenceProduit));

                  QString DateAchat = SQLCommande->value(5).toString();
                  TableCommande->setItem(i,5,new QTableWidgetItem(DateAchat));

                  QString Test = SQLCommande->value(6).toString();
                  TableCommande->setItem(i,6,new QTableWidgetItem(Test));
                  i++;

                }
            }
        }

        void Commande::Supprimer()
        {
            QSqlQuery SQLCommande ;
            QMessageBox Verification;
            Verification.setStandardButtons(QMessageBox::Yes);
            Verification.addButton(QMessageBox::No);
            Verification.setDefaultButton(QMessageBox::No);

            Verification.setWindowTitle("DELETE COMMANDE");
            Verification.setText("Are you sure you want to DELETE this COMMANDE ?");

            if(Verification.exec() == QMessageBox::Yes)
            {
                SQLCommande.prepare("DELETE from COMMANDE where NUMERO=?");
                SQLCommande.addBindValue(Numero);
                SQLCommande.exec();
            }

        }

        void Commande::Modifier()

        {

           QSqlQuery SQLCommande ;
           QMessageBox Verification;
           Verification.setStandardButtons(QMessageBox::Yes);
           Verification.addButton(QMessageBox::No);
           Verification.setDefaultButton(QMessageBox::No);

           Verification.setWindowTitle("UPDATE COMMANDE");
           Verification.setText("Are you sure you want to UPDATE this COMMANDE ?");

           if(Verification.exec() == QMessageBox::Yes)
           {
               SQLCommande.prepare("UPDATE COMMANDE SET Test=? WHERE Numero = ? ");
               SQLCommande.addBindValue(Test);
               SQLCommande.addBindValue(Numero);
               SQLCommande.exec();
           }
        }

    //________________________________________________________________________________________________________________//
    /*
     *
     *
     *
     *
     *
     *
     */
    /*____________________________________________________Set________________________________________________________*/

        void Commande::SetCinClient (int CinClient)
        {
            this->CinClient=CinClient;
        }

        void Commande::SetReferenceProduit (QString ReferenceProduit)
        {
            this->ReferenceProduit=ReferenceProduit;
        }

        void Commande::SetTest(int Test)
        {
            this->Test=Test;
        }

    //________________________________________________________________________________________________________________//
    /*
     *
     *
     *
     *
     *
     *
     *
     *
     */
    /*____________________________________________________Get________________________________________________________*/

        int Commande::GetCinClient()
        {
            return CinClient;
        }

        QString Commande::GetReferenceProduit()
        {
            return ReferenceProduit;
        }

        QString Commande::GetEmail(QString CIN)
        {
            QSqlQuery SQLCommande;
            SQLCommande.prepare("select MAIL from CLIENT where (CIN = ?)");
            SQLCommande.addBindValue(CIN);
            SQLCommande.exec();
            if(SQLCommande.first())
            {
                return (SQLCommande.value(0).toString());
            }
        }

    //________________________________________________________________________________________________________________//
    /*
     *
     *
     *
     *
     *
     *
     *
     */
    /*____________________________________________________Utility________________________________________________________*/

        void Commande::Trier(QTableWidget *TableCommande,bool TriNom,bool TriDate)
        {
            int checked=0;

            QSqlQuery *SQLCommande=new QSqlQuery(QSqlDatabase::defaultConnection);

            if(TriNom==true)
            {
                SQLCommande->prepare("select CLIENT.NOM,CLIENT.prenom,CLIENT.CIN,COMMANDE.NUMERO,COMMANDE.ReferenceProduit,COMMANDE.DATEACHAT,COMMANDE.TEST FROM CLIENT INNER JOIN COMMANDE ON(CLIENT.CIN=COMMANDE.CINCLIENT) ORDER BY CLIENT.NOM");
                if (SQLCommande->exec())
                {

                    qDebug()<<"Worked!";
                    int i=0;

                    while (SQLCommande->next()==true)
                    {
                      TableCommande->setRowCount(5+i);

                      QString nom = SQLCommande->value(0).toString();
                      TableCommande->setItem(i,0,new QTableWidgetItem(nom));

                      QString prenom = SQLCommande->value(1).toString();
                      TableCommande->setItem(i,1,new QTableWidgetItem(prenom));

                      QString CinClient = SQLCommande->value(2).toString();
                      TableCommande->setItem(i,2,new QTableWidgetItem(CinClient));

                      QString ReferenceProduit = SQLCommande->value(3).toString();
                      TableCommande->setItem(i,3,new QTableWidgetItem(ReferenceProduit));

                      QString DateAchat = SQLCommande->value(4).toString();
                      TableCommande->setItem(i,4,new QTableWidgetItem(DateAchat));

                      QString Test = SQLCommande->value(5).toString();
                      TableCommande->setItem(i,5,new QTableWidgetItem(Test));
                      i++;
                    }
                }
                checked=1;

            }

            if(TriDate==true)
            {
                SQLCommande->prepare("select CLIENT.NOM,CLIENT.prenom,CLIENT.CIN,COMMANDE.NUMERO,COMMANDE.ReferenceProduit,COMMANDE.DATEACHAT,COMMANDE.TEST FROM CLIENT INNER JOIN COMMANDE ON(CLIENT.CIN=COMMANDE.CINCLIENT) ORDER BY COMMANDE.DATEACHAT");
                if (SQLCommande->exec())
                {

                    qDebug()<<"Worked!";
                    int i=0;

                    while (SQLCommande->next()==true)
                    {
                      TableCommande->setRowCount(5+i);

                      QString nom = SQLCommande->value(0).toString();
                      TableCommande->setItem(i,0,new QTableWidgetItem(nom));

                      QString prenom = SQLCommande->value(1).toString();
                      TableCommande->setItem(i,1,new QTableWidgetItem(prenom));

                      QString CinClient = SQLCommande->value(2).toString();
                      TableCommande->setItem(i,2,new QTableWidgetItem(CinClient));

                      QString ReferenceProduit = SQLCommande->value(3).toString();
                      TableCommande->setItem(i,3,new QTableWidgetItem(ReferenceProduit));

                      QString DateAchat = SQLCommande->value(4).toString();
                      TableCommande->setItem(i,4,new QTableWidgetItem(DateAchat));

                      QString Test = SQLCommande->value(5).toString();
                      TableCommande->setItem(i,5,new QTableWidgetItem(Test));
                      i++;
                    }
                }
                checked=1;
            }

            if(checked==0)
            {
                SQLCommande->prepare("select CLIENT.NOM,CLIENT.prenom,CLIENT.CIN,COMMANDE.NUMERO,COMMANDE.ReferenceProduit,COMMANDE.DATEACHAT,COMMANDE.TEST FROM CLIENT INNER JOIN COMMANDE ON(CLIENT.CIN=COMMANDE.CINCLIENT)");
                if (SQLCommande->exec())
                {

                    qDebug()<<"Worked!";
                    int i=0;

                    while (SQLCommande->next()==true)
                    {
                      TableCommande->setRowCount(5+i);

                      QString nom = SQLCommande->value(0).toString();
                      TableCommande->setItem(i,0,new QTableWidgetItem(nom));

                      QString prenom = SQLCommande->value(1).toString();
                      TableCommande->setItem(i,1,new QTableWidgetItem(prenom));

                      QString CinClient = SQLCommande->value(2).toString();
                      TableCommande->setItem(i,2,new QTableWidgetItem(CinClient));

                      QString ReferenceProduit = SQLCommande->value(3).toString();
                      TableCommande->setItem(i,3,new QTableWidgetItem(ReferenceProduit));

                      QString DateAchat = SQLCommande->value(4).toString();
                      TableCommande->setItem(i,4,new QTableWidgetItem(DateAchat));

                      QString Test = SQLCommande->value(5).toString();
                      TableCommande->setItem(i,5,new QTableWidgetItem(Test));
                      i++;
                    }
                }
            }

        }

        void Commande::Rechercher(QString a,QTableWidget *Table)
        {
            QSqlQuery *SQLCommande=new QSqlQuery(QSqlDatabase::defaultConnection);
            SQLCommande->prepare("SELECT * FROM COMMANDE where CinClient LIKE '%"+a+"%' ");

            if (SQLCommande->exec())
            {
                int i=0;

                while (SQLCommande->next()==true)
                {
                  Table->setRowCount(5+i);

                  QString nom = SQLCommande->value(0).toString();
                  Table->setItem(i,0,new QTableWidgetItem(nom));

                  QString prenom = SQLCommande->value(1).toString();
                  Table->setItem(i,1,new QTableWidgetItem(prenom));

                  QString CinClient = SQLCommande->value(2).toString();
                  Table->setItem(i,2,new QTableWidgetItem(CinClient));

                  QString ReferenceProduit = SQLCommande->value(3).toString();
                  Table->setItem(i,3,new QTableWidgetItem(ReferenceProduit));

                  i++;
                }
            }

        }

        void Commande::Imprimer()
        {
          this->printer= new QPrinter();
          QPrintDialog * printer_dialog =new QPrintDialog(printer);
          if (printer_dialog->exec() == QDialog::Accepted)
          {
            QPainter *painter = new QPainter(printer);
          }
        }

        QString Commande::CurrentTime()
        {
            time_t temps;
            struct tm date;

            time(&temps);
            date=*localtime(&temps);
            return asctime(&date);

}
