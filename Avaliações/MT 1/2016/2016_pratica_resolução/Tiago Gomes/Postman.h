

#ifndef TESTE_2016_POSTMAN_H
#define TESTE_2016_POSTMAN_H

#include "Mail.h"
#include <string>
#include <vector>

class Postman {
    unsigned int id;
    static unsigned int last_id;
    string name;
    vector<Mail *> myMail;
public:
    Postman();
    Postman(string name);
    void setName(string nm);
    void addMail(Mail *m);
    void addMail(vector<Mail *> mails);
    string getName() const;
    vector<Mail *> getMail() const;
    unsigned int getID() const;
    bool operator< (const Postman &p);
};

template <class T>
unsigned int inVector (const vector<T> & v1, const T &elem) {
    for (auto &x: v1) {
        if (x == elem)
            return true;
    }
    return false;
}

template <class T>
unsigned int numberDifferent (const vector<T> & v1) {
    vector<T> result;
    for (auto &x: v1) {
        if (!inVector(result, x))
            result.push_back(x);
    }
    return result.size();
}

#endif //TESTE_2016_POSTMAN_H
