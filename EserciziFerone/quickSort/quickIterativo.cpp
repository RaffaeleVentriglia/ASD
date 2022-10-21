/*
    Progettare ed implementare una
    procedura quicksort iterativa
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include "stack.h"
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int index = left;
    for(int i = left; i < right; i++) {
        if(arr[i] <= pivot) {
            swap(arr[i], arr[index]);
            index++;
        }
    }
    swap(arr[index], arr[right]);
    return index;
}

void quickSort(int *arr, int n) {
    stack<pair<int, int>> st;
    int left = 0;
    int right = n-1;
    st.push(make_pair(left, right));
    while(!st.empty()) {
        left = st.top().first;
        right = st.top().second;
        st.pop();
        int pivot = partition(arr, left, right);
        if(pivot - 1 > left)
            st.push(make_pair(left, pivot - 1));
        if(pivot + 1 < right)
            st.push(make_pair(pivot + 1, right));
    }
}

/*
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
*/

void printArray(int *arr, int size) {
    for(size_t i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {2, 4, 3, 1};
    printArray(arr, 4);
    quickSort(arr, 4);
    printArray(arr, 4);
    return 0;
}
