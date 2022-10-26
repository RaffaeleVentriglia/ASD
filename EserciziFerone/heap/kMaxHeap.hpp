#ifndef KMAXHEAP_HPP
#define KMAXHEAP_HPP

#include <iostream>
#include <vector>

template <class T>
class kMaxHeap {
    private:
        std::vector<T>* heap;
        int heapSize;
        int k;
        void buildHeap();
        void kMaxHeapify(int i);
        void swap(T& a, T& b);
    public:
        kMaxHeap(std::vector<T>* heap, int heapSize, int k);
        void insert(T key);
        void print();
};

template <typename T>
kMaxHeap<T>::kMaxHeap(std::vector<T>* heap, int heapSize, int k) {
    this->heap = heap;
    this->heapSize = heapSize;
    this->k = k;
    buildHeap();
}

template <typename T>
void kMaxHeap<T>::kMaxHeapify(int i) {
    int index = i+1;
    int last = k*index;
    int first = last-k;
    int largest = i;
    for (int j = last; j > first; j++)
        if(j < heapSize && this->heap->at(largest) < this->heap->at(j))
            largest = j;
    if(largest != i) {
        swap(this->heap->at(i), this->heap->at(largest));
        kMaxHeapify(largest);
    }
}

template <typename T>
void kMaxHeap<T>::buildHeap() {
    for(int i = heapSize/k; i >= 0; i--)
        kMaxHeapify(i);
}

template <typename T>
void kMaxHeap<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void kMaxHeap<T>::insert(T key) {
    this->heap->push_back(key);
    heapSize++;
    buildHeap();
}

template <typename T>
void kMaxHeap<T>::print() {
    std::cout << "K Max Heap\n";
    for(int i = 0; i < heapSize; i++)
        std::cout << heap->at(i) << " ";
    std::cout << std::endl;
}

#endif