#include "bdd.h"
#include <QtSql>
#include<QSqlQuery>
#include<QSqlDatabase>
#include <QtSql>
#include <iostream>
#define q2c(string) string.toStdString()
bool connection::create_connection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("mydb");

    db.setUserName("hr");

    db.setPassword("hr");

    return (db.open());
}


