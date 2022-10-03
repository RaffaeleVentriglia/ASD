#ifndef tester_hpp
#define tester_hpp

#include <iostream>
#include <fstream>
#include <vector>

class Tester {
    private:
        std::ifstream problema, soluzione;
        std::ofstream esito;
    public:
        Tester(std::string strProblema, std::string strSoluzione, std::string strEsito);
        ~Tester();
        void check();
};

#endif