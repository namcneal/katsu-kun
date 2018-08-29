#include "suru.h"

Suru::Suru(){}

Suru::Suru(QString fullKanji, QString fullKana, QString meaning){
    fullKanji.chop(2);
    fullKana.chop(2);

    this->kanji = fullKanji;
    this->kana  = fullKana;
    this->meaning = meaning;
    this->form = QString("Dictionary");
}

Ichidan* Suru::toPotential(){
    Ichidan* toReturn = new Ichidan(this->kanji + QString::fromUtf8("出来る"),
                                    this->kana  + QString::fromUtf8("できる"),
                                    this->meaning);
    toReturn->form = QString::fromUtf8("Potential");

    return toReturn;
}

Ichidan* Suru::toPassive(){
    Ichidan* toReturn = new Ichidan(this->kanji + QString::fromUtf8("される"),
                                    this->kana  + QString::fromUtf8("される"),
                                    this->meaning);
    toReturn->form = QString::fromUtf8("Passive");

    return toReturn;
}

Ichidan* Suru::toCausative(){
    Ichidan* toReturn = new Ichidan(this->kanji + QString::fromUtf8("させる"),
                                    this->kana  + QString::fromUtf8("させる"),
                                    this->meaning);
    toReturn->form = QString::fromUtf8("Causative");

    return toReturn;
}

Ichidan* Suru::toCausativePassive(){
    Ichidan* toReturn = this->toCausative()->toPassive();
    toReturn->form = QString("Causative-passive");
    return toReturn;
}

QString Suru::getStem(){
    return this->kanji + QString::fromUtf8("し");
}

QString Suru::getShort(bool tense, bool polarity){
    // Present positive
    if (tense && polarity){
        return this->kanji + QString::fromUtf8( "する");
    }

    // Present negative
    else if (tense && !polarity){
        return this->kanji + QString::fromUtf8( "しない" );
    }

    // Past positive
    else if (!tense && polarity){
        return this->kanji + QString::fromUtf8( "した" );
    }

    // Past negative
    else{
        return this->kanji + QString::fromUtf8( "しなかった" );
    }
}

QString Suru::getTe(bool polarity){
    if (polarity){
       return this->kanji + QString::fromUtf8("して");
    }

    return this->kanji + QString::fromUtf8("しなくて");
}

QString Suru::getBa(bool polarity){
    if (polarity){
       return this->kanji + QString::fromUtf8("すれば");
    }

    return this->kanji + QString::fromUtf8("しなければ");
}
