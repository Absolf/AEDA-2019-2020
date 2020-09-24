
#include "Postman.h"

unsigned int Postman::last_id = 1;

Postman::Postman(): id(0) {}

void Postman::setName(string nm){
    name = nm;
}

string Postman::getName() const{
    return name;
}

vector<Mail *> Postman::getMail() const {
    return myMail;
}

void Postman::addMail(Mail *m) {
    myMail.push_back(m);
}

void Postman::addMail(vector<Mail *> mails) {
    myMail.insert(myMail.end(),mails.begin(),mails.end());
}

unsigned int Postman::getID() const{
    return id;
}

Postman::Postman(string name): name(name) {
    id = last_id;
    last_id++;
}

bool Postman::operator<(const Postman &p) {
    vector<string> zipCodes1;
    vector<string> zipCodes2;
    for (auto &x: myMail)
        zipCodes1.push_back(x->getZipCode());
    for (auto &x: p.getMail())
        zipCodes2.push_back(x->getZipCode());
    unsigned int n1 = numberDifferent<string>(zipCodes1);
    unsigned int n2 = numberDifferent<string>(zipCodes2);
    return n1 < n2;
}

