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
            tamanio=tam+1;
            arreglo=new T[tamanio];
            head=arreglo;
            tail=arreglo;
            //cont=arreglo;
        }
        ~Cola() {
            delete[] arreglo;
        }
        void push(T valor){
            
           
            if( (tail+1== head) || (tail+1== arreglo + tamanio && head == arreglo)){

                                
                cout<<"EL ARREGLO ESTA LLENO"<<endl;                     
                return;
            }
            if(tail==arreglo+tamanio && head!=arreglo){               
                tail=arreglo;
                
            }
            *tail=valor;
            tail++;
                
                     



        }

        bool pop(T &v){
             
            if(head==tail){
                cout<<"EL ARREGLO ESTA VACIO"<<endl;
                return false;
            }
            
            v=*head;
            head++;
            
            if(head==arreglo+tamanio){
                head=arreglo;
            }
            return true;
            

           

        }


        void mostrar(){
            T *h=head;
            T *t=tail;
            if(head==tail){
                cout<<"ESTA VACIO"<<endl;
                return;
            }
            while(h!=t){
                if(h==arreglo+tamanio){
                    h=arreglo;
                    
                }
                cout<<*h<<" ";
                h++;
                
            }
            cout<<endl;
            
        }





};

int main(){

    
    Cola<int> cola(20);
    int a=0;
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

/*

#include <iostream>
using namespace std;

template <class T>
struct nodo {
    T arr[5];
    nodo* next;
    int tamanio;

    nodo(nodo* n = nullptr) {
        next = n;
        tamanio = sizeof(arr) / sizeof(arr[0]);
    }
};

template <class T>
class Cola {
public:
    nodo<T>* list;
    nodo<T>* front;
    T* head;
    T* tail;
    int tam;

    Cola() {
        list = new nodo<T>;
        front = list;
        head = list->arr;
        tail = list->arr;
        tam = list->tamanio;
    }

    void push(T valor) {
        if (tail == list->arr + tam) {
            list->next = new nodo<T>;
            list = list->next;
            tail = list->arr;
        }
        *tail = valor;
        tail++;
    }

    bool pop(T& v) {
        if (front == list && head == tail) {
            cout << "pop Cola vacia" << endl;
            return false;
        }
        v = *head;
        head++;
        if (head == front->arr + tam) {
            nodo<T>* delnodo = front;
            front = front->next;
            delete delnodo;
            if (front != nullptr)
                head = front->arr;
        }
        return true;
    }

    void mostrar() {
        nodo<T>* fr = front;
        T* f = head;

        if (f == tail) {
            cout << "Cola vacía" << endl;
            return;
        }

        while (fr) {
            while (f < fr->arr + tam) {
                if (fr == list && f == tail)
                    break;
                cout << *f << " ";
                f++;
            }
            cout << " --- ";
            fr = fr->next;
            if (fr != nullptr)
                f = fr->arr;
        }
        cout << "NULL" << endl;
    }
};



*/