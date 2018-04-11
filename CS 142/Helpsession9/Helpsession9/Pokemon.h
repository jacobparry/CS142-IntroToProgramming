#pragma once

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Pokemon
{
private:
	string name;
	string cry;

	int attack;
	int defence;
	int level;

	int numBattles;




public:
	Pokemon(string newName, string newCry);
	~Pokemon();

	//GETTERS
	string GetName();
	string GetCry();
	int GetAttack();
	int GetDefence();
	int GetLevel();
	int GetBattles();


	//SETTERS
	void RaiseAttack(int val);
	void RaiseDefence(int val);
	void RaiseLevel(int val);
	void IncrementBattles();

	
	//GENERAL
	string toString();


};

