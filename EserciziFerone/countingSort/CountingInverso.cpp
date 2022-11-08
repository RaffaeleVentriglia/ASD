/*
    Implementare un counting sort inverso
*/

#include <iostream>
#include <vector>
#include "countingSort.hpp"
using namespace std;

int main() {
    int n = 5;
    vector<int> vec = {150,200,2,7,50};
    CountingSort::inverseCountingSort(&vec, n);
    for(auto i: vec)
        cout << i << " ";
    cout << endl;
}