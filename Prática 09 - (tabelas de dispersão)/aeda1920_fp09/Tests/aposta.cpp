#include "aposta.h"
#include <iostream>
#include <sstream>

using namespace std;

// a alterar
bool Aposta::contem(unsigned num) const
{
    auto it = numeros.find(num);
    if(it == numeros.end()){
        return false;
    }else
        return true;
}

//a alterar
void Aposta::geraAposta(const vector<unsigned> & valores, unsigned n)
{
    for(unsigned i = 1; i < valores.size() && i <= n; i++) {
        auto it = numeros.find(valores[i]);
        //cout << (*it);
        if(it == numeros.end()){
            numeros.insert(valores[i]);
        }else
            n++;
    }
}

//a alterar
unsigned Aposta::calculaCertos(const tabHInt & sorteio) const
{
    int cont = 0;
    for(auto it = sorteio.begin(); it != sorteio.end(); it++){
        auto i = numeros.find((*it));
        if(i != numeros.end())
            cont++;
    }
    return cont;
}

unsigned Aposta::somaNumeros() const {
    unsigned soma = 0;
    for(auto it = numeros.begin(); it != numeros.end(); it++){
        soma += (*it);
    }
    return soma;
}

unsigned  Aposta::tamanho() const{
    return numeros.size();
}




