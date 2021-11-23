#include "main.hpp"

int main() {
    Algoritmo BubbleSort;
    int arr[10] = {1,3,5,7,9,2,4,6,8,10};
    int left = 0;
    int right = 9;
    BubbleSort.BubbleSort(arr, left, right);
    return 0;
}