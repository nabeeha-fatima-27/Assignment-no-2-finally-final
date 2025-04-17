#include<iostream>
using namespace std;
int Countvowels(char arr[], int size);
int main() {
	const int size = 100;
	char arr[size];
	int length = 0;
	int vowelcount = 0;
	 cout << "Enter the array: ";
	 cin.getline(arr, 100);
	while (arr[length] != '\0')
		length++;
	
	Countvowels(arr, length);
	vowelcount= Countvowels(arr, length);
	cout << "Number of Vowels: " << vowelcount << endl;
	return 0;
}
int Countvowels(char arr[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o'||arr[i]=='u'||arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U')
			count++;
	}
	return count;
}