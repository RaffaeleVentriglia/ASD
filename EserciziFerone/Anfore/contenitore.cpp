#include <iostream>
#include "contenitore.hpp"
#include "anfora.hpp"

contenitore::contenitore() : qt(0){};

void contenitore::togli(int lt) {
    int newQt = qt - lt;
    if(newQt < 0) {
        std::cout << "Errore" << std::endl;
    } else {
        qt = newQt;
    }
}

void contenitore::versa(int lt) {
    qt = qt + lt;
}

int contenitore::getQt() const {
    return qt;
}