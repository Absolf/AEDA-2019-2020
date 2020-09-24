#include "jogador.h"

//a alterar
void Jogador::adicionaAposta(const Aposta & ap)
{
    apostas.insert(ap);
}

//a alterar
unsigned Jogador::apostasNoNumero(unsigned num) const
{
    unsigned cont = 0;
    for(auto it = apostas.begin(); it != apostas.end(); it++){
        if((*it).contem(num)){
            cont++;
        }
    }
    return cont;
}

//a alterar
tabHAposta Jogador::apostasPremiadas(const tabHInt & sorteio) const
{

	tabHAposta money;
	money.clear();
	for(auto it = apostas.begin(); it != apostas.end(); it++)
	{
	    if((*it).calculaCertos(sorteio) >3){
	        money.insert((*it));
	    }
	}
	return money;
}
