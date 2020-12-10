#include "gestclient.h"
#include <QtSql>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QTableWidget>
#include <QMessageBox>
gestclient::gestclient()
{
id="";
nom="";
prenom="";
tel="";
mail="";
score=0;
}

gestclient::gestclient (QString id,QString nom,QString prenom,QString tel,QString mail,int score)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->tel=tel;
    this->mail=mail;
    this->score=score;

}

gestclient::~gestclient(){}

void gestclient::ajout(QString id,QString nom ,QString email,QString prenom,QString tel)
{


    QSqlQuery query1;
    QMessageBox msgbox;
    msgbox.setText("client existant");
    query1.prepare("select count(ID) from CLIENT where ID='?' ");
    query1.bindValue(0,id);
    query1.exec();
    if(query1.value(0).toInt()==1) msgbox.exec();
    else {
    query1.prepare("INSERT INTO CLIENT (ID,NOM,TEL,MAIL,PRENOM) VALUES(?,?,?,?,?) ");
    query1.bindValue(0,id);
    query1.bindValue(1,nom);
    query1.bindValue(2,tel);
    query1.bindValue(3,email);
    query1.bindValue(4,prenom);
    query1.exec();
    }
}

void gestclient::afficherhistorique(QTableWidget *hist,QString ID){

    hist->setColumnCount(1);
    hist->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //hist->setHorizontalHeaderLabels(QString("REF"));
    QSqlQuery *afficher=new QSqlQuery(QSqlDatabase::defaultConnection);

         afficher->prepare("select * from HISTORIQUE where ID='"+ID+"'");


         if (afficher->exec())
         {
             qDebug()<<"done";
             int i=0;


                         while (afficher->next()==true)
                         {
                         hist->setRowCount(15+i);



                           QString refproduit = afficher->value(1).toString();
                           hist->setItem(i,0,new QTableWidgetItem(refproduit));


                                i++;
                          }

         }



}
void gestclient::del(QString id)
{

    QSqlQuery query1;
    query1.prepare("delete from CLIENT  where ID=?");
    query1.bindValue(0,id);
    query1.exec();
}

void gestclient::mod(QString id,QString nom,QString email,QString prenom,QString tel)
{
    QSqlQuery query1;

    query1.prepare("update CLIENT set NOM=? ,PRENOM=?,MAIL=?,TEL=? where ID=?");
    query1.bindValue(0,nom);
    query1.bindValue(1,prenom);
    query1.bindValue(2,email);
    query1.bindValue(3,tel);
    query1.bindValue(4,id);
    query1.exec();
}


void gestclient::recha(QString x,int a,QTableWidget *page)
{




    QSqlQuery query1;



       if(a==1)
      query1.exec("SELECT * FROM CLIENT where ID LIKE'%"+x+"%'");

      else if(a==2)
      query1.exec("SELECT * FROM CLIENT where NOM LIKE'%"+x+"%'");


       else if(a==3)
      query1.exec("SELECT * FROM CLIENT where MAIL LIKE'%"+x+"%'");
    int i=0;



                  while (query1.next()) {

                         QString id = query1.value(0).toString();
                          page->setItem(i,0,new QTableWidgetItem(id));
                         QString nom = query1.value(1).toString();
                          page->setItem(i,1,new QTableWidgetItem(nom));
                          QString tel = query1.value(4).toString();
                           page->setItem(i,2,new QTableWidgetItem(tel));
                           QString ml = query1.value(5).toString();
                            page->setItem(i,3,new QTableWidgetItem(ml));

                            i++;
                     }
}

void gestclient::exprt(QTableWidget *page)
{



    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
   // printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFileName("c:\\temp\\file.pdf");

    QTextDocument doc;
    QString style("<style>");
    style.append("table { border-collapse: collapse;font-size:10px; }");
    style.append("table, th, td { border: 1px solid black;text-align: left; }");
    //style.append("th, td { border: 1px solid black;text-align: left; }");
    style.append("</style>");

    QString text("<html><body background=z.jpg><h1><center><font color=green>LA LISTE DES CLIENTS</font></h1>");
    text.append("<br><center><table  border='1' cellspacing='5'><thead>");
    text.append("<tr>");
    for (int i = 0; i <  page->columnCount(); i++) {
        text.append("<th>").append( page->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i <  page->rowCount(); i++) {
        text.append("<tr>");
        for (int j = 0; j <  page->columnCount(); j++) {
            QTableWidgetItem *item =  page->item(i, j);
            if (!item || item->text().isEmpty()) {
                 page->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append( page->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setDefaultStyleSheet(style);
    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);



}
