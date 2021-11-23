#include <iostream>
using namespace std;

void stampa(int*, int);
void compSwap(int&, int&);
void swap(int&, int&);
void InsertionSort(int*, int, int);
void BubbleSort(int*, int, int);

void stampa(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}

void compSwap(int &a, int &b) {
    if(b < a) {
        swap(a, b);
    }
}

void swap(int &a, int &b) {
    int T = a;
    a = b;
    b = T;
}

void InsertionSort(int* arr, int key, int length) {
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

void BubbleSort(int* arr, int left, int right) {
    int i, j;
    for(i = left; i < right; i++) {
        for(j = right; j > i; j--) {
            compSwap(arr[j-1], arr[j]);
        }
    }
    stampa(arr, right);
}