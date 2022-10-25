#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MinHeap {
    private:
        vector<T>* tree;
        int heapSize;
        int parent(int i){return (i-1)/2;};
        int left(int i){return 2*i+1;};
        int right(int i){return 2*i+2;};
        void buildMinHeap();
        void minHeapify(int i);
        void swap(T& a, T& b);
    public:
        MinHeap(vector<T>* tree, int heapSize);
        void insert(T key);
        void print();
        double sumValue(int root, double x);
        void sumValue(int root, double x, double& sum);
};

template <typename T>
void MinHeap<T>::print(){
    cout << "***Min Heap***" << endl;
    for (int i=0; i<heapSize; i++)
        cout << tree->at(i) << " ";
    cout << endl;
}

template <typename T>
MinHeap<T>::MinHeap(vector<T>* tree, int heapSize) {
    this->tree = tree;
    this->heapSize = heapSize;
    buildMinHeap();
}

template <typename T>
void MinHeap<T>::minHeapify(int i) {
    int largest = i;
    int leftC = left(i);
    int rightC = right(i);
    if(leftC < heapSize && this->tree->at(largest) > this->tree->at(leftC))
        largest = leftC;
    if(rightC < heapSize && this->tree->at(largest) > this->tree->at(rightC))
        largest = rightC;
    if(largest != i) {
        swap(this->tree->at(i), this->tree->at(largest));
        minHeapify(largest);
    }
}

template <typename T>
void MinHeap<T>::swap(T& a, T& b){
    T temp = a; 
    a = b; 
    b = temp;
}

template <typename T>
void MinHeap<T>::buildMinHeap() {
    for(int i = heapSize/2; i >= 0; i--)
        minHeapify(i);
}

template <typename T>
void MinHeap<T>::insert(T key) {
    this->tree->push_back(key);
    heapSize++;
    buildMinHeap();
}

template <typename T>
double MinHeap<T>::sumValue(int root, double x) {
    if(x <= this->tree->at(root))
        return 0;
    int leftC = left(root);
    int rightC = right(root);
    if((leftC < heapSize && x < this->tree->at(leftC)) || (rightC < heapSize && x < this->tree->at(rightC)))
        return (double)this->tree->at(leftC) + sumValue(leftC, x) && (double)this->tree->at(rightC) + sumValue(rightC, x);
    return x;
}

template <typename T>
void MinHeap<T>::sumValue(int root, double x, double& sum) {
    if(x <= this->tree->at(root))
        return;
    sum += this->tree->at(root);
    int leftC = left(root);
    int rightC = right(root);
    if(leftC < heapSize && x > this->tree->at(leftC)) sumValue(leftC, x, sum);
    if(rightC < heapSize && x > this->tree->at(rightC)) sumValue(rightC, x, sum);
}

#endif