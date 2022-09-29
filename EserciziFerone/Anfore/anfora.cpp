#include "contenitore.hpp"
#include "anfora.hpp"
#include <iostream>

anfora::anfora(int lt) : capacita(lt){}

void anfora::riempi() {
    if (!isPiena()) {
        versa(capacita - getQt());
    } else {
        std::cout << "L'anfora è piena.\n";
    }
}

void anfora::svuota() {
    if (!isVuota()) {
        togli(getQt());
    } else {
        std::cout << "L'anfora è vuota.\n";
    }
}

bool anfora::isPiena() const{
    return getQt() == getCapacita();
}

bool anfora::isVuota() const {
    return getQt() == 0;
}

void anfora::spostaContenuto(anfora &secondaAnfora) {
    if (secondaAnfora.isPiena()) {
        std::cout << "La seconda anfora è piena.\n";
        return;
    } else if (this->isVuota()) {
        std::cout << "La prima anfora è vuota.\n";
        return;
    }
    int lt = secondaAnfora.getCapacita() - secondaAnfora.getQt();
    if (lt > this->getCapacita()) {
        lt = this->getQt();
    }
    secondaAnfora.versa(lt);
    this->togli(lt);
}

int anfora::getCapacita() const {
    return capacita;
}