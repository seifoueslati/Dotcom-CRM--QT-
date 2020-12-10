#include "gestproduit.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSql>




double gestproduit::getReduction() const
{
    return reduction;
}

void gestproduit::setReduction(const double &value)
{
    reduction = value;
}

QString gestproduit::getImage() const
{
    return image;
}

void gestproduit::setImage(const QString &value)
{
    image = value;
}

QString gestproduit::getQntv() const
{
    return qntv;
}

void gestproduit::setQntv(const QString &value)
{
    qntv = value;
}

gestproduit::gestproduit()
{
    reference="" ;
    scoreC="" ;
    scoreE="" ;
    qnt="" ;
     qntv="" ;
    date ="";
    prix ="";
    nom="" ;
    reduction=0 ;
     image="";
}
bool gestproduit::ajouterproduit ( QString ref , QString sC, QString sE, QString qt ,QString qtv , QString dat , QString prix ,  QString nm ,QString img )
{

    QSqlQuery *qry=new QSqlQuery(QSqlDatabase::defaultConnection);
    qry->prepare("insert into PRODUITS (REFRENCE,SCORECLIENT,SCOREEMPLOYE,QUANTITE,QUANTITE_VENDUE,DATEPRODUIT,PRIX,NOM,IMAGE) values('"+ref+"','"+sC+"','"+sE+"','"+qt+"','"+qtv+"','"+dat+"','"+prix+"','"+nm+"','"+img+"')");
    if (qry->exec())
    {
        qDebug()<<"done";
        return true ;
    }

    else
    {
        qDebug()<<"nope"<<" "<<qry->lastError();
        return false ;
    }
}
void gestproduit::affichertableview(QTableView *q)
{
    QSqlQuery *qry=new QSqlQuery(QSqlDatabase::defaultConnection);
    QSqlQueryModel *model=new QSqlQueryModel;
    qry->prepare("select * from PRODUITS");
    if (qry->exec())
    {
        qDebug()<<"done";
        model->setQuery(*qry);
        q->setModel(model);

    }
    else
    {
        qDebug()<<"erreur";

    }
}

void gestproduit::supprimer()
{
    QSqlQuery qry ;
    qry.prepare("DELETE from PRODUITS where refrence= ?");
    qry.addBindValue(this->reference);
    qry.exec();
}

void gestproduit::modifier()
{QSqlQuery qry ;


    qry.prepare("UPDATE PRODUITS SET QUANTITE =?,PRIX=? WHERE refrence=? ");
    qry.addBindValue(qnt);


    qry.addBindValue(prix.toDouble());
    qry.addBindValue(reference);
    qry.exec();
    qDebug()<<"ref"<<reference;
    qDebug()<<qry.lastError();
}

void gestproduit::reduire_prix()
{QSqlQuery qry ;
    qry.prepare("UPDATE PRODUITS SET PRIX=? WHERE refrence= ?");
   // qry.bindValue(0,(qnt));

    qry.addBindValue(prix.toDouble());
    qDebug()<<"prix"<<prix;
    qry.addBindValue(reference);
    qry.exec();
    qDebug()<<"ref"<<reference;
       qDebug()<<qry.lastError();
}

void gestproduit::tri(QTableView *p)
{
    QString queryStr("Select * from PRODUITS order by REFRENCE");
    QSqlQuery* query=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;
    query->prepare(queryStr);
    if (query->exec())
    {
        qDebug()<<"done";
        model->setQuery(*query);
        p->setModel(model);

    }
    else
    {
        qDebug()<<"erreur";

    }
}
void gestproduit::rechercher (QString a,QTableView *g)
{

    QSqlQuery qry;

    QSqlQueryModel *m = new QSqlQueryModel();// initialisation

    qry.prepare("SELECT * FROM PRODUITS WHERE REFRENCE like '%"+a+"%' OR DATEPRODUIT like'%"+a+"%' OR NOM like '%"+a+"%'" );// select base
    qry.exec();


    m->setQuery(qry);
    g->setModel(m);
}

QSqlQueryModel *gestproduit::get_images()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.exec("select refrence,image from PRODUITS   order by DATEPRODUIT   ");
    model->setQuery(query);
    return model;
}

void gestproduit::fetch_product_data_by_ref(QString ref)
{

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from PRODUITS where refrence=:ref ");
    query.bindValue(":ref",ref);
    query.exec();
    model->setQuery(query);
//    ref=model->data(model->index(i,0),Qt::DisplayRole).toString();
//    img=model->data(model->index(i,1),Qt::DisplayRole).toString();
    this->nom=model->data(model->index(0,7),Qt::DisplayRole).toString();
    this->prix=model->data(model->index(0,6),Qt::DisplayRole).toString();
    this->scoreC=model->data(model->index(0,1),Qt::DisplayRole).toString();
    this->scoreE=model->data(model->index(0,2),Qt::DisplayRole).toString();
    this->qnt=model->data(model->index(0,3),Qt::DisplayRole).toString();
    this->qntv=model->data(model->index(0,4),Qt::DisplayRole).toString();
    this->date=model->data(model->index(0,5),Qt::DisplayRole).toString();



}

void gestproduit::imprimer()
{ this->printer= new QPrinter();
    QPrintDialog * printer_dialog =new QPrintDialog(printer);
    if (printer_dialog->exec() == QDialog::Accepted) {
        QPainter *painter = new QPainter(printer);}}



QVector<double> gestproduit::NBProduit(QString annee)
{
    QString smois;
    QVector<double> nb;
    QVector<QString>mois;
    mois<<"01/"<<"02/"<<"03/"<<"04/"<<"05/"<<"06/"<<"07/"<<"08/"<<"09/"<<"10/"<<"11/"<<"12/";
    QSqlQuery query;
    for(int i=0;i<12;i++){
        smois=mois[i]+annee;
        query.prepare("SELECT COUNT(*) FROM PRODUITS WHERE TO_CHAR(DATEPRODUIT,'MM/YYYY')=:mois");
        query.bindValue(":mois",smois);
        query.exec();
        query.first();
        nb.push_back(query.value(0).toInt());
    }

     return  nb;
}






























