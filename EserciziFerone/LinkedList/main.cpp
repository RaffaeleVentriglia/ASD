#include <iostream>
#include "employee.hpp"
#include "manager.hpp"
#include "nodo.hpp"
#include "list.hpp"

int main() {
    list* myList = new list();
    myList->insert(new employee("Giuseppe", 1500));
    myList->insert(new employee("Raffaele", 1700));
    myList->insert(new manager("Mario", 1800, 400));
    myList->printList();
    std::cout << "La somma totale dei salari è: " << myList->sumSalary() << std::endl;
    return 0;
}