#ifndef ALGORITMI_HPP
#define ALGORITMI_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class algoritmi {
    private:
        // * Merge Sort
        template <typename T> static void merge(typename vector<T>::iterator, typename vector<T>::iterator, typename vector<T>::iterator);
        // * Quick Sort
        template <typename T> static typename vector<T>::iterator partition(typename vector<T>::iterator, typename vector<T>::iterator);
        // * Randomized Quick Sort
        template <typename T> static typename vector<T>::iterator randomizedPartition(typename vector<T>::iterator,typename vector<T>::iterator);
        // * Heap Sort
        template <typename T> static void buildMaxHeap(vector<T>*,int);
        template <typename T> static void maxHeapify(vector<T>*,int,int);
        // * Bubble Sort
        template <typename T> static void compswap (T&, T&);
        template <typename T> static void swap(T&, T&);
    public:
        // * Bubble Sort
        template <typename T> static void bubbleSort(typename vector<T>::iterator,typename vector<T>::iterator);
        // * Insertion Sort
        template <typename T> static void insertionSort(typename vector<T>::iterator begin, typename vector<T>::iterator end);
        // * Merge Sort
        template <typename T> static void mergeSort(typename vector<T>::iterator, typename vector<T>::iterator);
        // * Quick Sort
        template <typename T> static void quickSort(typename vector<T>::iterator, typename vector<T>::iterator);
        // * Randomized Quick Sort
        template <typename T> static void randomQuickSort(typename vector<T>::iterator,typename vector<T>::iterator);
        // * Hybrid Sort
        template <typename T> static void hybridSort(typename vector<T>::iterator,typename vector<T>::iterator);
        // * Heap Sort
        template <typename T> static void HeapSort(vector<T>*);
        // * Counting Sort
        static void countingSort(vector<int>*,int);
        // TODO Radix Sort
        // TODO Bucket Sort
};

// * MergeSort
template <typename T>
void algoritmi::mergeSort(typename vector<T>::iterator low, typename vector<T>::iterator high) {
    auto size = distance(low, high);
    if(size >= 2) {
        auto mid = next(low, size/2);
        mergeSort<T>(low, mid);
        mergeSort<T>(mid, high);
        merge<T>(low, mid, high);
    }
}

template <typename T>
void algoritmi::merge(typename vector<T>::iterator low, typename vector<T>::iterator mid, typename vector<T>::iterator high) {
    auto n = distance(low, high);
    auto index = (int) (n/2)-1;
    vector<T> ausiliare(n);
    typename vector<T>::iterator i, j, k;
    for(i = low; i != mid; i++)
        ausiliare.at(index--) = *i;
    index = (int) n-1;
    for(j = mid; j != high; j++)
        ausiliare.at(index--) = *j;
    i = ausiliare.begin();
    j = ausiliare.end()-1;
    for(k = low; k != high; k++)
        if(*j < *i)
            *k = *j--;
        else
            *k = *i++;
}

// * QuickSort
template <typename T>
void algoritmi::quickSort(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    auto size = distance(begin, end);
    if(size <= 0)
        return;
    typename vector<T>::iterator i = partition<T>(begin, end);
    quickSort<T>(begin, i-1);
    quickSort<T>(i+1, end);
}

template <typename T>
typename vector<T>::iterator algoritmi::partition(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    typename vector<T>::iterator i = begin-1, j = end;
    T vec = *end;
    while(1) {
        while(*(++i) < vec);
        while(vec < *(--j))
            if(j == begin)
                break;
        if(i >= j)
            break;
        swap(*i, *j);
    }
    swap(*i, *end);
    return i;
}

template <typename T>
void algoritmi::randomQuickSort(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    srand((unsigned)time(0));
    if(end <= begin)
        return;
    typename vector<T>::iterator i = randomizedPartition<T>(begin, end);
    randomQuickSort<T>(begin, i-1);
    randomQuickSort<T>(i+1, end);
}

template <typename T>
typename vector<T>::iterator algoritmi::randomizedPartition(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    int i = rand()%distance(begin, end);
    swap(*(begin+i), *begin);
    return partition<T>(begin, end);
}

// * InsertionSort

template <typename T>
void algoritmi::insertionSort(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    typename vector<T>::iterator i, j;
    T key;
    for(j = begin+1; j != end; j++) {
        key = *j;
        i = j-1;
        while(i >= begin && *i > key) {
            *(i+1) = *i;
            i--;
        }
        *(i+1) = key;
    }
}

// * BubbleSort

template <typename T>
void algoritmi::swap(T& x, T& y) {
    T tmp = x;
    x = y;
    y = x;
}

template <typename T>
void algoritmi::compswap(T& x, T& y) {
    if(y < x)
        swap(x, y);
}

template <typename T>
void algoritmi::bubbleSort(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    typename vector<T>::iterator i, j;
    for(i = begin; i != end; i++)
        for(j = end; j != i; j--)
            compswap(*(j-1), *j);
}

// * HybridSort
template <typename T>
void algoritmi::hybridSort(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    auto dist = distance(begin, end);
    if(dist > 2) {
        swap(*(next(begin, dist)), *(end-1));
        compswap(*(end-1), *begin);
        compswap(*end, *begin);
        compswap(*end, *(end-1));
        typename vector<T>::iterator i = partition<T>(begin, end);
        quickSort<T>(begin, i-1);
        quickSort<T>(i+1, end);
    }
    insertionSort<T>(begin, end);
}

#endif