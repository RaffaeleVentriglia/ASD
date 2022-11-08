#ifndef BST_HPP
#define BST_HPP

#include "node.hpp"
#include <iostream>
using namespace std;

template <typename T>
class BST {
    private:
        Node<T>* root;
        void InsNode(T, Node<T>*, Node<T>*);
    public:
        BST(Node<T>*);
        BST();
        ~BST();
        Node<T> *getRoot(){return root;}
        void search(T);
        Node<T> *search(T, Node<T>*);
        void minimum();
        Node<T> *minimum(Node<T>*);
        void maximum();
        Node<T> *maximum(Node<T>*);
        void predecessor(T);
        void successor(T);
        void insert(T);
        void insert(T, Node<T>*, Node<T>*);
        void deleteNode(Node<T>*);
};

template <typename T>
BST<T>::BST(Node<T>* root) {
    this->root = root;
}

template <typename T>
BST<T>::BST() {
    this->root = nullptr;
}

template <typename T>
BST<T>::~BST(){}

template <typename T>
void BST<T>::search(T key) {
    Node<int>* tmp = this->search(key, this->getRoot());
    if(tmp == nullptr)
        cout << "Nodo " << key << " non è stato trovato\n";
    else
        cout << "Nodo " << key << " trovato: " << tmp->getKey() << endl;
}

template <typename T>
Node<T>* BST<T>::search(T key, Node<T>* node) {
    if(node == nullptr || key == node->getKey())
        return node;
    if(key < node->getKey())
        search(key, node->getLeft());
    else
        search(key, node->getRight());
}

template <typename T>
void BST<T>::minimum() {
    Node<T>* tmp = this->root;
    while(tmp->getLeft() != nullptr)
        tmp = tmp->getLeft();
    cout << "Minimo: " << tmp->getKey() << endl;
}

template <typename T>
Node<T>* BST<T>::minimum(Node<T>* node) {
    while(node->getLeft() != nullptr)
        node = node->getLeft();
    return node;
}

template <typename T>
void BST<T>::maximum() {
    Node<T>* tmp = this->root;
    while(tmp->getRight() != nullptr)
        tmp = tmp->getRight();
    cout << "Massimo: " << tmp->getKey() << endl;
}

template <typename T>
Node<T>* BST<T>::maximum(Node<T>* node) {
    while(node->getRight() != nullptr)
        node = node->getRight();
    return node;
}

template <typename T>
void BST<T>::predecessor(T key) {
    Node<T>* node = this->search(key, this->getRoot());
    if(node->getLeft() != nullptr)
        cout << "Predecessore di " << key << ": " << maximum(node->getLeft()) << endl;
    Node<T>* pp = node->getParent();
    while(pp != nullptr && node == pp->getLeft()) {
        node = pp;
        pp = pp->getParent();
    }
    cout << "Predecessore di " << key << ": " << pp->getKey() << endl;
}

template <typename T>
void BST<T>::successor(T key) {
    Node<T>* node = this->search(key, this->getRoot());
    if(node->getRight() != nullptr)
        cout << "Successore di " << key << ": " << minimum(node->getRight()) << endl;
    Node<T>* pp = node->getParent();
    while(pp != nullptr && node == pp->getRight()) {
        node = pp;
        pp = pp->getParent();
    }
    cout << "Successore di " << key << ": " << pp->getKey() << endl;
}

template <typename T>
void BST<T>::insert(T key) {
    this->insert(key, nullptr, this->getRoot());
}

template <typename T>
void BST<T>::insert(T key, Node<T>* prev, Node<T>* cur) {
    if(this->root != nullptr)
        this->root = new Node<T>(key);
    if(cur == nullptr)
        InsNode(key, prev, cur);
    else if(key > cur->getKey())
        insert(key, cur, cur->getRight());
    else
        insert(key, cur, cur->getLeft());
}

// TODO deleteNode

template <typename T>
void BST<T>::InsNode(T key, Node<T>* prev, Node<T>* cur) {
    if(prev != nullptr) {
        cur = new Node<T>(key);
        cur->setParent(prev);
        if(key > prev->getKey())
            prev->setRight(cur);
        else
            prev->setLeft(cur);
    } else {
        cur = new Node<T>(key);
    }
}

#endif