#include <QCoreApplication>
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("127.0.0.1");
    database.setPort(3306);
    database.setDatabaseName("ANVI");
    database.setUserName("root");
    database.setPassword("root");
    bool ok = database.open();

    if(ok)
    {
        qDebug() << "Opened!";
        database.close();
    }
    else
    {
        qDebug() << "Error";
    }


    return a.exec();
}
