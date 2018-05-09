#include "databasemanager.h"

DatabaseManager::DatabaseManager(const QString& path)
{
    verbDB = QSqlDatabase::addDatabase("QSQLITE");
    verbDB.setDatabaseName(path);


    if (!verbDB.open())
    {
       qDebug() << "Error: connection with database failed";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }

}

void DatabaseManager::printAllEntries(){
    qDebug() << "Printing all verbs in the database";
    QSqlQuery query("SELECT * FROM 'genki_verbs'");
//    qDebug() << verbDB.tables().size();
    int dictKanji = query.record().indexOf("DICT_KANJI");

    while(query.next()){
        QString name =QObject::tr(query.value(dictKanji).toString());
        qDebug() << name;
    }

}
