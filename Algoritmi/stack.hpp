#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class stack {
    private:
        int dim, top;
        T* vet;
    public:
        stack();
        ~stack();
        void push(T);
        bool pop(T&);
        bool isEmpty();
};

template <typename T>
stack<T>::stack() {
    vet = nullptr;
    dim = 0;
    top = -1;
}

template <typename T>
stack<T>::~stack() {
    delete vet;
}

template <typename T>
void stack<T>::push(T elem) {
    if(top == dim-1) {
        T* tmp;
        tmp = new T[dim+10];
        for(int i = 0; i < dim; i++)
            tmp[i] = vet[i];
        dim += 10;
        delete[] vet;
        vet = tmp;
    }
    vet[++top] = elem;
}

template <typename T>
bool stack<T>::pop(T& elem) {
    if(top >= 0) {
        elem = vet[top--];
        return true;
    } else
        return false;
    return false;
}

template <typename T>
bool stack<T>::isEmpty() {
    return top == -1;
}

#endif
