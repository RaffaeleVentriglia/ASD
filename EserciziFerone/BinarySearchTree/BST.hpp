#ifndef BST_HPP
#define BST_HPP

#include "node.hpp"
#include <iostream>

template <class T>
class BST {
    private:
        Node<T> *root;
        void insertRic(T, Node<T>*, Node<T>*);
        void insertNode(T, Node<T>*, Node<T>*);
        void transplant(Node<T>*, Node<T>*);
        bool isEmpty(){return root == nullptr;}
        Node<T> *findSuccessor(Node<T> *);
        Node<T> *findPredecessor(Node<T> *);
    public:
        BST(){root = nullptr;};
        ~BST();
        Node<T> *getRoot(){return root;}
        void insert(T value){insertRic(value, nullptr, root);};
        Node<T> *treeSearch(Node<T> *, T);
        Node<T> *minimumTree(Node<T> *);
        Node<T> *maximumTree(Node<T> *);
        Node<T> *successor(Node<T> *);
        Node<T> *predecessor(Node<T> *);
        void treeDelete(Node<T> *);
        void preorderVisit(Node<T> *);
        void inorderVisit(Node<T> *);
        void postorderVisit(Node<T> *);
};

template <typename T>
BST<T>::~BST() {}

template <typename T>
void BST<T>::insertRic(T value, Node<T>* prev, Node<T>* cur) {
    if(root == nullptr)
        root = new Node<T>(value);
    else if(cur == nullptr)
        insertNode(value, prev, cur);
    else if(cur->getData() > value)
        insertRic(value, cur, cur->getLeft());
    else
        insertRic(value, cur, cur->getRight());
}

template <typename T>
void BST<T>::insertNode(T value, Node<T>* prev, Node<T>* cur) {
    cur = new Node<T>(value);
    cur->setParent(prev);
    if(cur->getData() > prev->getData())
        prev->setRight(cur);
    else
        prev->setLeft(cur);
}

template <typename T>
Node<T>* BST<T>::treeSearch(Node<T>* x, T key) {
    if(x == nullptr || key == x->getData())
        return x;
    if(key < x->getData())
        return treeSearch(x->getLeft(), key);
    else
        return treeSearch(x->getRight(), key);
}

template <typename T>
Node<T>* BST<T>::maximumTree(Node<T>* current) {
    if(isEmpty())
        return nullptr;
    else if(current->getRight() == nullptr)
        return current;
    else 
        return maximumTree(current->getRight());
}

template <typename T>
Node<T>* BST<T>::minimumTree(Node<T>* current) {
    if(isEmpty())
        return nullptr;
    else if(current->getLeft() == nullptr)
        return current;
    else 
        return minimumTree(current->getLeft());
}

template <typename T>
void BST<T>::preorderVisit(Node<T>* current) {
    if(current != nullptr) {
        std::cout << current->getData() << " ";
        preorderVisit(current->getLeft());
        preorderVisit(current->getRight());
    }
}

template <typename T>
void BST<T>::inorderVisit(Node<T>* current) {
    if(current != nullptr) {
        inorderVisit(current->getLeft());
        std::cout << current->getData() << " ";
        inorderVisit(current->getRight());
    }
}

template <typename T>
void BST<T>::postorderVisit(Node<T>* current) {
    if(current != nullptr) {
        postorderVisit(current->getLeft());
        postorderVisit(current->getRight());
        std::cout << current->getData() << " ";
    }
}

template <typename T>
Node<T>* BST<T>::successor(Node<T>* current) {
    if(current->getRight() != nullptr)
        return minimumTree(current->getRight());
    else 
        return findSuccessor(current);
}

template <typename T>
Node<T>* BST<T>::findSuccessor(Node<T>* current) {
    if(current == nullptr)
        return nullptr;
    Node<T> *x = current->getParent();
    if(x == nullptr)
        return nullptr;
    else if(current == x->getLeft())
        return x;
    else 
        return findSuccessor(x);
}

template <typename T>
Node<T>* BST<T>::predecessor(Node<T>* current) {
    if(current->getLeft() != nullptr)
        return maximumTree(current->getLeft());
    else 
        return findPredecessor(current);
}

template <typename T>
Node<T>* BST<T>::findPredecessor(Node<T>* current) {
    if(current == nullptr)
        return nullptr;
    Node<T> *x = current->getParent();
    if(x == nullptr)
        return nullptr;
    else if(current == x->getRight())
        return x;
    else 
        return findPredecessor(x);
}

template <typename T>
void BST<T>::treeDelete(Node<T>* current) {
    if(current == nullptr)
        current = nullptr;
    if(current->getLeft() == nullptr)
        transplant(current, current->getRight());
    else if(current->getRight() == nullptr)
        transplant(current, current->getLeft());
    else {
        Node<T>* x = successor(current);
        if(x->getParent() != current) {
            transplant(x, x->getRight());
            x->setRight(current->getRight());
            (x->getRight())->setParent(x);
        }
        transplant(current, x);
        x->setLeft(current->getLeft());
        (x->getLeft())->setParent(x);
    }
}



template <typename T>
void BST<T>::transplant(Node<T>* to, Node<T>* from) {
    if(to->getParent() == nullptr)
        root = from;
    else if(to == (to->getParent())->getLeft())
        (to->getParent())->setLeft(from);
    else
        (to->getParent())->setRight(from);
    if(from != nullptr)
        from->setParent(to->getParent());
}

#endif /* BST_HPP */