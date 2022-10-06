#ifndef blocco_hpp
#define blocco_hpp

#include "transazione.hpp"
#include "list.hpp"
#include "nodo.hpp"
#include <iostream>

class blocco {
    private:
        static int count;
        const int id;
        list<Transaction>* headTransaction;
    public:
        blocco() : id(count++), headTransaction(new list<Transaction>) {}
        ~blocco();
        int getId() {return this->id;};
        list<Transaction> *getHead() const {return this->headTransaction;};
        void printBlock();
        int searchAddree(std::string address, int balance);
};

int blocco::count = 0;

blocco::~blocco() {
    delete headTransaction;
}

void blocco::printBlock() {
    nodo<Transaction> *i = headTransaction->getHead();
    std::cout << "ID: " << id << std::endl;
    while(i != nullptr) {
        i->getData()->printTransaction();
        i = i->getNext();
    }
}

#endif blocco_hpp