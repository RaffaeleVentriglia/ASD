#ifndef nodo_hpp
#define nodo_hpp
#include "employee.hpp"
#include <iostream>

class nodo {
    private:
        employee* data;
        nodo* next;
    public:
        nodo(employee* data);
        void setData(employee* data);
        void setNext(nodo* next);
        employee* getData() const;
        nodo* getNext() const;
};

#endif