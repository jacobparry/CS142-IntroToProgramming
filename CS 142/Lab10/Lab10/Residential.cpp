#include "Residential.h"


Residential::Residential(int occupancy, string newTag, int rental, double newValue, string newAddress) : Property(newTag, rental, newValue, newAddress)
//// Give everything that residential needs to be a residential, and then call property and give property everything it needs to be a property
{
	occupied = occupancy;

}


Residential::~Residential()
{
}


double Residential::setTaxes()
{
	double taxes;
	if (occupied == OCCUPIED)
	{
		taxes = value * occupied_tax;
	}
	if (occupied == NOT_OCCUPIED)
	{
		taxes = value * non_occupied_tax;
	}
	return taxes;
}


////GENERAL
string Residential::toString()
{
	stringstream ss;


	ss << Property::toString() << "   ";
	if (occupied == NOT_OCCUPIED)
	{
		ss << "Not Occupied";
	}
	if (occupied ==OCCUPIED)
	{
		ss << "Occupied";
	}
	

	string returnString = ss.str();

	return returnString;
}

/*Inherits toString from Property*/