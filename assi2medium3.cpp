#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int countwords(ifstream& file);
int main() {
    int c = 0;
    ifstream file2("input.txt");
    c = countwords(file2);
    cout << "No. of Words: " << c << endl;
    return 0;
}

int countwords(ifstream& file) {
    string s;
    int count = 0;
    while (file >> s) {
        count++;
    }
    return count;
}
