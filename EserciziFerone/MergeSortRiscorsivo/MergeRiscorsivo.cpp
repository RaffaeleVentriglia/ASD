/*
    Progettare ed implementare una
    procedura merge ricorsiva
*/

#include <iostream>

void merge(int *v, int begin, int mid, int end) {

}

void mergesort(int *v, int begin, int end) {
    if(begin < end) {
        int mid = (begin + end) / 2;
        mergesort(v, begin, mid);
        mergesort(v, mid+1, end);
        //merge();
    }
}

int main() {

    return 0;
}