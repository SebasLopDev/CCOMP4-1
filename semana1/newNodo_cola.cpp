#include<iostream>
using namespace std;

struct nodo{
    int arr[5];
    nodo *next;     
    int tam;
    nodo(nodo *n=nullptr){        
        next=n;        
        tam=5;//sizeof(arr)/sizeof(arr[0]);
        
    }

};

class Cola{
    public:
        nodo *list;
        nodo *front;
        int *head;
        int *tail;        
        int cont=0;
        int recont=0;
        int tam;
        Cola(){
            list=new nodo;
            front=list;            
            head=list->arr;            
            tail=list->arr;
            tam=list->tam;
        }

        void push(int valor){
            if(cont%5==0 && cont!=0){
                list->next=new nodo;
                list=list->next;
                tail=list->arr;
            }
            *tail=valor;
            tail++;
            cont++;
        }

        void pop(int &v){
            if (cont == 0) {
                cout << "Cola vacía"<<endl;
                return;
            }
            v=*head;
            head++;
            cont--;
            recont++;
            if(recont%tam==0){
                nodo *delnodo=front;
                front=front->next;
                if (front!= nullptr){
                    head = front->arr;
                }                
                recont=0;
                delete delnodo;
            }
            
            
        }

        void mostrar(){
            int *f=head; 
            nodo *fr=front;
            int total=0;
            while(total<cont){
                while(f < fr->arr + tam && total<cont){
                    cout<<*f<<" ";
                    f++;
                    total++;
                }
                fr=fr->next;
                if (fr != nullptr) {
                    f = fr->arr;
                }
                cout<<"  ";

            }           

            cout<<endl;

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
    


    return 0;
}