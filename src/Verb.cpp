#include "verb.h"

Verb::Verb()
{
    this->kanji = QString::fromUtf8( "漢字る" );
    this->kana  = QString::fromUtf8( "かなる" );
    this->meaning = QString("Verb not loaded");
    this->form    = QString("Invalid");
}

Verb::Verb(QString kanji, QString kana, QString meaning){
    this->kanji = kanji;
    this->kana  = kana;
    this->meaning = meaning;
    this->form    = QString("Dictionary");
}

QString Verb::getMasu(bool tense, bool polarity){
    QString masu = this->getStem();

    // Present positive
    if (tense && polarity){
        masu += QString::fromUtf8( "ます" );
    }

    // Present negative
    else if (tense && !polarity){
        masu += QString::fromUtf8( "ません" );
    }

    // Past positive
    else if (!tense && polarity){
        masu += QString::fromUtf8( "ました" );
    }

    // Past negative
    else{
        masu += QString::fromUtf8( "ませんでした" );
    }

    return masu;
}

QString Verb::getTai(bool tense, bool polarity){
    QString tai = this->getStem();

    // Present positive
    if (tense && polarity){
        tai += QString::fromUtf8( "たい" );}

    // Present negative
    else if (tense && !polarity){
        tai += QString::fromUtf8( "たくない" );
    }

    // Past positive
    else if (!tense && polarity){
        tai += QString::fromUtf8( "たかった" );
    }

    // Past negative
    else{
        tai += QString::fromUtf8( "たくなかった" );
    }

    return  tai;
}

QString Verb::getTara(bool polarity){
     return this->getShort(0, polarity) + QString::fromUtf8("ら");
}
