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

#define PRE_RELEASE

int main() {

	string fileName;

	#ifdef PRE_RELEASE
		fileName = "StudentData_Emails.txt";
		cout << "Running in pre-release mode!" << endl << endl;
	#else
		cout << "Running in standard mode!" << endl << endl;
		fileName = "StudentData.txt";
	#endif

	#ifdef _DEBUG
		ifstream inputFile(fileName);

		vector<STUDENT_DATA> students;
		STUDENT_DATA newStudent;

		string lineData;

		int firstCommaIndex, secondCommaIndex;

		while (getline(inputFile, lineData)) {
			firstCommaIndex = lineData.find(",");
			secondCommaIndex = lineData.find(",", firstCommaIndex + 1);

			newStudent.lastName = lineData.substr(0, firstCommaIndex);
			newStudent.firstName = lineData.substr(firstCommaIndex + 1, secondCommaIndex - firstCommaIndex - 1);
			
			#ifdef PRE_RELEASE			//includes emails
				newStudent.email = lineData.substr(secondCommaIndex + 1, lineData.length() - secondCommaIndex);
			#endif
		
			students.push_back(newStudent);
		}

		#ifdef PRE_RELEASE		//Prints student info in pre-release mode (first and last name with email)
			for (int i = 0; i < students.size(); i++) {
				cout << students[i].firstName << " " << students[i].lastName << " - " << students[i].email << endl;
			}

		#else	//Prints student info in standard debug mode (first and last name)
			for (int i = 0; i < students.size(); i++) {
				cout << students[i].firstName << " " << students[i].lastName << endl;
			}
		#endif
	#endif

	return 1;
}