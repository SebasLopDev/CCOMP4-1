#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

void copiarArreglo(int* origen, int* destino, int tam) {
    for (int i = 0; i < tam; i++) {
        destino[i] = origen[i];
    }
}

void swap(int& a, int& b) {
    int aux = a;
    a = b;
    b = aux;
}

bool asc(int a, int b) { 
    return a > b;
}

bool desc(int a, int b) {
    return a < b;
}
//burbuja directa
void bubbleSortD_Asc(int* arr, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

void bubbleSortD_Desc(int* arr, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}


//burbuja polimorfica
class Orden {
public:
    virtual void ordenar(int*, int) = 0;
    virtual ~Orden() {}
};

class Bubble_Asc : public Orden {
public:
    void ordenar(int* arr, int tam) override {
        for (int i = 0; i < tam - 1; i++) {
            for (int j = 0; j < tam - 1 - i; j++) {
                if (asc(arr[j], arr[j + 1])) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

class Bubble_Desc : public Orden {
public:
    void ordenar(int* arr, int tam) override {
        for (int i = 0; i < tam - 1; i++) {
            for (int j = 0; j < tam - 1 - i; j++) {
                if (desc(arr[j], arr[j + 1])) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};


//burbuja punteros a funciones
void bubble(int* arr, int tam, bool (*comp)(int, int)) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (comp(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


//burbuja functores

template<class T>
class ASC {
public:
    inline bool operator()(const T &a,const T &b){ 
        return a > b;
    }
};

template<class T>
class DESC {
public:
    inline bool operator()(T a, T b){ 
        return a < b;
    }
};

template<class T, class O>
class BubbleSort {
public:
    O obj;
    void operator()(T* arr, int tam){ 
        for (int i = 0; i < tam - 1; i++) {
            for (int j = 0; j < tam - 1 - i; j++) {
                if (obj(arr[j], arr[j + 1])) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

void mostrar(int* arr, int tam = 30) {
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << "(primeros 30 valores)\n";
}

int main() {
    const int tam = 10000;

    int* original = new int[tam];
    int* copia = new int[tam];

    srand(static_cast<unsigned int>(time(0))); 
    for (int i = 0; i < tam; i++) {
        original[i] = rand() % 20000;
    }

    duration<double, milli> duracion;

    //DIRECTA
    copiarArreglo(original, copia, tam);
    auto inicio = high_resolution_clock::now();
    bubbleSortD_Asc(copia, tam);
    auto fin = high_resolution_clock::now();
    duracion = fin - inicio;
    cout << "Bubble Sort normal Ascendente:\n";
    mostrar(copia);
    cout << "Tiempo: " << duracion.count() << " ms\n\n";

    //FUNCTORES
    copiarArreglo(original, copia, tam);
    BubbleSort<int, ASC<int>> bubbleAsc;
    inicio = high_resolution_clock::now();
    bubbleAsc(copia, tam);
    fin = high_resolution_clock::now();
    duracion = fin - inicio;
    cout << "Bubble Sort con functores (Ascendente):\n";
    mostrar(copia);
    cout << "Tiempo: " << duracion.count() << " ms\n\n";

    //POLIMORFISMO
    copiarArreglo(original, copia, tam);
    Orden* p = new Bubble_Asc();
    inicio = high_resolution_clock::now();
    p->ordenar(copia, tam);
    fin = high_resolution_clock::now();
    duracion = fin - inicio;
    cout << "Bubble Sort con polimorfismo (Ascendente):\n";
    mostrar(copia);
    cout << "Tiempo: " << duracion.count() << " ms\n\n";
    delete p;

    //PUNTEROS A FUNCIONES
    copiarArreglo(original, copia, tam);
    inicio = high_resolution_clock::now();
    bubble(copia, tam, asc);
    fin = high_resolution_clock::now();
    duracion = fin - inicio;
    cout << "Bubble Sort con puntero a función (Ascendente):\n";
    mostrar(copia);
    cout << "Tiempo: " << duracion.count() << " ms\n\n";


    delete[] original;
    delete[] copia;

    return 0;
}
