#include<iostream>
using namespace std;


struct nodo{
    int arr[5];
    nodo *next;
    int tam=sizeof(arr)/sizeof(arr[0]);
    //int cont=0;
    nodo(nodo *n=NULL){       
        next=n;
        
    }

};

template<class T>
class Pila{    
    
    public: 
        nodo *list;
        T *top=nullptr;
        int tamanio;
    
        Pila(){
            list=new nodo();
            top=list->arr;
            tamanio=list->tam;
        }
        void push(T valor){

            if(top==list->arr+tamanio){
                
                nodo *newlist=new nodo;
                newlist->next=list;
                list=newlist;
                top=list->arr;
            }

            *top=valor;
            top++;
            
            /*if(top==list->arr+tam-1){
                *top=valor;
                return;
            }*/
            /*if(list->cont==sizeof(list->arr)/sizeof(list->arr[0])){
                nodo *newlist= new nodo();
                newlist->next=list;
                list=newlist;
                top=list->arr;*/
                
                /*list->next=new nodo(list);
                list=list->next;
                top=list->arr;*/
                
            
            


        }
        
        void pop(T &v){

            if ((top==list->arr && list->next==NULL) || (top!=list->arr && !list)) {
                cout << "pop PILA VACIA" << endl;
                return;
            }
           top--;
           v=*top;
           if(top==list->arr){
               
               nodo *del=list;
               list=list->next;
               top=list->arr+tamanio;
               delete del;
            }

            

        }

        void mostrar(){
            nodo *listar=list;
            T *ptr=top;
            if ((ptr==list->arr && list->next==NULL) || (ptr!=listar->arr && !listar)) {
                cout << "PILA VACIA" << endl;
                return;
            }
            while(listar){
                ptr--;
                cout<<*ptr<<" ";
                if(ptr==listar->arr){                    
                    listar=listar->next;
                    ptr=listar->arr+tamanio;                    
                    cout<<"--";
                }
            }
            cout<<" NULL";
            cout<<endl;
        }




};


int main(){
    Pila<int> pila;
    int a=0;
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);
    pila.push(5);
    pila.push(6);
    pila.push(7);
    pila.push(8);
    pila.push(9);
    pila.push(10);
    pila.push(12);
    pila.push(13);
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();    
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.push(20);
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.mostrar();
    pila.mostrar();
    cout<<"---"<<endl;
    pila.pop(a);




    return 0;
}