#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>

class Employee {
private:
	int salary;
	std::string employeeID;
	int isManager;
public:
	int getSalary() {
		return salary;
	}
	std::string getEmployeeID() {
		return employeeID;
	}
	int getIsManager() {
		return isManager;
	}
	virtual int getPay(){
		return 0;
	}
	void setSalary(int salary) {
		this->salary = salary;
	}
	void setEmployeeID(std::string employeeID) {
		this->employeeID = employeeID;
	}
	void setIsManager(int isManager) {
		this->isManager = isManager;
	}
	Employee(int salary = 0, std::string employeeID = "", int isManager = 1) {
		this->salary = salary;
		this->employeeID = employeeID;
		this->isManager = isManager;
	}
};

class ManagerEmployee : public Employee {
public:
	ManagerEmployee(int salary = 0, std::string employeeID = "", int isManager = 2) : Employee(salary, employeeID, isManager){}
	int getPay() {
		return (getSalary() + (getSalary()*0.2)) / 12;
	}
};

class WorkerEmployee : public Employee {
public:
	WorkerEmployee(int salary = 0, std::string employeeID = "", int isManager = 1) : Employee(salary, employeeID, isManager) {}
	virtual int getPay() {
		return (getSalary() - 1200) / 12;
	}
};

std::vector<std::string> findEmployeeInFile(std::string employeeID) {
	std::vector<std::string> result;
	std::ifstream myFile;
	std::string curLine;
	myFile.open("input.txt");
	if (myFile.is_open() && myFile.good()) {
		while (std::getline(myFile, curLine)) {
			std::string curEmployeeID = curLine.substr(0, 8);
			if (curEmployeeID.compare(employeeID) == 0) {
				result.push_back(curEmployeeID);
				curLine.erase(0, 9);
				int commaLoc = curLine.find(",");
				result.push_back(curLine.substr(0, commaLoc));
				curLine.erase(0, commaLoc+1);
				result.push_back(curLine);
				return result;
			}
		}
	}
	else {
		std::cout << "Error, file was not found!!";
	}
	return result;
}

void saveFile(std::vector<Employee*> employeeData) {
	std::ofstream outFile;
	outFile.open("output.txt");
	for (int i = 0; i < employeeData.size(); i++) {
		outFile << employeeData[i]->getEmployeeID() << " earns $" << employeeData[i]->getPay() << " per pay period" << std::endl;
	}
	std::cout << "A file named output.txt was created with pay information." << std::endl;
	outFile.close();
}

int main() {
	int numOfSpot;
	std::cout << "How many employees do you want to get payroll for?: " << std::endl;
	std::cin >> numOfSpot;
	std::vector<Employee*> employeeArray;
	for (int i = 0; i < numOfSpot; i++) {
		std::string employeeID;
		int salary;
		int isManager;
		std::vector<std::string> curEmployeeData;
		std::printf("Please enter the Employee ID for employee #%d\n", i + 1);
		std::cin >> employeeID;
		curEmployeeData = findEmployeeInFile(employeeID);

		while (curEmployeeData.size() == 0) {
			std::cout << "Error, employee doesn\'t exist! Please try again." << std::endl;
			std::printf("Please enter the Employee ID for employee #%d\n", i + 1);
			std::cin >> employeeID;
		}

		std::printf("Please enter the salary for employee #%d\n", i + 1);
		std::cin >> salary;
		while (salary != std::stoi(curEmployeeData[1])) {
			std::cout << "Error, employee salary doesn\'t match our records. Please try again" << std::endl;
			std::printf("Please enter the salary for employee #%d\n", i + 1);
			std::cin >> salary;
		}

		std::printf("Please enter the employee type for employee #%d\n(1 for worker, 2 for manager)\n", i + 1);
		std::cin >> isManager;
		while (isManager != std::stoi(curEmployeeData[2])) {
			std::cout << "Error, employee type doesn\'t match our records. Please try again" << std::endl;
			std::printf("Please enter the employee type for employee #%d\n(1 for worker, 2 for manager)\n", i + 1);
			std::cin >> isManager;
		}

		if (isManager == 1) {
			employeeArray.push_back(new WorkerEmployee(salary, employeeID, isManager));
		}
		else {
			employeeArray.push_back(new ManagerEmployee(salary, employeeID, isManager));
		}
	}

	saveFile(employeeArray);
	return 0;
}