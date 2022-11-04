#ifndef NODO_HPP
#define NODO_HPP

template <class T>
class nodo {
    private:
        nodo<T>* next;
        T* object;

    public:
        nodo(nodo<T>* next, T* info);
        ~nodo();
        void SetNext(nodo<T>* next) {this->next = next;}
        void SetObj(T* info) {this->object = info;}
        nodo<T> *getNext() {return next;}
        T *getObj() {return this->object;}
};

template <class T>
nodo<T>::nodo(nodo<T>* next, T* info) {
    this->next = next;
    this->object = info;
}

template <class T>
nodo<T>::~nodo() {
    delete next;
    delete object;
}

#endif
