#include <iostream>
using namespace std;

class Algoritmo {
    public:
        int arr[10] = {1,3,5,7,9,2,4,6,8,10};
        int length = 9;

        void merge(int*, int, int, int);
        void MergeSort(int*, int, int);
        void Cormen(int*);
        void stampa(int *);
};

void Algoritmo::merge(int* arr, int left, int right, int middle) {

}

void Algoritmo::MergeSort(int* arr, int left, int right) {
    if(left < right) {
        //MergeSort(arr, );
    }
}

void Algoritmo::stampa(int* arr) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}