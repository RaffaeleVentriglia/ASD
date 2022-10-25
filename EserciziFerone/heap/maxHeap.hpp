#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class MaxHeap {
    private:
        vector<T>* tree;
        int heapSize;

        int parent(int i) { return (i-1)/2; };
        int leftChild(int i) { return 2*i+1; };
        int rightChild(int i) {return 2*i+2; };

        void buildMaxHeap();
        void maxHeapify(int i);
        void swap(T& a, T& b);
    public:
        MaxHeap(vector<T>* tree, int heapSize);
        void insert(T key);
        void print();
};

template <typename T>
MaxHeap<T>::MaxHeap(vector<T>* tree, int heapSize) {
    this->tree = tree;
    this->heapSize = heapSize;
    buildMaxHeap();
}

template <typename T>
void MaxHeap<T>::maxHeapify(int i) {
    int largest = i; // elemento massimo
    int leftC = leftChild(i); // figlio sinistro
    int rightC = rightChild(i); // figlio destro
    if(leftC < heapSize && this->tree->at(leftC) > this->tree->at(largest))
        largest = leftC;
    if(rightC < heapSize && this->tree->at(rightC) > this->tree->at(largest))
        largest = rightC;
    if(largest != i) {
        swap(this->tree->at(i), this->tree->at(largest));
        maxHeapify(largest);
    }
}

template <typename T>
void MaxHeap<T>::insert(T key) {
    this->tree->push_back(key);
    heapSize++;
    buildMaxHeap();
}

template <typename T>
void MaxHeap<T>::buildMaxHeap() {
    for(int i = heapSize/2; i >= 0; i--)
        maxHeapify(i);
}

template <typename T>
void MaxHeap<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void MaxHeap<T>::print() {
    cout << "Max Heap" << endl;
    for(int i = 0; i < heapSize; i++)
      cout << tree->at(i) << " ";
    cout << endl;
}

#endif