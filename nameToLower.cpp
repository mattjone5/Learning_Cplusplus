#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string name;
	cout << "What is your name?\n";
	cin >> name;
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	cout << "Hi there " << name;
	return 0;
}

