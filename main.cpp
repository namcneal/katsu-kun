#include "mainwindow.h"
#include <QApplication>
#include "databasemanager.h"

#include "verb.h"
#include "ichidan.h"
#include "godan.h"
#include "suru.h"
#include "kuru.h"

void test(){
    DatabaseManager verbDB = DatabaseManager("C:/Users/techn/Documents/katsu-kun/Resources/genki_verbs.db");

    verbDB.queryDB("SELECT * FROM 'genki_verbs'");

    QString filename = "C:/Users/techn/Documents/katsu-kun/output.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite|QFile::Text)) {
        QTextStream stream(&file);

        Verb* forms[5];

        while(verbDB.query->next()){
            QString kanji =  verbDB.query->value(verbDB.kanjiIndex).toString();
            QString kana  =  verbDB.query->value(verbDB.kanaIndex).toString();
            int type      =  verbDB.query->value(verbDB.typeIndex).toInt();
            QString meaning =  verbDB.query->value(verbDB.meaningIndex).toString();

            switch(type){
            case 0:
                if (kana[kana.size() - 2] == QString::fromUtf8("す")){
                    for(int i =0; i < 5; i++){
                        forms[i] = new Suru(kanji, kana, meaning);
                    }
                }
                else{
                    for(int i =0; i < 5; i++){
                        forms[i] = new Kuru(kanji, kana, meaning);
                    }
                }
                break;
            case 1:
                for(int i =0; i < 5; i++){
                    forms[i] = new Ichidan(kanji, kana, meaning);
                }
                break;
            case 2:
                for(int i =0; i < 5; i++){
                    forms[i] = new Godan(kanji, kana, meaning);
                }
                break;
            }

            forms[1] = forms[1]->toPotential();
            forms[2] = forms[2]->toPassive();
            forms[3] = forms[3]->toCausative();
            forms[4] = forms[4]->toCausativePassive();

           if (type > -1){
               Verb* currentVerb = 0;
               for(int i = 0; i < 5; i++){
                   currentVerb = forms[i];
                   stream << currentVerb->getShort(true, true)   << "  "
                          << currentVerb->getShort(false, true)  << "  "
                          << currentVerb->getShort(true, false)  << "  "
                          << currentVerb->getShort(false, false) << "  " << endl;

                   stream << currentVerb->getMasu(true, true)   << "  "
                          << currentVerb->getMasu(false, true)  << "  "
                          << currentVerb->getMasu(true, false)  << "  "
                          << currentVerb->getMasu(false, false) << "  " << endl;


                   stream << currentVerb->getTe(true) << "  "
                          << currentVerb->getTe(false) << "  " << endl;

                   stream << currentVerb->getTai(true, true)   << "  "
                          << currentVerb->getTai(false, true)  << "  "
                          << currentVerb->getTai(true, false)  << "  "
                          << currentVerb->getTai(false, false) << "  " <<endl;

                   stream << currentVerb->getTara(true)  << "  "
                          << currentVerb->getTara(false) << "  " << endl;

                   stream << currentVerb->getBa(true)  << "  "
                          << currentVerb->getBa(false) << "  " << endl;

                   stream << endl;
               }

               stream << endl;

            }
       }

        qDebug() << "Finished writing to file.";
    }

}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();

    test();

    return a.exec();
}
