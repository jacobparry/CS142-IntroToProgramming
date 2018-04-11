#include "BYPerson.h"


BYPerson::BYPerson(string netid, int tenure)
{
	this->netid = netid;
	this->tenure = tenure;
}


BYPerson::~BYPerson()
{
}


string BYPerson::toString()
{
	cout << netid << endl;
	cout << tenure << endl;
}


