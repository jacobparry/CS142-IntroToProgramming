#pragma once
#include <string>
#include <sstream>

using namespace std;

const int STARTING_LEVEL = 1;
const int STARTING_STATS = 15;

class Pokemon
{
public:
	// Constructor and Deconstructor
	Pokemon(string name, string cry);
	~Pokemon(void);

	// Getters   just let you observe, they dont let you change
	string getName();
	string getCry();
	int getDefense();
	int getAttack();
	int getLevel();

	// Setters		Setters let you change things, 
	void raiseDefense(int increaseAmount);
	void raiseAttack(int increaseAmount);
	void raiseLevel();

	//General
	string toString();

private:
	string name;
	string cry;
	int defense;
	int attack;
	int level;
};

