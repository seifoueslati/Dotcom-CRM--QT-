#ifndef GESTCLIENT_H
#define GESTCLIENT_H
#include <QString>
#include <QTableWidget>

class gestclient
{

    QString id;
    QString nom;
    QString prenom;
    QString tel;
    QString mail;
    int score;
public:
    gestclient();
    ~gestclient();
    gestclient(QString,QString,QString,QString,QString,int);
    void rech();
    void ajout(QString, QString, QString, QString, QString);
    void del(QString);
    void mod(QString,QString, QString, QString, QString);
    void recha(QString,int,QTableWidget *);
    void exprt(QTableWidget *);

    void Setnom(QString nom){this->nom=nom;}
    void Setprenom(QString prenom){this->prenom=prenom;}
    void Setid(QString id){this->id=id;}
    void Setmail(QString mail){this->mail=mail;}
    void Settel(QString  tel){this->tel=tel;}

    QString Getnom(){return nom;}
    QString Getprenom(){return prenom;}
    QString Getid(){return id;}
    QString Getmail(){return mail;}
    QString Gettel(){return tel;}

    void afficherhistorique(QTableWidget *, QString ID);
};

#endif // GESTCLIENT_H
