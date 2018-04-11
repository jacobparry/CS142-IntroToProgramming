#include "Student.h"


Student::Student(string netid, int tenure, double GPA, string major) : BYPerson(netid, tenure)
{

}


Student::~Student()
{
}

void Student::ChangeMajor(string newMajor)
{
	major = newMajor;
}

void Student::SetGPA(double newGPA)
{
	GPA = newGPA;
}

string Student::toString()
{
	BYPerson::toString();

	cout << GPA << endl << major << endl;
}