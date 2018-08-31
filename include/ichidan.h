#ifndef ICHIDAN_H
#define ICHIDAN_H

#include "Verb.h"


class Ichidan : public Verb {

public:
    Ichidan();
    Ichidan(QString kanji, QString kana, QString meaning);

    ~Ichidan();

    Ichidan* toPotential() override;
    Ichidan* toPassive() override;
    Ichidan* toCausative() override;
    Ichidan* toCausativePassive() override;

    QString getStem() override;
    QString getShort(bool tense, bool polarity) override;
    QString getTe(bool polarity) override;
    QString getBa(bool polarity) override;


};

#endif // ICHIDAN_H
