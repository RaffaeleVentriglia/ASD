#ifndef MAXPRIORITYQUEUE_HPP
#define MAXPRIORITYQUEUE_HPP

#include <vector>
#include <iostream>
#include "MaxHeap.hpp"
using namespace std;

template <typename T>
class MaxPriorityQueue:private MaxHeap<T> {
    public:
        MaxPriorityQueue(vector<T>*);
        MaxPriorityQueue();
        virtual ~MaxPriorityQueue();
        T maximum(); // ! Θ(1)
        T extractMax(); // ! O(log n)
        void QueueInsert(T); // ! O(log n)
        void increasePriority(int, T); // ! O(log n)
        void print();
};

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue() {

}

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue(vector<T>* heap):MaxHeap<T>(heap) {

}

template <typename T>
MaxPriorityQueue<T>::~MaxPriorityQueue() {
    delete this->heap;
}

template <typename T>
T MaxPriorityQueue<T>::maximum() {return this->getRoot();}

template <typename T>
void MaxPriorityQueue<T>::QueueInsert(T key) {this->insert(key);}

template <typename T>
T MaxPriorityQueue<T>::extractMax() {
    if(this->getHeapSize() == 0)
        return false;
    T max = this->getRoot();
    this->swap(this->getHeap()->at(0), this->getHeap()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->maxHeapify(0);
    return max;
}

template <typename T>
void MaxPriorityQueue<T>::increasePriority(int i, T key) {
    if(key < this->getHeap()->at(i))
        return;
    this->setHeap(i, key);
    while(i > 0 && this->getHeap()->at(this->parent(i)) < this->getHeap()->at(i)) {
        this->swap(this->getHeap()->at(this->parent(i)), this->getHeap()->at(i));
    }
}

template <typename T>
void MaxPriorityQueue<T>::print() {
    cout << "Max Priority Queue\n";
    for(int i = 0; i < this->getHeapSize(); i++)
        cout << this->getHeap()->at(i) << " ";
    cout << endl;
}

#endif