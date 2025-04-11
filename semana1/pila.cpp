#include<iostream>
using namespace std;



class Pila{
    int *top=NULL;    
    int tamanio;
    int *arreglo;
    int cont=0;
    

    public:

        Pila(int *inicio,int tam){
            arreglo=inicio;
            tamanio=tam;
            top=arreglo;            
        }
        void push(int valor){
            if(cont<tamanio ){
                *top=valor;
                top++;
                cont++;
            }
            else{
                cout<<"ESTA LLENO"<<endl;
            }

        }

        void pop(int &v){
            if(cont==0){
                cout<<"EL ARREGLO ESTA VACÍO"<<endl;
            }else{
                top--;
                cont--;
                v=*top;
            }

        }

        void mostrar(){
            if(cont==0){
                cout<<"ESTA VACIO"<<endl;
            }else{
                for(int *p=arreglo;p<arreglo+cont;p++){
                    cout<<*p<<" ";
                }
                cout<<endl;

            }

        }

};



int main(){

    int arr[10];
    int a=0;
    Pila pila(arr,10);
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
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"valor eliminado es "<<a<<endl;
    pila.mostrar();
    
    


    return 0;
}