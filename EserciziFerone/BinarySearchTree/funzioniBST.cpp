#include <iostream>
#include <vector>
#include "BST.hpp"
#include "node.hpp"
using namespace std;

int main() {
    BST<int>* tree = new BST<int>;
    tree->insert(10);
    tree->insert(20);
    tree->insert(1);
    tree->insert(12);
    tree->insert(5);
    tree->insert(9);
    tree->insert(50);
    tree->search(50);
    tree->minimum();
    tree->maximum();
    return 0;
}