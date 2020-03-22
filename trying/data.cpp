#include "data.h"

Data::Data()
{


}

float Data::getBalance(){
    return balance;
}

float Data::getAmountWithdrawnToday(){
    return amountWithdrawnToday;
}

float Data::getMaxWithdrawableMoney(){
    return maxWithdrawableMoney;
}

bool Data::checkIfCardNotBlocked(){
    if(numberFailedLogins > 2){
        return false; //blocked card
    }
    else{
        return true;
    }
}

bool Data::sendPincode(int pin){
    if(pin == pincode){
        numberFailedLogins = 0;
        return true;
    }
    else{
        numberFailedLogins++;;
        return false;
    }
}


bool Data::checkWithdrawal(float withdrawnMoney, int numberOf10NotesWithdraw, int numberOf20NotesWithdraw, int numberOf50NotesWithdraw, bool lastConfirmation){ //withdraws money from bank account and if it is allowed
    if(checkIfEnoughNotes(numberOf10NotesWithdraw, numberOf20NotesWithdraw, numberOf50NotesWithdraw)){
            if(balance-withdrawnMoney < 0){             //returns true when allowed and false when not
                return false;
            }
            else{
                if(lastConfirmation){
                    balance = balance - withdrawnMoney;
                    deductNumberOf10Notes(numberOf10NotesWithdraw); //turn into function
                    deductNumberOf20Notes(numberOf20NotesWithdraw);
                    deductNumberOf50Notes(numberOf50NotesWithdraw);
                    return true;
                }
                else
                {
                    return true;
                }
            }
    }
    else{
            return false;
    }
}

void Data::deductNumberOf10Notes(int numberOfNotes){
    numberOf10Notes = numberOf10Notes - numberOfNotes;
}

void Data::deductNumberOf20Notes(int numberOfNotes){
    numberOf20Notes = numberOf20Notes - numberOfNotes;
}

void Data::deductNumberOf50Notes(int numberOfNotes){
    numberOf50Notes = numberOf50Notes - numberOfNotes;
}

float Data::getTotalCashInATM(){
    return numberOf10Notes * 10 + numberOf20Notes * 20 + numberOf50Notes * 50;
}

int Data::getNumberOf10Notes(){
    return numberOf10Notes;
}

int Data::getNumberOf20Notes(){
    return numberOf20Notes;
}

int Data::getNumberOf50Notes(){
    return numberOf50Notes;
}
bool Data::checkIfEnoughNotes(int checkNumberOf10Notes, int checkNumberOf20Notes, int checkNumberOf50Notes){
    if(checkNumberOf10Notes >= numberOf10Notes && checkNumberOf20Notes >= numberOf20Notes && checkNumberOf50Notes >= numberOf50Notes){
        return true;
    }
    else{
        return false;
    }
}

void Data::setNewBalance(){

}
