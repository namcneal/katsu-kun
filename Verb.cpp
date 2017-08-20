#include "Verb.h"

Verb::Verb()
{
    verbType = "";
    dictionaryKanji = "";
    dictionaryKana = "";
}

Verb::Verb(QString type, QString kanji, QString kana)
{
    verbType = type;
    dictionaryKanji = kanji;
    dictionaryKana = kana;
}

Verb::~Verb()
{

}

QString* Verb::getDictionary()
{
    QString* kanjiKanaPair = new QString[2];
    kanjiKanaPair[0] = dictionaryKanji;
    kanjiKanaPair[1] = dictionaryKana;
    return kanjiKanaPair;
}



