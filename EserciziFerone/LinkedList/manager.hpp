#ifndef manager_hpp
#define manager_hpp

#include "employee.hpp"
#include <iostream>

class manager : public employee {
    private:
        double bonus;
    public:
        manager(std::string employeeName, double salario, double bonus);
        double getBonus() const;
        void printEmployee();
};

#endif