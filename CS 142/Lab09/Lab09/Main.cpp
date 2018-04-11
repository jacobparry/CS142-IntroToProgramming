#include "Player.h"

const int STARTING_WINS = 0;
const int STARTING_LOSSES = 0;
const int STARTING_DRAWS = 0;
const int STARTING_MATCHES = 0;
const int PERCENT_CONVERSION = 100;

Player::Player(string new_Name)
{
	name = new_Name;

	wins = STARTING_WINS;
	losses = STARTING_LOSSES;
	draws = STARTING_DRAWS;
	total_matches = STARTING_MATCHES;

	win_ratio = NULL;


}


Player::~Player()
{
}


///////GETTERS
string Player::getName()
{
	return name;
}

double Player::getWins()
{
	return wins;
}

double Player::getLosses()
{
	return losses;
}

double Player::getDraws()
{
	return draws;
}

double Player::getMatchTotals()
{
	return total_matches;
}

double Player::getWinRecord()
{

	return win_ratio;
}


int Player::getRPSThrow()
{
	int throws = rand() % 3;
	
	return throws;
}

/////////SETTERS
void Player::IncrementWins()
{
	wins++;
}

void Player::IncrementLosses()
{
	losses++;
}

void Player::IncrementDraws()
{
	draws++;
}

void Player::IncrementMatches()
{
	total_matches++;
}

void Player::SetWinRecord()
{
	if (total_matches == 0)
	{

	}
	else
	{
		win_ratio = (wins / total_matches) * PERCENT_CONVERSION;
	}
}


//////////////GENERAL
string Player::toString()
{
	stringstream ss;
	SetWinRecord();

	ss << "Name: " << name << endl;
	ss << "Wins: " << wins << endl;
	ss << "Losses: " << losses << endl;
	ss << "Draws: " << draws << endl;
	ss << "Total Matches: " << total_matches << endl;
	ss << "Win Ratio: " << getWinRecord() << "%" << endl;


	string returnString = ss.str();

	return returnString;
}