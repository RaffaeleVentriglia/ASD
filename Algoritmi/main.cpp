#include "main.hpp"

int main() {
    int arr[10] = {1,3,5,7,9,2,4,6,8,10};
    int key;
    int length = 9;
    int left = 0;

    cout << "InsertionSort" << endl;
    InsertionSort(arr, key, length);
    cout << "BubbleSort" << endl;
    BubbleSort(arr, left, length);
    cout << "CountingSort" << endl;
    countingSort(arr, length);
    return 0;
}