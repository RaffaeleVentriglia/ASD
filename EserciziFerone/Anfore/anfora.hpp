#ifndef anfora_hpp
#define anfora_hpp

#include <iostream>
#include "contenitore.hpp"

class anfora : public contenitore {
    private:
        int capacita;
    public:
        anfora(int);
        int getCapacita() const;
        void riempi();
        void svuota();
        bool isVuota() const;
        bool isPiena() const;
        void spostaContenuto(anfora &secondaAnfora);
};

#endif