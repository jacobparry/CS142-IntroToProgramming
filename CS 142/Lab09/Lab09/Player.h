#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Player
{
private:
	string name;
	
	double wins;
	double losses;
	double draws;
	double total_matches;
	double win_ratio;


public:
	Player(string newName);
	~Player();


	/////GETTERS
	string getName();
	double getWins();
	double getLosses();
	double getDraws();
	double getMatchTotals();
	double getWinRecord();
	int getRPSThrow();

	/////SETTERS
	void IncrementWins();
	void IncrementLosses();
	void IncrementDraws();
	void IncrementMatches();
	void SetWinRecord();


	/////GENERAL
	string toString();

};

