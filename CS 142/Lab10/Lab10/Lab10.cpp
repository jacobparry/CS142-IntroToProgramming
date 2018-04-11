#include <iostream>
#include "Property.h"
#include <fstream>
#include <vector>
#include "Residential.h"
#include "Commercial.h"

using namespace std;

const string COMMERCIAL = "Commercial";
const string RESIDENTIAL = "Residential";
const int RENTAL_YES = 1;
const int RENTAL_NO = 0;
const int OCCUPIED = 1;
const int NOT_OCCUPIED = 0;
const int DISCOUNTED = 1;
const int NOT_DISCOUNTED = 0;

/* Displays all the properties that have been made*/
void Display_Properties(vector<Property*> all_property)
{

	for (int i = 0; i < all_property.size(); i++)
	{
		cout << all_property[i]->toString() << endl;
	}
}

/* Prompts for a file, and then inports it. If it breaks, it will tell you. It will then tell you all the valid properties
that have been made, and then it will display the tax report.*/
void Load_File(vector<Property*> & all_property)
{
	cout << "Give me a file name please (remember to add the file extension): ";
	string file_name;

	cin.sync();
	getline(cin, file_name);
	
	ifstream property_import;
	property_import.open(file_name.c_str());
	
	if (property_import.is_open())
	{
		while (!property_import.eof())
		{
			stringstream ss;

			string line;
			getline(property_import, line);

			ss << line;

			string tag;
			bool rental_status;
			string address;
			double value;
			bool occupied_status;

			bool discounted_status;
			double tax_discount;

			ss >> tag;

			if (tag == RESIDENTIAL)//If it passes as residential then it will pass and go forward with the creation if nothing else breaks.
			{
				if (ss >> rental_status >> value >> occupied_status && getline(ss, address))
				{
					Residential* newResidential = new Residential(occupied_status, tag, rental_status, value, address);

					all_property.push_back(newResidential);
				}
				else
				{
					cout << "Ignoring invalid properties in " << line << endl;
				}
			}
			else if (tag == COMMERCIAL)//If it passes as residential then it will pass and go forward with the creation if nothing else breaks.
			{
				if (ss >> rental_status >> value >> discounted_status >> tax_discount && getline(ss, address))
				{
					Commercial* newCommercial = new Commercial(discounted_status, tax_discount, tag, rental_status, value, address);

					all_property.push_back(newCommercial);
				}
				else
				{
					cout << "Ignoring invalid properties in " << line << endl;
				}
			}
			else
			{
				cout << "Ignoring invalid properties in " << line << endl;
			}
		}

		property_import.close();
	}
	else
	{
		cout << "That file doesn't exist." << endl;
	}
	cout << endl;
}

/*Prints out the tax form*/
void Print_Tax_report(vector<Property*> all_property)
{
	cout << "\n\nNOW PRINTING TAX REPORT" << endl;
	
	for (int i = 0; i < all_property.size(); i++)
	{
		cout << "**Taxes due at property: " << all_property[i]->getAddress() << endl;
		cout << "\tProperty ID: " << all_property[i]->getPropID() << endl;
		cout << "\tEstimated Value: " << all_property[i]->getValue() << endl;
		cout << "\tEstimated Taxes Due: " << all_property[i]->setTaxes() << endl << endl;
	}
	
}

/*Does the math to figure out what the tax would be and then sets that variable*/
void Compute_Taxes(vector<Property*> all_properties)
{
	for (int i = 0; i < all_properties.size(); i++)
	{
		all_properties[i]->setTaxes();
	}
	
}

void Sort_Properties(vector<Property*>& all_properties, vector<Property*>& temp)
{

	int lots_of_rounds = 100;
	cout << "Enter 1 to sort by taxes\n";
	cout << "Enter 2 to sort by address\n";
	
	int sort_selection;
	cin >> sort_selection;

	if (!cin.fail())
	{
		if (sort_selection == 1)
		{
			for (int x = 0; x < lots_of_rounds; x++)
			{
				for (int i = 0; i < all_properties.size(); i++)
				{
					for (int j = 0; j < all_properties.size(); j++)
					{
						double tax1 = all_properties[i]->getTaxes();
						double tax2 = all_properties[j]->getTaxes();

						if (tax1 < tax2)
						{
							temp.push_back(all_properties[i]);
						}
						if (tax1 > tax2)
						{
							temp.push_back(all_properties[j]);
						}
						if (tax1 == tax2)
						{

						}
						for (int y = 0; y < all_properties.size(); y++)
						{
							all_properties[y] = temp[y];
							temp.erase(temp.begin());
						}
					}
					

				}
			}
		}
		if (sort_selection == 2)
		{
			for (int i = 0; i < lots_of_rounds; i++)
			{
				for (int i = 0; i < all_properties.size(); i++)
				{

				}
			}
		}
	}
	
	
	
}

int main()
{
	vector<Property*> all_property;
	vector<Property*> temp;


	bool flag = true;
	while (flag)
	{
		cout << "\n\n-----------------------------------------\n";
		cout << "WELCOME TO JAKE'S AMAZING REAL ESTATE\n";
		cout << "-----------------------------------------";

		cout << "\n\n Do you want to: \n";
		cout << "1 - Display All Properties\n";
		cout << "2 - Inport Property From File and Calculate taxes\n";
		cout << "3 - Quit\n";
		cout << "4 - Sort vector\n";

		cout << "\nPick and option: ";

		int option_selection;
		cin >> option_selection;

		if (!cin.fail())
		{
			if (option_selection == 1)
			{
				Display_Properties(all_property);
			}
			if (option_selection == 2)
			{				
				Load_File(all_property);
				Compute_Taxes(all_property);

				cout << "\nAll Valid Properties:" << endl;
				Display_Properties(all_property);
				Print_Tax_report(all_property);
			}

			if (option_selection == 3)
			{
				flag = false;
			}
			if (option_selection == 4)
			{
				Sort_Properties(all_property, temp);
			}
		}
		else
		{
			cout << "That was an invalid option. Please select a valid option.";
			cin.clear();
			cin.ignore();
		}
	}
	return 0;
}