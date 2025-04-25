#include<iostream>
using namespace std;


template<class T>
class Pila{
    T *top=nullptr;    
    int tamanio;
    T *arreglo;
    //int cont=0;
    

    public:

        Pila(int tam){ //T *inicio,
            //arreglo=inicio;
            tamanio=tam;
            arreglo=new T[tamanio];
            top=arreglo;            
        }
        void push(T valor){
            if(top<arreglo+tamanio ){
                *top=valor;
                top++;
                //cont++;
            }
            else{
                cout<<"EL ARREGLO ESTA LLENO"<<endl;
            }

        }

        void pop(T &v){
            if(top==arreglo){
                cout<<"EL ARREGLO ESTA VACIO"<<endl;
            }else{
                top--;
                //cont--;
                v=*top;
            }

        }

        void mostrar(){  
            int *ptr=top;          
            if(top==arreglo){
                cout<<"ARREGLO VACIO"<<endl;
            }else{
                for(int *p=arreglo;p<ptr;p++){
                    cout<<*p<<" ";
                }
                cout<<endl;

            }

        }

};



int main(){

    
    Pila<int> pila(10);
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
    pila.push(11);
    pila.push(12);
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

    
    


    return 0;
}