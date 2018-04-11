#pragma once
#include "Property.h"
class Commercial :
	public Property
{
private:

	const int DISCOUNTED = 1;
	const int NOT_DISCOUNTED = 0;

	int discounted_status;
	double tax_discount;

	double non_rental_tax = .01;
	double rental_tax = .012;

public:
	Commercial(int discountStatus, double discount, string newTag, int rental, double newValue, string newAddress);
	~Commercial();

	/////GETTERS

	////SETTERS
	double setTaxes();
	/////GENERAL
	string toString();
};

