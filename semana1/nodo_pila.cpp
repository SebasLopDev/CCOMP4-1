#include<iostream>
using namespace std;


struct nodo{
    int arr[5];
    nodo *next;
    int cont=0;
    nodo(nodo *n=0){       
        next=n;
        
    }

};

class Pila{    
    
    public: 
        nodo *list;
        int *top=nullptr;
    
        Pila(){
            list=new nodo();
            top=list->arr;
        }
        void push(int valor){
            if(list->cont==sizeof(list->arr)/sizeof(list->arr[0])){
                nodo *newlist= new nodo();
                newlist->next=list;
                list=newlist;
                top=list->arr;
                
                /*list->next=new nodo(list);
                list=list->next;
                top=list->arr;*/
                
            }
            *top=valor;
            top++;
            list->cont++;


        }
        
        void pop(){
            top--;
            list->cont--;
            if(list->cont==0){
                delete list;
            }

        }

        void mostrar(){
            for(int *p=top;top;p++){
                cout<<*p<<" ";
            }
            cout<<endl;
        }




};


int main(){
    Pila pila;
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.mostrar();




    return 0;
}