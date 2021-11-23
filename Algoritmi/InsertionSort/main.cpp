#include "main.hpp"

int main() {
    Algoritmo InsertionSort;
    int arr[9] = {1,3,5,7,9,2,4,6,8};
    int key;
    int length = 9;
    InsertionSort.InsertionSort(arr, key, length);
    return 0;
}