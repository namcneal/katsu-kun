#ifndef KURU_H
#define KURU_H

#include "verb.h"
#include "ichidan.h"

class Kuru : public Verb{

public:
    Kuru();

    // These omit the Kuru ending so that it is always appended
    Kuru(QString fullKanji, QString fullKana, QString meaning);

    ~Kuru();

    Ichidan* toPotential() override;
    Ichidan* toPassive() override;
    Ichidan* toCausative() override;
    Ichidan* toCausativePassive() override;


    QString getStem() override;

    QString getShort(bool tense, bool polarity) override;

    QString getTe(bool polarity) override;
    QString getBa(bool polarity) override;
};

#endif // KURU_H
