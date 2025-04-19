#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void addstudent();
void displayRecord(ifstream& file);
void searchbyrollno(string roll);
void updatecgpa(string roll, float newgpa);
void deleteStudent(string rollno);
int main() {
	int option = 0;
	cout << "Select an option: " << endl;
	cout << "1. Add a student. " << endl;
	cout << "2. Display student record " << endl;
	cout << "3. Search by Roll No. " << endl;
	cout << "4. Updat CGPA. " << endl;
	cout << "5. Delete record. " << endl;
	cin >> option;
	if (option == 1) {
		addstudent();
	}
	else if (option == 2) {
		ifstream file2("students.txt");
		displayRecord(file2);
		file2.close();
	}
	else if (option == 3) {
		string rollno;
		cout << "Enter the roll number to search: ";
		cin >> rollno;
		searchbyrollno(rollno);
	}
	else if (option == 4) {
		string rollno;
		float ncgpa = 0;
		cout << "Enter the roll no: ";
		cin >> rollno;
		cout << "Enter new cgpa: ";
		cin >> ncgpa;
		updatecgpa(rollno, ncgpa);
	}
	else if (option == 5) {
		string rollno;
		cout << "Enter the roll no: ";
		cin >> rollno;
		deleteStudent(rollno);
	}
	else {
		cout << "Invalid Choice. " << endl;
	}
}
void addstudent() {
	string name;
	string rollnum;
	string department;
	float cgpa = 0;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter roll number: ";
	cin >> rollnum;
	cout << "Enter department: ";
	cin >> department;
	cout << "Enter CGPA: ";
	cin >> cgpa;
	ofstream file1("students.txt", ios::app);
	file1 << name << " " << rollnum << " " << department << " " << cgpa << " " << endl;
	file1.close();
}
void displayRecord(ifstream& file) {
	string namee;
	string rollno;
	string dept;
	float CGPA;
	if (!file) {
		cout << "Error opening file! " << endl;
	}
	else {
		cout << "Name" << "           " << "Rollno." << "             " << "Department" << "          " << "CGPA" << endl;
		while (file >> namee >> rollno >> dept >> CGPA) {
			cout << namee << "         " << rollno << "          " << dept << "          " << CGPA << endl;
		}

	}
}
void searchbyrollno(string roll) {
	ifstream file4("students.txt");
	string name;
	string rollno;
	string depart;
	float CgPa = 0;
	while (file4 >> name >> rollno >> depart >> CgPa)
	{
		if (rollno == roll)
			cout << name << " " << rollno << " " << depart << " " << CgPa << endl;
	}
}
void updatecgpa(string roll, float newgpa) {
	ifstream reader("students.txt");
	ofstream writer("temp.txt");

	if (!reader || !writer) {
		cout << "File couldn't be opened." << endl;
		return;
	}

	string name, r, dept;
	float gpa;
	bool found = false;

	while (reader >> name >> r >> dept >> gpa) {
		if (r == roll) {
			gpa = newgpa;
			found = true;
		}
		writer << name << " " << r << " " << dept << " " << gpa << endl;
	}

	reader.close();
	writer.close();

	if (!found) {
		cout << "No student found with roll number: " << roll << endl;
		return;
	}
	remove("students.txt");
	rename("temp.txt", "students.txt");

	cout << "GPA updated successfully for roll: " << roll << endl;
}
void deleteStudent(string roll) {
	ifstream reader("students.txt");
	ofstream writer("temp.txt");

	if (!reader || !writer) {
		cout << "File couldn't be opened." << endl;
		return;
	}

	string name, r, dept;
	float gpa;
	bool found = false;

	while (reader >> name >> r >> dept >> gpa) {
		if (r != roll) {
			writer << name << " " << r << " " << dept << " " << gpa << endl;
		}
		else {
			found = true;
		}
	}

	reader.close();
	writer.close();

	if (!found) {
		cout << "No student found with roll number: " << roll << endl;
		return;
	}
	remove("students.txt");
	rename("temp.txt", "students.txt");

	cout << "Student with roll " << roll << " deleted successfully." << endl;
}
