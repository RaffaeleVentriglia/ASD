#ifndef MAXKHEAP_HPP
#define MAXKHEAP_HPP

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class maxKheap {
    private:
        vector<T>* heap;
        int heapSize;
        int k;
        void buildMaxKHeap();
        void maxKheapify(int);
        void swap(T& a, T& b);
    public:
        maxKheap(int);
        maxKheap(vector<T>*, int);
        ~maxKheap();
        void insert(T);
        void print();
};

template <typename T>
maxKheap<T>::maxKheap(int k) {
    this->heap = new vector<T>;
    this->heapSize = 0;
    this->k = k;
}

template <typename T>
maxKheap<T>::maxKheap(vector<T>* heap, int k) {
    this->heap = heap;
    this->heapSize = heap->size();
    this->k = k;
    buildMaxKHeap();
}

template <typename T>
maxKheap<T>::~maxKheap() {
    delete heap;
}

template <typename T>
void maxKheap<T>::print() {
    cout << "Max K Heap" << endl;
    for(int i = 0; i < heapSize; i++)
        cout << heap->at(i) << " ";
    cout << endl;
}

template <typename T>
void maxKheap<T>::swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void maxKheap<T>::buildMaxKHeap() {
    for(int i = heapSize/k; i >= 0; i--)
        maxKheapify(i);
}

template <typename T>
void maxKheap<T>::insert(T key) {
    heapSize++;
    this->heap->push_back(key);
    buildMaxKHeap();
}

template <typename T>
void maxKheap<T>::maxKheapify(int i) {
    int max = i;
    int index = i+1;
    int last = k*index;
    int first = last-k;
    for(int j = last; j > first; j--)
        if(j < heapSize && this->heap->at(max) < this->heap->at(j))
            max = j;
    if(max != i) {
        swap(this->heap->at(i), this->heap->at(max));
        maxKheapify(max);
    }
}

#endif