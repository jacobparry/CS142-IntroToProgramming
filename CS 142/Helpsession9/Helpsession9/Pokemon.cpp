#include "Pokemon.h"

const int START_STATS = 0;
const int START_LEVEL = 0;
const int START_BATTLES = 0;

Pokemon::Pokemon(string newName, string newCry)
{
	name = newName;
	cry = newCry;

	attack = START_STATS;
	defence = START_STATS;
	level = START_LEVEL;
	numBattles = START_BATTLES;
}


Pokemon::~Pokemon()
{

}

string Pokemon::GetName()
{
	return name;
}

string Pokemon::GetCry()
{
	return cry;
}

int Pokemon::GetAttack()
{
	return attack;
}

int Pokemon::GetDefence()
{
	return defence;
}

int Pokemon::GetLevel()
{
	return level;
} 

int Pokemon::GetBattles()
{
	return numBattles;
}


////SETTERS
void Pokemon:: RaiseAttack(int val)
{
	attack += val;
}

void Pokemon:: RaiseDefence(int val)
{
	defence += val;
}

void Pokemon:: RaiseLevel(int val)
{
	level++;
}

void Pokemon:: IncrementBattles()
{
	numBattles++;
}


//GENERAL
string Pokemon:: toString()
{
	stringstream ss;

	ss << "Name: " << name << endl;
	ss << "Cry: " << cry << endl;
	ss << "Level: " << level << endl;
	ss << "Attack" << attack << endl;
	ss << "Defense: " << defence << endl;

	string returnString = ss.str();

	return returnString;
}