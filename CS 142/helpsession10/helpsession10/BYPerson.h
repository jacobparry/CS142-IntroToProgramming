#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class BYPerson
{
private:
	string netid;
	int tenure;
	

public:
	BYPerson();
	~BYPerson();

	void update_tenure(int time);

	virtual string toString();


	virtual int parkingfeedue=0;
};
/*     */
