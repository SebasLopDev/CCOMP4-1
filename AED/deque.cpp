#include<iostream>
using namespace std;

class Deque{
    private:
        int **map;
        int **acc;
        int **pi;
        int **pf;
        int sizeBloq;
        int sizeMap;
        int *posb;
        int *posf;
        int **iposb;
        int **iposf;
        //int ifr;
        //int jfr;
        //int ibk;
        //int jbk;

    public:
        Deque(int bloq,int tmap){
            sizeBloq=bloq;
            sizeMap=tmap;
            map=new int*[tmap];
            for(int **p=map;p<map+tmap;p++){
                *p=new int[bloq];
            }
            int mid=tmap/2;
            pi=map+mid-1;//map[mid];
            pf=map+mid-1;//mp[mid];
            posb=*pf;
            posf=*pi;
            acc=map;
            iposf=pi;
            iposb=pf;
            //ifr=mid;
            //ibk=mid;
            //jfr=0;
            //jbk=0;
        }

        ~Deque(){
            for(int **p=map;p<map+sizeMap;p++){
                delete[] *p;
            }
            delete[] map;
        }
        
        /*bool estaVacio(){
            //return pi==pf && j==0;
        }*/
        int operator [](int ind){
            int mid=ind/sizeBloq;
            int bid=ind%sizeBloq;
            return map[mid][bid];
        }
        void push_back(int x){
            //*(*(acc+ifr)+jfr);     
            if(pf==pi){
                pi--;
                iposf--;
            }
            //acc[ifr][jfr]=x;
            //jfr++;
            if(posb==*pf+sizeBloq && pf!=map+sizeMap){
                pf++;   
                posb = *pf;            
            }
            //redimensionar
            //int *m;
            //int tam=iposb-map-1;
            if(posb==*pf+sizeBloq && pf==map+sizeMap){
                int nsizeMap=sizeMap+1;
                int **newMap=new int*[nsizeMap];
                //m=*newMap;
                for(int **p=newMap;p<newMap+nsizeMap;p++){
                    *p=new int[sizeBloq];                   
                }
                for(int i=0;i<sizeMap;i++){
                    for(int j=0;j<sizeBloq;j++){
                        newMap[i][j]=map[i][j];
                        /**m=*t;
                        *(m+1);
                        if(*m<sizeBloq){
                            m=*q;
                        }*/
                    }
                    //*newMap=*q;
                    //newMap++;
                }
                /*for(int **q=newMap+sizeMap-1+tam;q<newMap+sizeMap;q++){

                    *q=*m;
                    m++;
                    //temp++;
                }*/
                for(int **r=map;r<map+sizeMap;r++){
                    delete[] *r;
                }
                delete [] map;
                //delete[] map;
                map=newMap;
                sizeMap=nsizeMap;
                /*for(int **r=;r<temp+sizeMap;r++){
                    delete[] *r;
                }
                delete [] temp;*/
            }
            
            *posb=x;
            posb++;
            *pf=posb;


            
            //**pf=x;
            //(*pf)++;


            /*if(estaVacio()){
                *(*(map+i)+j) = x;
                j++;
                pf = map[i];
                return;
                // *pf=x; 
                //pi--;
                               
            }

            if(j==sizeBloq){
                if(i + 1 == sizeMap){
                    cout << "Desbordamiento de mapa. Redimensionar aquí.\n";
                    return;
                }
                i++;
                j = 0;
                //pf++;
                i++;                
                j=0;*/
            //}
            /*if(i==sizeMap){
                int nsize=sizeMap*2;
                int **temp=new int*[nsize];
                for(int **p=temp;p<temp+nsize;p++){
                    *p=new int[sizeBloq];
                }
                map=temp;

            }            
            *(*(acc+i)+j)=x;
            j++;
            pf=map[i];*/

            
        }
        void print(){
            for(int i=0;i<sizeMap;i++){
                for(int j=0;j<sizeBloq;j++){
                    cout<<map[i][j]<<" ";
                }
            }        
            /*for(int **p=map;p<map+sizeMap;p++){
                for(int *q=*map;q<*map+sizeBloq;q++){
                    cout<<*q<<" ";
                }
            }*/
        }
       





};

int main(){
    Deque deque(5,7);
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.push_back(4);
    deque.push_back(5);

    deque.print();

    return 0;
}