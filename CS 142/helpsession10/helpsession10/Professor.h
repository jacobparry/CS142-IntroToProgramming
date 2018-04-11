#pragma once
#include "BYPerson.h"


class Professor :
	public BYPerson
{

private:
	vector<string> classes_taught;


public:
	Professor();
	~Professor();


	void Add_Class(string add_class );

};

