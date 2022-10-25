#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
void swap(T *x, T *y) {
    T temp = *x;
    *x = *y;
    *y = temp;
}


template <typename T>
void heapify2(vector<T> vec, T i) {
    int size = vec.size(); // trovo il size dell'array
    T largest = i; // imposto i come il più grande elemento
    T left = 2*i+1, right = 2*i+2;
    if(left < size && vec[left] > vec[largest])
        largest = left;
    if(right < size && vec[right] > vec[largest])
        largest = right;
    if(largest != i) {
        swap(vec[i], vec[largest]);
        heapify2(vec, largest);
    }


template <typename T>
void build_max_heap(vector<T> vec) {
    int size = vec.size();
    for(int i = (size/2); i >= 1; i--)
        heapify2(vec, i);
}

template <typename T>
void insert(vector<T> vec, T newN) {
    int size = vec.size();
    if(size == 0)
        vec.push_back(newN);
    else {
        vec.push_back(newN);
        for(int i = size/2-1; i >= 0; i--)
            heapify(vec, i);
    }
}

template <typename T>
void print(vector<T> vec) {
    for(size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << "\n";
}

void heapify(int *arr, int arr_size, int subtree) {
    int largest = subtree;
    int left = 2*subtree+1;
    int right = 2*subtree+2;
    if(left < arr_size && arr[left] > arr[largest])
        largest = left;
    if(right < arr_size && arr[right] > arr[largest])
        largest = right;
    if(largest != subtree) {
        swap(arr[subtree], arr[largest]);
        heapify(arr, arr_size, largest);
    }
}

void construct_heap(int *arr, int arr_size) {
    int lastNonLeafNode = (arr_size/2)-1;
    for(int subtree = lastNonLeafNode; subtree >= 0; subtree--) {
        heapify(arr, arr_size, subtree);
    }
}

void printHeap(int *arr, int arr_size) {
    for(int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand((unsigned)time(0));
    vector<int> heap;
    //    insert(heap, 3);

	/*
    for(int i = 0; i < 5; i++) {
        int n = (rand()%10)+1;
        heap.push_back(n);
    }
    print(heap);
    cout << "Max-Heap Array \n";
    build_max_heap(heap);
    print(heap);
    */

    int arr[] = {1,5,2,10,50,25,30,60};
    int size = sizeof(arr)/sizeof(arr[0]);
    construct_heap(arr, size);
    printHeap(arr, size);
    
    return 0;
}
