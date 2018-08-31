#ifndef SURU_H
#define SURU_H

#include "verb.h"
#include "ichidan.h"

class Suru : public Verb{

public:
    Suru();

    // These omit the suru ending so that it is always appended
    Suru(QString fullKanji, QString fullKana, QString meaning);

    ~Suru();

    Ichidan* toPotential() override;
    Ichidan* toPassive() override;
    Ichidan* toCausative() override;
    Ichidan* toCausativePassive() override;


    QString getStem() override;

    QString getShort(bool tense, bool polarity) override;

    QString getTe(bool polarity) override;
    QString getBa(bool polarity) override;
};

#endif // SURU_H
