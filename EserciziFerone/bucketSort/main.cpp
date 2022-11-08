#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void bucketSort(T arr[], int n) {
	vector<T> b[n];
	for (int i = 0; i < n; i++) {
		int bi = n * arr[i];
		b[bi].push_back(arr[i]);
	}
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

template <typename T>
void bucketSort(vector<T> vec) {
	int n = vec.size();
	vector<T> b[n];
	for (int i = 0; i < n; i++) {
		int bi = n * vec.at(i);
		b[bi].push_back(vec.at(i));
	}
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

int main() {
	string arr[] = { "ciao", "anna", "bella" };
	int n = sizeof(arr) / sizeof(arr[0]);
	bucketSort(arr, n);
	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}