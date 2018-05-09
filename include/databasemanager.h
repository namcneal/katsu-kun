#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QtSql>
#include <QDebug>

class DatabaseManager
{
public:
    DatabaseManager(const QString& path);
    void printAllEntries();


private:
    QSqlDatabase verbDB;
};

#endif // DATABASEMANAGER_H
