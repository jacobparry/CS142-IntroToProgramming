#include "Commercial.h"


Commercial::Commercial(int discountStatus, double discount, string newTag, int rental, double newValue, string newAddress) : Property(newTag, rental, newValue, newAddress)
{
	discounted_status = discountStatus;
	tax_discount = discount;

}


Commercial::~Commercial()
{
}



double Commercial::setTaxes()
{
	double taxes;

	if (rental_status == RENTAL_YES)
	{
		taxes = (value * rental_tax);
	}
	if (rental_status == RENTAL_NO)
	{
		taxes = (value * non_rental_tax);
	}


	if (discounted_status ==DISCOUNTED)
	{
		cout << "this is happening" << endl;
		taxes = taxes - (taxes*tax_discount);
	}

	return taxes;
}

////GENERAL
string Commercial::toString()
{
	stringstream ss;

	ss << Property::toString();
	if (discounted_status == DISCOUNTED)
	{
		ss << "   Discounted";
	}
	if (discounted_status == NOT_DISCOUNTED)
	{
		ss << "   NOT Discounted";
	}
	ss << "   Discount: " << tax_discount;


	string returnString = ss.str();

	return returnString;
}

/*Inherits toString from Property*/