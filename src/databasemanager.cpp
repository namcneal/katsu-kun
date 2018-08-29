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

       // Connect the databse to the query instance
       this->query = new QSqlQuery(verbDB);
    }

}

void DatabaseManager::queryDB(QString statement){
    this->query->prepare(statement);
    this->query->exec();
}

//void DatabaseManager::printAllEntries(){
//    qDebug() << "Printing all verbs in the database";
//    QSqlQuery query("SELECT * FROM 'genki_verbs'");
//    int dictKanji = query.record().indexOf("DICT_KANJI");

//    QString foo = QString::fromUtf8( "く" );

//    QString filename = "C:/Users/techn/Documents/katsu-kun/output.txt";
//    QFile file(filename);
//    if (file.open(QIODevice::ReadWrite|QFile::Text)) {
//        QTextStream stream(&file);

//        stream << "First line" << endl;

//        while(query.next()){
//            QString name = query.value(dictKanji).toString();

//            stream << name << " " << foo << endl;
//            foo = foo + 1;

//        }
//    }

