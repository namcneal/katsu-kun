#include "kuru.h"

Kuru::Kuru(){}

Kuru::Kuru(QString fullKanji, QString fullKana, QString meaning){
    fullKanji.chop(2);
    fullKana.chop(2);

    this->kanji = fullKanji;
    this->kana  = fullKana;
    this->meaning = meaning;
    this->form = QString("Dictionary");
}

Ichidan* Kuru::toPotential(){
    Ichidan* toReturn = new Ichidan(this->kanji + QString::fromUtf8("来られる"),
                                    this->kana  + QString::fromUtf8("こられる"),
                                    this->meaning);
    toReturn->form = QString::fromUtf8("Potential");

    return toReturn;
}

Ichidan* Kuru::toPassive(){
    Ichidan* toReturn = new Ichidan(this->kanji + QString::fromUtf8("来られる"),
                                    this->kana  + QString::fromUtf8("こられる"),
                                    this->meaning);
    toReturn->form = QString::fromUtf8("Passive");

    return toReturn;
}

Ichidan* Kuru::toCausative(){
    Ichidan* toReturn = new Ichidan(this->kanji + QString::fromUtf8("来させる"),
                                    this->kana  + QString::fromUtf8("こさせる"),
                                    this->meaning);
    toReturn->form = QString::fromUtf8("Causative");

    return toReturn;
}

Ichidan* Kuru::toCausativePassive(){
    Ichidan* toReturn = this->toCausative()->toPassive();
    toReturn->form = QString("Causative-passive");
    return toReturn;
}

QString Kuru::getStem(){
    return this->kanji + QString::fromUtf8("来");
}

QString Kuru::getShort(bool tense, bool polarity){
    // Present positive
    if (tense && polarity){
        return this->kanji + QString::fromUtf8( "来る");
    }

    // Present negative
    else if (tense && !polarity){
        return this->kanji + QString::fromUtf8( "来ない" );
    }

    // Past positive
    else if (!tense && polarity){
        return this->kanji + QString::fromUtf8( "来た" );
    }

    // Past negative
    else{
        return this->kanji + QString::fromUtf8( "来なかった" );
    }
}

QString Kuru::getTe(bool polarity){
    if (polarity){
       return this->kanji + QString::fromUtf8("来て");
    }

    return this->kanji + QString::fromUtf8("来なくて");
}

QString Kuru::getBa(bool polarity){
    if (polarity){
       return this->kanji + QString::fromUtf8("来れば");
    }

    return this->kanji + QString::fromUtf8("来なければ");
}
