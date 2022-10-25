/*
    Progettare ed implementare un algoritmo 
    ricorsivo che dato un array verifichi 
    se rappresenta un heap binario
*/

#include <iostream>

int left(int i) {
    return (2*i)+1;
}

int right(int i) {
    return (2*i)+2;
}

bool checkHeap(int *arr, int size, int i) {
    if(i > (size-2)/2)
        return true;
    bool leftC = ((arr[i] >= arr[left(i)]) && checkHeap(arr, size, left(i)));
    bool rightC = ((arr[i] >= arr[right(i)]) && checkHeap(arr, size, right(i)));
    return rightC && leftC;
}

int main() {
    int arr1[] = {1,5,20,50,3,9,7}; // false
    int arr2[] = {20,19,18,17,16,10}; // true
    bool isHeap1 = checkHeap(arr1, sizeof(arr1)/sizeof(arr1[0]), 0);
    bool isHeap2 = checkHeap(arr2, sizeof(arr2)/sizeof(arr2[0]), 0);
    std::cout << std::boolalpha << "isHeap: " << isHeap1 << std::endl;
    std::cout << std::boolalpha << "isHeap: " << isHeap2 << std::endl;
    return 0;
}