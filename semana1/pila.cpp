#include<iostream>
using namespace std;



class Pila{
    int *top=NULL;    
    int tamaño;
    int *arreglo;
    int cont=0;
    

    public:

        Pila(int *inicio,int tam){
            arreglo=inicio;
            tamaño=tam;
            top=arreglo;            
        }
        void push(int valor){
            if(cont<tamaño ){
                *top=valor;
                top++;
                cont++;
            }
            else{
                cout<<"ESTA LLENO"<<endl;
            }

        }

        void pop(){
            if(cont==0){
                cout<<"EL ARREGLO ESTA VACÍO"<<endl;
            }else{
                cont--;
                top--;
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
    Pila pila(arr,10);
    pila.pop();


    return 0;
}