#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Car.h"
#include <cstdlib>
#include <iomanip>

using namespace std;
/*
I pick option 2, it shows $10000.
I pick option 3, I enter Camero, Yellow, 9999.
I pick option 2, it shows $1.
I pick option 3, I enter Mustang, Blue, 2.
It tells me that it costs too much.
I selection option 5, I paint the camero blue.
I select option 1, it shows Camero, Blue, $10999.00
I select option 7, I save file as "Latest Report".
I selection option 6, I import "Latest Report.txt".
I select option 1, it shows 2 identical Cameros.
I select option 8, it closes.

I pick option 2, it shows $10000.
I pick option 3, I enter Camero, Yellow, aa.
It tells me that "aa" is not a valid price.
I pick option 3, I enter Mustang, Blue, 2.
I selection option 5, I paint the mustang orange.
I select option 1, it shows mustaing, orange, $1002.00
I select option 7, I save file as "Latest Report".
I selection option 6, I import "Latest Report.txt".
I select option 1, it shows 2 identical mustangs.
I select option 8, it closes.

I pick option 2, it shows $10000.
I pick option 3, I enter Challanger, Pink, 12345.
It tells me that it costs too much.
I pick option 3, I enter Mustang, Blue, 2.
I selection option 5, I paint the mustang orange.
I select option 1, it shows mustaing, orange, $1002.00
I select option 7, I save file as "Latest Report".
I selection option 6, I import "Latest Report.txt".
I select option 1, it shows 2 identical mustangs.
I selection option 6, I import "Latest Report.txt".
I select option 1, it shows 3 identical mustangs.
I select option 8, it closes.

*/
const int NOT_FOUND = -1;
const int FREE = 0;

/** Searches for a car, returns -1 if not found in inventory, otherwise returns location of car*/
int Find_Car(vector<Car> car_inventory, string car)
{
	for (int i = 0; i < car_inventory.size(); i++)
	{
		if (car_inventory[i].getName() == car)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

/** lists the information for hte current car inventory */
void Show_Inventory (vector<Car> car_inventory)
{
	

	for (int i = 0; i < car_inventory.size(); i++)
	{
		cout << car_inventory[i].toString() << endl;
	}
} 

/*Displays the current monetary balance*/
void Display_Balance(double balance)
{
	cout << setprecision(2) << fixed;
	cout << "Your current Balance is: $" << balance << endl;
}

/**adds a Car to the inventory if not already in it */
void Buy_Car(vector<Car>& car_inventory, string car_name, string car_color, double car_price, double& balance)
{
	int found = Find_Car(car_inventory, car_name);

	if (found == NOT_FOUND) ///Passes if the car was found.
	{
		//if (isdigit(car_price)) // Passes if the car price is a number
		{
			if (car_price >= FREE) // Passes if the car price is greater or = to 0.
			{
				if (car_price <= balance)
				{
					Car new_car = Car(car_name, car_color, car_price);
					car_inventory.push_back(new_car);
					balance = balance - car_price;
				}
				else
				{
					cout << "That car costs more money than you have.";
				}
			}
			else
			{
				cout << "\nYou cannot buy a car that is costs less than $0. Please try again.\n";
			}
		}
		//else
		{
			cout << "\nThat is not a number. Please try again.\n";
		}
	}
	else
	{
		cout << "That car is already in the inventory." << endl;
	}
}

/**Sells a Car and removes it from the inventory unless it is already not there */
void Sell_Car(vector<Car>& car_inventory, string car_name, double& balance)
{
	int found = Find_Car(car_inventory, car_name);

	if (found != NOT_FOUND)
	{
		double car_price = car_inventory[found].getPrice();
		
		car_inventory.erase(car_inventory.begin() + found); /// Erases the sold car from the vector. 
		
		balance = balance + car_price;
	}
	else
	{
		cout << "That car is not in the inventory." << endl;
	}
}

/* Paints the car and adds $1000 to its price.*/
void Paint_Car(vector<Car>& car_inventory, string car_name)
{
	int found = Find_Car(car_inventory, car_name);

	if (found != NOT_FOUND)
	{
		cout << "\nPick a color to paint it: ";

		string new_color;
		cin.sync();
		getline(cin, new_color);
		car_inventory[found].paint(new_color);
	}
	else
	{
		cout << "That car is not in the inventory." << endl;
	}
}


/*Load more information from a file*/
void Load_File(vector<Car>& car_inventory, double& current_balance)
{
	cout << "Give me a file name please (remember to add the file extension): ";
	string	filename;
	
	cin.sync();
	getline(cin, filename);
	
	
	ifstream car_inventory_import;
	car_inventory_import.open(filename.c_str());
	
	double new_balance;

	car_inventory_import >> new_balance;
	current_balance = current_balance + new_balance;

	while (!car_inventory_import.eof())
	{
		string car_name;
		string car_color;
		double car_price;

		car_inventory_import >> car_name;
		car_inventory_import >> car_color;
		car_inventory_import >> car_price;

		Car new_car = Car(car_name, car_color, car_price);

		car_inventory.push_back(new_car);
	}
	car_inventory_import.close();
}


/*Save current inventory and balance to a file*/
void Save_File(vector<Car> car_inventory, double current_balance)
{
	cout << "What do you want to save the file as: ";
	string file_name;
	cin.sync();
	getline(cin, file_name);
	string text = ".txt";
	string file_export = file_name + text;
	ofstream outfile(file_export);

	outfile << current_balance;

	for (int i = 0; i < car_inventory.size(); i++)
	{
		outfile << endl;
		outfile << car_inventory[i].getName() << " ";
		outfile << car_inventory[i].getColor() << " ";
		outfile << car_inventory[i].getPrice();
	}

	outfile.close();
}

int main()
{
	vector<Car> car_inventory;
	double current_balace = 10000;

	//Car Camero = Car("Camero", "Yellow", 16000);
	//cout << Camero.toString();
	//car_inventory.push_back(Camero);

	bool flag = true;
	while (flag)
	{
		cout << "\n\n-------------------------------------\n";
		cout << "WELCOME TO Crazy Jimmy's Bargain Auto\n";
		cout << "-------------------------------------";

		cout << "\n\n Do you want to: \n";
		cout << "1 - Show Current Inventory\n";
		cout << "2 - Show Current Balance\n";
		cout << "3 - Buy a Car\n";
		cout << "4 - Sell a Car\n";
		cout << "5 - Paint a Car\n";
		cout << "6 - Load File\n";
		cout << "7 - Save File\n";
		cout << "8 - Quit Program\n\n";

		
		cout << "Please pick a menu option: ";
		int option_selection;
		cin >> option_selection;

		if (!cin.fail())
		{
			if (option_selection == 1) //Show Current Inventory
			{
				Show_Inventory(car_inventory);
			}
			if (option_selection == 2) // Show Current Balance
			{
				Display_Balance(current_balace);
			}
			if (option_selection == 3) // Buy a car
			{
				string car_name;
				string car_color;
				double car_price;
				
				cout << "What is the name, color, and price of the car you want to buy?\n";
				
				cout << "\nName: ";
				cin.sync();
				getline(cin, car_name);

				cout << "Color: ";
				cin.sync();
				getline(cin, car_color);

				cout << "Price: $";
				cin >> car_price;
				

				Buy_Car(car_inventory, car_name, car_color, car_price, current_balace);
				
			}
			if (option_selection == 4) // Sell a car
			{
				string car_name;

				cout << "What is the name of the car you want to sell: ";
				cin.sync();
				getline(cin, car_name);

				Sell_Car(car_inventory, car_name, current_balace);
			}
			if (option_selection == 5) // Paint a car
			{
				cout << "What car do you want to paint: ";
				string car_name;
				cin.sync();
				getline(cin, car_name);

				Paint_Car(car_inventory, car_name);
			}
			if (option_selection == 6) // Load File
			{
				Load_File(car_inventory, current_balace);
			}
			if (option_selection == 7) // Save File
			{
				Save_File(car_inventory, current_balace);
			}
			if (option_selection == 8) // Quit Program
			{
				flag = false;
			}
			else
			{
			}
		}
		else
		{
			cout << "That is not a valid option!";
			cin.clear();
			cin.ignore();
			
		}
	}
}