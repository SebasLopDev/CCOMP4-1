#include<iostream>
using namespace std;

class Vectorx{
    private:
        int size;
        int *p;
        int capacity;
        
    public:
        Vectorx(int s=3){
            size=s;
            p=new int[size];
            capacity=0;      
            
        }

        ~Vectorx(){
            delete[] p;
        }

        void setsize(){
            cout<<size<<endl;
        }
        int operator [](int i){
            return p[i];
        }
        void push_back(int x){
            if(capacity==size){
                int nsize=size*2;
                int *q=new int[nsize];
                int *a=p; 
                int *b=q;               
                for(int i=0;i<size;i++){
                    *b=*a;
                    a++;
                    b++;
                }
                delete []p;
                p=q;
                size=nsize;
                //cout<<"expansion"<<endl;
            }
            *(p+capacity)=x;                
            capacity++;
            
            
        }

        void push_front(int x){
            if(capacity==size){
                int nsize=size*2;
                int *q=new int[nsize];
                int *a=p; 
                int *b=q;               
                for(int i=0;i<size;i++){
                    *b=*a;
                    a++;
                    b++;
                }
                delete []p;
                p=q;
                size=nsize;
                //cout<<"expansion"<<endl;
            }            
            for(int i=capacity;i>0;i--){
                *(p+i)=*(p+i-1);
                    
            }
            *p=x;
            capacity++;

            
        }

        void pop_back(){
            if(capacity>0){
                capacity--;
            }else{
                cout<<"vacio"<<endl;
            }
        }

        void pop_front(){
            if(capacity>0){
                for(int i=0;i<capacity;i++){
                    p[i]=p[i+1];
                        
                }
                
                capacity--;
            }

        }

        void print(Vectorx *p){
            
            for(int i=0;i<capacity;i++){
                cout<<(*p)[i]<<" ";
            }
        }    



};


int main(){
   Vectorx v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(1);
   v.push_back(2);
   v.push_back(1);
   v.push_back(2);
   v.push_front(0);
   v.push_front(20);
   v.pop_front();

   v.print(&v);
   cout<<endl;
   v.setsize();
    


    return 0;
}