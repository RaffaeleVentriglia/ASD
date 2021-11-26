#include <iostream>
using namespace std;

// funzioni standard per stampa e scambio di dati
void stampa(int*, int);
void compSwap(int&, int&);
void swap(int&, int&);
int getMax(int*, int);

void InsertionSort(int*, int, int);
void BubbleSort(int*, int, int);
void QuickSort(int*, int, int);
int Partition(int*, int, int);
void HeapSort(int*, int);
void heapify(int*, int, int);
void countSort(int*, int);
void countingSort (int*, int);
void radixsort(int*, int);

void stampa(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}

void compSwap(int &a, int &b) {
    if(b < a) {
        swap(a, b);
    }
}

void swap(int &a, int &b) {
    int T = a;
    a = b;
    b = T;
}

int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void InsertionSort(int* arr, int key, int length) {
    int i;
    for(int j = 2; j <= length; j++) {
        key = arr[j];
        i = j - 1;
        while(i > 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key;
    }
    stampa(arr, length);
}

void BubbleSort(int* arr, int left, int right) {
    int i, j;
    for(i = left; i < right; i++) {
        for(j = right; j > i; j--) {
            compSwap(arr[j-1], arr[j]);
        }
    }
    stampa(arr, right);
}

void QuickSort(int* arr, int p, int r) {
    if(p < r) {
        int q = Partition(arr, p, r);
        QuickSort(arr, p, q);
        QuickSort(arr, q+1, r);
    }
}

int Partition(int* arr, int p, int r) {
    int x = arr[r];
    int i = p-1;
    for(int j = p; j <= r-1; j++) {
        if(arr[j] <= x) {
            i = i+1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void HeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(int* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void countSort(int array[], int size) {
    int output[10];
    int count[10];
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    for (int i = 0; i <= max; ++i)
        count[i] = 0;
    for (int i = 0; i < size; i++)
        count[array[i]]++;
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void countingSort (int *A, int lengthA) {
    int max=A[0]; 
    int min=A[0]; //Calcolo elementi max e min
    for(int i=1; i<lengthA; i++){
        if(A[i]>max) 
            max=A[i];
        else if(A[i]<min) 
            min=A[i];
    }
    int lengthC = max-min+1; //Costruzione dell'array
    int *C = new int[lengthC]; //crea l'array C
    for(int i=0; i<lengthC; i++)
        C[i]=0; //inizializza a zero gli elementi di C
    for(int i=0; i<lengthA; i++)
        C[A[i]-min]++;
    // aumenta il numero di volte che si è incontrato il valore
    // Ordinamento in base al contenuto dell'array delle frequenze
    int k=0; // indice per l'array A
    for(int i=0; i<lengthC; i++){
    //scrive C[i] volte il valore i+min nell'array A
        while (C[i]>0){
            A[k++] = i+min;
            C[i]--;
        }
    }
    delete[] C;
}

void radixsort(int array[], int size) {
    // trova l'elemento massimo
    int max = getMax(array, size);
    // applica il quick sort per ordinare 
    // gli elementi in base al valore posizionale
    for (int place = 1; max / place > 0; place *= 10)
        QuickSort(array, size, place);
}