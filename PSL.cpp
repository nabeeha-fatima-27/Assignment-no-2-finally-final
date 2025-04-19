#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void addplayer();
void displayRecord(ifstream& file);
void searchbyname(string name);
void updatestats(string name, string type, int stats);
void deleteplayer(string name);
int main() {
	int option = 0;
	cout << "Select an option: " << endl;
	cout << "1. Add a player. " << endl;
	cout << "2. Display player records " << endl;
	cout << "3. Search by name. " << endl;
	cout << "4. Update stats. " << endl;
	cout << "5. Delete record. " << endl;
	cin >> option;
	if (option == 1) {
		addplayer();
	}
	else if (option == 2) {
		ifstream file2("players.txt");
		displayRecord(file2);
		file2.close();
	}
	else if (option == 3) {
		string name;
		cout << "Enter the name to search: ";
		cin >> name ;
		searchbyname(name);
	}
	else if (option == 4) {
		string name;
		string type;
		int stats = 0;
		cout << "Enter the name: ";
		cin >> name;
		cout << "Enter the type(wkts or runs): ";
		cin >> type;
		cout << "Enter the new stats: ";
		cin >> stats;
		updatestats(name, type, stats);
	}
	else if (option == 5) {
		string name;
		cout << "Enter the name: ";
		cin >> name;
		deleteplayer(name);
	}
	else {
		cout << "Invalid Choice. " << endl;
	}
}
void addplayer() {
	string name;
	string tname;
	string role;
	int wkts = 0;
	int runs = 0;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter team: ";
	cin >> tname ;
	cout << "Enter role: ";
	cin >> role;
	cout << "Enter wickets: ";
	cin >> wkts;
	cout << "Enter the runs: ";
	cin >> runs;
	ofstream file1("players.txt", ios::app);
	file1 << name << " " << tname << " " << role<< " " << wkts << " "<<runs << endl;
	file1.close();
}
void displayRecord(ifstream& file) {
	string namee;
	string t_name;
	string role_;
	int wickets=0;
	int run = 0;
	if (!file) {
		cout << "Error opening file! " << endl;
	}
	else {
		cout << "Name" << "                " << "Team" << "               " << "Role" << "            " << "Wickets" << "    " << "Runs" << endl;
		while (file >> namee >> t_name >> role_ >> wickets>>run) {
			cout << namee << "         " << t_name << "          " <<role_<< "          " << wickets<<"          "<<run << endl;
		}

	}
}
void searchbyname(string name) {
	ifstream file4("players.txt");
	string namee;
	string team;
	string rol;
	int w = 0;
	int r = 0;
	while (file4 >> namee >> team >> rol>> w>>r)
	{
		if (namee == name)
			cout << namee << " " << team<< " " << rol << " " << w <<" "<<r << endl;
	}
}
void updatestats(string name,string type, int stats) {
	ifstream reader("players.txt");
	ofstream writer("temp.txt");

	if (!reader || !writer) {
		cout << "File couldn't be opened." << endl;
		return;
	}

	string namee;
	string team;
	string rool;
	int wi = 0;
	int ru = 0;
	bool found = false;

	while (reader >> namee >> team >> rool>> wi>>ru) {
		if ( namee== name) {
			if (type == "wkts")
				wi = stats;
			else if (type == "runs")
				ru = stats;
			found = true;
		}
		writer << namee << " " << team<< " " << rool<< " " << wi<<" "<<ru << endl;
	}

	reader.close();
	writer.close();

	if (!found) {
		cout << "No player found with name: " <<name << endl;
		return;
	}
	remove("players.txt");
	rename("temp.txt", "players.txt");

	cout << "Stats updated successfully for: " << name << endl;
}
void deleteplayer(string name) {
	ifstream reader("players.txt");
	ofstream writer("temp.txt");

	if (!reader || !writer) {
		cout << "File couldn't be opened." << endl;
		return;
	}

	string namee;
	string team;
	string rool;
	int wi = 0;
	int ru = 0;
	bool found = false;

	while (reader >> namee >> team >> rool >> wi>>ru) {
		if (namee!= name) {
			writer << namee << " " << team<< " " << rool<< " " << wi<<" "<<ru << endl;
		}
		else {
			found = true;
		}
	}

	reader.close();
	writer.close();

	if (!found) {
		cout << "No player found with name  " << name << endl;
		return;
	}
	remove("players.txt");
	rename("temp.txt", "players.txt");

	cout << "Player with name " << name<< " deleted successfully." << endl;
}
