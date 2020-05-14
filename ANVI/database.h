#ifndef DATABASE_H
#define DATABASE_H
#include <QString>



class database
{
public:
    explicit database();
    QString teruggave();

    void checkGebruikersId();
    void sessieStart();
    void checkPassword();
    void checkGeblokkeerd();
    void pogingReset();
    void pogingOmhoog();
    void checkPogingen();
    void blokeerPas();
    void sessieEind();

    void getBriefgeldAantal();

    void setNewBalance();
    float getBalance();
    float getAmountWithdrawnToday(); //maximaal bedrag dat valt te pinnen per dag?

    void verlaag50Briefjes(int numberOfNotes);
    void verlaag20Briefjes(int numberOfNotes);
    void verlaag10Briefjes(int numberOfNotes);

    float getTotaalGeldInATM();

private:
    QString woord;

    int gebruikersId;
    QString pasId;
    QString rekeningnummer;
    QString automaatId;
    int huidigeSessieId;
    int pincodeIngevoerd; //gehashed
    bool pincode;
    bool pasGeblokkeerd;
    int aantalFoutpogingen;

    int biljet50;
    int biljet20;
    int biljet10;

    float balance;
    float withdrawnToday;

};

#endif // DATABASE_H
