/*
 * BankOfficer.cpp
 */
#include "BankOfficer.h"

unsigned int BankOfficer::id_aux = 1;

BankOfficer::BankOfficer(): id(0) {}

BankOfficer::BankOfficer(string name) {
    this->id =id_aux++;
    this->name;
}

void BankOfficer::setName(string nm){
	name = nm;
}

string BankOfficer::getName() const{
	return name;
}

vector<Account *> BankOfficer::getAccounts() const {
	return myAccounts;
}

void BankOfficer::addAccount(Account *a) {
	myAccounts.push_back(a);
}

unsigned int BankOfficer::getID() const{
	return id;
}


bool BankOfficer::operator>(BankOfficer &bak) {
    if(this->myAccounts.size() == bak.myAccounts.size()){
        return this->name > bak.name;
    }
    return this->myAccounts.size() > bak.myAccounts.size();
}


// ----------------------------------------------------------------------------------------------

// a alterar



