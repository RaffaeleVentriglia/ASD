#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MaxHeap {
    private:
        vector<T>* heap;
        int heapSize;
        int left(int i){return 2*i+1;}
        int right(int i){return 2*i+2;}
        void buildMaxHeap();
    protected:
        int parent(int i){return(i-1)/2;}
        T getRoot(){return this->heap.at(0);}
        T getTail(){return this->heap.at(heapSize-1);}
        vector<T>* getHeap(){return this->heap;}
        void setHeap(int i, T key){this->heap.at(i) = key;}
        void setHeapSize(int heapSize){this->heapSize = heapSize;}
        int getHeapSize(){return this->heapSize;}
        void maxHeapify(int);
        void swap(T&, T&);
    public:
        MaxHeap(vector<T>*);
        MaxHeap();
        ~MaxHeap();
        void insert(T);
        void print();
};

template <typename T>
void MaxHeap<T>::swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
MaxHeap<T>::MaxHeap(vector<T>* heap) {
    this->heap = heap;
    this->heapSize = heapSize;
    buildMaxHeap();
}

template <class T>
MaxHeap<T>::MaxHeap() {
    this->heap = new vector<T>;
    this->heapSize = 0;
}

template <typename T>
MaxHeap<T>::~MaxHeap() {
    delete heap;
}

template <typename T>
void MaxHeap<T>::buildMaxHeap() {
    for(int i = heapSize/2; i >= 0; i--)
        maxHeapify(i);
}

template <typename T>
void MaxHeap<T>::maxHeapify(int i) {
    int max = i;
    int leftC = left(i);
    int rightC = right(i);
    if(leftC < heapSize && this->heap.at(max) < this->heap.at(leftC))
        max = leftC;
    if(rightC < heapSize && this->heap.at(max) < this->heap.at(rightC))
        max = rightC;
    if(max != i) {
        swap(this->heap.at(i), this->heap.at(max));
        maxHeapify(max);
    }
}

template <typename T>
void MaxHeap<T>::insert(T key) {
    heapSize++;
    this->heap.push_back(key);
    int i = heapSize-1;
    while(i != 0 && this->heap.at(parent(i)) < this->heap.at(i)) {
        swap(this->heap.at(i), this->heap.at(parent(i)));
        i = parent(i);
    }
}

template <typename T>
void MaxHeap<T>::print() {
    cout << "MAxHeap" << endl;
    for(int i = 0; i < heapSize; i++)
        cout << heap.at(i) << " ";
    cout << endl;
}

#endif
