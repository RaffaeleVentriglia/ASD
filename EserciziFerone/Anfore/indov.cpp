#include <iostream>
#include "indov.hpp"
#include "contenitore.hpp"
#include "anfora.hpp"

indovinello::indovinello() : primaAnfora(3), secondaAnfora(5){};

void indovinello::risolvi() {
    std::cout << "A: " << primaAnfora.getQt() << ", B: " << secondaAnfora.getQt() << std::endl;
    primaAnfora.riempi();
    std::cout << "Riempi l'anfora A: A = " << primaAnfora.getQt() << ", B = " << secondaAnfora.getQt() << std::endl; /*A: 3, B: 0*/
    primaAnfora.spostaContenuto(secondaAnfora);
    std::cout << "Sposta il contenuto dell'anfora A nell'anfora B: A = " << primaAnfora.getQt() << ", B = " << secondaAnfora.getQt() << std::endl; /*A: 0, B: 3*/
    primaAnfora.riempi();
    std::cout << "Riempi l'anfora A: A = " << primaAnfora.getQt() << ", B = " << secondaAnfora.getQt() << std::endl; /*A: 3, B: 3*/
    primaAnfora.spostaContenuto(secondaAnfora);
    std::cout << "Sposta il contenuto dell'anfora A nell'anfora B: A = " << primaAnfora.getQt() << ", B = " << secondaAnfora.getQt() << std::endl; /*A: 1, B: 5*/
    secondaAnfora.svuota();
    std::cout << "Svuota l'anfora B: A = " << primaAnfora.getQt() << ", B = " << secondaAnfora.getQt() << std::endl; /*A: 1, B: 0*/
    primaAnfora.spostaContenuto(secondaAnfora);
    std::cout << "Sposta il contenuto dell'anfora A nell'anfora B: A = " << primaAnfora.getQt() << ", B = " << secondaAnfora.getQt() << std::endl; /* A: 0, B: 1*/
    primaAnfora.riempi();
    std::cout << "Riempi l'anfora A: A = " << primaAnfora.getQt() << ", B = " << secondaAnfora.getQt() << std::endl; /*A: 3, B: 1*/
    primaAnfora.spostaContenuto(secondaAnfora);
    std::cout << "Sposta il contenuto dell'anfora A nell'anfora B: A = " << primaAnfora.getQt() << ", B = " << secondaAnfora.getQt() << std::endl; /* A: 0, B: 4*/
}