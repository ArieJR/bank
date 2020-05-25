#ifndef DATABASE_H
#define DATABASE_H
#include <QString>




class database
{
public:
    explicit database();

    void checkGebruikersId();
    void sessieStart();

    bool checkPassword(QString pincodeIngevoerd);
    bool checkGeblokkeerd();
    void pogingReset();
    void pogingOmhoog();
    int checkPogingen();
    void blokeerPas();
    void sessieEind();

    int get50BriefgeldAantal();
    int get20BriefgeldAantal();
    int get10BriefgeldAantal();

    void setNewBalance(float bedragGepind);
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
    QString automaatId = "Pin_School";
    int huidigeSessieId;

    bool pincode;
    bool pasGeblokkeerd = false;    //hard
    int aantalFoutpogingen;

    int biljet50;
    int biljet20;
    int biljet10;

    float balance = 200;
    float withdrawnToday;
    float bedragGepind;

    float bedragInAutomaat;
    float biljet10InAutomaat;
    float biljet20InAutomaat;
    float biljet50InAutomaat;
};

#endif // DATABASE_H
