#include <iostream>
#include "wCount.hpp"

int main() {

    WordCount test("testo.txt");
    test.Count();
    std::map<std::string, int> occ = test.getOccurrence();
    std::map<std::string, int>::iterator it;
    for(it = occ.begin(); it != occ.end(); it++) {
        std::cout << "Parola: " << it->first << ": " << it->second << std::endl;
    }

    /*
    std::map<std::string, int> parole;
    std::map<std::string, int>::iterator it;
    std::ifstream input("testo.txt");
    std::string str;
    while(input >> str) {
        it = parole.find(str);
        if(it == parole.end()) {
            parole.insert(std::make_pair(str, 1));
        } else {
            parole.find(str)->second++;
        }
    }
    for(it = parole.begin(); it != parole.end(); it++) {
        std::cout << "Parola: " << it->first << ": " << it->second << std::endl;
    }
    */
    return 0;
}
