#include<iostream>
using namespace std;
void printArray(int arr[], int size);
int main() {
	const int s = 5;
	int arr[s];
	printArray(arr, s);
	return 0;
}
void printArray(int arr[], int size) {
	cout << "Enter Array elements: ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	for (int i = 0; i < size; i++)
		cout<< arr[i]<<" ";
	}