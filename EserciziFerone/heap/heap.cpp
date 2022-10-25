#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "maxHeap.hpp"
using namespace std;

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
    MaxHeap<int> tree(new vector<int>, 0);
    /*
    for(size_t i = 0; i < 5; i++) {
        int n = (rand()%10)+1;
        tree.insert(n);
    }
    */
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(70);
    tree.insert(1);
    tree.insert(2);
    tree.insert(5);
    tree.insert(100);
    tree.insert(200);
    tree.print();
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

    // int arr[] = {1,5,2,10,50,25,30,60};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // construct_heap(arr, size);
    // printHeap(arr, size);
    
    return 0;
}
