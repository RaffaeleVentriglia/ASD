/*
    riscrivere il quicksort utilizzando
    il contenitore vector e gli iteratori
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T> void swap(T* x, T* y) {
    T temp = *x;
    *x = *y;
    *y = temp;
}

vector<int>::iterator partition(vector<int>::iterator begin, vector<int>::iterator end) {
    vector<int>::iterator i = begin - 1;
    vector<int>::iterator j = end;
    int v = *end;
    while(1) {
        while(*(++i) < v);
        while(v < *(--j))
            if(j == begin)
                break;
        if(i >= j)
            break;
        swap(*i, *j);
    }
    swap(*i, *end);
    return i;
}

void quickSort(vector<int>::iterator begin, vector<int>::iterator end) {
    auto size = distance(begin, end);
    if(begin < end) {
        vector<int>::iterator i = partition(begin, end);
        quickSort(begin, i - 1);
        quickSort(i + 1, end);
    }
}


template <class T> void printArray(vector<T> arr) {
    typename vector<T>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++)
        cout << *it << " ";
    cout << "\n";
}

int main() {
    srand((unsigned)time(0));
    vector<int> vec;
    int size = (rand() % 10) + 1;
    for(size_t i = 0; i < size; i++)
        vec.push_back((rand() % 10) + 1);
    cout << "Vector creato \n";
    printArray(vec);
    quickSort(vec.begin(), vec.end() - 1);
    cout << "Vector ordinato \n";
    printArray(vec);
}
