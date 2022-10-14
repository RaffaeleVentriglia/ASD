/*
    Riscrivere il Merge Sort utilizzando 
    il contenitore Vector ed un iteratore
    Aggiornamento
*/

#include <iostream>
#include <vector>

void Merge(std::vector<int>::iterator begin, std::vector<int>::iterator mid, std::vector<int>::iterator end) {
    auto distance = std::distance(begin, end);
    std::vector<int> local(distance);
    int index = 0;

    std::vector<int>::iterator i, j, k;
    for (i = begin; i != mid; i++) {
        local.at(index++) = *i;
    }
    local.at(index--) = *i;

    index = (int) distance - 1;
    for (i = mid; i != end ; i++) {
        local.at(index--) = *i;
    }

    i = local.begin();
    j = local.end()-1;
    for(k = begin; k != end; k++) {
        if(*j < *i) {
            *k = *j;
            std::advance(j, -1);
        } else {
            *k = *i;
            std::advance(i, 1);
        }
    }
}

void MergeSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    auto size = std::distance(begin, end);
    if(size < 2) {
        return;
    }
    auto mid = std::next(begin, size/2);
    MergeSort(begin, mid);
    MergeSort(mid, end);
    Merge(begin, mid, end);
}

template <class T> void printArray(std::vector<T> arr) {
    typename std::vector<T>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++) std::cout << *it << "\n";
    std::cout << "\n\n";
}

int main() {
    std::vector<int> vec = {100, 90, 45, 15, 70, 20};
    MergeSort(vec.begin(), vec.end());
    printArray(vec);
}