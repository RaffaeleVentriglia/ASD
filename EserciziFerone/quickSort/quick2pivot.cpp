/*
    • Implementare il Quicksort con doppio pivot
    • Questa variante utilizza un pivot per la parte sinistra dell'array ed
    un pivot per la parte destra con il vincolo che il pivot sinistro sia
    minore del pivot destro
    • Al termine della procedura di partition, l'array sarà diviso in tre
    parti:
    • La prima in cui gli elementi sono minori del pivot sinistro
    • La seconda in cui gli elementi sono maggiori o uguali del
    pivot sinistro e minori uguali del pivot destro
    • La terza in cui gli elementi sono maggiori del pivot destro
    • L'algoritmo viene richiamato ricorsivamente sulle tre parti
    dell'array
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int partition(int *arr, int left, int right) {
    int i = left - 1;
    int piv = right;
    while(true) {
        while(arr[++i] <= piv);
        while(piv < arr[--piv])
            if(piv == left)
                break;
        if(i >= piv)
            break;
        swap(arr[i], arr[piv]);
    }
    swap(arr[i], arr[right]);
    return i;
}

void quickSort(int *arr, int left, int right) {
    if(left < right) {
        int piv1 = partition(arr, left, right);
        int piv2 = partition(arr, piv1, right);
        quickSort(arr, left, piv1 - 1);
        quickSort(arr, piv1 + 1, piv2 - 1);
        quickSort(arr, piv2 + 1, right);
    }
}

void printArray(int *arr, int size) {
    for(size_t i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    srand((unsigned)time(0));
    int size = (rand() % 10) + 1;
    int arr[size];
    for(size_t i = 0; i < size; i++)
        arr[i] = (rand() % 10) + 1;
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}