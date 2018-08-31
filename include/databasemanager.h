#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QtSql>
#include <QDebug>

class DatabaseManager
{
public:
    DatabaseManager(const QString& path);

    // Instance used to query the database, as not to always recreate
    QSqlQuery* query;

    void queryDB(QString statement);

    // Index for the columns in the database
    int kanjiIndex = 1;
    int kanaIndex  = 2;
    int typeIndex  = 3;
    int meaningIndex   = 4;
    int chapterIndex    = 5;


private:
    // The current database being used by the program
    QSqlDatabase verbDB;

};

#endif // DATABASEMANAGER_H
