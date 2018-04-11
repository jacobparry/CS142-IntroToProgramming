#include <iostream>

#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include "Player.h"

using namespace std;

/*
TEST CASE 1
Select option 2, add player 1
Select option 2, add player 1
Tells me that player already exists.
Select option 2, add player 2
Select option 2, add player 3
Select option 3, add player 1 to the Line-up.
Select option 3, add player 2 to the Line-up.
Select option 3, add player 2 to the Line-up.
Select option 3, add player 3 to the Line-up.
Select option 5, Player 1 fights Player 2, Player 1 wins.
Select option 5, Player 2 fights Player 3, Player 3 wins.
Select option 3, add player B to the Line-up.
Select option 3, add player C to the Line-up.
Select option 5, Player 2 fights Player 3, Player 2 wins.
Select option 1, it displays all of the player info. Player B has a 66.66666% win ratio.
Select option 6, the program exits.

TEST CASE 2
Select option 2, add player A
Select option 2, add player A
Tells me that player already exists.
Select option 2, add player B
Select option 2, add player C
Select option 3, add player A to the Line-up.
Select option 3, add player A to the Line-up.
Select option 3, add player B to the Line-up.
Select option 3, add player C to the Line-up.
Select option 5, Player A fights Player A, ends in a draw.
Select option 5, Player B fights Player C, Player B wins.
Select option 3, add player B to the Line-up.
Select option 3, add player C to the Line-up.
Select option 5, Player B fights Player C, Player B wins.
Select option 1, it displays all of the player info. Player B has a 50% win ratio.
Select option 6, the program exits.


TEST CASE 3
Select option 2, add player Jon
Select option 2, add player Jon
Tells me that player already exists.
Select option 2, add player Ben
Select option 2, add player Carson
Select option 3, add player Jon to the Line-up.
Select option 3, add player Jon to the Line-up.
Select option 3, add player Ben to the Line-up.
Select option 3, add player Carson to the Line-up.
Select option 5, Player Jon fights Player Jon, ends in a draw.
Select option 5, Player Ben fights Player Carson, Player Carson wins.
Select option 3, add player Ben to the Line-up.
Select option 3, add player Carson to the Line-up.
Select option 5, Player Ben fights Player Carson, Player Carson wins.
Select option 1, it displays all of the player info. Player Ben has a 0% win ratio.
Select option 6, the program exits.

*/

const int NOT_FOUND = -1;
const int FIRST_POSITION = 0;
const int SECOND_POSITION = 1;
const int ROCK = 0;
const int PAPER = 1;
const int SCISSORS = 2;
const int MIN_CONSTESTANTS = 2;

/* Looks for a name in the all_player vector. If its found, returns its index. If not, returns -1 */
int Find_Player(vector<Player*> all_players, string toFind)
{
	for (int i = 0; i < all_players.size(); i++)
	{
		if (all_players[i] -> getName() == toFind)
		{
			return i;
		}
	}

	return NOT_FOUND;
}

/* Loops through the vector containing the pointers to all the players created and displays them to the screen*/
void Show_All_Players(vector<Player*> all_players)
{
	for (int i = 0; i < all_players.size(); i++)
	{
		cout << all_players[i]->toString() << endl;
		//cout << all_players[i]->getWinRecord() << endl;
	}
}

/* Loops through the vector containing the pointers to the line up players and displays them to the screen*/
void Show_Line_Up(vector<Player*> line_up)
{
	for (int i = 0; i < line_up.size(); i++)
	{
		cout << line_up[i]->toString() << endl;
	}
}

/* Searches for a name, and if it is not found then it will create that player and add its pointer to the vector  */
void Add_Player(vector<Player*>& all_players)
{
	cout << "Please enter the name of the player you want to add: ";
	string toFind;
	cin.sync();
	getline(cin, toFind);

	int found = Find_Player(all_players, toFind);

	if (found == NOT_FOUND)
	{
		Player* newpointer = new Player(toFind);
		all_players.push_back(newpointer);

		cout << toFind << " has been added.";
	}
	else
	{
		cout << "\nThat player already exists. Create a different player.\n";
	}
}

/* Searches for a name, if it doesnt exist then it says so, but if the player does exist it adds it to the line-up  */
void Add_to_Lineup(vector<Player*>& line_up, vector<Player*> all_players)
{
	cout << "Please enter the player name you want to add to the line-up: ";
	string to_add;
	cin.sync();
	getline(cin, to_add);

	int found = Find_Player(all_players, to_add);

	if (found == NOT_FOUND)
	{
		cout << "That player does not exist.";
	}
	else
	{
		line_up.push_back(all_players[found]);

		cout << to_add << " has been added to the line-up";
	}

}

/* Takes the first 2 players in the line up vector. If they are the same person, it ends in a draw, but if not 
then it goes on to compete both of them and it updates all of the statistics.  */
void Fight(vector<Player*>& line_up)
{
	

	if (line_up.size() >= MIN_CONSTESTANTS)
	{

		cout << "\n\nLETS GET READY TO RUUUUUMMMMMBBBBLEE!!!\n";
		

		int player1_throw = line_up[FIRST_POSITION]->getRPSThrow();
		int player2_throw = line_up[SECOND_POSITION]->getRPSThrow();

		

		if (line_up[FIRST_POSITION]->getName() == line_up[SECOND_POSITION]->getName())/////Checks if the players are the same player.
		{
			

			line_up[FIRST_POSITION]->IncrementDraws();
			line_up[FIRST_POSITION]->IncrementMatches();

			cout << "The match ended in a tie!\n";
		}
		
		else if (line_up[FIRST_POSITION]->getName() != line_up[SECOND_POSITION]->getName())
		{
			if (player1_throw == ROCK)
			{
				cout << line_up[FIRST_POSITION]->getName() << " throws Rock!\n";
			}
			if (player1_throw == PAPER)
			{
				cout << line_up[FIRST_POSITION]->getName() << " throws Paper!\n";
			}
			if (player1_throw == SCISSORS)
			{
				cout << line_up[FIRST_POSITION]->getName() << " throws Scissors!\n";
			}
			if (player2_throw == ROCK)
			{
				cout << line_up[SECOND_POSITION]->getName() << " throws Rock!\n";
			}
			if (player2_throw == PAPER)
			{
				cout << line_up[SECOND_POSITION]->getName() << " throws Paper!\n";
			}
			if (player2_throw == SCISSORS)
			{
				cout << line_up[SECOND_POSITION]->getName() << " throws Scissors!\n";
			}
		}
			
		
		

		else if (player1_throw == ROCK)/////////Goes through the different scenarios and determine the winner, and then updates statistics.
		{
			line_up[FIRST_POSITION]->IncrementMatches();
			line_up[SECOND_POSITION]->IncrementMatches();

			if (player2_throw == ROCK)
			{
				line_up[FIRST_POSITION]->IncrementDraws();
				line_up[SECOND_POSITION]->IncrementDraws();
				cout << "The match ended in a tie!\n";
			}
			if (player2_throw == PAPER)
			{
				line_up[FIRST_POSITION]->IncrementLosses();
				line_up[SECOND_POSITION]->IncrementWins();
				cout << line_up[SECOND_POSITION]->getName() << " wins!\n";
			}
			if (player2_throw == SCISSORS)
			{
				line_up[FIRST_POSITION]->IncrementWins();
				line_up[SECOND_POSITION]->IncrementLosses();
				cout << line_up[FIRST_POSITION]->getName() << " wins!\n";
			}
		}
		else if (player1_throw == PAPER)////////Goes through the different scenarios and determine the winner, and then updates statistics.
		{
			line_up[FIRST_POSITION]->IncrementMatches();
			line_up[SECOND_POSITION]->IncrementMatches();

			if (player2_throw == ROCK)
			{
				line_up[FIRST_POSITION]->IncrementWins();
				line_up[SECOND_POSITION]->IncrementLosses();
				cout << line_up[FIRST_POSITION]->getName() << " wins!\n";

			}
			if (player2_throw == PAPER)
			{
				line_up[FIRST_POSITION]->IncrementDraws();
				line_up[SECOND_POSITION]->IncrementDraws();
				cout << "The match ended in a tie!\n";
			}
			if (player2_throw == SCISSORS)
			{
				line_up[FIRST_POSITION]->IncrementLosses();
				line_up[SECOND_POSITION]->IncrementWins();
				cout << line_up[SECOND_POSITION]->getName() << " wins!\n";
			}
		}
		else if (player1_throw == SCISSORS)////////Goes through the different scenarios and determine the winner, and then updates statistics.
		{
			line_up[FIRST_POSITION]->IncrementMatches();
			line_up[SECOND_POSITION]->IncrementMatches();

			if (player2_throw == ROCK)
			{
				line_up[FIRST_POSITION]->IncrementLosses();
				line_up[SECOND_POSITION]->IncrementWins();
				cout << line_up[SECOND_POSITION]->getName() << " wins!\n";
			}
			if (player2_throw == PAPER)
			{
				line_up[FIRST_POSITION]->IncrementWins();
				line_up[SECOND_POSITION]->IncrementLosses();
				cout << line_up[FIRST_POSITION]->getName() << " wins!\n";
			}
			if (player2_throw == SCISSORS)
			{
				line_up[FIRST_POSITION]->IncrementDraws();
				line_up[SECOND_POSITION]->IncrementDraws();
				cout << "The match ended in a tie!\n";
			}
		}

		line_up[FIRST_POSITION]->SetWinRecord();
		line_up[SECOND_POSITION]->SetWinRecord();

		line_up.erase(line_up.begin());/////Erases the first 2 players from the line-up vector.
		line_up.erase(line_up.begin());
	}
	else
	{
		cout << "There are not enough contestants in the line-up to compete.";
	}
}



int main()
{
	srand(time(0));
	

	vector<Player*> all_players;
	vector<Player*> line_up;
	

	bool flag = true;
	while (flag)
	{

		cout << "\n\n-----------------------------------------\n";
		cout << "WELCOME TO ULTIMATE ROCK, PAPER, SCiSSORS\n";
		cout << "-----------------------------------------";

		cout << "\n\n Do you want to: \n";
		cout << "1 - Display All Players\n";
		cout << "2 - Add Player\n";
		cout << "3 - Add Player to Line-up\n";
		cout << "4 - Show Line-up\n";
		cout << "5 - Fight\n";
		cout << "6 - Quit\n";

		cout << "\nPick and option: ";
		int option_selection;
		cin >> option_selection;

		if (!cin.fail())
		{
			if (option_selection == 1)/////Display all players
			{
				Show_All_Players(all_players);
			}
			if (option_selection == 2)////Add Player
			{
				Add_Player(all_players);
			}
			if (option_selection == 3)////Add player to line-up
			{
				Add_to_Lineup(line_up, all_players);
			}
			if (option_selection == 4)////Show Line-up
			{
				Show_Line_Up(line_up);
			}
			if (option_selection == 5)////Fight
			{
				Fight(line_up);
			}
			if (option_selection == 6)////Quit
			{
				flag = false;
			}
			else
			{
				
			}
			
		}
		else
		{
			cout << "\nThat is not a valid option. Please pick a valid option.\n";
			cin.clear();
			cin.ignore();
		}

	}


	return 0;
}