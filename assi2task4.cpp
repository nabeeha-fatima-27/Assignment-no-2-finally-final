#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void savetext(string s);
int main() {
	string text;
	savetext(text);
	return 0;
}
void savetext(string s) {
	cout << "Enter the text: ";
	cin >> s;
	ofstream file1("output.txt");
	file1 << s;
	file1.close();

}