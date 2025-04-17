#include<iostream>
using namespace std;
int sum(int arr[], int size);
int main() {
	const int s = 5;
	int arr[s];
	int summ;
	cout << "Enter the array values: ";
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
	}
	sum(arr, s);
	summ= sum(arr, s);
	cout << "Sum of Array Values: " << summ << endl;
	return 0;
}
int sum(int arr[], int size) {
	int sum1 = 0;
	for (int i = 0; i < size; i++)
	{
		sum1 += arr[i];
	}
	return sum1;
}