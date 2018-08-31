#ifndef VERB_H
#define VERB_H

#include <map>

#include <QString>

class Verb
{
public:
    Verb();
    Verb(QString kanji, QString kana, QString meaning);

    ~Verb(){};

    virtual Verb* toPotential(){};
    virtual Verb* toPassive(){};
    virtual Verb* toCausative(){};
    virtual Verb* toCausativePassive(){};


    /*
     * Tense boolean: 1 -> Non-past and 0 -> Past
     * Polarity     : 1 -> Positive and 1 -> Negative
     *
    */

    virtual QString getStem(){};

    virtual QString getShort(bool tense, bool polarity){};
    QString getMasu(bool tense, bool polarity);

    virtual QString getTe(bool polarity){};

    QString getTai(bool tense, bool polarity);

    QString getTara(bool polarity);
    virtual QString getBa(bool polarity){};

    QString form;
protected:
    QString kanji;
    QString kana;
    QString meaning;

};

#endif // VERB_H
