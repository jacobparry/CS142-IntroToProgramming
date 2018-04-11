#include <iostream>
#include "testfunctions.h"

using namespace std;

/* 
DESCRIPTION - This function will test the reverseString() implementation.

PARAMETERS/INPUTS:
    @         None

RETURNS -     The number of test cases passing.
*/
int testReverseString()
{
	int numPassed = 0;

	cout << "Testing reverseString()...\n";
	cout << "-----------------------------\n\n";

	// Test reverseString( "cs142" )
	string input  = "cs142";
	string target = "241sc";
	string result = reverseString( input );

	if ( result == target )
	{
		cout << "SUCCESS!!!   reverseString(\"" << input << "\") produced \""
			 << target << "\".\n";
		numPassed++;
	}
	else
	{
		cout << "FAILURE!!!   reverseString(\"" << input << "\") produced \""
			<< result << "\" instead of \"" << target << "\".\n";
	}


	// Test reverseString( "programming" )
	input  = "programming";
	target = "gnimmargorp";
	result = reverseString( input );

	if (result == target)
	{
		cout << "SUCCESS!!!   reverseString(\"" << input << "\") produced \""
			<< target << "\".\n";
		numPassed++;
	}
	else
	{
		cout << "FAILURE!!!   reverseString(\"" << input << "\") produced \""
			<< result << "\" instead of \"" << target << "\".\n";
	}


	// Test reverseString( "Go Cougars!" )
	input = "Go Cougars!";
	target = "!sraguoC oG";
	result = reverseString(input);

	if (result == target)
	{
		cout << "SUCCESS!!!   reverseString(\"" << input << "\") produced \""
			<< target << "\".\n";
		numPassed++;
	}
	else
	{
		cout << "FAILURE!!!   reverseString(\"" << input << "\") produced \""
			<< result << "\" instead of \"" << target << "\".\n";
	}


	// Test reverseString( "Racecar" )
	input = "Racecar";
	target = "racecaR";
	result = reverseString(input);

	if (result == target)
	{
		cout << "SUCCESS!!!   reverseString(\"" << input << "\") produced \""
			<< target << "\".\n";
		numPassed++;
	}
	else
	{
		cout << "FAILURE!!!   reverseString(\"" << input << "\") produced \""
			<< result << "\" instead of \"" << target << "\".\n";
	}


	cout << "Passed " << numPassed << "/4 tests.\n\n";


	return numPassed;
}




/*
DESCRIPTION - This function will test the sumRange() implementation.

PARAMETERS/INPUTS:
@         None

RETURNS -     The number of test cases passing.
*/
int testSumRange()
{
	int numPassed = 0;

	cout << "Testing sumRange()...\n";
	cout << "-----------------------------\n\n";

	// Test sumRange( 1, 10 )
	int low = 1;
	int high = 10;
	int targetSum = 55;
	int result = sumRange(low, high);

	if (result == targetSum)
	{
		cout << "SUCCESS!!!   sumRange(\"" << low << ", " << high << "\") produced "
			<< targetSum << ".\n";
		numPassed++;
	}
	else
	{
		cout << "FAILURE!!!   sumRange(\"" << low << ", " << high << "\") produced "
			<< result << " instead of the expected " << targetSum << ".\n";
	}



	// Test sumRange( 5, 10 )
	low = 5;
	high = 10;
	targetSum = 45;
	result = sumRange(low, high);

	if (result == targetSum)
	{
		cout << "SUCCESS!!!   sumRange(\"" << low << ", " << high << "\") produced "
			<< targetSum << ".\n";
		numPassed++;
	}
	else
	{
		cout << "FAILURE!!!   sumRange(\"" << low << ", " << high << "\") produced "
			<< result << " instead of the expected " << targetSum << ".\n";
	}



	// Test sumRange( 5, 5 )
	low = 5;
	high = 5;
	targetSum = 5;
	result = sumRange(low, high);

	if (result == targetSum)
	{
		cout << "SUCCESS!!!   sumRange(\"" << low << ", " << high << "\") produced "
			<< targetSum << ".\n";
		numPassed++;
	}
	else
	{
		cout << "FAILURE!!!   sumRange(\"" << low << ", " << high << "\") produced "
			<< result << " instead of the expected " << targetSum << ".\n";
	}



	// Test sumRange( 5, 4 )
	low = 5;
	high = 4;
	targetSum = 0;
	result = sumRange(low, high);

	if (result == targetSum)
	{
		cout << "SUCCESS!!!   sumRange(\"" << low << ", " << high << "\") produced "
			<< targetSum << ".\n";
		numPassed++;
	}
	else
	{
		cout << "FAILURE!!!   sumRange(\"" << low << ", " << high << "\") produced "
			<< result << " instead of the expected " << targetSum << ".\n";
	}



	cout << "Passed " << numPassed << "/4 tests.\n\n";

	return numPassed;
}






int main()
{
	// Calling this function to run the tests on reverseString()
	testReverseString();

	// Calling this function to run the tests on sumRange()
	testSumRange();

	system("pause()");
	return 0;
}