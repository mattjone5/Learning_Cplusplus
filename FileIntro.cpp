#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> loadFile(string filename) {
	ifstream myFile;
	string curLine;
	vector<string> allLines;
	myFile.open(filename);
	if (myFile.is_open() && myFile.good()) {
		while (getline(myFile, curLine)) {
			allLines.push_back(curLine);
		}
		return allLines;
	}
	else {
		cout << "Error: File can't be found.";
	}
}

void printVector(vector<string> myVecetor) {
	for (string line : myVecetor) {
		cout << line << "\n";
	}
}

int main() {
	string filename;
	cout << "Please enter a file name:\n";
	cin >> filename;
	vector<string> myVec = loadFile(filename);
	printVector(myVec);
	return 0;
}