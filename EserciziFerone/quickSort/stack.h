#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
    private:
        int dim;
        int top;
        T *arr;
    public:
        Stack();
        ~Stack();
        bool Pop(T&);
        void Push(T);
        bool isEmpty();
};

template <typename T>
Stack<T>::Stack() {
    arr = nullptr;
    dim = 0;
    top = -1;
}

template <typename T>
Stack<T>::~Stack() {
    delete arr;
}

template <typename T>
bool Stack<T>::Pop(T& elem) {
    if(top >= 0) {
        elem = arr[top--];
        return true;
    } else
        return false;
    return false;
}

template <typename T>
void Stack<T>::Push(T elem) {
    if(top == dim - 1) { // caso in cui lo stack fosse pieno
        T *app;
        app = new T[dim + 10];
        for(size_t i = 0; i < dim; i++)
            app[i] = arr[i];
        dim += 10;
        delete[] arr;
        arr = app;
    }
    arr[++top] = elem;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return top == -1;
}

#endif
