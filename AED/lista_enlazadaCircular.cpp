#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;
    node(int v,node *n=nullptr){
        data=v;
        next=n;
    }
};

class CircularLinkedList
{
    node* head=NULL;
public:

    /*bool find(int x,node **&p){
        p=&head;
        while(*p && (*p)->data<x){
            p=&((*p)->next);
        }
        return *p && (*p)->data==x;
    }*/
    void add(int value)
    {
        //TO DO
        if(head==NULL){
            head=new node(value);
            head->next=head;
        }
        else if(head->data>=value){
            node *tmp=head;
            do{
                tmp=tmp->next;
            }while(tmp->next!=head);
            node *t=new node(value);
            t->next=head;
            head=t;
            tmp->next=head;
        }else{
            node *ultimo=head;
            node *newNode=new node(value);
            //if(ultimo->next!=head){
                do{
                    ultimo=ultimo->next;
                }while(ultimo->next!=head && ultimo->next->data<=value);
                newNode->next=ultimo->next;
                ultimo->next=newNode;
            //}
            /*else{
                newNode->next=head;
                do{
                    ultimo=ultimo->next;
                }while(ultimo->next!=head);
                ultimo->next=newNode;
            }*/
            //head=newNode;

        }

       
    }

    void del(int value)
    {
        // TO DO
        if (!head) return;
        node *temp=head;        
        node *sig;
        node *t=nullptr;
        if (head->data == value && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        if(temp->data==value){//cuando el valor a eliminar esta al inicio
            t = head;
            // buscar el último nodo
            node *last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
            delete t;
            /*t=head;
            head=head->next;            
            delete t;*/
        }else{  //admite todas excepto las del inicio
            while(temp->next->data!=value){
                temp=temp->next;
            }
            sig=temp->next;
            temp->next=sig->next;
            delete sig;

        }

        

    }

    void print()
    {
        int cont = 0;
        node* ptr = head;
        cout << "head->";
        while (head && cont < 1)
        {
            cout << ptr->data<<" -> ";
            ptr = ptr->next;
            if (ptr == head) cont++;
        }
        if (head) cout << ptr->data;
        cout<< " <- head \n ";

    }
};

int main()
{
    int ADD[10] = { 2,4,6,8,10,1,3,5,7,9 };
    int DEL[10] = { 9,7,5,3,1,10,8,6,4,2 };
    CircularLinkedList CLL;
    for (int i = 0; i < 10; i++)
    {
        cout << "ADD " << ADD[i] << endl;
        CLL.add(ADD[i]);
        CLL.print();
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "DEL " << DEL[i] << endl;
        CLL.del(DEL[i]);
        CLL.print();
    }
}
