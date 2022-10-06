#ifndef nodo_hpp
#define nodo_hpp

#include "transazione.hpp"
#include <iostream>

template <typename T>
class nodo {
    private:
        nodo* next;
        T* data;
    public:
        nodo(T* data);
        void setData(T* data);
        void setNext(nodo* next);
        T* getData() const;
        nodo* getNext() const;
};

template<typename T> nodo<T>::nodo(T* data) {
    this->data = data;
    this->next = nullptr;
}

template<typename T> void nodo<T>::setData(T* data) {
    this->data = data;
}

template<typename T> void nodo<T>::setNext(nodo* next) {
    this->next = next;
}

template<typename T> T* nodo<T>::getData() const {
    return this->data;
}

template<typename T> nodo<T>* nodo<T>::getNext() const {
    return this->next;
}

#endif