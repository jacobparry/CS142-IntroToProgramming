#include "testfunctions.h"
#include <string>
#include <iostream>

/* *****************************************************************************
REVERSESTRING()

DESCRIPTION -    This function reverses the order of the characters in
                 an input string.

PARAMETERS/INPUTS:
    @TOREVERSE - The string to be reversed

RETURNS -        A string with the characters of TOREVERSE in the
                 reverse/opposite of their original order.

***************************************************************************** */

string reverseString( string toReverse )
{
	// PUT YOUR CODE HERE
	reverse(toReverse.begin(), toReverse.end());

	return toReverse;
}






/* *****************************************************************************
SUMRANGE()

DESCRIPTION - This function takes an input range specified by two integers.
              All of the integers in this range (inclusive of the specified
              limits) are summed up and the total is returned.

PARAMETERS/INPUTS:
    @LOW -    The lower limit of the range to be summed
    @HIGH -   The upper limit of the range to be summed

RETURNS -     The total of all of the integers of the specified range (inluding
              the low and high limits) is returned.

***************************************************************************** */

int sumRange(int low, int high)
{
	int sum = 0;

	for (int i = low; i <= high; i++)
	{
		sum = sum + i;
	}

	return sum;
}