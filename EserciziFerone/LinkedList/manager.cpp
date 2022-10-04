#include "manager.hpp"
#include <iostream>

manager::manager(std::string employeeName, double salario, double bonus) : employee(employeeName, salario), bonus(bonus) {}

double manager::getBonus() const {
    return bonus;
}

void manager::printEmployee() {
    std::cout << "Nome: " << getName() << ", salario: " << getSalario() << ", bonus: " << getBonus() << std::endl;
}