#include<iostream>
using namespace std;
int palindrome(char arr[], int size);
int main() {
	const int size = 100;
	char arr[size];
	int p = 0;
	cout << "Enter the array: ";
	cin.getline(arr, 100);
	int length = 0;
	while (arr[length] != '\0')
		length++;
	palindrome(arr, length);
	p= palindrome(arr, length);
	if (p == 1)
		cout << "Is a Palindrome. " << endl;
	else
		cout << "Is not a Palindrome. " << endl;
	return 0;
}
int palindrome(char arr[], int size) {
	int ispalindrome = 1;
	for (int i = 0; i < size/2; i++) 
		if (arr[i] != arr[size -1- i]) {
			ispalindrome = 0;
			break;
		}
	if (ispalindrome == 1)
		return 1;
	if (ispalindrome == 0)
		return 0;
}