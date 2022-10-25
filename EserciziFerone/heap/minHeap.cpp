/*
    Progettare ed implementare una algoritmo che, dato un
    Min-Heap ed un valore X, stampi la somma dei valori dei
    nodi minori di X.
*/

#include <iostream>
#include <vector>
#include "minHeap.hpp"
using namespace std;

int main() {
    MinHeap<int> minheap(new vector<int>, 0);
    minheap.insert(100);
    minheap.insert(10);
    minheap.insert(20);
    minheap.insert(35);
    minheap.insert(1);
    minheap.insert(2);
    minheap.insert(200);
    minheap.print();

    double sum = 0;
    minheap.sumValue(0, 90, sum);
    cout << "Somma dei nodi con valore minore di 90: " << sum << endl;

    sum = 0;
    minheap.sumValue(0, 30, sum);
    cout << "Somma dei nodi con valore minore di 30: " << sum << endl;

    return 0;
}