
#include "PostOffice.h"
#include <string>



PostOffice::PostOffice(string firstZCode, string lastZCode):
        firstZipCode(firstZCode), lastZipCode(lastZCode)
{}
PostOffice::PostOffice() {}

void PostOffice::addMailToSend(Mail *m) {
    mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
    mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
    postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
    return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
    return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
    return postmen;
}

vector<Mail *> PostOffice::removePostman(string name) {
    vector<Mail *> result;
    vector<Postman>::iterator it;
    for (it = postmen.begin(); it != postmen.end(); it++) {
        if ((*it).getName() == name) {
            result = (*it).getMail();
            postmen.erase(it);
            return result;
        }
    }
    return result;
}

vector<Mail *> PostOffice::endOfDay(unsigned int &balance) {
    vector<Mail *> result;
    unsigned int total = 0;
    vector<Mail *>::iterator it;
    for (it = mailToSend.begin(); it != mailToSend.end(); it++) {
        total += (*it)->getPrice();
        if (((*it)->getZipCode() >= firstZipCode) && ((*it)->getZipCode() <= lastZipCode))
            addMailToDeliver(*it);
        else
            result.push_back(*it);
    }
    mailToSend.clear();
    balance = total;
    return result;
}

class NoPostmanException {
    string name;
public:
    NoPostmanException(string name) {this->name = name;}
    string getName() const {return name;}
};

Postman PostOffice::addMailToPostman(Mail *m, string name) {
    for (auto &x: postmen) {
        if (x.getName() == name) {
            x.addMail(m);
            return x;
        }
    }
    throw NoPostmanException(name);
}
