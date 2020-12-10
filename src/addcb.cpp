#include "addcb.h"
#include "ui_addcb.h"
#include "smtp.h"
#include <QtSql>
#include <QTextStream>


#include <QTcpSocket>
AddCB::AddCB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCB)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/editclient");
        ui->label->setPixmap(pix.scaled(800,800,Qt::KeepAspectRatio));
        connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(sendMail()));


}

AddCB::~AddCB()
{
    delete ui;
}


void AddCB::on_pushButton_clicked()
{
}

void AddCB::on_pushButton_2_clicked()
{


}

void AddCB::on_pushButton_3_clicked()
{

}


void AddCB::mailSent(QString status)
{
    if(status == "Message sent")
    QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "WELCOME \n e-mail sent!\n\n" ) );
}

void AddCB::on_pushButton_4_clicked()
{
}
