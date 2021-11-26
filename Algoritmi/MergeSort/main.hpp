#include <iostream>
using namespace std;

class Algoritmo {
    public:
        void merge(int*, int*, int, int*, int);
        void MergeSort(int*, int, int);
        void Cormen(int*);
        void stampa(int *, int);
};

void Algoritmo::merge(int* c, int* arr, int N, int* b, int M) {
    for( int i=0, j=0, k=0; k< N+M; k++) {
        if ( i == N) { 
            c[k] = b[j++]; 
            continue;
        }
        if ( j == M) { 
            c[k] = arr[i++]; 
            continue;
        }
        c[k] = (arr[i] < b[j]) ? arr[i++] : b[j++];
    }
}

void Algoritmo::MergeSort(int* arr, int left, int right) {
    if(left < right) {
        int r = (left+right)/2;
        MergeSort(arr, left, r);
        MergeSort(arr, r+1, right);
        //merge(arr, left, right, r);
    }
}

void Algoritmo::stampa(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}