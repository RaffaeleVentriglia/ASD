#include <iostream>
using namespace std;

class Algoritmo {
    public:
        void BubbleSort(int*, int, int);
        void compSwap(int&, int&);
        void swap(int&, int&);
        void stampa(int*, int);
};

void Algoritmo::stampa(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}

void Algoritmo::compSwap(int &a, int &b) {
    if(b < a) {
        swap(a, b);
    }
}

void Algoritmo::swap(int &a, int &b) {
    int T = a;
    a = b;
    b = T;
}

void Algoritmo::BubbleSort(int* arr, int left, int right) {
    int i, j;
    for(i = left; i < right; i++) {
        for(j = right; j > i; j--) {
            compSwap(arr[j-1], arr[j]);
        }
    }
    stampa(arr, right);
}