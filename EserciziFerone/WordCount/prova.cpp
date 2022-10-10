#include <iostream>
#include <map>
#include <fstream>
#include <string>

int main() {
    std::map<std::string, int> occ;
    std::map<std::string, int>::iterator it;
    std::ifstream inp("testo.txt");
    std::string str;
    while(inp >> str) {
        it = occ.find(str);
        if(it == occ.end()) {
            occ.insert(std::make_pair(str, 1));
        } else {
            occ.find(str)->second++;
        }
    }
    for(it = occ.begin(); it != occ.end(); it++) {
        std::cout << "Parola: " << it->first << ": " << it->second << std::endl;
    }
    return 0;
}
