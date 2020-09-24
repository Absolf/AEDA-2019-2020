/*
 * Bank.h
 */

#ifndef SRC_BANK_H_
#define SRC_BANK_H_

#include "Account.h"
#include <vector>
#include <algorithm>
#include <set>
#include "BankOfficer.h"
using namespace std;

class Bank {
	vector<Account *> accounts;
	vector<BankOfficer> bankOfficers;
public:
	Bank();
	void addAccount(Account *a);
	void addBankOfficer(BankOfficer b);
	vector<BankOfficer> getBankOfficers() const;
	vector<Account *> getAccounts() const;

	//-------
	double getWithdraw(string cod1) const;
	vector<Account *> removeBankOfficer(string name);
	const BankOfficer& addAccountToBankOfficer(Account *ac, string name);
	void sortAccounts();
};

template<class T>
unsigned  int numberDifferent(const vector<T> & v1){
    set<T> aux;
    for(int i = 0; i< v1.size(); i++){
        aux.insert(v1[i]);
    }
    return aux.size();
};

class NoBankOfficerException {
	string name;
public:
	NoBankOfficerException(){};
	NoBankOfficerException(string name) :name(name){};
	string getName() const{
		return name;
	}
};



#endif /* SRC_BANK_H_ */
