#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
  public: 
    Grafo();
    ~Grafo();
    Grafo & inserirNo(const N &dados);
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);
    Grafo & eliminarAresta(const N &inicio, const N &fim);
    A & valorAresta(const N &inicio, const N &fim);
    int numArestas(void) const;
    int numNos(void) const;
    void imprimir(std::ostream &os) const; 
};

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);


// excecao NoRepetido
template <class N>
class NoRepetido
{
public:
   N info;
   NoRepetido(N inf) { info=inf; }
};
template <class N> 
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }

// excecao NoInexistente
template <class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};

template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }

//excecao ArestaRepetida
template<class N>
class ArestaRepetida
{
public:
    N info1, info2;
    ArestaRepetida(N inf1, N inf2): info1(inf1), info2(inf2) {}
};

template <class N>
ostream &operator<<(ostream &out, const ArestaRepetida<N> &a)
{
    out << "Aresta repetida: " << a.info1 << " , " << a.info2;
    return out;
}

//excecao ArestaInexistente
template <class N>
class ArestaInexistente
{

public:
    N info1, info2;
    ArestaInexistente(N inf1, N inf2): info1(inf1), info2(inf2) {}
};

template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaInexistente<N> &a)
{ out << "Aresta inexistente: " << a.info1 << " , " << a.info2 ; return out; }


template<class N, class A>
Grafo<N, A>::Grafo() {}

template<class N, class A>
Grafo<N, A>::~Grafo() {
    typename vector < No <N, A> *>::const_iterator it;
    for(it=nos.begin(); it != nos.end(); it++)
        delete *it;
}

template<class N, class A>
int Grafo<N,A>::numNos() const {
    return nos.size();
}

template<class N, class A>
int Grafo<N,A>::numArestas() const
{
    int nArestas = 0;
    typename vector< No<N,A> *>::const_iterator it = nos.begin();
    while(it != nos.end())
    {
        nArestas += (*it)->arestas.size();
        it++;
    }
    return nArestas;
}

template<class N, class A>
Grafo<N, A> & Grafo<N,A>::inserirNo(const N &dados)
{
    typename vector< No<N,A> *>::const_iterator it;

    for(it = nos.begin(); it != nos.end(); it++){
        if ((*it)->info == dados) throw  NoRepetido<N>(dados);
    }
    No<N,A> *newNo = new No<N,A>(dados);
    nos.push_back((newNo));
    return *this;
}

template<class N, class A>
Grafo<N, A> & Grafo <N,A>::inserirAresta(const N &inicio, const N &fim, const A &val)
{
    typename vector< No<N,A> *>::const_iterator it;
    typename vector< Aresta<N,A> >::iterator ita;
    bool encontrouInicio = false;
    bool encontrouFim = false;

    No<N,A> *noInicio_apt=NULL;
    No<N,A> *noFim_apt = NULL;

    for (it = nos.begin() ; it != nos.end() ; it++){

        if ((*it)->info == inicio){
            encontrouInicio = true;
            noInicio_apt=*it;
            for(ita = (*it)->arestas.begin(); ita != (*it)->arestas.end(); ita++){
                if( ita->destino->info == fim) throw ArestaRepetida<N> (inicio, fim);
            }
            if(encontrouFim == true) break;
        }
        else if((*it)->info == fim) {
            encontrouFim =true;
            noFim_apt=*it;
            if(encontrouInicio == true) break;
        }
    }

    if(!encontrouInicio) throw NoInexistente<N> (inicio);
    if(!encontrouFim) throw NoInexistente<N> (fim);

    Aresta<N,A> arestaNew(noFim_apt, val);
    noInicio_apt->arestas.push_back(arestaNew);

    return *this;

}

template<class N,class A>
A & Grafo<N, A>::valorAresta(const N &inicio, const N &fim)
{
    typename vector< No<N,A> *>::iterator it;
    typename vector< Aresta<N,A> >::iterator ita;
    for( it= nos.begin(); it != nos.end(); it++)
    {
        if ((*it)->info == inicio){
            for (ita = (*it)->arestas.begin(); ita != (*it)->arestas.end(); ita++){
                if(ita->destino->info == fim) return ita->valor;
            }
            throw ArestaInexistente<N> (inicio, fim);
        }
    }
    throw NoInexistente<N> (inicio);
}

template<class N, class A>
Grafo<N,A> & Grafo <N,A>::eliminarAresta(const N &inicio, const N &fim){
    typename vector< No<N,A> *>::iterator it;
    typename vector< Aresta<N,A> >::iterator ita;
    for( it= nos.begin(); it != nos.end(); it++){
        if ((*it)->info == inicio){
            for (ita = (*it)->arestas.begin(); ita != (*it)->arestas.end(); ita++){
                if( ita->destino->info == fim){
                    (*it)->arestas.erase(ita);
                    return *this;
                }
            }
            throw ArestaInexistente<N> (inicio, fim);
        }
    }
    throw NoInexistente<N>(inicio);
    return *this;
}



template <class N, class A>
void Grafo<N,A>::imprimir(std::ostream &os) const
{
    typename vector< No<N,A> *>::const_iterator it;
    typename vector< Aresta<N,A> >::const_iterator ita;
    for (it = nos.begin(); it != nos.end(); it++) {
        os << "( " << (*it)->info ;
        for (ita = (*it)->arestas.begin();  ita != (*it)->arestas.end(); ita++) {
            os << "[ " <<  ita->destino->info << " " << ita->valor << "] " ;
        }
        os << ") ";
    }
}

template <class N, class A>
std::ostream & operator<<(std::ostream &out, const Grafo<N, A> &g)
{
    g.imprimir(out);
    return out;
}


