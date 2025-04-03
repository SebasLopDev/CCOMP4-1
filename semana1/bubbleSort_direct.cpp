#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono; 

void swap(int &a,int &b){
    int aux=a;
    a=b;
    b=aux;
}

bool asc(int a,int b){
     return a>b;
};
bool desc(int a,int b){
    return a<b;
};

void bubbleSortD_Asc(int *arr,int tam){
    for(int i=0;i<tam-1;i++){
        for(int j=0;j<tam-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

}

void bubbleSortD_Desc(int *arr,int tam){
   for(int i=0;i<tam-1;i++){
        for(int j=0;j<tam-1-i;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

}
void mostrar(int *arr,int tam){
    for(int i=0;i<tam;i++){
        cout<<arr[i]<<" ";
    }

}





int main(){

    /*int arr[]={45, 12, 89, 32, 67, 24, 78, 91, 10, 53,
    6, 83, 37, 95, 28, 41, 55, 99, 14, 72,
    63, 30, 21, 81, 1, 47, 19, 74, 52, 96,
    88, 33, 16, 79, 92, 58, 25, 62, 36, 86,
    11, 66, 98, 3, 43, 76, 8, 90, 5, 54,
    22, 50, 97, 70, 38, 29, 85, 46, 34, 82,
    7, 94, 13, 61, 26, 68, 9, 42, 100, 23,
    56, 77, 40, 15, 80, 48, 31, 71, 2, 49,
    59, 93, 35, 64, 87, 20, 4, 57, 75, 27,
    17, 65, 60, 39, 84, 44, 18, 51, 73, 31};
    
    int tam=sizeof(arr)/sizeof(arr[0]);*/


    const int tam = 100000;
    int arr[tam];

    srand(time(0)); // Inicializar semilla aleatoria
    for (int i = 0; i < tam; i++) {
        arr[i] = rand() % 20000; // Números aleatorios entre 0 y 9999
    }

    auto inicio = high_resolution_clock::now();  // Inicio del tiempo
    bubbleSortD_Desc(arr,tam);
    auto fin = high_resolution_clock::now();  // Fin del tiempo

    mostrar(arr,tam);

    auto duracion = duration_cast<milliseconds>(fin - inicio);
    cout << "Tiempo de ejecucion: " << duracion.count() << " ms" << endl;




    return 0;
}