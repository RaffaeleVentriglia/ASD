/*
    Progettare ed implementare una
    procedura quicksort iterativa
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stack.h"
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int partition(int *arr, int left, int right) {
    int i = left - 1, j = right;
    int v = arr[right];
    while(1) {
        while(arr[++i] < v);
        while(v < arr[--j])
            if(j == left)
                break;
        if(i >= j)
            break;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[right]);
    return i;
}

void quickSort(int *arr, int left, int right) {
    // creiamo uno stack
    Stack<int> st;

    st.Push(left);
    st.Push(right);

    while(!st.isEmpty()) {
        st.Pop(left);
        st.Pop(right);
        int p = partition(arr, left, right);
        if(p < left) {
            st.Push(left);
            st.Push(p - 1);
        } else if(right > p) {
            st.Push(p + 1);
            st.Push(right);
        }
    }
}

void printArray(int *arr, int size) {
    for(size_t i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {2, 4, 3, 1};
    printArray(arr, 4);
    quickSort(arr, 0, 3);
    printArray(arr, 4);
    return 0;
}
