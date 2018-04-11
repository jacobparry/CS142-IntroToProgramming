#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Property
{
protected:

	const int RENTAL_YES = 1;
	const int RENTAL_NO = 0;
	

	string tag;
	int rental_status;
	string address;
 	int property_id; 
	double value;
	double taxes;  //// this can be virtual
	static int prop_ID;

public:
	Property(string newTag, int rental, double newValue, string newAddress);
	~Property();

	/////GETTERS
	double getTaxes();
	string getAddress();
	int getPropID();
	double getValue();

	//////SETTERS

	virtual double setTaxes() = 0;

	//////GENERAL
	virtual string toString();

};

