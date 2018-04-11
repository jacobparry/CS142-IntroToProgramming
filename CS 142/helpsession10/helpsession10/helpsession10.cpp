#include <iostream>

#include "Student.h"
#include "Professor.h"
#include <fstream>
#include <sstream>



using namespace std;





int main()
{
	string newStudent = "Jake";
	double newPGA = 3.65;

	Student* newStud = new Student();
	Professor* newProf = new Professor();

	vector<BYPerson*> database;
	database.push_back(newStud);
	database.push_back(newProf);


	ifstream infile("newfile.txt");

	stringstream ss;
	string newsstring;
	getline(infile, newsstring);

	ss << newsstring;




	system("pause");
	return 0;
}