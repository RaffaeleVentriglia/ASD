#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "MaxHeap.hpp"
#include "nodo.hpp"
#include "stack.hpp"
#include "LinkedList.hpp"
using namespace std;

int main() {

    // * inserire elementi di un array in un vector
    // ! fai attenzione a come lo usi
    // ? può essere utile sempre?
    // TODO: inserire tutte le strutture dati
    int arr[] = {2,7,4,9,1,6};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    for(int i = 0; i < vec.size(); i++)
        cout << vec.at(i) << " ";
    cout << endl;
    return 0;
}