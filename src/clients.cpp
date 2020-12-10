#include "clients.h"
#include "ui_clients.h"
#include "bdd.h"
#include "eml.h"
#include <QtWidgets>
#include <QApplication>
#include <QtCore>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QtSql>
#include <QGuiApplication>
#include <QQuickView>
#include <QResizeEvent>
#include <QtGui>
#include "smtp.h"
//#include "classemploye.h"
#include "employe.h"
#include <QTextStream>
#include <QTcpSocket>
#include <QComboBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>


Clients::Clients(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clients)
{

    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(3);


    gestclient gererclient;
    QSqlQuery query1;


    statistique("SELECT ID,SCORE FROM CLIENT ORDER BY SCORE",ui->CLIENT,"SCORE","ID CLIENT","SCORE DE CLIENT");
    statistique("SELECT DEPARTEMENT,COUNT(DEPARTEMENT) nbr FROM EMPLOYE group by DEPARTEMENT ORDER BY nbr",ui->EMPLOYE,"NOMBRE ","DEPARTEMENT","NBR EMPLOYE/DEPARTEMENT");
    statistique("SELECT ref_produit, count(ref_produit) nbr FROM tab_rapport GROUP BY ref_produit ORDER BY NBR DESC ",ui->AFTERSALE,"PRODUIT","REF PRODUIT","QTE/PRODUIT" );
   // statistique("SELECT REF,QTE FROM PRODUIT ORDER BY QTE",ui->PRODUIT);
    QPixmap pix2("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/bgg");
    QPixmap pix("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/clientse");
     ui->label_3->setPixmap(pix.scaled(1080,720,Qt::KeepAspectRatio));
      ui->label_7->setPixmap(pix2.scaled(1080,720,Qt::KeepAspectRatio));
chargertable();

}



Clients::~Clients()
{
    delete ui;
}

//***********************************************************************
void Clients::find()
{
int a;

    QString sh=ui->lineEdit->text();
       if(ui->combo->currentText()=="ID")
     a=1;

      else if(ui->combo->currentText()=="NAME")
      a=2;


       else if(ui->combo->currentText()=="E-MAIL")
     a=3;

    ui->tableWidget->clear();

    gestclient gererclient;
    gererclient.recha(sh,a,ui->tableWidget);


}

void Clients::chargertable()
{

    ui->tableWidget->setRowCount(25);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ui->tableWidget->setHorizontalHeaderLabels(QString("CIN;NOM;TEL;E-MAIL").split(";"));
       QSqlQuery query1;

       query1.prepare("SELECT * FROM CLIENT order by(NOM)");
       query1.exec();
          int i=0;
                     while (query1.next()) {

                            QString id = query1.value(0).toString();
                             ui->tableWidget->setItem(i,0,new QTableWidgetItem(id));
                            QString nom = query1.value(1).toString();
                             ui->tableWidget->setItem(i,1,new QTableWidgetItem(nom));
                             QString tel = query1.value(4).toString();
                              ui->tableWidget->setItem(i,2,new QTableWidgetItem(tel));
                             QString ml = query1.value(5).toString();
                              ui->tableWidget->setItem(i,3,new QTableWidgetItem(ml));
                              i++;
                        }
}

void Clients::afficher_detclients(int row)
{
    QString xid=ui->tableWidget->item(row,0)->text();
    ui->tabWidget->setCurrentIndex(1);

    QPixmap pix("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/detailsemployee");
     ui->label_6->setPixmap(pix.scaled(1080,720,Qt::KeepAspectRatio));
 QString id=xid ;


     QSqlQuery query2;

                  query2.prepare("select * from CLIENT where ID='"+id+"'");
                  query2.exec();
         while (query2.next()) {

                 QString nom = query2.value(1).toString();
                 QString pic = query2.value(2).toString();
                 QString score = query2.value(3).toString();
                 QString tel = query2.value(4).toString();
                 QString mail = query2.value(5).toString();
                 QPixmap pix2(pic);
                 gestclient gererclient;
                 gererclient.afficherhistorique(ui->historique,xid);
                 ui->showpic->setPixmap(pix2.scaled(91,91,Qt::KeepAspectRatio));
                 ui->showscore->setText("  "+score);
                 ui->showname->setText("NAME: "+nom);
                 ui->showtel->setText("TEL: "+tel);
                 //ui->show->setText(mail);

            }




}


//***********************************************************************


void Clients::ajout()
{
    QString name=ui->linename->text();
    QString id=ui->lineid->text();
    QString email=ui->lineadr->text();
    QString prenom=ui->linesurname->text();
    QString tel=ui->lineEdit_5->text();
    gestclient gererclient;
    gererclient.ajout(id,name,email,prenom,tel);
}


void Clients::modifier()
{

    QString name=ui->linename->text();
    QString id=ui->lineid->text();
    QString email=ui->lineadr->text();
    QString prenom=ui->linesurname->text();
    QString tel=ui->lineEdit_5->text();;
    gestclient gererclient;
    gererclient.mod(id,name,email,prenom,tel);

}

void Clients::supprimer()
{

    QString id=ui->lineid->text();


}

void Clients::on_lineEdit_editingFinished()
{


find();
}

void Clients::on_gestclientclient0_clicked()
{

    ui->tabWidget->setCurrentIndex(2);
}


void Clients::on_chargertabclient0_clicked()
{

chargertable();
}

void Clients::on_mailclient0_clicked()
{
    edit1=new eml(this);
    edit1->show();
}

void Clients::sendMail()
{
    Smtp* smtp = new Smtp("testbasededo@gmail.com","dollaichamolla", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("testbasededo@gmail.com", ui->lineadr->text()  ,"welcome","welcome to TM");
}


void Clients::topdf()
{
    gestclient gererclient;
    gererclient.exprt(ui->tableWidget);
}

void Clients::on_exportpdfclient0_clicked()
{
   topdf();
}

void Clients::on_clienttop3client0_clicked()//top 3
{



    QSqlQuery query1;

    //**********************************************

QQuickView *view = new QQuickView;
view->setSource(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + QLatin1String("/Qt5_CinematicExperience.qml")));
view->show();
    //*********************************************************

      query1.prepare("SELECT * FROM table1 WHERE id=(SELECT id, MAX(num1+num2) FROM table2 limit 5)");
query1.exec();
    int i=0;

                  while (query1.next()) {

                         QString id = query1.value(0).toString();
                          ui->tableWidget->setItem(i,0,new QTableWidgetItem(id));
                         QString nom = query1.value(1).toString();
                          ui->tableWidget->setItem(i,1,new QTableWidgetItem(nom));

                            i++;
                     }
}

void Clients::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    QPixmap pix("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/detailsemployee");
     ui->label_6->setPixmap(pix.scaled(1080,720,Qt::KeepAspectRatio));
      ui->tabWidget->setCurrentIndex(1);

       afficher_detclients(index.row());

}

void Clients::on_editclientreturn_clicked()//return
{
    ui->tabWidget->setCurrentIndex(0);
}

void Clients::on_statbarclient4_clicked()//return
{
    ui->tabWidget->setCurrentIndex(0);
}

void Clients::on_bajout_clicked()
{
    ajout();
    sendMail();
}

void Clients::on_bmod_clicked()
{
    modifier();
}

void Clients::on_bsupp_clicked()
{
    supprimer();
}

void Clients::on_ret1_clicked()
{
     ui->tabWidget->setCurrentIndex(0);
}

void Clients::on_employebarclient0_clicked()
{

    emp=new Employe(this);
    emp->show();
    this->hide();
    emp->on_refresh_clicked();
}
//******************************************************

//******************************************************
void Clients::statistique(QString qmd,QCustomPlot *w,QString barre,QString titre,QString qte)
{


    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    w->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *regen = new QCPBars(w->xAxis, w->yAxis);
    regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    // set names and colors:

    regen->setName(barre);
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));



    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> regenData;


    ticks << 1 << 2 << 3 << 4 << 5 ;
    QSqlQuery q;
    q.prepare(qmd)  ;

    if(q.exec()){
    while (q.next()) {
    labels << q.value(0).toString();
    regenData   << q.value(1).toDouble();;
    }}
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    w->xAxis->setTicker(textTicker);

    w->xAxis->setTickLabelRotation(60);

    w->xAxis->setTickLength(0, 5);
    w->xAxis->setRange(0, 5);
    w->xAxis->setLabel(titre);

    w->xAxis->setBasePen(QPen(Qt::white));
    w->xAxis->setTickPen(QPen(Qt::white));
    w->xAxis->grid()->setVisible(true);
    w->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    w->xAxis->setTickLabelColor(Qt::white);
    w->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    w->yAxis->setRange(0, 100);
    w->yAxis->setPadding(1); // a bit more space to the left border
    w->yAxis->setLabel(qte);
    w->yAxis->setBasePen(QPen(Qt::white));
    w->yAxis->setTickPen(QPen(Qt::white));
    w->yAxis->setSubTickPen(QPen(Qt::white));
    w->yAxis->grid()->setSubGridVisible(true);
    w->yAxis->setTickLabelColor(Qt::white);
    w->yAxis->setLabelColor(Qt::white);
    w->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    w->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:


    regen->setData(ticks, regenData);

    // setup legend:
    w->legend->setVisible(true);
    w->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    w->legend->setBrush(QColor(255, 255, 255, 100));
    w->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    w->legend->setFont(legendFont);
    w->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}

void Clients::on_aftersaleclient_clicked()
{
    rec=new aftersale(this);
    rec->show();
    this->hide();
}

void Clients::on_statclient1_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
      statistique("SELECT ID,SCORE FROM CLIENT ORDER BY SCORE",ui->CLIENT,"SCORE","ID CLIENT","SCORE DE CLIENT");
}

void Clients::on_employeclient_clicked()
{
    emp=new Employe(this);
    emp->show();
    this->hide();
    emp->on_refresh_clicked();
}

void Clients::on_aftersaleclient4_clicked()
{
    rec=new aftersale(this);
    rec->show();
    this->hide();
}

void Clients::on_sendemailclient4_clicked()
{
    edit1=new eml(this);
    edit1->show();
}

void Clients::on_refreshstatclient4_clicked()
{
    statistique("SELECT ID,SCORE FROM CLIENT ORDER BY SCORE",ui->CLIENT,"SCORE","ID CLIENT","SCORE DE CLIENT");
    statistique("SELECT DEPARTEMENT,COUNT(DEPARTEMENT) nbr FROM EMPLOYE group by DEPARTEMENT ORDER BY nbr",ui->EMPLOYE,"NOMBRE ","DEPARTEMENT","NBR EMPLOYE/DEPARTEMENT");
    statistique("SELECT ref_produit, count(ref_produit) nbr FROM tab_rapport GROUP BY ref_produit ORDER BY NBR DESC ",ui->AFTERSALE,"PRODUIT","REF PRODUIT","QTE/PRODUIT" );
//    statistique("SELECT REF,QTE FROM PRODUIT ORDER BY QTE",ui->PRODUIT);
}

void Clients::on_clientbarclient0_clicked()
{
    ui->tabWidget->setCurrentIndex(0);

}

void Clients::on_clientbarclient4_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}



void Clients::on_prodbarclient0_clicked()
{
    prod=new produit(this);
    prod->show();
}

void Clients::on_mailclient2_clicked()
{
    edit1=new eml(this);
    edit1->show();
}

void Clients::on_editclient2_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void Clients::on_deleteclient2_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void Clients::on_produitbarclient2_clicked()
{
    prod=new produit(this);
    prod->show();
}

void Clients::on_statbarclient2_clicked()
{
    rec=new aftersale(this);
    rec->show();
}

void Clients::on_employebarclient2_clicked()
{
    emp=new Employe(this);
    emp->show();
  //  this->hide();
    emp->on_refresh_clicked();
}

void Clients::on_clientbarclient2_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void Clients::on_produitbarclient4_clicked()
{
    prod=new produit(this);
    prod->show();
}
/*
void Clients::on_tableWidget_clicked(const QModelIndex &index)
{

    ui->lineid->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(0).data().toString());
    ui->linename->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(1).data().toString());
    ui->lineEdit_5->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(2).data().toString());
    ui->lineadr->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(3).data().toString());
}*/
