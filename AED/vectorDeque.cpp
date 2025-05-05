#include <iostream>

class XVector
{
public:
    XVector(int size_map, int size_vec);
    ~XVector();
    void push_back(int x);
    void push_front(int x);
    int operator[](int i);
    int** map;
    int **ptr;
    int size_map, size_vec;
    int count;
};

int XVector::operator[](int i){
    int row = i / size_vec;
    int col = i % size_vec;
    return map[row][col];
}
XVector::XVector(int sm, int sv)
{
    size_map = sm;
    size_vec = sv;
    map= new int*[size_map];
    for(int **p=map;p<map+size_map;p++){
        *p=new int[size_vec];
    }
    ptr=map;
    count=0;

}

XVector::~XVector()
{
    for(int **p=map;p<map+size_map;p++){
        delete[] *p;
    }
    delete[] map;
}

void XVector::push_back(int x){
    /*if((*ptr)==(*map)+size_vec){
        ptr++;

    }*/
    if(count==size_map*size_vec){
        int nsize=size_map*2;
        int **newMap;
        newMap=new int*[nsize];
        for(int **i=newMap;i<newMap+nsize;i++){
            *i=new int[size_vec];
        }
        //copiar valores
        for(int r=0;r<size_map;r++){
            for(int s=0;s<size_vec;s++){
                *(*(newMap+r)+s)=*(*(map+r)+s);
            }
            //newMap++;
        }
        for(int **r=map;r<map+size_map;r++){
            delete[] *r;
        }
        delete [] map;
        //delete[] map;
        map=newMap;
        size_map=nsize;

        
    }
    int row = count / size_vec;
    int col = count % size_vec;
    *(*(map+row)+col) = x;
    count++;
    /***ptr=x;
    (*ptr)+=1;*/

}

void XVector::push_front(int x){
    if(count==size_map*size_vec){
        int nsize=size_map*2;
        int **newMap;
        newMap=new int*[nsize];
        for(int **p=newMap; p<newMap+nsize;p++){
            *p=new int[size_vec];
        }
        //copiar elementos mas a la derecha
        for(int i=0;i<size_map;i++){
            for(int j=0;j<size_vec;j++){
                *(*(newMap+i)+j)=*(*(map+i)+j);
            }
        }
        for(int **r=map;r<map+size_map;r++){
            delete[] *r;
        }
        delete [] map;
        //delete[] map;
        map=newMap;
        size_map=nsize;


    }
    //mover a la derecha el arreglo
    for(int i = count; i > 0; --i){
        int row_now = i / size_vec;
        int col_now = i % size_vec;
        int row_prev = (i - 1) / size_vec;
        int col_prev = (i - 1) % size_vec;    
        *(*(map+row_now)+col_now) = *(*(map+row_prev)+col_prev);
    }

    **map= x;
    count++;
}

void print( XVector* p)
{ //no modificar esta función
    for ( int i = 0; i < p->count; i++ )
        std::cout<<(*p)[i]<<" ";
    std::cout<<"\n";
}

int main()
{
    //no modificar esta función main
    XVector v(4,3);
    v.push_back(3); v.push_back(8); v.push_back(1);
    v.push_back(4); v.push_back(9); v.push_back(6);
    v.push_back(7);
    print(&v);
    v.push_front(5); v.push_front(2);
    print(&v);
    v.push_front(11); v.push_front(17);
    v.push_back(22);
    print(&v);
    v.push_front(33); v.push_back(77);
    print(&v);
}