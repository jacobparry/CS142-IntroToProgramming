#pragma once

#include <iostream>

#include <string>

#include <vector>



using namespace std;



class Student

{

private:

	string name;



public:

	Student(string name);

	string getName();

	void setName(string newName);





	~Student();

};



Student::Student(string studentName)

{

	name = studentName;

}






Student::~Student()

{

}







int main()

{

	vector<Student*> students;



	string name;

	cin >> name;





	for (size_t i = 0; i < length; i++)
	{

	}




	return 0;
}