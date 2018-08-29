#include "ichidan.h"

Ichidan::Ichidan() : Verb(){}


Ichidan::Ichidan(QString kanji, QString kana, QString meaning) : Verb(kanji, kana, meaning) {}

Ichidan* Ichidan::toPotential(){
    QString lastChar = QString(kanji[kanji.size() - 1]);

    QString newKanji = kanji,
            newKana  = kana;

    QString ending = QString::fromUtf8("られる");
    newKanji.chop(1);
    newKana.chop(1);
    newKanji += ending;
    newKana += ending;

    Ichidan* toReturn = new Ichidan(newKanji, newKana, meaning);
    toReturn->form = QString("Potential");

    return toReturn;
}

Ichidan* Ichidan::toPassive(){
    Ichidan* toReturn = this->toPotential();
    toReturn->form = QString("Passive");

    return toReturn;
}

Ichidan* Ichidan::toCausative(){
    QString lastChar = QString(kanji[kanji.size() - 1]);

    QString newKanji = kanji,
            newKana  = kana;

    QString ending = QString::fromUtf8("させる");
    newKanji.chop(1);
    newKana.chop(1);
    newKanji += ending;
    newKana += ending;

    Ichidan* toReturn = new Ichidan(newKanji, newKana, meaning);
    toReturn->form = QString("Causative");

    return toReturn;
}

Ichidan* Ichidan::toCausativePassive(){
    Ichidan* toReturn = this->toCausative()->toPassive();
    toReturn->form = QString("Causative-passive");

    return toReturn;
}


QString Ichidan::getStem(){
    QString stem = kanji;
    stem.chop(1);
    return stem;
}

QString Ichidan::getShort(bool tense, bool polarity){

    // Present positive
    if (tense && polarity){
        return kanji;
    }

    // Present negative
    else if (tense && !polarity){
        return this->getStem() + QString::fromUtf8( "ない" );
    }

    // Past positive
    else if (!tense && polarity){
        return this->getStem() + QString::fromUtf8( "た" );
    }

    // Past negative
    else{
        return this->getStem() + QString::fromUtf8( "なかった" );
    }
}

QString Ichidan::getTe(bool polarity){
    if (polarity){
        return this->getStem() + QString::fromUtf8("て");
    }

    return this->getStem() + QString::fromUtf8("なくて");
}

QString Ichidan::getBa(bool polarity){
    if (polarity){
        return this->getStem() + QString::fromUtf8("れば");
    }
    else{
        return this->getStem() + QString::fromUtf8("なければ");
    }
}
