#ifndef GODAN_H
#define GODAN_H

#include "verb.h"
#include "ichidan.h"


class Godan : public Verb
{
public:

    static std::map <QString, QString> aChanges;
    static std::map <QString, QString> iChanges;
    static std::map <QString, QString> eChanges;
    static std::map <QString, QString> teChanges;
    static std::map <QString, QString> taChanges;


    Godan();
    Godan(QString kanji, QString kana, QString meaning);

    ~Godan();

    Ichidan* toPotential() override;
    Ichidan* toPassive() override;
    Ichidan* toCausative() override;
    Ichidan* toCausativePassive() override;


    QString getStem() override;
    QString getShort(bool tense, bool polarity) override;
    QString getTe(bool polarity) override;
    QString getBa(bool polarity) override;

};

#endif // GODAN_H
