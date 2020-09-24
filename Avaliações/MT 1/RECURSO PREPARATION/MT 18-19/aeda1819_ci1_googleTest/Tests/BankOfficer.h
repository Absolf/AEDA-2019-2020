/*
 * BankOfficer.h
 */

#ifndef SRC_BANKOFFICER_H_
#define SRC_BANKOFFICER_H_

#include "Account.h"
#include <string>
#include <vector>

class BankOfficer {
    static unsigned int id_aux;
	unsigned int id;
	string name;
	vector<Account *> myAccounts;
public:
	BankOfficer();
	BankOfficer(string name);
	void setName(string nm);
	void addAccount(Account *a);
	void addAccount(vector<Account *> accounts);
	string getName() const;
	vector<Account *> getAccounts() const;
	unsigned int getID() const;

	//-------
	bool operator >(BankOfficer & bak);
	vector<Account *> removeBankOfficer(string name);
};


#endif /* SRC_BANKOFFICER_H_ */
