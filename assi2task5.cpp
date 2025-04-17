#include<iostream>
using namespace std;
void printchar(char arr[], int size);
int main() {
	const int size = 100;
	char arr[size];
	cout << "Enter the array: ";
	cin.getline(arr, 100);
	int length = 0;
	while (arr[length] != '\0')
		length++;
	printchar(arr, length);
	return 0;
}
void printchar(char arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}