#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "tester.hpp"

Tester::Tester(std::string strProblema, std::string strSoluzione, std::string strEsito) {
    problema.open(strProblema);
    soluzione.open(strSoluzione);
    esito.open(strEsito);
}

Tester::~Tester() {
    problema.close();
    esito.close();
    soluzione.close();
}

void Tester::check() {
    std::string strProblema, strSoluzione;
    while(std::getline(problema, strProblema) && std::getline(soluzione, strSoluzione)) {
        std::string simboliSoluzione;
        // controllo se i segni combaciano
        for(std::size_t i = 0; i < strSoluzione.length(); i++) {
            if(strSoluzione.at(i) == '<' || strSoluzione.at(i) == '>') {
                simboliSoluzione.push_back(strSoluzione.at(i));
            }
        }
        if(strProblema != simboliSoluzione) {
            esito << "Sbagliata" << std::endl;
            continue;
        }
        // inserisco i numeri nel vettore
        std::vector<int> numeri;
        std::size_t symbolIndex = 0;
        for(std::size_t i = 0; i < strSoluzione.length(); i += symbolIndex + 1) {
            int numero = stoi(strSoluzione.substr(i), &symbolIndex);
            numeri.push_back(numero);
        }
        // controllo la lunghezza del vettore
        if(numeri.size() != strProblema.length() + 1) {
            esito << "Sbagliata" << std::endl;
            continue;
        }
        // controllo se i numeri sono nella posizione giusta
        bool flag = false;
        for(std::size_t i = 0; i < strProblema.length(); i++) {
            if(strProblema.at(i) == '<' && numeri.at(i) > numeri.at(i + 1)) {
                esito << "Sbagliata" << std::endl;
                flag = true;
                break;
            } else if(strProblema.at(i) == '>' && numeri.at(i) < numeri.at(i + 1)) {
                esito << "Sbagliata" << std::endl;
                flag = true;
                break;
            }
        }
        if(flag == true) {
            continue;
        }
        flag = false;
        // controllo se ci sono duplicati
        sort(numeri.begin(), numeri.end());
        for(std::size_t i = 0; i < strProblema.length(); i++) {
            if(numeri.at(i) != i + 1) {
                esito << "Sbagliata" << std::endl;
                flag = true;
                break;
            }
        }
        if(flag == true) {
            continue;
        }
        esito << "Corretta" << std::endl;
    }
}