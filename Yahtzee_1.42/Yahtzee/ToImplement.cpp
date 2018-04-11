/* *****************************************************************************

CS 142 - Winter 2015
Midterm 1 - Yahtzee

Student Name: Jacob Parry
Student NetID: Jake421
Section and Instructor: Section 1, Robert Burton
Development Platform:  Visual Studio Express 2013

***************************************************************************** */



#include <iostream>
#include <string>

#include "YahtC++.h"

using namespace std;


// Some constants that you may find useful
const char CHAR_YES = 'Y';
const char CHAR_NO = 'N';
const int  TURNS_PER_GAME = 13;
const int  SIDES_PER_DIE = 6;





/* *****************************************************************************
GETYN()

DESCRIPTION - This function prompts the user for input in the form of either a
              'Y' or an 'N'.  Your program should accept either upper- or
			  lower-case Y and N.  Any other character that's given as input is
			  invalid and your program should continue to prompt the user until
			  a valid input character (a Y or an N) is received.

PARAMETERS/INPUTS:
    @PROMPT - This string parameter is used as the display prompt for the user.
	          For example, if prompt has the value "Do you want to quit?", then
			  the program will display "Do you want to quit? [Y/N]: " and wait
			  for user input.

RETURNS - Either an upper-case 'Y' or an 'N'

***************************************************************************** */

char getYN(string prompt)
{
	cout << prompt << " [Y/N]: ";  //Prints out the options you are supposed to select.
	char yes_or_no = 'Y';

	char Y_or_N = 't'; //Sets a user defined variable to be entered in. this will be used to return a value.
	cin >> Y_or_N;

	bool flag = true;   // This while loop is so it will keep repromting if they enter in a bad value.
	while (flag)
	{
		if (Y_or_N == 'Y' || Y_or_N == 'y') // if this proves true, sets flag to false and ends the loop. 
		{
			yes_or_no = CHAR_YES;
			flag = false;
		}
		else if (Y_or_N == 'N' || Y_or_N == 'n')  // if this proves true, sets flag to false and ends the loop.
		{
			yes_or_no = CHAR_NO;
			flag = false;
		}
		else
		{
			cin.clear();
			cin.ignore();
			cin >> Y_or_N;
		}

	}
	return yes_or_no; //will return either a Y or a N, depending on the value entered.

}







/* *****************************************************************************
GETCHARINRANGE()

DESCRIPTION - This function prompts the user for input in the form of a single
              character in a specified range.  Your program should accept either
			  upper- or lower-case characers, but always return upper case.  If
			  the character that's given by the user is in the specified range
			  (you may assume that the input characters are upper-case), then
			  then it should return it (return the upper-case version if a
			  lowe-case character was entered).  If the input is not in the
			  valid range, then your program should continue to prompt the user
			  until a valid input character (in the correct range) is received.

PARAMETERS/INPUTS:
    @MIN -    An upper-case character that begins the valid range.
	@MAX -    An upper-case character that ends the valid range.

RETURNS -     An upper-case character in the specified range.


***************************************************************************** */

char getCharInRange(char min, char max)
{
	// YOUR CODE GOES HERE...
	char range_char = 't';
	char char_to_return = 'j';
	bool flag = true;
	while (flag)
	{

	
		cin >> range_char;

		if (!cin.fail())
		{
			if (!isdigit(range_char)) // If the option entered is not a digit it will pass.
			{
				if (isalpha(range_char))// If the option entered is an alphabet value it will pass.
				{
					if (!islower(range_char)) // If the option entered is not lower case it will pass.
					{
						if (range_char >= min && range_char <= max) //// If the option entered is in range it will pass.
						{
							char_to_return = range_char;
							flag = false;
						}
						else
						{
						}
					}
					else
					{
						range_char = toupper(range_char); // If the option entered is lower case it will change it to upper.
						if (range_char >= min && range_char <= max)//// If the option entered is in range it will pass.
						{
							char_to_return = range_char;
							flag = false;
						}
						else
						{
						}
					}
				}
				else
				{
				}
			}
			else
			{
			}
		}
		else
		{
		}

	}

	return char_to_return;


	
}







/* *****************************************************************************
ISVALIDOPTION_YAHTZEE()

DESCRIPTION - This function determines whether the values on the five dice
              passed in as parameters constitute a YAHTZEE (all five dice have
			  an identical value).  For example, the values 2 2 2 2 2 represent
			  a YAHTZEE.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS - Either TRUE (if the values are all identical) or FALSE (otherwise).

***************************************************************************** */

bool isValidOption_YAHTZEE(int die1, int die2, int die3, int die4, int die5)
{
	// YOUR CODE GOES HERE...
	if (die1 == die2 && die1 == die3 && die1 == die4 && die1 == die5) // If die1 equals all the other die, it will be true and prove to be a yahtzee.
	{
		return true;

	}
	else // If die1 doesnt equal all the others, it is false and is not a yahtzee.
	{
		return false;
	}

}





/* *****************************************************************************
ISVALIDOPTION_SMSTRAIGHT()

DESCRIPTION - This function determines whether there is a small straight.  For
              example if the dice values were 2 5 4 3 4, there is a small
			  straight 2-3-4-5 present.  Any sequence of four consecutive
			  values (each in the range 1-6) is a small straight.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS -     Either TRUE (if a small straight is present in the dice) or
              FALSE (otherwise).

***************************************************************************** */

bool isValidOption_SmStraight(int die1, int die2, int die3, int die4, int die5)
{
	// YOUR CODE GOES HERE...

	int side1 = 1;
	int side2 = 2;
	int side3 = 3;
	int side4 = 4;
	int side5 = 5;
	int side6 = 6;

	bool flag = true;

	if (side1 == die1 || side1 == die2 || side1 == die3 || side1 == die4 || side1 == die5) //If side1 == at least 1 of the dice, it will be true
	{
		if (side2 == die1 || side2 == die2 || side2 == die3 || side2 == die4 || side2 == die5)//If side2 == at least 1 of the dice, it will be true
		{
			if (side3 == die1 || side3 == die2 || side3 == die3 || side3 == die4 || side3 == die5)//If side3 == at least 1 of the dice, it will be true
			{
				if (side4 == die1 || side4 == die2 || side4 == die3 || side4 == die4 || side4 == die5)//If side4 == at least 1 of the dice, it will be true
				{
					flag = true; /// If it gets to this point it proves there is at least a small straight.
				}
				else
				{
					flag = false;
				}
			}
			else
			{
				flag = false;
			}
		}
		else
		{
			flag = false;
		}
	}
	else if (side2 == die1 || side2 == die2 || side2 == die3 || side2 == die4 || side2 == die5)//If side2 == at least 1 of the dice, it will be true
	{
		if (side3 == die1 || side3 == die2 || side3 == die3 || side3 == die4 || side3 == die5)//If side3 == at least 1 of the dice, it will be true
		{
			if (side4 == die1 || side4 == die2 || side4 == die3 || side4 == die4 || side4 == die5)//If side4 == at least 1 of the dice, it will be true
			{
				if (side5 == die1 || side5 == die2 || side5 == die3 || side5 == die4 || side5 == die5)//If side5 == at least 1 of the dice, it will be true
				{
					flag = true;/// If it gets to this point it proves there is at least a small straight.
				}
				else
				{
					flag = false;
				}
			}
			else
			{
				flag = false;
			}
		}
		else
		{
			flag = false;
		}
	}
	else if (side3 == die1 || side3 == die2 || side3 == die3 || side3 == die4 || side3 == die5)//If side3 == at least 1 of the dice, it will be true
	{
		if (side4 == die1 || side4 == die2 || side4 == die3 || side4 == die4 || side4 == die5)//If side4 == at least 1 of the dice, it will be true
		{
			if (side5 == die1 || side5 == die2 || side5 == die3 || side5 == die4 || side5 == die5)//If side5 == at least 1 of the dice, it will be true
			{
				if (side6 == die1 || side6 == die2 || side6 == die3 || side6 == die4 || side6 == die5)//If side6 == at least 1 of the dice, it will be true
				{
					flag = true; //If it gets to this point it proves there is at least a small straight.
				}
				else
				{
					flag = false;
				}
			}
			else
			{
				flag = false;
			}
		}
		else
		{
			flag = false;
		}
	}
	else
	{
		flag = false;
	}
	return flag;

	
}







/* *****************************************************************************
ISVALIDOPTION_3OFAKIND()

DESCRIPTION - This function determines whether there are 3 (or more) dice that
              have the same value.  For example if the dice values were
			  2 5 5 1 5, there is a 3-of-a-kind, the fives.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS -     Either TRUE (if 3 or more dice have the same value) or
              FALSE (otherwise).

***************************************************************************** */

bool isValidOption_3OfAKind(int die1, int die2, int die3, int die4, int die5)
{
	// YOUR CODE GOES HERE...

	int three_of_a_kind = 0;
	int yes_three_of_kind = 3;
	int plusone = 1;
	bool flag = true;

	/*
	Every time a die == another die, it will add 1 to three_of_a_kind. If three_of_a_kind >= 3, then it proves there is at least a 3 of a kind.
	*/

	if (die1 == die2){ three_of_a_kind = three_of_a_kind + plusone; }
	if (die1 == die3){ three_of_a_kind = three_of_a_kind + plusone; }
	if (die1 == die4){ three_of_a_kind = three_of_a_kind + plusone; }
	if (die1 == die5){ three_of_a_kind = three_of_a_kind + plusone; }
	if (die2 == die3){ three_of_a_kind = three_of_a_kind + plusone; }
	if (die2 == die4){ three_of_a_kind = three_of_a_kind + plusone; }
	if (die2 == die5){ three_of_a_kind = three_of_a_kind + plusone; }
	if (die3 == die4){ three_of_a_kind = three_of_a_kind + plusone; }
	if (die3 == die5){ three_of_a_kind = three_of_a_kind + plusone; }
	if (die4 == die5){ three_of_a_kind = three_of_a_kind + plusone; }

	if (three_of_a_kind >= yes_three_of_kind)
	{
		return flag;
	}
	else
	{
		flag = false;
		return flag;
	}

	return false;  // TO BE CHANGED
}








/* *****************************************************************************
POINTSFOR_SIXES()

DESCRIPTION - This function computes the number of points for sixes.  If two
              dice show sixes, then this would return 12, if four dice show
			  sixes, then this function would return 24, and so forth.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS -     The total of all dice showing a six (an int).

***************************************************************************** */

int pointsFor_Sixes(int die1, int die2, int die3, int die4, int die5)
{
	// YOUR CODE GOES HERE...

	int sixespoints = 6;
	int totalsixpoints = 0;

	// Every time a die equals 6, it adds 6 to a variable. that variable is then return with the total points for sixes.

	if (die1 == SIDES_PER_DIE){ totalsixpoints = totalsixpoints + sixespoints; }
	if (die2 == SIDES_PER_DIE){ totalsixpoints = totalsixpoints + sixespoints; }
	if (die3 == SIDES_PER_DIE){ totalsixpoints = totalsixpoints + sixespoints; }
	if (die4 == SIDES_PER_DIE){ totalsixpoints = totalsixpoints + sixespoints; }
	if (die5 == SIDES_PER_DIE){ totalsixpoints = totalsixpoints + sixespoints; }

	return totalsixpoints;  // TO BE CHANGED
}





