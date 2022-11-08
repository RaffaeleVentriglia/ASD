/*
    Data una sequenza di interi (rappresentata da un array),
    trovare il k-esimo elemento più grande per ogni i=0..N-1.
    • seq=[10, 3, 21, 1, -1, 45, 8, 12, 78]
    • k=2
    • i=1 k-max=3
    • i=2 k-max=10
    • i=3 k-max=10
    • ...
*/

#include <iostream>
#include <vector>
#include "../../StruttureDati/MinPriorityQueue.hpp"
using namespace std;

int main() {
    vector<int> sequenza = {10, 3, 21, 1, -1, 45, 8, 12, 78};
    vector<int>* vec = new vector<int>;
    const int k = 5;
    for(int i = 0; i < k; i++)
        vec->push_back(sequenza.at(i));
    cout << "K: " << k << endl;
    MinPriorityQueue<int>* minQueue = new MinPriorityQueue<int>(vec);
    int min = minQueue->minimum();
    cout << "i: " << k-1 << ", k max: " << min << endl;
    for(int i = k; i < sequenza.size(); i++) {
        if(sequenza.at(i) > minQueue->minimum()) {
            minQueue->extractMin();
            minQueue->queueInsert(sequenza.at(i));
        }
        cout << "i: " << i << ", k max: " << minQueue->minimum() << endl;
    }
    return 0;
}