#include "aftersale.h"
#include "ui_aftersale.h"
#include <QCoreApplication>
#include <QtSql>
#include <iostream>
#include <QString>
#include<time.h>
#include <QDialog>
#include <qdialog.h>
#include <ctime>
#include <QLineEdit>
#include "QPixmap"
#include<QImage>
#include<raport.h>
#include<QMessageBox>
#include <QtWidgets>
#include <QPrinter>
#include<QSqlQuery>
#include <QSharedPointer>
#include<QSharedDataPointer>
#include<qsharedpointer.h>
#include<qcustomplot.h>
#include <QPrinter>
#include <QtSerialPort/QtSerialPort>
#include<QPrintDialog>
#include <QtNetwork>
#include <smtp.h>
#include "QPixmap"
#include<QSystemTrayIcon>
#include<QImage>


aftersale::aftersale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aftersale)
{   
    n= new QSystemTrayIcon(this);
    n->show();
    n->setIcon(QIcon("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/support/tm.png"));
    ui->setupUi(this);
    QPixmap pix("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/bgg.png");
      ui->label_5->setPixmap(pix.scaled(1080,660,Qt::IgnoreAspectRatio));
        ui->label_8->setPixmap(pix.scaled(1080,660,Qt::IgnoreAspectRatio));
         ui->label_7->setPixmap(pix.scaled(1080,660,Qt::IgnoreAspectRatio));
QPixmap pix1("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/support/add.png");
ui->label_9->setPixmap(pix1.scaled(130,50,Qt::IgnoreAspectRatio));
ui->pushButton->setStyleSheet("QPushButton{background: transparent;}");

QPixmap pix2("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/support/modify.png");
ui->label_10->setPixmap(pix2.scaled(130,50,Qt::IgnoreAspectRatio));
ui->pushButton_3->setStyleSheet("QPushButton{background: transparent;}");

QPixmap pix3("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/support/delete.png");
ui->label_11->setPixmap(pix3.scaled(130,50,Qt::IgnoreAspectRatio));
ui->pushButton_2->setStyleSheet("QPushButton{background: transparent;}");

QPixmap pix4("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/support/statistics.png");
ui->label_12->setPixmap(pix4.scaled(60,60,Qt::IgnoreAspectRatio));
ui->pushButton_4->setStyleSheet("QPushButton{background: transparent;}");

QPixmap pix5("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/support/imp");
ui->label_13->setPixmap(pix5.scaled(90,90,Qt::IgnoreAspectRatio));
ui->pushButton_5->setStyleSheet("QPushButton{background: transparent;}");

QPixmap pix6("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/support/pdf");
ui->label_14->setPixmap(pix6.scaled(90,90,Qt::IgnoreAspectRatio));
ui->pushButton_6->setStyleSheet("QPushButton{background: transparent;}");

QPixmap pix7("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/support/maill");
ui->label_15->setPixmap(pix7.scaled(90,90,Qt::IgnoreAspectRatio));
ui->pushButton_7->setStyleSheet("QPushButton{background: transparent;}");

QPixmap pix8("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/support/Go");
ui->label_16->setPixmap(pix8.scaled(75,75,Qt::IgnoreAspectRatio));
ui->pushButton_8->setStyleSheet("QPushButton{background: transparent;}");

QPixmap pix9("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/support/Go");
ui->label_20->setPixmap(pix9.scaled(75,75,Qt::IgnoreAspectRatio));
ui->pushButton_10->setStyleSheet("QPushButton{background: transparent;}");

}


aftersale::~aftersale()
{
    delete ui;
}


QString aftersale::afficher_date()
{
    time_t temps;
struct tm date;
time(&temps);
date=*localtime(&temps);
return asctime(&date);

}


void aftersale::notification(){
    QSqlQuery q;
    QString a;
    q.prepare("SELECT ref_produit, count(ref_produit) nbr FROM tab_rapport GROUP BY ref_produit ORDER BY nbr DESC")  ;
    if(q.exec()){
    while (q.next()) {a=q.value(0).toString();break;
}}
        n->showMessage("reclamation !!","le produit qui a causé le plus de reclamation est de reference : "+a,QSystemTrayIcon::Information,1200000);


}

void aftersale:: pdf(QString x)  {


QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

QPrinter printer(QPrinter::PrinterResolution);
printer.setOutputFormat(QPrinter::PdfFormat);
printer.setPaperSize(QPrinter::A4);
printer.setOutputFileName(fileName);

QTextDocument doc;
doc.setHtml(x);
doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
doc.print(&printer);
}

void aftersale::afficher(){
    raport r;
    QSqlQueryModel * model=r.afficher_table();

    ui->tableView-> setModel(model);

}


void aftersale::on_pushButton_clicked()
{
    QPixmap pix1("/support/add.png");
    ui->label_9->setPixmap(pix1.scaled(125,45,Qt::IgnoreAspectRatio));
  QString dat=afficher_date();
  QString CIN=ui->cin->text();
  QString nom=ui->nom->text();
  QString rapport=ui->rapport->toPlainText();
  QString ref_produit=ui->ref->text();
  QString prenom=ui->prenom->text();
  raport r(nom,prenom ,CIN,rapport,ref_produit,dat);
  if(ref_produit!=""){
  if(r.ajouter_rapport()){
       QMessageBox::information(this,"reclamation ajoutee","reclamation ajoutee");

       afficher();
  }
  else
QMessageBox::critical(this,"reclamation","probleme ajout verifier informations il faut saisir cin+ref");

}
  else
QMessageBox::critical(this,"reclamation","probleme ajout verifier informations il faut saisir cin+ref");

  ui->label_9->setPixmap(pix1.scaled(130,50,Qt::IgnoreAspectRatio));
}




void aftersale::on_pushButton_2_clicked()
{
    QPixmap pix2("/support/modify.png");
    ui->label_10->setPixmap(pix2.scaled(125,45,Qt::IgnoreAspectRatio));

    QString dat=afficher_date();
    QString CIN=ui->cin->text();
    QString nom=ui->nom->text();
    QString rapport=ui->rapport->toPlainText();
    QString ref_produit=ui->ref->text();
    QString prenom=ui->prenom->text();
    raport r(nom,prenom ,CIN,rapport,ref_produit,dat);
    if(r.modifier_rapport() && CIN!="" ){
         QMessageBox::information(this,"reclamation ","reclamation modifiee");
         afficher();
    }
    else
  QMessageBox::critical(this,"reclamation","probleme modification verifier informations");
 ui->label_10->setPixmap(pix2.scaled(130,50,Qt::IgnoreAspectRatio));
}




void aftersale::on_pushButton_3_clicked()
{QPixmap pix3("/support/delete.png");
    ui->label_11->setPixmap(pix3.scaled(125,45,Qt::IgnoreAspectRatio));
    QString CIN =ui->cin->text()  ;
     QString ref_produit =ui->ref->text()  ;
     raport r;
     if(r.supprimer_rapport(CIN,ref_produit)==true){
         QMessageBox::information(this,"reclamation ","reclamation supprimee");
         afficher();
    }
    else
  QMessageBox::critical(this,"reclamation","probleme suppression veuillez saisir cin+ref_produit");
     ui->label_11->setPixmap(pix3.scaled(130,50,Qt::IgnoreAspectRatio));
}

void aftersale::on_tableView_clicked(const QModelIndex &index)
{
    QString a=ui->tableView->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("select * from TAB_RAPPORT where DATE_RAPPORT='"+a+"' OR NOM='"+a+"' OR PRENOM='"+a+"' OR REF_PRODUIT='"+a+"' OR CIN='"+a+"'OR RAPPORT='"+a+"'")  ;

    if(q.exec()){
    while (q.next()) {
     ui->cin->setText(q.value(0).toString());

     ui->ref->setText(q.value(3).toString());


    }}
    ;
}




void aftersale::on_lineEdit_5_textChanged(const QString &arg1)
{
    QString a=arg1;

    raport r;
   QSqlQueryModel * model=r.recherche(a);
    ui->tableView-> setModel(model);

}

void aftersale::on_tableView_activated(const QModelIndex &index)
{ raport r;
     QString v=ui->tableView->model()->data(index).toString();
    QString a=r.afficher_rapport(v);
            ui->plainTextEdit->setPlainText(a);
     ui->tabWidget->setCurrentIndex(1);
}

void aftersale::on_pushButton_5_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dia(&printer,this);
    if(dia.exec()==QDialog::Rejected)return;
    ui->plainTextEdit->print(&printer);

}

void aftersale::on_pushButton_6_clicked()
{
    pdf(ui->plainTextEdit->toPlainText());

}

void aftersale::on_pushButton_7_clicked()
{
    Smtp* smtp = new Smtp("tmcozoom@gmail.com","tmco123456","smtp.gmail.com");
        smtp->sendMail("tmcozoom@gmail.com","youssef.hamila@esprit.tn","reclamation ","votre reclamation a bien été traitée vous recevrez une réponse dans les plus brefs délais");
 QMessageBox::information(this,"reclamation ","e-mail envoye ");
}
void aftersale ::statistique(){
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->widget->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *regen = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);

    regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders


    // set names and colors:

    regen->setName("nb reclamation");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));



    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> regenData;


    ticks << 1 << 2 << 3 << 4 << 5 ;
    QSqlQuery q;
    q.prepare("SELECT ref_produit, count(ref_produit) nbr FROM tab_rapport GROUP BY ref_produit ORDER BY NBR DESC ")  ;

    if(q.exec()){
    while (q.next()) {
    labels << q.value(0).toString();
    regenData   << q.value(1).toDouble();;
    }}
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->widget->xAxis->setTicker(textTicker);

    ui->widget->xAxis->setTickLabelRotation(60);

    ui->widget->xAxis->setTickLength(0, 4);
    ui->widget->xAxis->setRange(0, 5);
    ui->widget->xAxis->setLabel("reference produit");

    ui->widget->xAxis->setBasePen(QPen(Qt::white));
    ui->widget->xAxis->setTickPen(QPen(Qt::white));
    ui->widget->xAxis->grid()->setVisible(true);
    ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->widget->xAxis->setTickLabelColor(Qt::white);
    ui->widget->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->widget->yAxis->setRange(0, 8);
    ui->widget->yAxis->setPadding(5); // a bit more space to the left border
    ui->widget->yAxis->setLabel("nombre de reclamation pour chaque produit");
    ui->widget->yAxis->setBasePen(QPen(Qt::white));
    ui->widget->yAxis->setTickPen(QPen(Qt::white));
    ui->widget->yAxis->setSubTickPen(QPen(Qt::white));
    ui->widget->yAxis->grid()->setSubGridVisible(true);
    ui->widget->yAxis->setTickLabelColor(Qt::white);
    ui->widget->yAxis->setLabelColor(Qt::white);
    ui->widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:


    regen->setData(ticks, regenData);

    // setup legend:
    ui->widget->legend->setVisible(true);
    ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->widget->legend->setBrush(QColor(255, 255, 255, 100));
    ui->widget->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->widget->legend->setFont(legendFont);
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void aftersale::on_pushButton_4_clicked()
{

  statistique();
    ui->tabWidget->setCurrentIndex(2);

}

void aftersale::on_pushButton_8_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}


void aftersale::on_pushButton_10_pressed()
{
    ui->tabWidget->setCurrentIndex(0);
}

void aftersale::on_pushButton_8_pressed()
{
    ui->tabWidget->setCurrentIndex(0);
}

void aftersale::on_recherche_textChanged(const QString &arg1)
{    QString a=arg1;

     raport r;
    QSqlQueryModel * model=r.recherche(a);
     ui->tableView-> setModel(model);

}
