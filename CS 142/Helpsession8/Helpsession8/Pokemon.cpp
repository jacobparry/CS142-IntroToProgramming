#include "Pokemon.h"
/*Everything included in Pokemon.h will also be 
	recorded in this main*/

// Creates and initializes a Pokemon
Pokemon::Pokemon(string name_in, string cry_in)
{
	name = name_in;
	cry = cry_in;
	defense = STARTING_STATS;
	attack = STARTING_STATS;
	level = STARTING_LEVEL;
}

//Deconstructor - don't need to worry about this yet
Pokemon::~Pokemon(void)
{
}

// returns the name of the Pokemon
string Pokemon::getName()
{
	return name;
}

// returns the cry of the Pokemon
string Pokemon::getCry()
{
	return cry;
}

// returns the defense of the Pokemon
int Pokemon::getDefense()
{
	return defense;
}

// returns the attack of the Pokemon
int Pokemon::getAttack()
{
	return attack;
}

//returns the level of the Pokemon
int Pokemon::getLevel()
{
	return level;
}

// raises the defense stat by a given amount
void Pokemon::raiseDefense(int increaseAmount)
{
	defense += increaseAmount;
}

// raises the attack stat by a given amount
void Pokemon::raiseAttack(int increaseAmount)
{
	attack += increaseAmount;
}

// raises the Pokemon level by 1
void Pokemon::raiseLevel()
{
	level++;
}

//returns a string containing all the Pokemon's info
string Pokemon::toString()
{
	stringstream ss;
	ss << "Name: " << name << endl;
	ss << "Level: " << level << endl;
	ss << "Attack: " << attack << endl;
	ss << "Defense: " << defense << endl;
	ss << "Cry: " << cry << endl;

	return ss.str();
}