#ifndef MINKHEAP_HPP
#define MINKHEAP_HPP

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class minKheap {
    private:
        vector<T>* heap;
        int heapSize;
        int k;
        void buildMinKHeap();
        void MinKheapify(int);
        void swap(T& a, T& b);
    public:
        minKheap(int);
        minKheap(vector<T>*, int);
        ~minKheap();
        void insert(T);
        void print();
};

template <typename T>
minKheap<T>::minKheap(int k) {
    this->heap = new vector<T>;
    this->heapSize = 0;
    this->k = k;
}

template <typename T>
minKheap<T>::minKheap(vector<T>* heap, int k) {
    this->heap = heap;
    this->heapSize = heap->size();
    this->k = k;
    buildMinKHeap();
}

template <typename T>
minKheap<T>::~minKheap() {delete heap;}

template <typename T>
void minKheap<T>::print() {
    cout << "Min K Heap" << endl;
    for(int i = 0; i < heapSize; i++)
        cout << heap->at(i) << " ";
    cout << endl;
}

template <typename T>
void minKheap<T>::swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void minKheap<T>::buildMinKHeap() {
    for(int i = heapSize/k; i >= 0; i--)
        MinKheapify(i);
}

template <typename T>
void minKheap<T>::insert(T key) {
    heapSize++;
    this->heap->push_back(key);
    buildMinKHeap();
}

template <typename T>
void minKheap<T>::MinKheapify(int i) {
    int index = i+1;
    int last = k*index;
    int first = last-k;
    int min = i;
    for(int j = last; j > first; j--)
        if(j < heapSize && this->heap->at(min) > this->heap->at(j))
            min = j;
    if(min != i) {
        swap(this->heap->at(i), this->heap->at(min));
        MinKheapify(min);
    }
}

#endif