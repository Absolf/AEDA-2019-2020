
#ifndef TESTE_2016_MAIL_H
#define TESTE_2016_MAIL_H

#include <string>
using namespace std;


class Mail {
    string sender;
    string receiver;
    string zipCode;
public:
    Mail(string send, string rec, string zcode);
    virtual ~Mail();
    string getZipCode() const;
    virtual int getPrice() const = 0;
};


class RegularMail: public Mail {
    unsigned int weight;
public:
    RegularMail(string send, string rec, string code, unsigned int w);
    int getPrice() const;
};


class GreenMail: public Mail {
    string type;  // "envelope", "bag", "box"
public:
    GreenMail(string send, string rec, string code, string t);
    int getPrice() const;
};

#endif //TESTE_2016_MAIL_H
