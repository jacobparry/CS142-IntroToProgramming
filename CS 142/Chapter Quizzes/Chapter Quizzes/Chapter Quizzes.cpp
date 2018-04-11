#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NOT_FOUND = -1;
const int times_to_shuffle = 100;
const int EVEN = 0;
const int POW_OF_2 = 2;
const int TRUE_POW = 1;


int main()
{

	bool power = false;
	vector<string> restaurants(8);

	int number_of_restaurants = 0;
	for (int i = 0; i < restaurants.size(); i++)
	{
		number_of_restaurants++;
	}

	double true_power = number_of_restaurants;
	int number_of_rounds = 0;

	if ((number_of_restaurants % 2) == EVEN)
	{
		bool trial = true;
		while (trial)
		{

			true_power = true_power / POW_OF_2;
			number_of_rounds++;
			if (true_power == TRUE_POW)
			{

				trial = false;
			}
			else if (true_power < TRUE_POW)
			{

				trial = false;
			}
		}
	}
	else
	{
	}

	system("pause");
	return 0;
}