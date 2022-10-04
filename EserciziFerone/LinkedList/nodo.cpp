#include "nodo.hpp"
#include "employee.hpp"

nodo::nodo(employee* data) {
    this->data = data;
    this->next = nullptr;
}

void nodo::setData(employee* data) {
    this->data = data;
}

void nodo::setNext(nodo* next) {
    this->next = next;
}

employee* nodo::getData() const {
    return this->data;
}

nodo* nodo::getNext() const {
    return this->next;
}