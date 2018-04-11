#include <iostream>
#include <iomanip>
#include <string>
#include <ostream>
#include <fstream>

using namespace std;

const int ARRAY_ROWS = 20;
const int ARRAY_COLUMNS = 20;
const int TOP_BOTTOM_TEMP = 100;
const int LEFT_RIGHT_TEMP = 0;
const int TOP_ROW = 0;
const int BOTTOM_ROW = 19;
const int LEFTMOST_COLUMN = 0;
const int RIGHTMOST_COLUMN = 19;
const int BEGINNING_CELL_VALUE = 0;

const double ITERATION_STOP_LIMIT = .1;
const int NUMBER_FOR_AVERAGE = 4;
const int TOP_ADJUSTMENT = -1;
const int BOTTOM_ADJUSTMENT = 1;
const int LEFT_ADJUSTMENT = -1;
const int RIGHT_ADJUSTMENT = 1;
const int CHANGEBABLE_CELLS = 324;

void initialize_array(double hotplate[ARRAY_ROWS][ARRAY_COLUMNS])
{
	
	for (int row = 0; row < 20; row++)//////////////Sets all cells to 0.
	{
		for (int column = 0; column < 20; column++)
		{
			hotplate[row][column] = BEGINNING_CELL_VALUE;
		}
	}
	
	for (int top = 0; top < 20; top++)////////////////Sets top and bottom rows to 100
	{
		hotplate[TOP_ROW][top] = TOP_BOTTOM_TEMP;
	}

	for (int bottom = 0; bottom < 20; bottom++)////////////////Sets top and bottom rows to 100
	{
		hotplate[BOTTOM_ROW][bottom] = TOP_BOTTOM_TEMP;
	}

	for (int left = 0; left < 20; left++)////////////////////////Sets left and right rows to 0
	{
		hotplate[left][LEFTMOST_COLUMN] = LEFT_RIGHT_TEMP;
	}

	for (int right = 0; right < 20; right++)///////////////////////Sets left and right rows to 0
	{
		hotplate[right][RIGHTMOST_COLUMN] = LEFT_RIGHT_TEMP;
	}
}

bool average_cells(double hotplate[ARRAY_ROWS][ARRAY_COLUMNS], int& counter)
{

	double temp_array[20][20];

	bool flag = false;
	double old_average = 100;
	double average = 0;
	double change_in_average = 0;

		double top = 0;
		double bottom = 0;
		double left = 0;
		double right = 0;
		
		for (int r = 0; r < 20; r++)////////////////Sets hotplate to a temperary array
		{
			for (int c = 0; c < 20; c++)
			{
				temp_array[r][c] = hotplate[r][c];
			}
		}

		for (int current_row = 0; current_row < 20; current_row++)
		{

			for (int current_column = 0; current_column < 20; current_column++)
			{
				if (hotplate[current_row] == hotplate[TOP_ROW])///////If its the top, bottom, left, or right then do nothing
				{
				}
				if (hotplate[current_row] == hotplate[BOTTOM_ROW])///////If its the top, bottom, left, or right then do nothing
				{

				}
				if (hotplate[current_column] == hotplate[LEFTMOST_COLUMN])///////If its the top, bottom, left, or right then do nothing
				{

				}
				if (hotplate[current_column] == hotplate[RIGHTMOST_COLUMN])///////If its the top, bottom, left, or right then do nothing
				{

				}
				if (hotplate[current_row] > hotplate[TOP_ROW] && hotplate[current_row] < hotplate[BOTTOM_ROW] && hotplate[current_column] > hotplate[LEFTMOST_COLUMN] && hotplate[current_column] < hotplate[RIGHTMOST_COLUMN])
				{
					top = hotplate[(current_row + TOP_ADJUSTMENT)][current_column];
					bottom = hotplate[(current_row + BOTTOM_ADJUSTMENT)][current_column];///////////Calculates the average of adjacent cells.
					left = hotplate[current_row][(current_column + LEFT_ADJUSTMENT)];
					right = hotplate[current_row][(current_column + RIGHT_ADJUSTMENT)];

					average = (top + bottom + left + right) / NUMBER_FOR_AVERAGE;

					temp_array[current_row][current_column] = average;

					change_in_average = (temp_array[current_row][current_column] - hotplate[current_row][current_column]);
					
					if (change_in_average < ITERATION_STOP_LIMIT)
					{
						counter++;
						if (counter == CHANGEBABLE_CELLS)/////////////Calculats how many cells are less that .1 change
						{
							flag = true;
						}
						
					}
					else
					{

					}
				}
			}
		}

		for (int b = 0; b < 20; b++)
		{
			for (int n = 0; n < 20; n++) ///////////////// Sets the temp array to equal the hotplate array.
			{
				hotplate[b][n] = temp_array[b][n];
			}
		}

		return flag;
}

void display_array(double hotplate[ARRAY_ROWS][ARRAY_COLUMNS])
{
	for (int row = 0; row < 20; row++)/////////////Prints out the array values
	{
		for (int column = 0; column < 20; column++)
		{
			cout << hotplate[row][column] << " ";
		}
		cout << endl;
	}
}

void export_array(double hotplate[ARRAY_ROWS][ARRAY_COLUMNS])
{
	ofstream outfile("lab6output.csv");   /////////////Exports the array values to a file.
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 20; column++)
		{
			outfile << hotplate[row][column] << ",";
		}
		outfile << endl;
	}
	outfile.close();
}

int main()
{
	cout << setprecision(1) << fixed;//////// sets decimal place to 1
	
	double hotplate[ARRAY_ROWS][ARRAY_COLUMNS];

	initialize_array(hotplate);/////////Function that initializes the array.

	display_array(hotplate);/////////Function that displays the array.

	cout << "\n\n";
	
	int counter = 0;
	bool change_in_average = average_cells(hotplate, counter); /////////Function that  does 1 iteration.

	display_array(hotplate);


	bool flagship = true;
	while (flagship)
	{
		counter = 0;
		change_in_average = average_cells(hotplate, counter);//////////Calculates the average and iterates until change < .1
		if (change_in_average == true)
		{
			flagship = false;
		}
		else
		{

		}
	}
	
	export_array(hotplate); //////////////////Exports the array to a file.




	system("pause");

	return 0;
}