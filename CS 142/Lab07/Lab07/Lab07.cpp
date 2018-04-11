#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Case 1
I select option 2, add bambam
I select option 1, displays all.
I select option 4, shuffles them all.
I select option 5. It tells me invalid, it needs to be a factor of 2.
I select option 3, remove olive garden.
I select option 5
I pick A,B,A,B for round 1
I pick B,A for round 2
I pick A for round 3
McDonalds wins! The program exits

Case 2
I select option 1, displays all. olive garden, outback, texas roadhouse, ihop, mcdonalds, gloria's little italy, goodwood, panda express
I select option 2, add Olive Garden, it fails because it is already there.
I select option 4, shuffles them all.
order is now : gloria's little italy, mcdonalds, panda express, ihop, goodwood, outback, texas roadhouse, olive garden
I select option 5
I pick A,B,A,B for round 1
I pick B,A for round 2
I pick A for round 3
IHOP wins! The program exits 

Case 3
I select option 3, I remove Bambam, it fails because its not there.
I select option 2, I add bambam.
I select option 3, remove bambam.
I select option 4, shuffles.
I select option 1, order is now : mcdonalds, gloria's little italy, goodwood, panda express, outback, texas roadhouse, ihop, olive garden
I add 8 more restaurants
I select option 5
Rounds are now 4 instead of 3
I alternate a b a b for every option
Goodwood wins! The program exits.
*/

const int NOT_FOUND = -1;
const int times_to_shuffle = 100;
const int EVEN = 0;
const int POW_OF_2 = 2;
const int TRUE_POW = 1;
const int QUIT = 0;

void Populate_Restaurants(vector<string>& restaurants)
{
	string Olive_Garden = "olive garden";
	string Outback = "outback";
	string Texas = "texas roadhouse";
	string IHOP = "ihop";
	string McDonalds = "mcdonalds";
	string Gloria = "gloria's little italy";
	string Goodwood = "goodwood";
	string Panda = "panda express";

	restaurants.push_back(Olive_Garden);///////////List of restaurants I am populating the array with.
	restaurants.push_back(Outback);
	restaurants.push_back(Texas);
	restaurants.push_back(IHOP);
	restaurants.push_back(McDonalds);
	restaurants.push_back(Gloria);
	restaurants.push_back(Goodwood);
	restaurants.push_back(Panda);

}

int Find_Restaurant(vector<string> restaurants, string toFind)
{
	for (int i = 0; i < restaurants.size(); i++) ///// Finds if the restaurant is there or not
	{
		if (restaurants[i] == toFind)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

void Make_Lowercase(string& add_me)
{
	const int length = add_me.length(); ////////Makes everything lowercase to solve for issues of upper and lowercase letters in words.
	for (int i = 0; i < length; ++i)
	{
		add_me[i] = tolower(add_me[i]);
	}
}

void Display_Restaurants(vector<string> restaurants)
{
	for (int i = 0; i < restaurants.size(); i++)///////Displays the vector to the screen.
	{
		cout << restaurants[i];
		if (i < (restaurants.size()- TRUE_POW))
		{
			cout << ", ";
		}
		else
		{
			cout << "\n\n";
		}
	}
}

void Add_Restaurant(vector<string>& restaurants)
{
	cout << "What is the name of the restaurant you wish to add? : ";

	string add_me;
	cin.sync();
	getline(cin, add_me);

	Make_Lowercase(add_me);//////Makes everything lowercase to solve for issues of upper and lowercase letters in words.

	int location = Find_Restaurant(restaurants, add_me);

	if (location == NOT_FOUND)///// If its not on the list, its added to the list.
	{
		restaurants.push_back(add_me);
		cout << endl;
		cout << add_me << " has been added to the list.\n\n";
	}
	else /// If its on the list, nothing happens.
	{
		cout << "\nThe restaurant is already on the list. \n\n";
	}
}

void Remove_Restaurant(vector<string>& restaurants)
{
	cout << "What is the name of the restaurant you wish to remove? : ";
	string remove_me;
	
	cin.sync();
	getline(cin, remove_me);

	Make_Lowercase(remove_me);//////Makes everything lowercase to solve for issues of upper and lowercase letters in words.
	int location = Find_Restaurant(restaurants, remove_me);

	if (location != NOT_FOUND)///// if its on the list, it is removed.
	{
		restaurants.erase(restaurants.begin() + location);
		cout << endl;
		cout << remove_me << " has been removed from the list.\n\n";
	}
	else///// it its not there, nothing happens..
	{
		cout << "\nThat restaurant is not on the list.\n\n";
	}
	
}

void Shuffle_Restaurants(vector<string>& restaurants)
{
	for (int i = 0; i < times_to_shuffle; i++)
	{
		int random1 = rand() % restaurants.size();
		int random2 = rand() % restaurants.size();

		if (random1 != random2)
		{
			string switch1 = restaurants[random1];
			string switch2 = restaurants[random2];

			restaurants[random1] = switch2;
			restaurants[random2] = switch1;
		}

	}
}

bool power_of_two(vector<string> restaurants)
{
	bool power = false;

	int number_of_restaurants = 0;
	for (int i = 0; i < restaurants.size(); i++)
	{
		number_of_restaurants++;
	}
	
	double true_power = number_of_restaurants;

	if ((number_of_restaurants % 2) == EVEN) //////// Tells if the number of restaurants is even.
	{
		bool trial = true;
		while (trial)
		{
			
			true_power = true_power / POW_OF_2;///////// Tells if the number of restaurants is a factor of 2 or not.
			if (true_power == TRUE_POW)
			{
				power = true;
				trial = false;
			}
			else if (true_power < TRUE_POW)
			{
				power = false;
				trial = false;
			}
		}
	}
	else
	{
		power = false;
	}
		
	return power;
}

int total_round(vector<string> restaurants)
{
	int number_of_restaurants = 0;
	for (int i = 0; i < restaurants.size(); i++)
	{
		number_of_restaurants++;
	}

	double true_power = number_of_restaurants;
	int number_of_rounds = 0;

	if ((number_of_restaurants % 2) == EVEN)//////// Tells if the number of restaurants is even.
	{
		bool trial = true;
		while (trial)
		{
			
			true_power = true_power / POW_OF_2;/////// Tells if the number of restaurants is a factor of 2 or not.
			number_of_rounds++; ///////// Solves for the amount of rounds needed.
			if (true_power == TRUE_POW)
			{
				
				trial = false;
			}
			else if (true_power < TRUE_POW)
			{
				
				trial = false;
			}
		}
	}
	else
	{
	}

	return number_of_rounds;
}

int Start_Tournament(vector<string> restaurants)
{
	bool flag = true;
	vector<string> winner;
	vector<string> temp;
	int position1 = 0;
	int position2 = 1;
	const int last_restaurant = 1;
	const int COMPLETE = 0;

	int max_rounds = total_round(restaurants);
	int current_round = 0;

	while (flag)
	{
		bool power = power_of_two(restaurants); /////// If restaurants are a power of 2 it goes on.
		if (power != false)
		{
			for (int round = 0; round < max_rounds; round++)///////// Resets after each round
			{
				int number_of_restaurants = 0;
				for (int i = 0; i < restaurants.size(); i++)
				{
					number_of_restaurants++;
				}
				int matches = number_of_restaurants / POW_OF_2;

				current_round++;
				cout << "Please choose one of the following two options [A]/[B].\n\n";

				for (int match = 1; match <= matches; match++) //////// resets after each match
				{
					
					bool choice = true;
					while (choice)
					{
						string restaurant_choice;
						
						cout << "Match " << match << "/" << matches << ", Round " << current_round << "/" << max_rounds << " ";
						cout << "[A] ---" << restaurants[position1] << " or [B] --- " << restaurants[position2] << ": ";

						cin.sync();
						getline(cin, restaurant_choice);

						if (restaurant_choice == "a" || restaurant_choice == "A")
						{
							temp.push_back(restaurants[position1]);  ////////Removes the 2 options from the list so they cannot be used again.
							restaurants.erase(restaurants.begin() + position1);
							restaurants.erase(restaurants.begin() + position1);
							choice = false;
						}
						else if (restaurant_choice == "b" || restaurant_choice == "B")
						{
							temp.push_back(restaurants[position2]);////////Removes the 2 options from the list so they cannot be used again.
							restaurants.erase(restaurants.begin() + position1);
							restaurants.erase(restaurants.begin() + position1);
							choice = false;
						}
						else
						{
							cout << "\nThat was not one of the options. Please select [A] or [B].\n\n"; ///////Gets mad at you if you dont select one of the two options
							cin.clear();
						}
						
					}
					

				}
				restaurants = temp;
				temp = winner;
				if (restaurants.size() == last_restaurant)
				{
					winner = restaurants;
					cout << "\n\nThe winner is " << winner[position1] << "!! Lets go eat!\n\n"; ////////// Tells you who the winner of the tournament is.
					flag = false;
					return COMPLETE;
				}
			}
		}
		else
		{
			cout << "\n\nPlease make the number of restaurants a power of 2. For example 2, 4, 8, 16, etc.\n\n";
			flag = false;
		}
	}
	
	
}

int main()
{
	srand(time(0));  /////Makes it random

	vector<string> restaurants;

	Populate_Restaurants(restaurants);

	bool flag = true;

	while (flag)
	{
		cout << "////////////////////////////////////////////////////////\n";
		cout << "///////////It's Time For Restaurant Wars!!//////////////\n";
		cout << "////////////////////////////////////////////////////////\n\n";

		
		cout << "Option 1 - Display All Restaurants\n";
		cout << "Option 2 - Add a Restaurant.\n";
		cout << "Option 3 - Remove a Restaurant.\n";
		cout << "Option 4 - Shuffle the order of the Restaurants.\n";
		cout << "Option 5 - Begin the Tournament.\n";
		cout << "Option 6 - Close Program.\n\n";

		cout << "Which option would you like to pick? [1]/[2]/[3]/[4]/[5]/[6] : ";

		int option_selection;
		cin >> option_selection;

		if (!cin.fail()) //////////Runs different functions depending on the option selected.
		{
			if (option_selection == 1 || option_selection == 2 || option_selection == 3 || option_selection == 4 || option_selection == 5 || option_selection == 6)
			{
				if (option_selection == 1)
				{
					Display_Restaurants(restaurants);
				}
				if (option_selection == 2)
				{
					Add_Restaurant(restaurants);
				}
				if (option_selection == 3)
				{
					Remove_Restaurant(restaurants);
				}
				if (option_selection == 4)
				{
					Shuffle_Restaurants(restaurants);
				}
				if (option_selection == 5)
				{
					int complete = Start_Tournament(restaurants);
					if (complete == QUIT)
					{
						system("pause");
						return 0;
					}
				}
				if (option_selection == 6)///////quits the program
				{
					flag = false;
				}
			}
			else
			{
				cout << "\nInvalid Imput\n\n";
				cin.clear();
				cin.ignore();
			}
			
		}
		else
		{
			cout << "\nInvalid Imput\n\n";
			cin.clear();
			cin.ignore();
		}
	}

	return 0;
}


