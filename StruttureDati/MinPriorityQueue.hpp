#ifndef MINPRIORITYQUEUE_HPP
#define MINPRIORITYQUEUE_HPP

#include "MinHeap.hpp"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MinPriorityQueue:private MinHeap<T>{
    public:
        MinPriorityQueue(vector<T>*);
        MinPriorityQueue();
        virtual ~MinPriorityQueue();
        T minimum(); // * Θ(1)
        T extractMin(); // * O(log n)
        void queueInsert(T); // * O(log n)
        void decreasePriority(int,T);
        void print();
};

template <typename T>
MinPriorityQueue<T>::MinPriorityQueue(){

}

template <typename T>
MinPriorityQueue<T>::MinPriorityQueue(vector<T>* tree):MinHeap<T>(tree){

}

template <typename T>
MinPriorityQueue<T>::~MinPriorityQueue(){
    delete this->getHeap();
}

template <typename T>
T MinPriorityQueue<T>::minimum(){
    return this->getRoot();
}

template <typename T>
void MinPriorityQueue<T>::queueInsert(T key){
    this->insert(key);
}

template <typename T>
T MinPriorityQueue<T>::extractMin(){
    if (this->getHeapSize() == 0)
        return false;
    T min = this->getRoot();
    this->swap(this->getHeap()->at(0),this->getHeap()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->minHeapify(0);
    return min;
}

template <typename T>
void MinPriorityQueue<T>::decreasePriority(int i, T key){
    if (key > this->getHeap()->at(i))
        return;
    this->setTree(i,key);
    while ( i > 0 && this->getHeap()->at(this->parent(i)) > this->getHeap()->at(i) ){
        this->swap(this->getHeap()->at(this->parent(i)),this->getHeap()->at(i));
        i = this->parent(i);
    }    
}

template <typename T>
void MinPriorityQueue<T>::print(){
    cout << endl << "Min Priority Queue" << endl;
    for (int i=0; i<this->getHeapSize(); i++)
        cout << this->getHeap()->at(i) << " ";
    cout << endl;
}

#endif