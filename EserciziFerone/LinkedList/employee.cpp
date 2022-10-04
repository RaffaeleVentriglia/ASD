#include <iostream>
#include "employee.hpp"

employee::employee(std::string nome, double salario) {
    this->nome = nome;
    this->salario = salario;
}

void employee::setName(std::string nome) {
    this->nome = nome;
}

void employee::setSalario(double salario) {
    this->salario = salario;
}

std::string employee::getName() const {
    return nome;
}

double employee::getSalario() const {
    return salario;
}

void employee::printEmployee() {
    std::cout << "Nome: " << getName() << ", salario: " << getSalario() << std::endl;
}

employee employee::operator+(employee emp2) {
    employee tmp("", 0);
    tmp.setSalario(this->getSalario() + emp2.getSalario());
    return tmp;
}