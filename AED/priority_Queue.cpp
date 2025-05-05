#include <iostream>
#include <queue>

class CSortedQueue
{
public:
    void pushx(int x);
    void popx();
    int frontx();
    void remx(int x);
    void printx();
    std::queue<int> q;
};

void CSortedQueue::pushx(int x)

{
    int tam=q.size();
    int val;
    bool inst=false;
    for(int i=0;i<tam;i++){
        val=q.front();
        q.pop();
        if(!inst && val>=x){
            q.push(x);
            inst=true;
        }
        q.push(val);
    }
    if(!inst){
        q.push(x);
    }
}

void CSortedQueue::popx()
{
    if(!q.empty()){
        q.pop();

    }
}

int CSortedQueue::frontx()
{   
    return q.front();
}

void CSortedQueue::remx(int x)
{
    int tam=q.size();
    int val;

    for(int i=0;i<tam;i++){
        val=q.front();
        q.pop();
        if(x==val){
            continue;
        }else{
            q.push(val);
        }
    }
}

void CSortedQueue::printx()
{
    
    int tam=q.size();
    int val;
    for(int i=0;i<tam;i++){
        val=q.front();
        q.pop();
        std::cout<<val<<" ";
        q.push(val);
    }
    std::cout<<std::endl;
}

int main()
{
    CSortedQueue sq;
    sq.pushx(40); sq.printx();
    sq.pushx(23); sq.printx();
    sq.pushx(51); sq.printx();
    sq.pushx(12); sq.printx();
    sq.pushx(30); sq.printx();
    sq.pushx(5);  sq.printx();
    sq.pushx(40); sq.printx();
    sq.pushx(18); sq.printx();
    
    sq.remx(40);  sq.printx();
    sq.remx(23);  sq.printx();
    sq.remx(12);  sq.printx();
    sq.remx(5);  sq.printx();

    std::cout<<"\nfront => "<<sq.frontx(); sq.popx();
    std::cout<<"\nfront => "<<sq.frontx(); sq.popx();
    std::cout<<std::endl;
    sq.printx();
}

