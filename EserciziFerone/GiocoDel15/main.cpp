#include <iostream>
#include <fstream>
#include <map>
#include <vector>

int main() {
    std::map<int, std::vector<int>> amap;
    std::map<int, std::vector<int>>::iterator it;
    std::ifstream in;
    in.open("gioco.txt");
    int num;
    while(in >> num) {

    }
    
    return 0;
}