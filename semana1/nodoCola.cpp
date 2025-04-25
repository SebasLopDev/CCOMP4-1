#include<iostream>
using namespace std;

struct nodo{
    int arr[5];
    nodo *next;     
    int tamanio=sizeof(arr)/sizeof(arr[0]);;
    nodo(nodo *n=nullptr){        
        next=n;        
        //tam=5;//sizeof(arr)/sizeof(arr[0]);
        
    }

};

class Cola{
    public:
        nodo *list;
        nodo *front;
        int *head;
        int *tail;        
        //int cont=0;
        //int recont=0;
        int tam;
        Cola(){
            list=new nodo;
            front=list;            
            head=list->arr;            
            tail=list->arr;
            tam=list->tamanio;
        }

        void push(int valor){
            if(tail<list->arr+tam){
                *tail=valor;
                tail++;
            }
           //*tail=valor;
           //tail++;
            if(tail==list->arr+tam){
                list->next=new nodo;
                list=list->next;
                tail=list->arr;
                return;
            }
            /*if(cont%5==0 && cont!=0){
                list->next=new nodo;
                list=list->next;
                tail=list->arr;
            }*/
            //cont++;
        }

        void pop(int &v){
            if (head == tail) {
                cout << "pop Cola vacía"<<endl;
                return;
            }
            v=*head;
            head++;
            if(head==list->arr+tam){                
                nodo *delnodo=front;
                front=front->next;
                delete delnodo;
                if (front != nullptr)
                    head = front->arr;
                return;
            }
            //cont--;
            //recont++;
            /*if(recont%tam==0){
                nodo *delnodo=front;
                front=front->next;
                if (front!= nullptr){
                    head = front->arr;
                }                
                recont=0;
                delete delnodo;
            }*/
            
            
        }

        void mostrar(){
            nodo *fr = front;
            int *f = head;

            while (fr != nullptr) {
                while (f < fr->arr + tam) {
                    if (fr == list && f == tail) // si llegamos a tail, paramos
                        break;
                    cout << *f << " ";
                    f++;
                }
                fr = fr->next;
                if (fr != nullptr)
                    f = fr->arr;
            }

            cout << "NULL" << endl;

        }

};

int main(){

    Cola cola;
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
    cola.push(12);
    cola.push(13);
    cola.push(14);
    cola.push(15);
    cola.push(16);
    cola.push(17);
    cola.mostrar();
    cola.pop(a);
    cout<<"Elemento eliminado "<<a<<endl;
    cola.pop(a);
    cout<<"Elemento eliminado "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"Elemento eliminado "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"Elemento eliminado "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"Elemento eliminado "<<a<<endl;
    cola.mostrar();
    cola.pop(a);
    cout<<"Elemento eliminado "<<a<<endl;
    cola.mostrar();
    


    return 0;
}