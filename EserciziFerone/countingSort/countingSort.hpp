#ifndef COUNTINGSORT_HPP
#define COUNTINGSORT_HPP

#include <iostream>
#include <vector>
using namespace std;

class CountingSort {
    public:
        static void countingSort(vector<int>*, int);
        static void inverseCountingSort(vector<int>*, int);
};

void CountingSort::countingSort(vector<int>* vec, int n) {
    int max = vec->at(0);
    int min = vec->at(0);
    int k = 0;
    for(int i = 1; i < n; i++) {
        if(vec->at(i) > max)
            max = vec->at(i);
        else if(vec->at(i) < min)
            min = vec->at(i);
    }
    int length = max-min+1;
    int *C = new int[length];
    for(int i = 0; i < length; i++)
        C[i] = 0;
    for(int i = 0; i < n; i++)
        C[vec->at(i)-min]++;
    for(int i = 0; i < length; i++) {
        while(C[i] > 0) {
            vec->at(k++) = i+min;
            C[i]--;
        }
    }
    delete[] C;
}

void CountingSort::inverseCountingSort(vector<int>* vec, int n) {
    int max = vec->at(0);
    int min = vec->at(0);
    int k = n-1;
    for(int i = 1; i < n; i++) {
        if(vec->at(i) > max)
            max = vec->at(i);
        else if(vec->at(i) < min)
            min = vec->at(i);
    }
    int length = max-min+1;
    int *C = new int[length];
    for(int i = 0; i < length; i++)
        C[i] = 0;
    for(int i = 0; i < n; i++)
        C[vec->at(i)-min]++;
    for(int i = 0; i < length; i++) {
        while(C[i] > 0) {
            vec->at(k--) = i+min;
            C[i]--;
        }
    }
    delete[] C;
}

#endif