#ifndef list_hpp
#define list_hpp

#include "transazione.hpp"
#include "nodo.hpp"

template <typename T>
class list {
    private:
        nodo<T>* head;
        nodo<T>* tail;
    public:
        list();
        ~list();
        nodo<T>* getHead() const {return this->head;};
        nodo<T>* getTail() const {return this->tail;};
        void insert(T* obj);
};

template <typename T> list<T>::list() {
    this->head = nullptr;
    this->tail = head;
}

template <typename T> list<T>::~list() {
    delete head;
    delete tail;
}

template <typename T> void list<T>::insert(T* obj) {
    nodo<T>* tmp = new nodo<T>(obj);
    if(tmp == nullptr) {
        head = tail = tmp;
    } else {
        tail->setNext(tmp);
        tail = tmp;
    }
}

#endif