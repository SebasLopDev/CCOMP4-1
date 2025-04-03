#include<iostream>
using namespace std;


template<class T>
struct nodo{
    T valor;
    nodo<T>*next;

    nodo(int v, nodo<T>*n=0){
        valor=v;
        next=n;
    }

};

template<class P>
class Pila{
    nodo<T>*top=0;
    public:
        void push(T valor){
            top=new nodo<T>(valor,top);

        }

        bool pop(T &v){
            nodo<T>*tmp=top;
            if(tmp){
                top=top->next;
                v=tmp->valor;
                delete tmp;
                return true;
            }
            return false;

        }

};



int main(){




    return 0;
}