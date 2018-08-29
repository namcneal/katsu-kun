#include "godan.h"

std::map <QString, QString> Godan::aChanges  =  {
    {QString::fromUtf8( "う" ), QString::fromUtf8( "わ" )},
    {QString::fromUtf8( "く" ), QString::fromUtf8( "か" )},
    {QString::fromUtf8( "ぐ" ), QString::fromUtf8( "が" )},
    {QString::fromUtf8( "す" ), QString::fromUtf8( "さ" )},
    {QString::fromUtf8( "つ" ), QString::fromUtf8( "た" )},
    {QString::fromUtf8( "ぶ" ), QString::fromUtf8( "ば" )},
    {QString::fromUtf8( "む" ), QString::fromUtf8( "ま" )},
    {QString::fromUtf8( "る" ), QString::fromUtf8( "ら" )}
  };

std::map <QString, QString> Godan::iChanges{
    {QString::fromUtf8( "う" ), QString::fromUtf8( "い" )},
    {QString::fromUtf8( "く" ), QString::fromUtf8( "き" )},
    {QString::fromUtf8( "ぐ" ), QString::fromUtf8( "ぎ" )},
    {QString::fromUtf8( "す" ), QString::fromUtf8( "し" )},
    {QString::fromUtf8( "つ" ), QString::fromUtf8( "ち" )},
    {QString::fromUtf8( "ぶ" ), QString::fromUtf8( "び" )},
    {QString::fromUtf8( "む" ), QString::fromUtf8( "み" )},
    {QString::fromUtf8( "る" ), QString::fromUtf8( "り" )}
  };

std::map <QString, QString> Godan::eChanges{
    {QString::fromUtf8( "う" ), QString::fromUtf8( "え" )},
    {QString::fromUtf8( "く" ), QString::fromUtf8( "け" )},
    {QString::fromUtf8( "ぐ" ), QString::fromUtf8( "げ" )},
    {QString::fromUtf8( "す" ), QString::fromUtf8( "せ" )},
    {QString::fromUtf8( "つ" ), QString::fromUtf8( "て" )},
    {QString::fromUtf8( "ぶ" ), QString::fromUtf8( "べ" )},
    {QString::fromUtf8( "む" ), QString::fromUtf8( "め" )},
    {QString::fromUtf8( "る" ), QString::fromUtf8( "れ" )}
  };

std::map <QString, QString> Godan::teChanges{
    {QString::fromUtf8( "う" ), QString::fromUtf8( "って" )},
    {QString::fromUtf8( "く" ), QString::fromUtf8( "いて" )},
    {QString::fromUtf8( "ぐ" ), QString::fromUtf8( "いで" )},
    {QString::fromUtf8( "す" ), QString::fromUtf8( "して" )},
    {QString::fromUtf8( "つ" ), QString::fromUtf8( "って" )},
    {QString::fromUtf8( "ぶ" ), QString::fromUtf8( "んで" )},
    {QString::fromUtf8( "む" ), QString::fromUtf8( "んで" )},
    {QString::fromUtf8( "る" ), QString::fromUtf8( "って" )}
  };

std::map <QString, QString> Godan::taChanges{
    {QString::fromUtf8( "う" ), QString::fromUtf8( "った" )},
    {QString::fromUtf8( "く" ), QString::fromUtf8( "いた" )},
    {QString::fromUtf8( "ぐ" ), QString::fromUtf8( "いだ" )},
    {QString::fromUtf8( "す" ), QString::fromUtf8( "した" )},
    {QString::fromUtf8( "つ" ), QString::fromUtf8( "った" )},
    {QString::fromUtf8( "ぶ" ), QString::fromUtf8( "んだ" )},
    {QString::fromUtf8( "む" ), QString::fromUtf8( "んだ" )},
    {QString::fromUtf8( "る" ), QString::fromUtf8( "った" )}
  };


Godan::Godan(){}

Godan::Godan(QString kanji, QString kana, QString meaning) : Verb(kanji, kana, meaning){}

Ichidan* Godan::toPotential(){
    QString lastChar = QString(kanji[kanji.size() - 1]);

    QString newKanji = kanji,
            newKana  = kana;

    QString ending = eChanges[lastChar] + QString::fromUtf8("る");
    newKanji.chop(1);
    newKana.chop(1);
    newKanji += ending;
    newKana += ending;

    Ichidan* toReturn = new Ichidan(newKanji, newKana, meaning);
    toReturn->form = QString("Passive");

    return toReturn;
}

Ichidan* Godan::toPassive(){
    QString lastChar = QString(kanji[kanji.size() - 1]);

    QString newKanji = kanji,
            newKana  = kana;

    QString ending = aChanges[lastChar] + QString::fromUtf8("れる");
    newKanji.chop(1);
    newKana.chop(1);
    newKanji += ending;
    newKana += ending;

    Ichidan* toReturn = new Ichidan(newKanji, newKana, meaning);
    toReturn->form = QString("Passive");

    return toReturn;
}

Ichidan* Godan::toCausative(){
    QString lastChar = QString(kanji[kanji.size() - 1]);

    QString newKanji = kanji,
            newKana  = kana;

    QString ending = aChanges[lastChar] + QString::fromUtf8("せる");
    newKanji.chop(1);
    newKana.chop(1);
    newKanji += ending;
    newKana += ending;

    Ichidan* toReturn = new Ichidan(newKanji, newKana, meaning);
    toReturn->form = QString("Causative");

    return toReturn;

}

Ichidan* Godan::toCausativePassive(){
    Ichidan* toReturn = this->toCausative()->toPassive();
    toReturn->form = QString("Causative-passive");
    return toReturn;
}


QString Godan::getStem(){
    QString stem = kanji;
    QString lastChar = QString(stem[stem.size() - 1]);
    lastChar = iChanges[lastChar];

    stem.chop(1);
    return stem + lastChar;
}

QString Godan::getShort(bool tense, bool polarity){
    QString base = kanji;
    QString lastChar = QString(kanji[kanji.size() - 1]);
    base.chop(1);

    // Present positive
    if (tense && polarity){
        return kanji;
    }

    // Present negative
    else if (tense && !polarity){
        return base + aChanges[lastChar] + QString::fromUtf8( "ない" );
    }

    // Past positive
    else if (!tense && polarity){
        // Change verbs ending in -iku to -iru to get irregular conjugation
        if (kana.mid(kana.size() - 2) == QString::fromUtf8("いく")){
            return base + QString::fromUtf8("った");
        }

        return base + taChanges[lastChar];
    }

    // Past negative
    else{
        return base + aChanges[lastChar] + QString::fromUtf8( "なかった" );
    }
}

QString Godan::getTe(bool polarity){
    QString base = this->kanji;

    if (polarity){
        // Change verbs ending in -iku to -iru to get irregular conjugation
        if (kana.mid(kana.size() - 2) == QString::fromUtf8("いく")){
            base.chop(1);
            return base + QString::fromUtf8("って");
        }

        QString ending = QString(base[base.size() - 1]);
        ending = teChanges[ending];
        base.chop(1);
        return base + ending;
     }

    else{
        QString ending = QString(base[base.size() - 1]);
        ending = aChanges[ending] + QString::fromUtf8("なくて");
        base.chop(1);
        return base + ending;
    }
}

QString Godan::getBa(bool polarity){
    QString base = kanji;
    QString lastChar = QString(kanji[kanji.size() - 1]);
    base.chop(1);

    if (polarity){
        return base + eChanges[lastChar] + QString::fromUtf8("ば");
    }
    else{
        return base + aChanges[lastChar] + QString::fromUtf8( "なければ" );
    }
}
