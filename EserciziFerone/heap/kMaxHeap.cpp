/*
    • Progettare ed implementare una classe che implementi un
      heap k-nario (ogni nodo ha k figli)
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "kMaxHeap.hpp"

int main() {
    srand((unsigned)time(0));
    kMaxHeap<int> tree(new std::vector<int>, 0, 2);
    for(int i = 0; i < 40; i++)
        tree.insert(rand()%100);
    tree.print();
    return 0;
}