
#include "employe.h"
#include "ui_employe.h"
#include <QtSql>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include<qcustomplot.h>
#include <QMessageBox>
//#include <notification.h>

#include <QWidget>
Employe::Employe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Employe)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Lenovo/Desktop/template");
       ui->label->setPixmap(pix.scaled(1080,720,Qt::KeepAspectRatio));
    QPixmap pix1("C:/Users/Lenovo/Desktop/template");
       ui->pic->setPixmap(pix1.scaled(1080,720,Qt::KeepAspectRatio));
    QPixmap pix2("C:/Users/Lenovo/Desktop/template");
       ui->label_7->setPixmap(pix2.scaled(1080,720,Qt::KeepAspectRatio));
    QPixmap pix3("C:/Users/Lenovo/Desktop/template");
       ui->pic_2->setPixmap(pix3.scaled(1080,720,Qt::KeepAspectRatio));
    QPixmap pix4("C:/Users/Lenovo/Desktop/template");
          ui->label_22->setPixmap(pix4.scaled(1080,720,Qt::KeepAspectRatio));
          ui->notif_widget->hide();
          ui->recieved->hide();



       ui->tabWidget->setCurrentIndex(0);
       on_refresh_clicked();


       ui->tableWidget->setColumnCount(7);
       ui->tableWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
       ui->tableWidget->setHorizontalHeaderLabels(QString("NAME;SURNAME;PHONE;CIN;E-MAIL;DEPARTEMENT;SCORE").split(";"));
       ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

       ui->top3_table->setColumnCount(7);
       ui->top3_table->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
       ui->top3_table->setHorizontalHeaderLabels(QString("NAME;SURNAME;PHONE;CIN;E-MAIL;DEPARTEMENT;SCORE").split(";"));
       ui->top3_table->setSelectionBehavior(QAbstractItemView::SelectRows);
}

Employe::~Employe()
{
    delete ui;
}

void Employe::on_refresh_clicked()
{
    classemploye gereremploye;
    gereremploye.Afficher_Employe(ui->tableWidget);



}

void Employe::on_ajouter_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->name->clear();
    ui->surname->clear();
    ui->phone->clear();
    ui->cin->clear();
    ui->email->clear();
    ui->departement->clear();
    ui->message->clear();

}

void Employe::on_cancel_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void Employe::on_add_clicked()

{

    classemploye gereremploye;
    if (gereremploye.Ajouter_Employe(ui->name->text(),ui->surname->text(),ui->phone->text().toInt(),ui->cin->text().toInt(),ui->email->text(),ui->departement->text()))
    {

        QMessageBox msgBox;
        msgBox.setText("L'employé a été ajouté avec succes");
        msgBox.exec();



        ui->message->clear();
        ui->tabWidget->setCurrentIndex(0);
        ui->recieved->show();
        //notification *n;
        //n->setPopupText("client ajouté");
        //n->show();



     on_refresh_clicked();

    }
    else
    {
    ui->message->setText("Veuillez revérifier les champs");
    }


}


void Employe::on_return_2_clicked()
{
     ui->tabWidget->setCurrentIndex(0);
}

void Employe::on_modify_clicked()
{
    ui->tabWidget->setCurrentIndex(3);


}

void Employe::on_tableWidget_clicked(const QModelIndex &index)
{
    ui->tabWidget->setCurrentIndex(2);

    ui->name_3->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(0).data().toString());
    ui->surname_3->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(1).data().toString());
    ui->phone_3->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(2).data().toString());
    ui->cin_3->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(3).data().toString());
    ui->email_3->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(4).data().toString());
    ui->departement_3->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(5).data().toString());
     ui->score_3->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(6).data().toString());

    ui->name_2->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(0).data().toString());
    ui->surname_2->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(1).data().toString());
    ui->phone_2->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(2).data().toString());
    ui->cin_2->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(3).data().toString());
    ui->email_2->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(4).data().toString());
    ui->departement_2->setText(ui->tableWidget->selectionModel()->selectedIndexes().at(5).data().toString());





}

void Employe::on_delete_2_clicked()
{

    classemploye gereremployer;

    QMessageBox msgBox;
    msgBox.setWindowTitle("Delete Employee");
    msgBox.setText("Are you sure you want to delete this employee ?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
        gereremployer.SetCIN(ui->cin_2->text().toInt());
      gereremployer.Supprimer_Employe();
    ui->tableWidget->clear();
      ui->tabWidget->setCurrentIndex(0);
      this->on_refresh_clicked();




    }
    else {
         ui->message->clear();
    }




}


void Employe::on_cancel_2_clicked()
{
     ui->tabWidget->setCurrentIndex(2);
}

void Employe::on_save_clicked()
{

         classemploye gereremploye;
         QMessageBox msgBox;
         msgBox.setWindowTitle("Modify Employee");
         msgBox.setText("Are you sure you want to modify this employee ?");
         msgBox.setStandardButtons(QMessageBox::Yes);
         msgBox.addButton(QMessageBox::No);
         msgBox.setDefaultButton(QMessageBox::No);
         if(msgBox.exec() == QMessageBox::Yes){
             gereremploye.Setnom(ui->name_2->text());
             gereremploye.Setprenom(ui->surname_2->text());
             gereremploye.Settel(ui->phone_2->text().toInt());
             gereremploye.SetCIN(ui->cin_3->text().toInt());
             gereremploye.Setmail(ui->email_2->text());
             gereremploye.Setdepartement(ui->departement_2->text());


             gereremploye.Modifier_Employe(ui->cin_2->text());


             ui->name_3->setText(ui->name_2->text());
             ui->surname_3->setText(ui->surname_2->text());
             ui->phone_3->setText(ui->phone_2->text());
             ui->cin_3->setText(ui->cin_3->text());
             ui->email_3->setText(ui->email_2->text());
             ui->departement_3->setText(ui->departement_2->text());



           ui->tabWidget->setCurrentIndex(2);
           on_refresh_clicked();



         }
         else {
              ui->message->clear();
         }




}

void Employe::on_rechercher_editingFinished()
{

    int type;
    QString a_rechercher=ui->rechercher->text();

    if(ui->type_recherche->currentText()=="CIN")
    {type=1;}

         else if(ui->type_recherche->currentText()=="PRENOM")
    { type=2;}


          else if(ui->type_recherche->currentText()=="DEPARTEMENT")
       { type=3;}


       ui->tableWidget->clear();

       classemploye gereremploye;
       gereremploye.Rechercher_Employe(a_rechercher,type,ui->tableWidget);
}

void Employe::on_print_clicked()
{
    this->printer= new QPrinter();
    QPainter *painter = new QPainter(printer);

    classemploye gereremploye;
    gereremploye.Imprimer_Employe();

    ui->tableWidget->render(painter);

}
void Employe::stat(){
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

       regen->setName("DEPARTEMENTS");
       regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
       regen->setBrush(QColor(0, 168, 140));



       // prepare x axis with country labels:
       QVector<double> ticks;
       QVector<QString> labels;
       QVector<double> regenData;


       ticks << 1 << 2 << 3 << 4 << 5 ;
       QSqlQuery q;
       q.prepare("SELECT departement, count(departement) nbr FROM employe GROUP BY departement ORDER BY NBR DESC ")  ;

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
       ui->widget->xAxis->setLabel("NOM DU DEPARTEMENT");

       ui->widget->xAxis->setBasePen(QPen(Qt::white));
       ui->widget->xAxis->setTickPen(QPen(Qt::white));
       ui->widget->xAxis->grid()->setVisible(true);
       ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
       ui->widget->xAxis->setTickLabelColor(Qt::white);
       ui->widget->xAxis->setLabelColor(Qt::white);

       // prepare y axis:
       ui->widget->yAxis->setRange(0, 8);
       ui->widget->yAxis->setPadding(5); // a bit more space to the left border
       ui->widget->yAxis->setLabel("NOMBRE D'E DEPARTEMENTS'EMPLOYES PAR DEPARTEMENT");
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





void Employe::on_statistics_clicked()
{
    stat();
    ui->tabWidget->setCurrentIndex(4);

}

void Employe::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(0);

}

void Employe::on_pushButton_2_clicked()
{
    ui->tabWidget->setCurrentIndex(5);

     classemploye gereremploye;
        gereremploye.Top_Employe(ui->top3_table);






}

void Employe::on_top3_table_clicked(const QModelIndex &index)
{
    ui->name_4->setText( ui->top3_table->selectionModel()->selectedIndexes().at(0).data().toString());
    ui->surname_4->setText( ui->top3_table->selectionModel()->selectedIndexes().at(1).data().toString());
    ui->phone_4->setText( ui->top3_table->selectionModel()->selectedIndexes().at(2).data().toString());
    ui->cin_4->setText( ui->top3_table->selectionModel()->selectedIndexes().at(3).data().toString());
    ui->email_4->setText( ui->top3_table->selectionModel()->selectedIndexes().at(4).data().toString());
    ui->departement_4->setText( ui->top3_table->selectionModel()->selectedIndexes().at(5).data().toString());
    ui->score_4->setText( ui->top3_table->selectionModel()->selectedIndexes().at(6).data().toString());

}


void Employe::on_notif_button_clicked()
{
    if(ui->notif_widget->isVisible()==true)
       {

          ui->notif_widget->hide();
          ui->notif_label->hide();
           ui->recieved->hide();
           ui->nb_notif->setText("!");


       }
       else
       {
           ui->notif_widget->show();


       }
}
