#pragma once
#include "Property.h"
class Residential :
	public Property
{
private:
	
	const int OCCUPIED = 1;
	const int NOT_OCCUPIED = 0;
	
	int occupied;

	double non_occupied_tax = .009;
	double occupied_tax = .006;

public:
	Residential(int occupancy, string newTag, int rental, double newValue, string newAddress);
	~Residential();


	/////GETTERS

	////SETTERS
	double setTaxes();

	/////GENERAL
	string toString();
};	


