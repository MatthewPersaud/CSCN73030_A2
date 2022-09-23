#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA {
	string firstName;
	string lastName;
};

int main() {

	ifstream inputFile("StudentData.txt");

	vector<STUDENT_DATA> students;
	STUDENT_DATA newStudent;

	string lineData;

	int commaIndex;

	while (getline(inputFile, lineData)) {
		commaIndex = lineData.find(",");

		newStudent.lastName = lineData.substr(0, commaIndex);
		newStudent.firstName = lineData.substr(commaIndex + 1, lineData.length());

		students.push_back(newStudent);
	}

	return 1;
}