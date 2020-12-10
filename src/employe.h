#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "classemploye.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

#include <QMainWindow>

namespace Ui {
class Employe;
}

class Employe : public QMainWindow
{
    Q_OBJECT

public:
    explicit Employe(QWidget *parent = 0);
    ~Employe();
        void on_refresh_clicked();

private slots:
    void stat();


    void on_ajouter_clicked();

    void on_cancel_clicked();

    void on_add_clicked();

   // void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_return_2_clicked();

    void on_modify_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    //void on_modify_clicked(bool checked);

    void on_delete_2_clicked();

    void on_cancel_2_clicked();

    void on_save_clicked();

    void on_rechercher_editingFinished();

    void on_print_clicked();

    //void on_cin_2_returnPressed();

   // void on_cin_2_selectionChanged();

    void on_statistics_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

   void on_top3_table_clicked(const QModelIndex &index);

   void on_notif_button_clicked();

private:
    Ui::Employe *ui;
    QPrinter *printer;
};

#endif // EMPLOYE_H
