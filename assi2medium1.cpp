#include<iostream>
using namespace std;
int max(int arr[], int size);
int main() {
    const int size = 5;
    int arr[size];
    int maxi = 0;
    cout << "Enter the Array Values: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Array Values: ";
    for (int i = 0; i < size; i++)
        cout << arr[i]<<" ";
        cout << endl;
    max(arr, size);
    maxi= max(arr, size);
    cout << "Largest Number: " << maxi << endl;
    return 0;
}
int max(int arr[], int size) {
    int max1 = 0;
    for (int i = 0; i < size; i++)
    if (arr[i]>max1)
        max1 = arr[i];
    return max1;
}