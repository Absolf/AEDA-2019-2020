/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------

// a alterar
double Bank::getWithdraw(string cod1) const{
    double total = 0.0;
    for(auto it = accounts.begin(); it != accounts.end(); it++){
        if((*it)->getCodH() == cod1){
            total += (*it)->getWithdraw();
        }
    }
	return total;
}


// a alterar
vector<Account *> Bank::removeBankOfficer(string name){
	vector<Account *> res = {};
	vector<BankOfficer>::iterator it = bankOfficers.begin();
	for(it; it != bankOfficers.end(); it++){
	    if((*it).getName() == name){
	        res = (*it).getAccounts();
	        bankOfficers.erase(it);
	        break;
	    }
	}
	return res;
}


// a alterar
const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
    BankOfficer *bo= new BankOfficer();
    vector<BankOfficer>::iterator it = bankOfficers.begin();
    for(it; it!= bankOfficers.end(); it++){
        if((*it).getName() == name){
            (*it).addAccount(ac);
            return (*it);
        }
    }
    throw NoBankOfficerException(name);
}


// a alterar
bool sortFunction(Account * ac1, Account *ac2){
    if(ac1->getBalance() == ac2->getBalance())
        return ac1->getCodIBAN() < ac2->getCodIBAN();
    return ac1->getBalance() < ac2->getBalance();
}

void Bank::sortAccounts() {
    sort(accounts.begin(),accounts.end(),sortFunction);
}