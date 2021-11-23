#include <iostream>
using namespace std;

class Algoritmo {
    public:
        void InsertionSort(int*, int, int);
        void stampa(int*, int);
};

void Algoritmo::InsertionSort(int* arr, int key, int length) {
    int i;
    for(int j = 2; j <= length; j++) {
        key = arr[j];
        i = j - 1;
        while(i > 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key;
    }
    stampa(arr, length);
}

void Algoritmo::stampa(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}