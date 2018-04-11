
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

double coin_path(double position)
{
	const double right = 0.5;////////Sets how much to move the token right or left.
	const double left = -0.5;
	cout << setprecision(1) << fixed;
	int chance = rand() % 2;
	double final_position = position;
	if (!cin.fail())
	{
		if (final_position >= 0 && final_position <= 8)
		{
			if (final_position == 0)
			{
				final_position = position + right;
			}
			else if (position == 8)
			{
				final_position = position + left;
			}
			else if (position > 0 && position < 8)
			{
				if (chance == 0)
				{
					final_position = position + right;
				}
				else
				{
					final_position = position + left;
				}
			}
		}
		else
		{
			cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
			cin.clear();
			cin.ignore();
		}
	}
	else
	{
		cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
		cin.clear();
		cin.ignore();
	}
	
	return final_position;

}

double prize_money(double final_position)
{
	const double slot0_8 = 100.00;
	const double slot1_7 = 500.00;/////////////sets constants for prize money.
	const double slot2_6 = 1000.00;
	const double slot3_5 = 0.00;
	const double slot4 = 10000.00;
	double prize = 0.00;
	
	cout << setprecision(2) << fixed;

	if (!cin.fail())
	{
		if (final_position >= 0 && final_position <= 8)
		{
			if (final_position == 0 || final_position == 8)
			{
				prize = prize + slot0_8;
			}
			else if (final_position == 1.0 || final_position == 7.0)
			{
				prize = prize + slot1_7;
			}
			else if (final_position == 2.0 || final_position == 6.0)/////////////////////////////// This section prints out how much money you won.
			{
				prize = prize + slot2_6;
			}
			else if (final_position == 3.0 || final_position == 5.0)
			{
				prize = prize + slot3_5;
			}
			else if (final_position == 4.0)
			{
				prize = prize + slot4;
			}
		}
		else
		{
			cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
			cin.clear();
			cin.ignore();
		}
	}
	else
	{
		cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
		cin.clear();
		cin.ignore();
	}
	
	return prize;
}

double average_money(double total_money_won, int tokens)
{
	double average_prize_money = total_money_won / tokens;

	return average_prize_money;
}

double all_slot_money(double position)
{
	double total_money_won = 0;
	double money_won = 0;
		for (int i = 0; i < 12; i++)
		{
			position = coin_path(position);
		}
		double final_position = position;
		money_won = prize_money(final_position);

		total_money_won = total_money_won + money_won;

		return total_money_won;
}

void multiple_coin_drop(double slot, int tokens)
{
	double total_money_won = 0;
	double money_won = 0;
	

	for (int j = 0; j < tokens; j++)
	{
		double position = slot;

		for (int i = 0; i < 12; i++)
		{
			position = coin_path(position);
		}
		double final_position = position;
		money_won = prize_money(final_position);

		total_money_won = total_money_won + money_won;

	}

	double average_money_won = average_money(total_money_won, tokens);
	cout << "\n\n\nTotal money won for slot " << slot << ": $" << total_money_won;
	cout << "\n\nAverage money won per token: $" << average_money_won << "\n\n\n\n";
}

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
		cout << "Option 3: Play multiple tokens into every slot. \n";
		cout << "Option 4: Quit the game and go home a loser. \n\n\n";
		cout << "Please enter option you would like to pick, 1, 2, 3, or 4: ";

		const double slot0_8 = 100.00;
		const double slot1_7 = 500.00;/////////////sets constants for prize money.
		const double slot2_6 = 1000.00;
		const double slot3_5 = 0.00;
		const double slot4 = 10000.00;

		const double right = 0.5;////////Sets how much to move the token right or left.
		const double left = -0.5;
		
		double money_won = 0.00;
		double total_money_won = 0.00;
		double average_money_won = 0.00;

		double option_selection;
		cin >> option_selection;
		if (!cin.fail())
		{
			if (option_selection == 1 || option_selection == 2 || option_selection == 3 || option_selection == 4)
			{
				//////////////////////////////////////////////////////////////////////////////////////////////////Option 1
				//////////////////////////////////////////////////////////////////////////////////////////////////Option 1
				if (option_selection == 1)
				{                       	
					cout << "\nSINGLE\n";
					cout << "\nPlease enter in which slot (0-8) you would like to drop your token: ";

					double slot;
					cin >> slot;/////////////Sets which slot to put the token into.

					double position = slot;
					if (!cin.fail())
					{
						if (slot == 0 || slot == 1 || slot == 2 || slot == 3 || slot == 4 || slot == 5 || slot == 6 || slot == 7 || slot == 8)
						{
							cout << "\n\nTOKEN PATH\n[" << slot << " ";
							for (int i = 0; i < 12; i++)
							{
								position = coin_path(position);

								cout << position;
								if (i < 11)
								{
									cout << " ";
								}
								else
								{
									cout << "]";
								}
							}
							double final_position = position;
							money_won = prize_money(final_position);
							cout << "\n\nYou won: $" << money_won << "\n\n\n\n";
						}//Closing bracket for the slot 1,2,3,4,5,6,7 or 8 test.
						else//Else paired with the slot 1,2,3,4,5,6,7 or 8 test.
						{
							cin.clear();
							cin.ignore();
							cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
						}
						
					}//Closing bracket for the slot cin.fail test.
					else//Else paired with the slot cin.fail test.
					{
						cin.clear();
						cin.ignore();
						cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
					}

				}//Closing bracket for the option selection == 1 test
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 2
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 2
				else if (option_selection == 2)
				{
					cout << setprecision(2) << fixed;
					cout << "\nMULTIPLE\n";
					cout << "\nPlease enter in how many tokens you want to drop: ";

					int tokens;
					cin >> tokens;

					if (!cin.fail())
					{
						if (tokens > 0)
						{
							cout << "\nPlease enter in which slot (0-8) you want to drop the tokens: ";
							double slot;
							cin >> slot;
							
							if (!cin.fail())
							{
								if (slot == 0 || slot == 1 || slot == 2 || slot == 3 || slot == 4 || slot == 5 || slot == 6 || slot == 7 || slot == 8)
								{
									multiple_coin_drop(slot, tokens);
									
									
									/*for (int j = 0; j < tokens; j++)
									{
										double position = slot;

										double final_position = multiple_coin_drop(position);
									
										
										money_won = prize_money(final_position);

										total_money_won = total_money_won + money_won;
									}

									double average_money_won = average_money(total_money_won, tokens);
									cout << "\n\n\nTotal money won: $" << total_money_won;
									cout << "\n\nAverage money won per token: $" << average_money_won << "\n\n\n\n";*/

								}// slot == 0,1,2,3,4,5,6,7,8 test
								else
								{
									cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";;
									cin.clear();
									cin.ignore();
								}
							}//clsing bracket for the slot cin.fail test.
							else
							{
								cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
								cin.clear();
								cin.ignore();
							}
						}// Closing bracket for tokens > 0 test.
						else
						{
							cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
							cin.clear();
							cin.ignore();
						}
					}//closing bracket for the token cin.fail test
					else
					{
						cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
						cin.clear();
						cin.ignore();
					}

				}
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 3
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 3
				else if (option_selection == 3)
				{
					double slot0 = 0;
					double slot1 = 1;
					double slot2 = 2;
					double slot3 = 3;
					double slot4 = 4;
					double slot5 = 5;
					double slot6 = 6;
					double slot7 = 7;
					double slot8 = 8;

					cout << "\nPlease enter how many tokens do you want to drop into every slot: ";
					int tokens;
					cin >> tokens;

					if (!cin.fail())
					{
						if (tokens > 0)
						{
							multiple_coin_drop(slot0, tokens);
							multiple_coin_drop(slot1, tokens);
							multiple_coin_drop(slot2, tokens);
							multiple_coin_drop(slot3, tokens);
							multiple_coin_drop(slot4, tokens);
							multiple_coin_drop(slot5, tokens);
							multiple_coin_drop(slot6, tokens);
							multiple_coin_drop(slot7, tokens);
							multiple_coin_drop(slot8, tokens);

							/*total_money_won = slot3_5;
							
							for (int k = 0; k < tokens; k++)
							{
								double position = slot0;
								money_won = all_slot_money(position);
								total_money_won = total_money_won + money_won;
								average_money_won = average_money(total_money_won, tokens);
							}
							cout << "\n\n\nTotal money won for slot 0: " << total_money_won;
							cout << "\nAverage money won per token: " << average_money_won;
							
							total_money_won = slot3_5;
							for (int k = 0; k < tokens; k++)
							{
								double position = slot1;
								money_won = all_slot_money(position);
								total_money_won = total_money_won + money_won;
								average_money_won = average_money(total_money_won, tokens);
							}
							cout << "\n\n\nTotal money won for slot 1: " << total_money_won;
							cout << "\nAverage money won per token: " << average_money_won;
							
							total_money_won = slot3_5;
							for (int k = 0; k < tokens; k++)
							{
								double position = slot2;
								money_won = all_slot_money(position);
								total_money_won = total_money_won + money_won;
								average_money_won = average_money(total_money_won, tokens);
							}
							cout << "\n\n\nTotal money won for slot 2: " << total_money_won;
							cout << "\nAverage money won per token: " << average_money_won;
							
							total_money_won = slot3_5;
							for (int k = 0; k < tokens; k++)
							{
								double position = slot3;
								money_won = all_slot_money(position);
								total_money_won = total_money_won + money_won;
								average_money_won = average_money(total_money_won, tokens);
							}
							cout << "\n\n\nTotal money won for slot 3: " << total_money_won;
							cout << "\nAverage money won per token: " << average_money_won;
							
							total_money_won = slot3_5;
							for (int k = 0; k < tokens; k++)
							{
								double position = slot4;
								money_won = all_slot_money(position);
								total_money_won = total_money_won + money_won;
								average_money_won = average_money(total_money_won, tokens);
							}
							cout << "\n\n\nTotal money won for slot 4: " << total_money_won;
							cout << "\nAverage money won per token: " << average_money_won;
							
							total_money_won = slot3_5;
							for (int k = 0; k < tokens; k++)
							{
								double position = slot5;
								money_won = all_slot_money(position);
								total_money_won = total_money_won + money_won;
								average_money_won = average_money(total_money_won, tokens);
							}
							cout << "\n\n\nTotal money won for slot 5: " << total_money_won;
							cout << "\nAverage money won per token: " << average_money_won;
						
							total_money_won = slot3_5;
							for (int k = 0; k < tokens; k++)
							{
								double position = slot6;
								money_won = all_slot_money(position);
								total_money_won = total_money_won + money_won;
								average_money_won = average_money(total_money_won, tokens);
							}
							cout << "\n\n\nTotal money won for slot 6: " << total_money_won;
							cout << "\nAverage money won per token: " << average_money_won;
							
							total_money_won = slot3_5;
							for (int k = 0; k < tokens; k++)
							{
								double position = slot7;
								money_won = all_slot_money(position);
								total_money_won = total_money_won + money_won;
								average_money_won = average_money(total_money_won, tokens);
							}
							cout << "\n\n\nTotal money won for slot 7: " << total_money_won;
							cout << "\nAverage money won per token: " << average_money_won;
							
							total_money_won = slot3_5;
							for (int k = 0; k < tokens; k++)
							{
								double position = slot8;
								money_won = all_slot_money(position);
								total_money_won = total_money_won + money_won;
								average_money_won = average_money(total_money_won, tokens);
							}
							cout << "\n\n\nTotal money won for slot 8: " << total_money_won;
							cout << "\nAverage money won per token: " << average_money_won << "\n\n\n";*/
							
						}
						else
						{
							cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
							cin.clear();
							cin.ignore();
						}
						
					}
					else
					{
						cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
						cin.clear();
						cin.ignore();
					}
				}
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 4
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 4
				else if (option_selection == 4)
				{
					cout << "\n\nGOODBYE, FAREWELL, AUFWIEDERSEHEN AND ADDIO\n\n";
					flag = false;
				}
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 3
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Option 3
			}////Closing bracket for option selection 1,2,3, or 4 test
			else// Else paired with the option selection 1,2,3, or 4 test
			{
				cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
				cin.clear();
				cin.ignore();
			}
	
		}//Closing bracket for the option selection cin.fail test
		else // Else paired the option selection cin.fail test
		{
			cout << "\n\nThat input was invalid. Please enter a valid input.\n\n";
			cin.clear();
			cin.ignore();
		}
		cin.clear();
	}
	system("pause");
	return 0;
}