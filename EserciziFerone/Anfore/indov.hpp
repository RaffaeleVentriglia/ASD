#ifndef indov_hpp
#define indov_hpp

#include "anfora.hpp"
#include "contenitore.hpp"

class indovinello {
    private:
        anfora primaAnfora;
        anfora secondaAnfora;
    public:
        indovinello();
        void risolvi();
};

#endif