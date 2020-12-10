#ifndef GESTIONCOMMANDE_H
#define GESTIONCOMMANDE_H
#include "commande.h"
#include <QMainWindow>

namespace Ui {
class GestionCommande;
}

class GestionCommande : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionCommande(QWidget *parent = 0);
    ~GestionCommande();
private slots:
    void on_RechercheCommande_clicked();

    void on_TriButton_clicked();

    void on_Imprimer_pressed();

    void on_Back_clicked();

    void on_DeleteButton_clicked();

    void on_UpdateButton_clicked();

private:
    Ui::GestionCommande *ui;
};

#endif
