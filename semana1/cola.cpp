#include<iostream>
using namespace std;


class Cola{
    private:
        int *head=NULL; 
        int *tail=NULL;   
        int tamaño;
        int *arreglo;
        int cont=0;
        bool estado=false;
    
    public:

        Cola(int *inicio,int tam){
            arreglo=inicio;
            tamaño=tam;
            head=inicio;
            tail=inicio;
        }

        void push(int valor){

            if(cont<tamaño ){
                *tail=valor;
                tail++;
                cont++;
                if (tail == arreglo + tamaño) {  
                    tail = arreglo;
                }
            }
            else{
                cout<<"ESTA LLENO"<<endl;
            }       
                     



        }

        void pop(int &v){
           if(cont==0){
                cout<<"ARREGLO VACÍO"<<endl;
           }else{

                v=*head;
                head++;
                cont--;
                if(head==arreglo+tamaño){
                    head=arreglo;
                }
           }

        }


        void mostrar(){

            if(cont==0){
                cout<<"ESTA VACIO"<<endl;
            }else{

                int *aux=head;
                for(int i=0;i<cont;i++){
                    cout<<*aux<<" ";
                    aux++;
                    if(aux==arreglo+tamaño){
                        aux=arreglo;
                    }
                }
                cout<<endl;
            }
        }





};

int main(){

    int arr[10];
    int a=0;
    Cola cola(arr,10);
    cola.push(1);
    cola.push(2);
    cola.push(3);
    cola.push(4);
    cola.push(5);
    cola.push(6);
    cola.push(7);
    cola.push(8);
    cola.push(9);
    cola.push(10);
    cola.push(11);
    cola.mostrar();
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();


    return 0;
}