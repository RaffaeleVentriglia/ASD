#ifndef wCount_hpp
#define wCount_hpp

#include <iostream>
#include <string>
#include <map>
#include <fstream>

class WordCount {
    private:
        std::map<std::string, int> occ;
        std::ifstream file;
    public:
        WordCount(std::string);
        ~WordCount();
        std::map<std::string, int> getOccurrence() const { return occ; };
        std::map<std::string, int>::iterator getIndex(std::string word);
        void Count();
};

WordCount::WordCount(std::string file) {
    this->file.open(file);
}

WordCount::~WordCount() {
    this->file.close();
    this->occ.clear();
}

std::map<std::string, int>::iterator WordCount::getIndex(std::string word) {
    return this->occ.find(word);
}


void WordCount::Count() {
    std::string str;
    while(file >> str) {
        std::map<std::string, int>::iterator index = getIndex(str);
        if(index == this->occ.end()) {
            this->occ.insert(std::make_pair(str, 1));
        } else {
            index->second++;
        }
    }
}

#endif