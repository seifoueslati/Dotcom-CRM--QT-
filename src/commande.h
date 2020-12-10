#ifndef COMMANDE_H
#define COMMANDE_H
#include <ctime>
#include<time.h>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QTableView>
#include <QString>
#include <QtSql>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QPrintDialog>
#include "notification.h"
#include "QMessageBox"

class Commande
{
private :
    int CinClient;
    QString ReferenceProduit;
    QString DateAchat;
    QPrinter * printer;
    int Numero;
    int Test;

public:
/*_________________________________________________Constractors________________________________________________*/

    Commande();
    Commande(int,int,QString,int,QString);
    //Commande::~Commande();
//______________________________________________________________________________________________________________//
/*
*
*
*/
/*____________________________________________________CRUD________________________________________________________*/

    bool Ajouter();
    bool Afficher(QTableWidget *);
    void Supprimer();
    void Modifier();

//________________________________________________________________________________________________________________//
/*
*
*
*/
/*____________________________________________________Set________________________________________________________*/

    void SetCinClient(int);
    void SetReferenceProduit(QString );
    void SetTest(int);

//________________________________________________________________________________________________________________//
/*
*
*
*/
/*____________________________________________________Get________________________________________________________*/

    int GetCinClient();
    QString GetReferenceProduit();
    QString GetEmail(QString);

//________________________________________________________________________________________________________________//
/*
*
*
*/
/*____________________________________________________Utility________________________________________________________*/

    void Rechercher(QString ,QTableWidget *);
    void Imprimer();
    void Trier(QTableWidget *,bool,bool);
    QString CurrentTime();

//________________________________________________________________________________________________________________//



};

#endif // COMMANDE_H
