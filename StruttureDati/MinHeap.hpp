#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class MinHeap {
    private:
        vector<T>* heap;
        int heapSize;
        int left(int i){return 2*i+1;}
        int right(int i){return 2*i+2;}
        void buildMinHeap();
    protected:
        int parent(int i){return (i-1)/2;}
        T getRoot(){return this->heap->at(0);}
        T getTaill(){return this->heap->at(heapSize-1);}
        vector<T>* getHeap(){return this->heap;}
        void setHeap(int i, T key){this->heap.at(i) = key;}
        void setHeapSize(int heapSize){this->heapSize = heapSize;}
        int getHeapSize(){return this->heapSize;}
        void swap(T& a, T& b);
        void minHeapify(int);
    public:
        MinHeap();
        MinHeap(vector<T>*);
        ~MinHeap();
        void print();
        void insert(T);
};

template <typename T>
MinHeap<T>::MinHeap() {
    this->heap = new vector<T>;
    this->heapSize = 0;
}

template <typename T>
MinHeap<T>::MinHeap(vector<T>* heap) {
    this->heap = heap;
    this->heapSize = heap->size();
    buildMinHeap();
}

template <typename T>
MinHeap<T>::~MinHeap() {
    delete heap;
}

template <typename T>
void MinHeap<T>::swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void MinHeap<T>::buildMinHeap() {
    for(int i = heapSize/2; i >= 0; i--)
        minHeapify(i);
}

template <typename T>
void MinHeap<T>::print() {
    cout << "MinHeap" << endl;
    for(int i = 0; i < heapSize; i++)
        cout << heap->at(i) << " ";
    cout << endl;
}

template <typename T>
void MinHeap<T>::minHeapify(int i) {
    int min = i;
    int leftC = left(i);
    int rightC = right(i);
    if(leftC < heapSize && this->heap->at(min) > this->heap->at(leftC))
        min = leftC;
    if(rightC < heapSize && this->heap->at(min) > this->heap->at(rightC))
        min = rightC;
    if(min != i) {
        swap(this->heap->at(i), this->heap->at(min));
        minHeapify(min);
    }
}

template <typename T>
void MinHeap<T>::insert(T key) {
    heapSize++;
    this->heap->push_back(key);
    int i = heapSize-1;
    while(i > 0 && this->heap->at(parent(i)) > this->heap->at(i)) {
        swap(this->heap->at(i), this->heap->at(parent(i)));
        i = parent(i);
    }
}

#endif