#include <iostream>
#include<vector>
#include<cmath>
using namespace std;



struct CBinNode
{
    CBinNode(int _v)
    { 
        value = _v; nodes[0] = nodes[1] = 0;
    }
    int value;
    CBinNode* nodes[2];
};



class CBinTree
{
public:
    CBinTree();
    ~CBinTree();
    bool Insert(int x);
    void Print();
    void kneighbors(int x, int k);
private:
    bool Find(int x, CBinNode**& p);
    void InOrder(CBinNode* n);
    void guardar(CBinNode *n,vector<int>&p);
    void eliminar(CBinNode *n);
    CBinNode* m_root;
};

CBinTree::CBinTree()
{   m_root = 0; }

CBinTree::~CBinTree()
{
    eliminar(m_root);
}
void CBinTree::eliminar(CBinNode* n)
{
    if ( !n ) return;
    eliminar(n->nodes[0]);    
    eliminar(n->nodes[1]);
    delete n;
}

bool CBinTree::Find(int x, CBinNode**& p)
{
    for ( p = &m_root ; *p && (*p)->value != x ; p = &( (*p)->nodes[ (*p)->value < x ] ) );
    return *p && (*p)->value == x;
}

bool CBinTree::Insert(int x)
{
    CBinNode** p;
    if ( Find(x,p) ) return 0;
    *p = new CBinNode(x);
    return 0;
}

void CBinTree::InOrder(CBinNode* n)
{
    if ( !n ) return;
    InOrder(n->nodes[0]);
    cout<<n->value<<" ";
    InOrder(n->nodes[1]);
}

void CBinTree::guardar(CBinNode* n,std::vector<int>&p)
{
    if ( !n ) return;
    guardar(n->nodes[0],p);
    p.push_back(n->value);//<<n->value<<" ";
    guardar(n->nodes[1],p);
}

void CBinTree::Print()
{
    InOrder(m_root);
    cout<<endl;
}

void CBinTree::kneighbors(int x, int k)
{
    std::cout<<"\n("<<x<<","<<k<<") => ";
    // The code goes from here down
    CBinNode *p=m_root;
    std::vector<int> v;
    guardar(p,v);
    for(size_t i=0;i<v.size();i++){
        v[i]=abs(v[i]-x);
    }
    for(int i=0;i<v.size()-1;i++){
        for(int j=0;j<v.size()-1-i;j++){
            if(v[j]>v[j+1]){
                int aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }

    //imprimir los valores k vecinos
    for(int q=0;q<k;q++){
        cout<<v[q]+x<<" ";
    }

    
        

    
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    CBinTree t;
    t.Insert(55); t.Insert(41); t.Insert(77);
    t.Insert(33); t.Insert(47); t.Insert(61);
    t.Insert(88); t.Insert(20); t.Insert(36);
    t.Insert(44); t.Insert(51); t.Insert(57);
    t.Insert(65); t.Insert(80); t.Insert(99);
    t.Print();
    
    t.kneighbors(33,4);
    t.kneighbors(88,3);
    t.kneighbors(76,2);
    t.kneighbors(47,5);
    t.kneighbors(61,4);
    t.kneighbors(50,3);
    t.kneighbors(81,5);
    t.kneighbors(20,7);
}
