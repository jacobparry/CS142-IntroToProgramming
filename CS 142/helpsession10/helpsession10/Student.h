#pragma once
#include "BYPerson.h"
class Student :
	public BYPerson
{
private:
	double GPA;
	string major;

public:
	Student();
	~Student();

	void SetGPA(double newGPA);
	void ChangeMajor(string newMajor);

	string toString();

};

/*student inherits netid and tenure from BYPerson*/