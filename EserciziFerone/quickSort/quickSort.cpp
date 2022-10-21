#include <iostream>
#include <ctime>
#include <cstdlib>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int vett[], int begin, int end) {
    int i = begin - 1;
    int pivot = vett[end];
    for(int j = begin; j <= end; j++) {
        if(vett[j] < pivot) {
            i++;
            swap(&vett[i], &vett[j]);
        }
    }
    swap(&vett[i + 1], &vett[end]);
    return i + 1;
}

void randomizedPartition(int vett[], int begin, int end) {
    int i = (rand() % begin) + end;
    swap(&vett[i], &vett[begin]);
    partition(vett, begin, end);
}

/*

// DA AGGIUSTARE
int partitionHoare(int vett[], int begin, int end) {
    int x = vett[begin];
    int i = begin - 1;
    int j = end + 1;
    while(vett[--j] <= x);
    while(vett[++i] > x);
    if(i < j)
        swap(&vett[i], &vett[j]);
    return j;
}

*/

void quickSort(int vett[], int begin, int end) {
    if(begin < end){
        int i = partition(vett, begin, end);
        quickSort(vett, begin, i - 1);
        quickSort(vett, i + 1, end);
    }
}

void printArray(int vett[], int size) {
    for(int i = 0; i < size; i++)
        std::cout << vett[i] << " ";
    std::cout << std::endl;
}

int main() {
    srand((unsigned)time(0));
    int n = 5;
    int vett[n];
    for (size_t i = 0; i < n; i++)
        vett[i] = (rand() % 10) + 1;
    printArray(vett, n);
    quickSort(vett, 0, n - 1);
    std::cout << "Array ordinato: \n";
    printArray(vett, n);
    return 0;
}