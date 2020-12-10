#ifndef CLASSEMPLOYEB_H
#define CLASSEMPLOYE_H
#include <QString>
#include <QTableWidget>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>


class classemploye
{
    QString id;
    QString password;
    QString nom;
    QString prenom;
     long CIN;
    long tel;
    int score;
    QString mail;    
    QString departement;
    QPrinter *printer;

public:
    classemploye();
    ~classemploye();
    classemploye(QString,QString,QString,QString,long int,long int,QString,int,QString);

    bool Ajouter_Employe(QString, QString, int , int, QString, QString);
    void Afficher_Employe(QTableWidget *);
    void Supprimer_Employe();
    void Modifier_Employe(QString cin_amodifier);
    void Rechercher_Employe(QString,int type, QTableWidget *);
    void Imprimer_Employe();
    void Top_Employe(QTableWidget *);

    void Setnom(QString nom){this->nom=nom;}
    void Setprenom(QString prenom){this->prenom=prenom;}
    void SetCIN(int  CIN){this->CIN=CIN;}
    void Setid(QString id){this->id=id;}
    void Setpassword(QString password){this->password=password;}
    void Setmail(QString mail){this->mail=mail;}
    void Settel(int  tel){this->tel=tel;}
    void Setscore(int  score){this->score=score;}
    void Setdepartement(QString departement) {this->departement=departement;}

    QString Getnom(){return nom;}
    QString Getprenom(){return prenom;}
    int GetCIN(){return CIN;}
    QString Getid(){return id;}
    QString Getpasswrod(){return password;}
    QString Getmail(){return mail;}
    int Gettel(){return tel;}
    int Getscore(){return score;}
    QString Getdepartement(){return departement;}



};

#endif // CLASSEMPLOYEB_H
