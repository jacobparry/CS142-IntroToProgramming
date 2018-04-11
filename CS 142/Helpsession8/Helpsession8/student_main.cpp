#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
#include <fstream>

using namespace std;

const int NOTFOUND = -1;

int find(vector<Pokemon*> pokedex, string name)
{
	for (int i = 0; i < pokedex.size(); i++)
	{
		if (pokedex[i]-> getName() == name)
		{
			return i;
		}
	}
	return NOTFOUND;
}

void raiseAttack(vector<Pokemon*> pokedex, string name, int val)
{
	int loc = find(pokedex, name);
	if (loc  > -1)
	{
		pokedex[loc]->raiseAttack(val);
	}
}

int main()
{
	vector<Pokemon*> pokedex;
	vector<Pokemon*> backpack;

	Pokemon* newPokemon = new Pokemon("Charzard", "Char char");
	
	pokedex.push_back(newPokemon);
	int location = find(pokedex, "Charzard");

	Pokemon* newerPoke = pokedex[location];
	backpack.push_back(newerPoke);

	


	int menuChoice = 0;
	while(menuChoice != 8)
	{
		cout << "\n\n----------------------------------\n";
		cout << "WELCOME TO PROFESSOR OAK'S POKEDEX\n";
		cout << "----------------------------------";

		cout << "\n\n Do you want to: \n";
		cout << "1 - Display All Pokemon\n";
		cout << "2 - Display a Specific Pokemon's Info\n";
		cout << "3 - Add a New Pokemon\n";
		cout << "4 - Increase the Attack of a Pokemon\n";
		cout << "5 - Increase the Defense of a Pokemon\n";
		cout << "6 - Increment a Pokemon's Level\n";
		cout << "7 - Import Old Pokedex File\n";
		cout << "8 - Quit\n";

		cin >> menuChoice; // you will be changing this

		if (menuChoice == 1)
		{
		
		}
		if (menuChoice == 2)
		{
		
		}
		if (menuChoice == 3)
		{
			string name, cry;
			cout << "enter pokemon name: ";
			cin >> name;
			cout << "enter cry";
			cin >> cry;

			
		}
		if (menuChoice == 4)
		{

		}
		if (menuChoice == 5)
		{

		}
		if (menuChoice == 6)
		{

		}
		if (menuChoice == 7)
		{
			
		}
		if (menuChoice == 8)
		{

		}
	}

	system("pause");
	return 0;
}