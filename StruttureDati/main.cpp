#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "MaxHeap.hpp"
#include "nodo.hpp"
#include "stack.hpp"
#include "LinkedList.hpp"
#include "MinHeap.hpp"
#include "MaxKheap.hpp"
#include "MinKheap.hpp"
using namespace std;

int main() {
    // ! fare attenzione all'uso
    // ? mi serve per ricordare come si fa
    // TODO: inserire tutte le strutture dati

    // * inserire elementi di un array in un vector
    int arr[] = {2,7,4,9,1,6};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    for(int i = 0; i < vec.size(); i++)
        cout << vec.at(i) << " ";
    cout << endl;

    // * USO DELLO STACK
    stack<int> memStack;
    int firstElement = 20;
    memStack.push(firstElement);
    memStack.pop(firstElement);

    // * USO DEI NODI
    nodo<int> new_node(nullptr, new int(5));
    new_node.SetNext(new nodo<int>(nullptr, new int(20)));

    // * USO DELLA LINKED LIST
    LinkedList<string>* newList = new LinkedList<string>;
    newList->InsNodo(newList->getLast(), new string("Prova 1"));
    newList->InsNodo(newList->getLast(), new string("Prova 2"));

    // * USO DEL MAXHEAP
    MaxHeap<int> maxHeap;
    maxHeap.insert(20);
    maxHeap.insert(30);
    maxHeap.insert(40);
    maxHeap.insert(50);
    maxHeap.insert(1);
    maxHeap.print();

    // * USO DEL MINHEAP
    MinHeap<int> minHeap;
    minHeap.insert(20);
    minHeap.insert(10);
    minHeap.insert(6);
    minHeap.insert(60);
    minHeap.insert(30);
    minHeap.insert(1);
    minHeap.print();

    // * USO DEL MAX K HEAP
    maxKheap<int> kMaxHeap(3);
    kMaxHeap.insert(9);
    kMaxHeap.insert(1);
    kMaxHeap.insert(4);
    kMaxHeap.insert(7);
    kMaxHeap.print();

    // * USO DEL MIN K HEAP
    minKheap<int> kMinHeap(3);
    kMinHeap.insert(9);
    kMinHeap.insert(1);
    kMinHeap.insert(4);
    kMinHeap.insert(7);
    kMinHeap.print();

    return 0;
}