
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

/*
TEST CASE 1
I enter in "-1" for which option I want, a bad input.
It takes me back to the menu.
I enter in "6" for which option I want, a bad input.
It takes me back to the menu.
I pick option 1.
I enter -1 for which slot, a bad input.
I pick option 1 again.
I enter 9 for which slot, a bad input.
It takes me back to the opening menu.
I pick option 1 again.
I enter 4 for which slot.
I get as positions: 4.5  5  4.5  4  3.5  3  2.5  2  1.5  2  1.5  1
I won $500 dollars!

TEST CASE 2
I enter in "-65" for which option I want, a bad input.
It takes me back to the menu.
I enter in "21" for which option I want, a bad input.
It takes me back to the menu.
I pick option 2.
I enter in -21 tokens, a bad input.
It takes me back to the menu.
I pick option 2.
I enter in 89 tokens.
I enter in slot -1, a bad input.
It takes me back to the menu.
I enter in slot 9, a bad input.
It takes me back to the menu.
I pick option 2.
I enter in 89 tokens.
I enter in slot 8.
I won $150,200 with 89 tokens!

TEST CASE 3.
I enter in "-99" for which option I want, a bad input.
It takes me back to the menu.
I enter in "33" for which option I want, a bad input.
It takes me back to the menu.
I enter in 3 for option 3.
The application closed.
*/

using namespace std;

int main()
{
	srand(time(0));

	bool flag = true;
	while (flag)
	{
		cout << "*******************************************************************************\n";
		cout << "**************************TIME TO PLAY SOME PLINKO!!!**************************\n";
		cout << "*******************************************************************************\n\n\n\n\n";

		cout << "MENU\n";
		cout << "Option 1: Play a single token. \n";////////////////////////////Opening Menue
		cout << "Option 2: Play multiple tokens. \n";
		cout << "Option 3: Quit the game and go home a loser. \n\n\n";
		cout << "Please enter option you would like to pick, 1, 2, or 3: ";

		const double slot0_8 = 100.00;
		const double slot1_7 = 500.00;/////////////sets constants for prize money.
		const double slot2_6 = 1000.00;
		const double slot3_5 = 0.00;
		const double slot4 = 10000.00;

		const double right = 0.5;////////Sets how much to move the token right or left.
		const double left = -0.5;

		double money_won = 0.00;

		int option_selection;
		cin >> option_selection;


		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 1
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 1
		if (option_selection == 1)
		{
			cout << "\nSINGLE\n";
			cout << "\nPlease enter in which slot (0-8) you would like to drop your token: ";

			double slot;
			cin >> slot;/////////////Sets which slot to put the token into.

			double position = slot;

			cout << endl;

			if (slot == 0.0 || slot == 1.0 || slot == 2.0 || slot == 3.0 || slot == 4.0 || slot == 5.0 || slot == 6.0 || slot == 7.0 || slot == 8.0)//////Tells what to do if you select a slot 0-8.
			{
				cout << "[";
				for (int i = 0; i < 12; i++)////Repeats the calculation for token position 12 times.
				{
					cout << setprecision(1) << fixed;
					int chance = rand() % 2;
					if (slot >= 0.0 && slot <= 8.0)
					{
						if (position == 0.0)
						{
							position = position + right;
							cout << position;
						}
						else if (position == 8.0)
						{
							position = position + left;
							cout << position;
						}
						else if (position > 0.0 && position < 8.0)
						{
							if (chance == 0)
							{
								position = position + right;
								cout << position;
							}
							else
							{
								position = position + left;
								cout << position;
							}
						}
					}
					if (i < 11)
					{
						cout << " ";
					}
					else
					{
						cout << "]\n";
					}
				}
				
			}
			else
			{
				cout << "\n\nINVALID\n";/////////////////////////Returns user to menu following invalid input.
			}
			cout << setprecision(2) << fixed;
			if (position == 0 || position == 8)
			{
				cout << "\nYou won $" << slot0_8 << "\n\n";
			}
			else if (position == 1 || position == 7)
			{
				cout << "\nYou won $" << slot1_7 << "\n\n";
			}
			else if (position == 2 || position == 6)/////////////////////////////// This section prints out how much money you won.
			{
				cout << "\nYou won $" << slot2_6 << "\n\n";
			}
			else if (position == 3 || position == 5)
			{
				cout << "\nYou won $" << slot3_5 << "\n\n";
			}
			else if (position == 4)
			{
				cout << "\nYou won $" << slot4 << "\n\n";
			}
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 2
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 2
		else if (option_selection == 2)
		{
			cout << "\nMULTIPLE\n";
			cout << "\nEnter in how many tokens you want to drop: ";//This section determines how many tokens to be dropped in.

			int tokens;
			cin >> tokens;

			cout << setprecision(2) << fixed;

			if (tokens <= 0) /////////////////////////Returns user to menu following invalid input.
			{
				cout << "\n\nINVALID\n";
			}

			if (tokens > 0)
			{
				cout << "\nPlease enter in which slot (0-8) you would like to drop your tokens: ";//This section determines which slot you drop tokens into.

				int slot;
				cin >> slot;

				if (slot != 0 && slot != 1 && slot != 2 && slot != 3 && slot != 4 && slot != 5 && slot != 6 && slot != 7 && slot != 8)
				{
					cout << "\n\nINVALID\n";/////////////////////////Returns user to menu following invalid input.
				}

				if (slot >= 0 && slot <= 8)
				{

					for (int j = 0; j < tokens; j++)////////////Calculates the position and final place for each coin that you drop in.
					{
						double position = slot;
						for (int i = 0; i < 12; i++)
						{
							int chance = rand() % 2;
							if (slot >= 0 && slot <= 8) /////////Tells token position for slots 0-8
							{
								if (position == 0)
								{
									position = position + right;
								}
								else if (position == 8)
								{
									position = position + left;
								}
								else if (position > 0 && position < 8)
								{
									if (chance == 0)
									{
										position = position + right;
									}
									else
									{
										position = position + left;
									}
								}
							}
						}

						int final_pos = position;
						if (final_pos == 0 || final_pos == 8)
						{
							money_won = money_won + slot0_8;
						}
						else if (final_pos == 1 || final_pos == 7)
						{
							money_won = money_won + slot1_7;
						}
						else if (final_pos == 2 || final_pos == 6)    ////////////////////////////////This section calculations the total money won for dropping multiple chips.
						{
							money_won = money_won + slot2_6;
						}
						else if (final_pos == 3 || final_pos == 5)
						{
							money_won = money_won + slot3_5;
						}
						else if (final_pos == 4)
						{
							money_won = money_won + slot4;
						}

					}///For Loop j

					cout << "\nYou won $" << money_won << " with " << tokens << " tokens!\n" << endl;
					double average_money = money_won / tokens;
					cout << "Average money won per token: $" << average_money << endl;
				}
			}//Token IF
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 3
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 3
		else if (option_selection == 3)
		{
			cout << "\nGOODBYE\n";
			flag = false;
		}
		else
		{
			cout << "\n\nINVALID\n";
			 
		}
		cout << "\n\n\n\n";
		cin.clear();
		cin.ignore();
	}
	system("pause");
	return 0;
}