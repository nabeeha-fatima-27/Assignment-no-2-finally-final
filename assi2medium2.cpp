#include<iostream>
using namespace std;
void reverse(char arr[], int size);
int main() {
	const int size = 100;
	char arr[size];
	int length = 0;
	cout << "Enter the array: ";
	cin.getline(arr, 100);
	while (arr[length] != '\0')
		length++;
	for (int i = 0; i < length; i++)
		cout << arr[i];
	    cout << endl;
	reverse(arr,length);
	return 0;
}
void reverse(char arr[], int size) {
	int temp = 0;
	for (int i = 0; i < size / 2; i++) {
		temp = arr[i];
		arr[i] = arr[size-1-i];
		arr[size-1-i] = temp;
	}
	cout << "Reversed array: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
}
