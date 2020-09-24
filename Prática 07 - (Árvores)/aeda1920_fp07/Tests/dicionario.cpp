#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "dicionario.h"
#include "bst.h"

using namespace std;

BST<PalavraSignificado> Dicionario::getPalavras() const {
	return palavras;
}

//a alterar
bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const {
     return palavra < ps1.palavra;
}

bool PalavraSignificado::operator == (const PalavraSignificado &ps1) const {
    return palavra == ps1.palavra;
}

//a alterar
void Dicionario::lerDicionario(ifstream &fich)
{
    vector<string> lines;
    string line;
    for(line; getline(fich, line);){
        lines.push_back(line);
    }
    for(int i = 0; i< lines.size(); i++){
        string word = lines[i];
        i++;
        string meaning = lines[i];
        PalavraSignificado p1(word, meaning);
        palavras.insert(p1);
    }
}

//a alterar
string Dicionario::consulta(string palavra) const
{
    PalavraSignificado p1(palavra,"");
    PalavraSignificado px = palavras.find(p1);
    PalavraSignificado pNotFound("","");
    if(px==pNotFound){
        BSTItrIn<PalavraSignificado> it(palavras);
        string pAntes="", sAntes="";
        while(!it.isAtEnd() && it.retrieve()<p1){
            pAntes=it.retrieve().getPalavra();
            sAntes=it.retrieve().getSignificado();
            it.advance();
        }
        string pApos="", sApos="";
        if(!it.isAtEnd()){
            pApos=it.retrieve().getPalavra();
            sApos=it.retrieve().getSignificado();
        }
        throw PalavraNaoExiste(pAntes,sAntes,pApos,sApos);
    }
    else
        return px.getSignificado();
}

//a alterar
bool Dicionario::corrige(string palavra, string significado)
{
    PalavraSignificado px = palavras.find(PalavraSignificado(palavra,""));
    PalavraSignificado pNotFound("","");
    if(px==pNotFound){
        palavras.insert(PalavraSignificado(palavra,significado));
        return  false;
    } else{
        palavras.remove(PalavraSignificado(palavra,""));
        px.setSignificado(significado);
        palavras.insert(px);
        return true;
    }
}

//a alterar


void Dicionario::imprime() const
{
    for(auto it = palavras.begin(); it !=palavras.end();it++) {
        cout << (*it).getPalavra() << endl;
        cout << (*it).getSignificado()<<endl;
    }
}
