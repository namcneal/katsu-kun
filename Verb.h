#ifndef VERB_H
#define VERB_H

#include <QString>


class Verb
{
public:
    Verb();
    Verb(QString type, QString kanji, QString kana);
    ~Verb();

    // Getters and setters for the booleans that determine what forms are valid for this verb
    void setPotentialBool(bool value);
    void setPassiveBool(bool value);
    void setCausativeBool(bool value);
    void setCausativePassiveBool(bool value);

    void getPotentialBool(bool value);
    void getPassiveBool(bool value);
    void getCausativeBool(bool value);
    void getCausativePassiveBool(bool value);


    QString* getDictionary();


private:
    // The booleans that determine what forms are valid for the verb
    // For example, 'aru' does not have a causative form, so it would have causative=False
    bool potential, passive, causative, causativePassive;


    QString verbType;
    QString dictionaryKanji;
    QString dictionaryKana;
};

#endif // VERB_H
