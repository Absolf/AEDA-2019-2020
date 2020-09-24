# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
    stack<T> pilha;
    T minEle;
public:
	StackExt() {};
	bool empty() const; 
	T &top();
	void pop();
	void push(const T & val);
	T &findMin();
};

// a alterar
template <class T> 
bool StackExt<T>::empty() const
{
    if(pilha.empty())
        return true;
    else
        return false;
}

//a alterar
template <class T> 
T& StackExt<T>::top()
{
    //T *novo = new T();
    return pilha.top();
}

//a alterar
template <class T> 
void StackExt<T>::pop()
{
    if(pilha.empty())
        return;
    T t = pilha.top();
    pilha.pop();
    if(t< minEle){
        minEle = 2*minEle - t;
    }
}

//a alterar
template <class T> 
void StackExt<T>::push(const T & val)
{
    if(pilha.empty()){
        minEle = val;
        pilha.push(val);
    }
    if(val < minEle){
        pilha.push(2*val - minEle);
        minEle = val;
    }
    else
        pilha.push(val);
}

//a alterar
template <class T> 
T& StackExt<T>::findMin()
{
   return minEle;
}

