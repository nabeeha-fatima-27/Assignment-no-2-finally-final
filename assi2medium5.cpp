#include <iostream>
using namespace std;
void copy(int arr1[10], int arr2[10]);
int main() {
	int arra1[10];
	int arra2[10];
	cout << "Enter the array values: ";
	for (int i = 0; i < 10; i++)
	{
		cin >> arra1[i];
	}
	cout << "Before Function: ";
	for (int i = 0; i < 10; i++)
	{
		cout<< arra1[i]<<" ";
	}
	cout << endl;
	copy(arra1, arra2);
	cout << "Copied string: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arra2[i] << " ";
	}
	return 0;
}
void copy(int arr1[10], int arr2[10]) {
	for (int i = 0; i < 10; i++)
	{
		arr2[i] = arr1[i];
	}
}
