#include "list.hpp"
#include "nodo.hpp"
#include <iostream>

list::list() {
    head = nullptr;
    tail = head;
}

list::~list() {
    while(head != nullptr) {
        nodo* tmp = head;
        head = head->getNext();
        delete tmp;
    }
}

nodo* list::getHead() const {
    return this->head;
}

nodo* list::getTail() const {
    return this->tail;
}

void list::insert(employee* data) {
    nodo* tmp = new nodo(data);
    if(this->head == nullptr) {
        tail = head = tmp;
    } else {
        tail->setNext(tmp);
        tail = tmp;
    }
}

void list::printList() {
    nodo* tmp = head;
    while(tmp != nullptr) {
        tmp->getData()->printEmployee();
        tmp = tmp->getNext();
    }
}

double list::sumSalary() {
    nodo* tmp = head;
    employee sum("", 0);
    while(tmp != nullptr) {
        employee tmpEmp("", tmp->getData()->getSalario());
        sum = sum + tmpEmp;
        tmp = tmp->getNext();
    }
    return sum.getSalario();
}