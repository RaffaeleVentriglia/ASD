#ifndef list_hpp
#define list_hpp
#include "nodo.hpp"
#include <iostream>

class list {
    private:
        nodo* head;
        nodo* tail;
    public:
        list();
        ~list();
        nodo* getHead() const;
        nodo* getTail() const;
        void insert(employee* data);
        void printList();
        double sumSalary();
};

#endif 