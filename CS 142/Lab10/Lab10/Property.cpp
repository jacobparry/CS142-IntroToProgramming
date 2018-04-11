#include "Property.h"
using namespace std;

int Property::prop_ID = 0;

Property::Property(string newTag, int rental, double newValue, string newAddress)
{
	tag = newTag;
	rental_status = rental;
	value = newValue;
	address = newAddress;
	property_id = prop_ID;

	prop_ID++;
}


Property::~Property()
{
}

/////GETTERS
double Property::getTaxes()
{
	return taxes;
}

string Property::getAddress()
{
	return address;
}

int Property::getPropID()
{
	return property_id;
}

double Property::getValue()
{
	return value;
}
/////SETTERS

/////GENERAL
 string Property::toString()
 {
	 stringstream ss;
	 ss << "Property ID: " << property_id;
	 ss << "   Address: " << address;
	 if (rental_status == RENTAL_YES)
	 {
		 ss << "   Rental";
	 }
	 if (rental_status == RENTAL_NO)
	 {
		 ss << "   NOT Rental";
	 }
	 ss << "   Estimated Value: " << value;


	 string returnString = ss.str();

	 return returnString;
 }