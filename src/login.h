#ifndef LOGIN_H
#define LOGIN_H
#include "clients.h"
#include <QMainWindow>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

    void verifier();
private slots:
    void on_Login_But_clicked();

private:
    Ui::login *ui;
    Clients *c;

};

#endif // LOGIN_H
