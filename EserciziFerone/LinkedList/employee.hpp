#ifndef employee_hpp
#define employee_hpp

#include <iostream>

class employee {
    private:
        std::string nome;
        double salario;
    public:
        employee(std::string nome, double salario);
        void setName(std::string name);
        void setSalario(double salario);
        std::string getName() const;
        double getSalario() const;
        virtual void printEmployee();
        employee operator+(employee emp2);
};

#endif