#ifndef DATA_H
#define DATA_H
#include "login.h"
#include "qshareddata.h"


class Data: public QSharedData
{

    public:
        Data();
        float getBalance();
        float getAmountWithdrawnToday(); //maximaal bedrag dat valt te pinnen per dag?
        float getMaxWithdrawableMoney();
        bool checkIfCardNotBlocked();
        bool sendPincode(int pin); // pincode will be handled in the database
        int getNumberOf50Notes();
        int getNumberOf20Notes();
        int getNumberOf10Notes();
        void setNewBalance();

        bool checkWithdrawal(float withdrawnMoney, int numberOf10NotesWithdraw, int numberOf20NotesWithdraw, int numberOf50NotesWithdraw, bool lastConfirmation); //deduction of money takes place in the database


    private:
        float balance = 1000;
        float maxWithdrawableMoney = 250;
        float amountWithdrawnToday;
        int pincode = 1234;
        int numberFailedLogins = 0;
        int numberOf50Notes = 100;
        int numberOf20Notes = 100;
        int numberOf10Notes = 100;
        bool cardNotBlocked;
        float getTotalCashInATM();
        bool checkIfEnoughNotes(int checkNumberOf10Notes, int checkNumberOf20Notes, int checkNumberOf50Notes);
        void deductNumberOf50Notes(int numberOfNotes);
        void deductNumberOf20Notes(int numberOfNotes);
        void deductNumberOf10Notes(int numberOfNotes);
};

#endif // DATA_H
