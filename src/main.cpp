#include "mainwindow.h"
#include <QApplication>
#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();

    DatabaseManager verbDB = DatabaseManager("C:/Users/techn/Documents/Katsu-kun/genki_verbs.db");
    verbDB.printAllEntries();


    return a.exec();
}
