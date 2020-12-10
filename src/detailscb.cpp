#include "detailscb.h"
#include "ui_detailscb.h"
#include "eml.h"
#include <QtSql>
DetailsCB::DetailsCB(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DetailsCB)
{


        //******************************************************

        ui->setupUi(this);
        QPixmap pix("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/detailsemployee");
            ui->label->setPixmap(pix.scaled(1080,720,Qt::KeepAspectRatio));
          // qDebug() <<xid;


            //******************************************************


}

DetailsCB::~DetailsCB()
{
    delete ui;
}

void DetailsCB::on_pushButton_10_clicked()
{
    edit=new AddCB(this);
    edit->show();
}

void DetailsCB::on_pushButton_12_clicked()
{
    this->hide();
}

void DetailsCB::on_pushButton_13_clicked()
{


}

void DetailsCB::on_sendm_clicked()
{
   QString aa=ui->label_6->text();
   QSqlQuery q2;
   q2.exec("truncate table EM");
   q2.exec("insert into EM values ('"+aa+"')");

    //ui->centralwidget->hide();
    edit1=new eml(this);
    edit1->show();
}
