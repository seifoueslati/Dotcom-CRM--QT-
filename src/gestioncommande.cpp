#include "gestioncommande.h"
#include "ui_gestioncommande.h"

GestionCommande::GestionCommande(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionCommande)
{
    ui->setupUi(this);

    ui->ListeCommande->setColumnCount(8);
    ui->ListeCommande->setColumnWidth(5,150);
    ui->ListeCommande->setColumnWidth(1,150);
    ui->ListeCommande->setColumnWidth(2,150);
    ui->ListeCommande->setColumnWidth(3,150);
    ui->ListeCommande->setColumnWidth(4,150);
    ui->ListeCommande->setColumnWidth(6,150);
    ui->ListeCommande->setColumnWidth(7,150);
    ui->ListeCommande->setColumnWidth(0,150);
    ui->ListeCommande->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ui->ListeCommande->setHorizontalHeaderLabels(QString("CIN;Nom;Prenom;NumeroCommande;NumeroCommande;REF_PRO;DateAchat;Test").split(";"));
    ui->ListeCommande->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->StackedWidgetCommande->setCurrentIndex(0);

    Commande commande;
     notification *n = new notification;


    commande.Afficher(ui->ListeCommande);



}
GestionCommande::~GestionCommande()
{
    delete ui;
}



void GestionCommande::on_RechercheCommande_clicked()
{
    Commande C;
    if(ui->BarreRechercheCommande->text()!="")
    {
        ui->ListeCommande->clear();
        C.Rechercher(ui->BarreRechercheCommande->text(),ui->ListeCommande);
    }
    else
    {
        C.Afficher(ui->ListeCommande);
    }
}


void GestionCommande::on_TriButton_clicked()
{
    Commande C;
    ui->ListeCommande->clear();
    C.Trier(ui->ListeCommande,ui->TriNom->isChecked(),ui->TriDate->isChecked());
}

void GestionCommande::on_Imprimer_pressed()
{
    Commande C;
    C.Imprimer();
}

void GestionCommande::on_Back_clicked()
{
    ui->StackedWidgetCommande->setCurrentIndex(0);
}

void GestionCommande::on_DeleteButton_clicked()
{
    Commande C(ui->NumeroCRUD->text().toInt(),ui->CinClientCRUD->text().toInt(),ui->ReferenceProduitCRUD->text(),ui->Test->text().toInt(),"");
    C.Supprimer();
    ui->ListeCommande->clear();
    C.Afficher(ui->ListeCommande);
    ui->StackedWidgetCommande->setCurrentIndex(0);

    notification *n = new notification;
    n->setPopupText("La Commande a etait Supprimer!");
    n->show();
}

void GestionCommande::on_UpdateButton_clicked()
{
    Commande C(ui->NumeroCRUD->text().toInt(),ui->CinClientCRUD->text().toInt(),ui->ReferenceProduitCRUD->text(),ui->Test->text().toInt(),"");
    C.Modifier();
    ui->ListeCommande->clear();
    C.Afficher(ui->ListeCommande);
    ui->StackedWidgetCommande->setCurrentIndex(0);
 notification *n = new notification;
    n->setPopupText("La Commande a etait MAJ!");
    n->show();
}
