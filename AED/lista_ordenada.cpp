#include<iostream>
using namespace std;

struct Cnodo{
    Cnodo *next;
    int valor;
    Cnodo(int v=0,Cnodo *n=nullptr){
        valor=v;
        next=n;
    }

};

class Clist{
    private:
        Cnodo *head;

    public:
        Clist();
        bool find(int x,Cnodo **&p);
        bool ins(int x);
        bool rem(int x);
        void mostrar();

};
Clist::Clist(){
    head=nullptr;

}

bool Clist::find(int x,Cnodo **&p){
    p=&head;
    while(*p && (*p)->valor<x){
        p=&((*p)->next);

    }
    return (*p && (*p)->valor==x);
    
    
};

bool Clist::ins(int x){
    Cnodo **p;
    if(find(x,p)){
        return true;
    }else{        
        Cnodo *t=new Cnodo(x);
        t->next=*p;
        *p=t;
        return false;
    }

};

bool Clist::rem(int x){
    Cnodo **p;
    Cnodo *t;
    if(find(x,p)){
        t=*p;
        *p=t->next;
        delete t;
        return true;
    }
    return false;
};

void Clist::mostrar(){
    Cnodo *p=head;
    while(p){
        cout<<p->valor<<" -> ";
        p=p->next;
    }
    cout<<"NULL";
    cout<<endl;
};


int main(){
    Clist list;
    list.ins(2);
    list.ins(3);
    list.ins(5);
    list.ins(1);
    list.ins(3);
    list.ins(4);
    list.mostrar();
    list.rem(4);
    list.mostrar();



    return 0;
}