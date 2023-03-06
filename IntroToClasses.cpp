#include <iostream>
using namespace std;

class PlayerInfo {
private:
	string username;
	string password;
	int level;
public:
	string getUsername() {
		return username;
	}
	string getPassword() {
		return password;
	}
	int getLevel() {
		return level;
	}
	PlayerInfo(string username = "", string password = "", int level = 0) {
		this->username = username;
		this->password = password;
		this->level = level;
	}
};

class Person {
public:
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}

	void setName(string name) {
		this->name = name;
	}

	void setAge(int age) {
		this->age = age;
	}
private:
	string name;
	int age;

};

int main() {
	
	string username;
	string password;

	Person matt;
	matt.setName("Matt J.");
	cout << "Your name is " << matt.getName() << endl;
	cout << "Please enter a username: \n";
	cin >> username;
	cout << "Please enter a password: \n";
	cin >> password;

	PlayerInfo player1(username,password, 0);

	if (player1.getLevel() == 0) {
		cout << "Hey you are new to the game!!" << endl;
	}
	cout << "Welcome " << player1.getUsername();

	return 0;
}
