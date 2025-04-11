#include <iostream>
using namespace std;

struct nodo {
    int arr[5];
    nodo* next;
    int tam;

    nodo(nodo* n = nullptr) {
        next = n;
        tam = 5;
    }
};

class Pila {
public:
    int* top;
    nodo* list;
    int cont = 0;
    int tam;

    Pila() {
        list = new nodo();
        top = list->arr;
        tam=list->tam;
    }

    void push(int valor) {
        if (cont % tam == 0) {
            nodo* newlist = new nodo();
            newlist->next = list;
            list = newlist;
            top = list->arr;
        }
        *top = valor;
        top++;
        cont++;
    }

    void pop(int& v) {
        if (cont == 0) {
            cout << "PILA VACIA" << endl;
            return;
        }

        cont--; 
        top--;      
        v = *top;   

        if (cont % 5 == 0 && list->next != nullptr) {
            nodo* aux = list;
            list = list->next;
            delete aux;
            top = list->arr + tam; 
        }

    }

    void mostrar() {
        nodo* inicio = list;
        int* f = top;
        int total = 0;

        while (total < cont) {
            while (f > inicio->arr && total < cont) {
                f--;
                cout << *f << " ";
                total++;
            }
            inicio = inicio->next;
            if (inicio != nullptr)
                f = inicio->arr + tam;
            cout << "  ";
        }
        cout << endl;
    }
};

int main() {
    Pila pila;
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
    pila.push(13);
    pila.push(14);
    pila.push(15);
    pila.push(16);
    pila.push(17);
    
    //pila.push(6);
    pila.mostrar();
    pila.pop(a);
    cout<<"Elemento eliminado "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"Elemento eliminado "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"Elemento eliminado "<<a<<endl;
    pila.mostrar();
    pila.pop(a);
    cout<<"Elemento eliminado "<<a<<endl;
    pila.mostrar();

    return 0;
}
