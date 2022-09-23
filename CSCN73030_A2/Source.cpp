// CSCN73030_A2 - Matthew Persaud
// Fall 2022
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA {
	string firstName;
	string lastName;
	string email;
};

int main() {

	#ifdef _DEBUG
		cout << "Running in DEBUG mode!" << endl << endl;
		ifstream inputFile("StudentData.txt");
	#else
		cout << "Running in Release mode!" << endl << endl;
		ifstream inputFile("StudentData_Emails.txt");
	#endif

	vector<STUDENT_DATA> students;
	STUDENT_DATA newStudent;

	string lineData;

	int firstCommaIndex, secondCommaIndex;

	while (getline(inputFile, lineData)) {
		firstCommaIndex = lineData.find(",");

		#ifdef _DEBUG	//reads data in DEBUG mode
			newStudent.lastName = lineData.substr(0, firstCommaIndex);
			newStudent.firstName = lineData.substr(firstCommaIndex + 1, lineData.length() - firstCommaIndex);
		#else			//reads data in RELEASE mode (includes emails)
			secondCommaIndex = lineData.find(",", firstCommaIndex + 1);
			newStudent.lastName = lineData.substr(0, firstCommaIndex);
			newStudent.firstName = lineData.substr(firstCommaIndex + 1, secondCommaIndex - firstCommaIndex - 1);
			newStudent.email = lineData.substr(secondCommaIndex + 1, lineData.length() - secondCommaIndex);
		#endif

		students.push_back(newStudent);
	}

	#ifdef _DEBUG	//Prints student info in DEBUG mode (first and last name)
		for (int i = 0; i < students.size(); i++) {
			cout << students[i].firstName << " " << students[i].lastName << endl;
		}
	#else			//Prints student info in RELEASE mode (first and last name with email)
		for (int i = 0; i < students.size(); i++) {
			cout << students[i].firstName << " " << students[i].lastName << " - " << students[i].email << endl;
		}
	#endif

	return 1;
}