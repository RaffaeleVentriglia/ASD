#include <iostream>
#include <vector>
#include "BST.hpp"
using namespace std;

int main() {
    BST<int> abr;
    abr.insert(13);
    abr.insert(12);
    abr.insert(16);
    abr.insert(10);
    abr.insert(11);
    abr.insert(14);
    abr.insert(17);
    abr.insert(30);
    abr.insert(20);
    abr.insert(1);
    cout << endl << "Preorder" << endl;
    abr.preorderVisit(abr.getRoot());
    cout << endl << "Inorder" << endl;
    abr.inorderVisit(abr.getRoot());
    cout << endl << "Postorder" << endl;
    abr.postorderVisit(abr.getRoot());
    cout << endl;

    cout << "Massimo: " << abr.maximumTree(abr.getRoot())->getData() << endl;
    cout << "Minimo: " << abr.minimumTree(abr.getRoot())->getData() << endl;

    auto *cerca = abr.treeSearch(abr.getRoot(), 10);
    cout << endl<< "Il successore di: "<< cerca->getData()<<" è: "<< abr.successor(cerca)->getData();
    cout << endl<< "Il Predecessore di: "<< cerca->getData()<<" è: "<< abr.predecessor(cerca)->getData() << endl;
    
    cout << "Cancello i nodi con i valori 14 e 10" << endl;
    abr.treeDelete(abr.treeSearch(abr.getRoot(), 14));
    abr.treeDelete(abr.treeSearch(abr.getRoot(), 10));

    cout << endl << "Preorder" << endl;
    abr.preorderVisit(abr.getRoot());
    cout << endl << "Inorder" << endl;
    abr.inorderVisit(abr.getRoot());
    cout << endl << "Postorder" << endl;
    abr.postorderVisit(abr.getRoot());
    cout << endl;
    return 0;
}