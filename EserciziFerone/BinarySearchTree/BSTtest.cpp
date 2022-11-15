#include <iostream>
#include <vector>
#include "BST.hpp"
using namespace std;

int main() {
    BST<int> tree;
    tree.insert(13);
    tree.insert(12);
    tree.insert(16);
    tree.insert(10);
    tree.insert(11);
    tree.insert(14);
    tree.insert(17);
    tree.insert(30);
    tree.insert(20);
    tree.insert(1);
    cout << endl << "Preorder" << endl;
    tree.preorderVisit(tree.getRoot());
    cout << endl << "Inorder" << endl;
    tree.inorderVisit(tree.getRoot());
    cout << endl << "Postorder" << endl;
    tree.postorderVisit(tree.getRoot());
    cout << endl;

    cout << "Massimo: " << tree.maximumTree(tree.getRoot())->getData() << endl;
    cout << "Minimo: " << tree.minimumTree(tree.getRoot())->getData() << endl;

    auto *cerca = tree.treeSearch(tree.getRoot(), 10);
    cout << endl<< "Il successore di: "<< cerca->getData()<<" è: "<< tree.successor(cerca)->getData();
    cout << endl<< "Il Predecessore di: "<< cerca->getData()<<" è: "<< tree.predecessor(cerca)->getData() << endl;
    
    cout << "Cancello i nodi con i valori 30 e 10" << endl;
    tree.treeDelete(tree.treeSearch(tree.getRoot(), 30));
    tree.treeDelete(tree.treeSearch(tree.getRoot(), 10));

    cout << endl << "Preorder" << endl;
    tree.preorderVisit(tree.getRoot());
    cout << endl << "Inorder" << endl;
    tree.inorderVisit(tree.getRoot());
    cout << endl << "Postorder" << endl;
    tree.postorderVisit(tree.getRoot());
    cout << endl;

    cout << "Massimo: " << tree.maximumTree(tree.getRoot())->getData() << endl;
    cout << "Minimo: " << tree.minimumTree(tree.getRoot())->getData() << endl;
    return 0;
}