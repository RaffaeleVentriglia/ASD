#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "nodo.hpp"

template <typename T>
class LinkedList {
    private:
        nodo<T>* head;
        nodo<T>* last;
        void InsHead(T* new_nodo);
        void InsLast(T* new_nodo);
    public:
        LinkedList();
        ~LinkedList();
        void setHead(nodo<T>* head) {
            this->head = head;
        }
        void setLast(nodo<T>* last) {
            this->last = last;
        }
        nodo<T> *getHead(){return head;}
        nodo<T> *getLast(){return last;}
        void InsNodo(nodo<T>* last, T* new_nodo);
};

template <typename T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
    this->last = head;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while(this->head != nullptr) {
        auto* tmp = head;
        head = head->getNext();
        delete tmp;
    }
}

template <typename T>
void LinkedList<T>::InsNodo(nodo<T>* last, T* new_nodo) {
    if(last == nullptr)
        InsHead(new_nodo);
    else
        InsLast(new_nodo);
}

template <typename T>
void LinkedList<T>::InsHead(T* new_nodo) {
    nodo<T>* node = new nodo<T>(nullptr, new_nodo);
    head = node;
    last = head;
}

template <typename T>
void LinkedList<T>::InsLast(T* new_nodo) {
    nodo<T>* node = new nodo<T>(nullptr, new_nodo);
    last -> SetNext(node);
    last = node;
}

#endif
