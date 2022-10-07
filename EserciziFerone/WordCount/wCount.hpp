#ifndef wCount_hpp
#define wCount_hpp

#include <iostream>
#include <string>
#include <map>
#include <fstream>

class WordCount {
    private:
        std::map<std::string, int> occ;
        std::map<std::string, int>::iterator it;
    public:
        void Calcola(std::ifstream);
};


void WordCount::Calcola(std::ifstream ifs) {
    std::string str;
    while(ifs >> str) {
        it = this->occ.find(str);
        if(it == this->occ.end()) {
            this->occ.insert(std::make_pair(str, 1));
        } else {
            this->occ.find(str)->second++;
        }
    }
    for(it = this->occ.begin(); it != this->occ.end(); it++) {
        std::cout << "Parola: " << it->first << ": " << it->second << std::endl;
    }
}

#endif