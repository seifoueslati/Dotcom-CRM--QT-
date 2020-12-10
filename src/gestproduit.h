#ifndef GESTPRODUIT_H
#define GESTPRODUIT_H
#include <QString>
#include <QTableView>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <vector>


class gestproduit
{
    QString reference ;
    QString scoreC ;
    QString scoreE ;
    QString qnt ;
    QString qntv ;
    QString date ;
    QString prix ;
    QString nom ;
    double reduction ;
    QString image;
    QPrinter *printer;
public:
    gestproduit();
    gestproduit ( QString ,QString ,QString ,QString ,QString , QString , QString , QString );
    void setreference (QString r) {reference=r ; }
    void setnom (QString n) {nom=n;}
    void setdate (QString dt) {date =dt;}
    void setprix (QString prix) {this->prix=prix;}
    void setscoreC (QString scoreC) {this->scoreC=scoreC;}
    void setscoreE (QString scoreE) {this->scoreE=scoreE;}
    void setqnt(QString qnt) {this->qnt =qnt;}
    QString getreference () {return reference ;}
    QString getnom () {return nom;}
    QString getprix () {return prix;}
    QString getqnt () {return qnt;}

    QString getScoreC() {return scoreC;}
    QString getScoreE() {return scoreE;}

    QVector<double> NBProduit(QString annee);
    QString getdate () {return date;}
    bool ajouterproduit (QString , QString , QString , QString , QString , QString , QString , QString, QString img);
    void affichertableview(QTableView*);
    void supprimer();
    void modifier();
    void reduire_prix();
    void tri(QTableView*);
    void rechercher (QString a,QTableView *g);
    static QSqlQueryModel * get_images();
    void fetch_product_data_by_ref(QString ref);
    void imprimer ();
    bool Ajouter(QString , QString , QString , QString , QString , QString , QString , QString, QString img);

    double getReduction() const;
    void setReduction(const double &value);
    QString getImage() const;
    void setImage(const QString &value);

    QString getQntv() const;
    void setQntv(const QString &value);
};

#endif // GESTPRODUIT_H
