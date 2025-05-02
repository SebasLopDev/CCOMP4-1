#include<iostream>
using namespace std;

template<class T>
class Cola{
    private:
        T *head=nullptr; 
        T *tail=nullptr;   
        int tamanio;
        T *arreglo;
        T *cont=nullptr;
        //int cont=0;
        //bool estado=false;
    
    public:
        Cola(int tam){
            tamanio=tam;
            arreglo=new T[tamanio];
            head=arreglo;
            tail=arreglo;
            //cont=arreglo;
        }

        void push(T valor){
            
           
            if( (tail+1== head) || (tail== arreglo + tamanio && head == arreglo)){
                //*tail=valor;
                cout<<"EL ARREGLO ESTA LLENO"<<endl;                     
                return;
            }
            if(tail==arreglo+tamanio && head!=arreglo){               
                tail=arreglo;
                
            }
            *tail=valor;
            tail++;
                
                     



        }

        void pop(T &v){
             
            if(head==tail){
                cout<<"EL ARREGLO ESTA VACIO"<<endl;
                return;
            }
            
            v=*head;
            head++;
            
            if(head==arreglo+tamanio){
                head=arreglo;
            }
            

           

        }


        void mostrar(){
            T *h=head;
            T *t=tail;
            if(h==t){
                cout<<"ESTA VACIO"<<endl;
                return;
            }
            while(h==tail){
                cout<<*h<<" ";
                h++;
                if(h==arreglo+tamanio){
                    
                    h=arreglo;
                    
                }
                
            }
            cout<<endl;
            
        }





};

int main(){

    
    int a=0;
    Cola<int> cola(10);
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
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();
    cout<<"-------- push"<<endl;
    cola.push(12);
    cola.push(13);
    cola.push(14);
    cola.mostrar();
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();
    cout<<"------ push"<<endl;    
    cola.push(15);
    cola.mostrar();
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"elemento eliminado es "<<a<<endl;
    cola.mostrar();
    cola.pop(a);

    


    return 0;
}