#include <iostream>
using namespace std;

class Algoritmo {
    public:
        int arr[10] = {1,3,5,7,9,2,4,6,8,10};
        int length = 9;
        void QuickSort(int*, int, int);
        int Partition(int*, int, int);
        void stampa(int*, int);
        void swap(int&, int&);
};

void Algoritmo::QuickSort(int* arr, int p, int r) {
    if(p < r) {
        int q = Partition(arr, p, r);
        QuickSort(arr, p, q);
        QuickSort(arr, q+1, r);
    }
}

int Algoritmo::Partition(int* arr, int p, int r) {
    int x = arr[r];
    int i = p-1;
    for(int j = p; j <= r-1; j++) {
        if(arr[j] <= x) {
            i = i+1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void Algoritmo::swap(int &a, int &b) {
    int T = a;
    a = b;
    b = T;
}

void Algoritmo::stampa(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}