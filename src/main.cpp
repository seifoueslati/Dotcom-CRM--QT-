#include "clients.h"
#include "bdd.h"
#include <QApplication>
#include <QGuiApplication>
#include <QQuickView>
#include<QSplashScreen>
#include "login.h"
int main(int argc, char *argv[])
{

       QApplication a(argc, argv);

       /*QPixmap pixmap("C:/Users/seif/Desktop/projectqt/CLIENTBOSS/aa");
       QSplashScreen splash(pixmap);
       splash.show();
       a.thread()->sleep(2);
       a.processEvents();
       splash.showMessage( QObject::trUtf8( "Check software and plugins versions..." ), Qt::AlignLeft | Qt::AlignBottom );

*/
    Clients w;
    connection C; 
    login l;
    if(C.create_connection()==true)
       {
        printf("connection established");
         l.show();
    }
   else
        printf("error");


    return a.exec();
}
