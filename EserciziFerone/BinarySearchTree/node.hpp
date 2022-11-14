#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <typename T>
class Node {
    private:
        T data;
        Node *parent;
        Node *left;
        Node *right;
    public:
        Node(T);
        ~Node();
        void setParent(Node *p){parent = p;}
        void setLeft(Node *l){left = l;}
        void setRight(Node *r){right = r;}
        void setData(T d){data = d;}
        Node *getParent(){return parent;}
        Node *getLeft(){return left;}
        Node *getRight(){return right;}
        T getData(){return data;}
};

template <typename T> Node<T>::Node(T d) {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    data = d;
}

template <typename T> Node<T>::~Node() {
    delete parent;
    delete left;
    delete right;
    delete data;
}

#endif