#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;

int main()
{	/*  Test Case 1										Test Case 2										Test Case 3
		11 guests										21 guests										6 guests
		1 large, 1 medium, 1 small pizzas				3 large pizzas									2 medium pizzas
		total area is 628.319							total area is 942.478							total area is 402.124 square inches
		each guest eats 57.1199 square inches			each guest will eat 44.8799 square inches		each guest will eat 67.0206 square inches
		total cost for the pizza is $37 plus 10% tip	total cost for the pizza is $51 plus 15% tip	total cost is $26 with a 12% tip.
	
	
	
	*/

	// Part 1 of Lab 2
	cout << "How many guests are coming to your pizza party?\n";
	
	int guests;
	cin >> guests;

	int large_pizza = guests / 7;					// Gives the amount of large pizzas needed.
	int remainder1_guests = guests % 7;				// Gives the amount of guests who need a smaller pizza than a large.
	int medium_pizza = remainder1_guests / 3;		// Gives the amount of medium pizzas needed.
	int remainder2_guests = remainder1_guests % 3;	// Gives the remainder of guests who need a small pizza.
	int small_pizza = remainder2_guests;			// Gives the # of small pizzas needed.

	cout << "\nYou will need: " << large_pizza << " large pizzas, "
		<< medium_pizza << " medium pizzas, " << "and " << small_pizza << " small pizzas.\n\n";\



	// Part 2 of Lab 2

	const int large_diam = 20;
	const int medium_diam = 16;		//These are setting the constants for the pizza diameter.
	const int small_diam = 12;

	const double large_radius = 20 / 2;
	const double medium_radius = 16 / 2;		//These are setting the constants for the pizza radius.
	const double small_radius = 12 / 2;

	const double pi = 3.14159;

	const double large_area = pi * pow(large_radius, 2);
	const double medium_area = pi * pow(medium_radius, 2);  //These are setting the constants for a single pizza area.
	const double small_area = pi * pow(small_radius, 2);

	const double tot_large_area = large_area * large_pizza;
	const double tot_med_area = medium_area * medium_pizza;  //These are setting the constants for the total pizza area.
	const double tot_small_area = small_area * small_pizza;

	const double total_pizza_area = tot_large_area + tot_med_area + tot_small_area;

	cout << "You will need to buy " << total_pizza_area << " square inches of pizza.\n";
	cout << "Each guest will eat " << total_pizza_area / guests << " square inches of pizza.\n\n";



	// Part 3 of Lab 2

	const double large_price = 14.68;
	const double medium_price = 11.48;  //These are setting the constants for the pizza price.
	const double small_price = 7.28;

	const double pizza_cost = (large_pizza * large_price) + (medium_pizza * medium_price) + (small_pizza * small_price);

	cout << "How much % tip do you want to pay?\n";
	
	double tip;
	cin >> tip;
	cout << "\n";
	const double tip_percent = tip / 100;
	const double tip_paid = tip_percent * pizza_cost;  //These are setting the constants for the tip and total price.
	const double total_cost = pizza_cost + tip_paid;
	const int total_paid = total_cost + .5;

	cout << "Tip included. your pizza party will cost you $" << total_paid << ".\n\n";

	system("pause");
	return 0;

}