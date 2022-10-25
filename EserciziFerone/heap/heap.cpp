#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
void swap(T *x, T *y) {
    T temp = *x;
    *x = *y;
    *y = temp;
}

template <typename T>
void heapify(vector<T> vec, T i) {
    int size = vec.size(); // trovo il size dell'array
    T largest = i; // imposto i come il più grande elemento
    T left = 2*i+1, right = 2*i+2;
    if(left < size && vec[left] > vec[largest])
        largest = left;
    if(right < size && vec[right] > vec[largest])
        largest = right;
    if(largest != i) {
        swap(vec[i], vec[largest]);
        heapify(vec, largest);
    }
}

template <typename T>
void build_max_heap(vector<T> vec) {
    int size = vec.size();
    for(int i = (size/2); i >= 1; i--)
        heapify(vec, i);
}

template <typename T>
void insert(vector<T> vec, T newN) {
    int size = vec.size();
    if(size == 0)
        vec.push_back(newN);
    else {
        vec.push_back(newN);
        for(int i = size/2-1; i >= 0; i--)
            heapify(vec, i);
    }
}


template <typename T>
void print(vector<T> vec) {
    for(size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << "\n";
}

// PROVA CON ARRAY
void heapify2(int array_in[], int array_size, int subtree_root_index)

{

    int largest_value = subtree_root_index;

    int left = 2*subtree_root_index + 1;

    int right = 2*subtree_root_index + 2;


    if (left < array_size && array_in[left] > array_in[largest_value]){

    largest_value = left; 

}


    if (right < array_size && array_in[right] > array_in[largest_value]){

    largest_value = right; 

}


    if (largest_value != subtree_root_index )

{

    swap(array_in[subtree_root_index], array_in[largest_value]);


    heapify2(array_in, array_size, largest_value);

}


}

void construct_heap(int array_in[], int array_size){

int last_non_leaf_node = (array_size/2) -1;

for (int subtree_root_index = last_non_leaf_node; subtree_root_index >=0; subtree_root_index-=1){

    heapify2(array_in, array_size, subtree_root_index);

}

}

void print_heap(int array_in[], int array_size){

  cout << "Printing values at each node in heap" << endl;

  for (int index = 0; index < array_size; index+=1){

    cout<< array_in[index] << endl;

}

}

int main() {
    srand((unsigned)time(0));
    vector<int> heap;
    //    insert(heap, 3);

	/*
    for(int i = 0; i < 5; i++) {
        int n = (rand()%10)+1;
        heap.push_back(n);
    }
    print(heap);
    cout << "Max-Heap Array \n";
    build_max_heap(heap);
    print(heap);
    */

    int arr[] = {3,5,8,10,17,11,13,19,22,24,29};
    int size = sizeof(arr)/sizeof(arr[0]);
    construct_heap(arr, size);
    print_heap(arr, size);
    
    return 0;
}
