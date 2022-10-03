#include <iostream>
#include <vector>
#include <fstream>
#include "tester.hpp"

int main() {
    Tester soluzione("problema.txt", "soluzione.txt", "esito.txt");
    soluzione.check();
    return 0;
}