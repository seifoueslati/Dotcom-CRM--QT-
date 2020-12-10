#include "eml.h"
#include "ui_eml.h"
#include <QtSql>
#include "smtp.h"

eml::eml(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::eml)
{

     ui->setupUi(this);
    QPixmap pix("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/a");
    ui->label->setPixmap(pix.scaled(1080,720,Qt::KeepAspectRatio));
    QSqlQuery q2;
    q2.exec("select * from EM");
     while (q2.next()) {
    QString a=q2.value(0).toString();
       ui->lineEdit->setText(a);
     }
     q2.exec("truncate table EM");


}

void eml::send()
{
    Smtp* smtp = new Smtp("testbasededo@gmail.com","dollaichamolla", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("testbasededo@gmail.com", ui->lineEdit->text() ,ui->lineEdit_2->text()+"\n",ui->textEdit->toPlainText());



}


eml::~eml()
{
    delete ui;
}

void eml::on_pushButton_clicked()
{
    send();
}

void eml::on_pushButton_2_clicked()
{
    this->hide();
}
