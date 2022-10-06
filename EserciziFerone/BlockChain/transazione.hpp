#ifndef transazione_hpp
#define transazione_hpp

#include <iostream>

class Transaction {
    private:
        std::string from;
        std::string to;
        int qt;
    public:
        Transaction(std::string, std::string, int);
        // setter
        void setFrom(std::string);
        void setTo(std::string);
        void setQt(int);
        // getter
        std::string getFrom() {return this->from;};
        std::string getTo() {return this->to;};
        int getQt() {return this->qt;};
        void printTransaction();
};

Transaction::Transaction(std::string from, std::string to, int qt) {
    this->from = from;
    this->to = to;
    this->qt = qt;
}

void Transaction::setFrom(std::string from) {
    this->from = from;
}

void Transaction::setTo(std::string to) {
    this->to = to;
}

void Transaction::setQt(int qt) {
    this->qt = qt;
}

void Transaction::printTransaction() {
    std::cout << "From: " << getFrom() << std::endl;
    std::cout << "To: " << getTo() << std::endl;
    std::cout << "Qt: " << getQt() << std::endl;
}

#endif