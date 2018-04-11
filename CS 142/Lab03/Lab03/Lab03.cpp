#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

/*
	Test case 1
	Estimated miles = 15000
	Gas cost = $3.00
	Hybrid car = $60000
	Hybrid mpg = 60
	Hybrid Resale value = $45000
	Hybrid 5 year gas = 1250 gallons
	Hybrid 5 year cost = $18750
	Normal car = $25000
	Normal mpg = 30
	Normal Resale Value = $15000
	Normal 5 year gas = 2500 gallons
	Normal 5 year cost = $17500

	Test case 2
	Estimated miles = 10000
	Gas cost = $2.00
	Hybrid car = $40000
	Hybrid mpg = 40
	Hybrid Resale value = $25000
	Hybrid 5 year gas = 1250 gallons
	Hybrid 5 year cost = $17500
	Normal car = $30000
	Normal mpg = 35
	Normal Resale Value = $16000
	Normal 5 year gas = 1428.57 gallons
	Normal 5 year cost = $16857

	Test case 3
	Estimated miles = 5000
	Gas cost = $1.00
	Hybrid car = $20000
	Hybrid mpg = 45
	Hybrid Resale value = $15000
	Hybrid 5 year gas = 555.56 gallons
	Hybrid 5 year cost = $5555
	Normal car = $15000
	Normal mpg = 28
	Normal Resale Value = $9000
	Normal 5 year gas = 892.857 gallons
	Normal 5 year cost = $6892

	EXTRA CREDIT
	Non-hybrid cost= $15000
	Non-hybrid mpg= 25
	Non-hybrid resale = $11,250
	Hybrid cost = $32000
	Hybrid mpg = ???			****** 166.5  MPG ******
	Hybrid resale = $24000
	Gas cost = $2.50
	Miles driven = 10000
*/





int main()
{	
	//Part 1
	cout << "Please enter in how many miles you drive a year on average: ";							//Entering in different wanted values and correcting for them if negative.
	double miles_year;
	cin >> miles_year;
	if (miles_year <= 0)
	{
		cout << "Only positive numbers may be entered. Please enter a positive number.\n\n";
		cout << "\nPlease enter in how many miles you drive a year on average: ";
		cin >> miles_year;	
	}


	cout << "Please enter in how much a gallon of gas costs: $";				//Entering in different wanted values and correcting for them if negative.
	double gas_cost;
	cin >> gas_cost;
	if (gas_cost <= 0)
	{
		cout << "Only positive numbers may be entered. Please enter a positive number.\n\n";
		cout << "\nPlease enter in how much a gallon of gas costs: $";
		cin >> gas_cost;
	}


	cout << "Please enter in how much the hybrid car costs that you want: $";				//Entering in different wanted values and correcting for them if negative.
	double hybrid_cost;
	cin >> hybrid_cost;
	if (hybrid_cost <= 0)
	{
		cout << "Only positive numbers may be entered. Please enter a positive number.\n\n";
		cout << "\nPlease enter in how much the hybrid car costs that you want: $";
		cin >> hybrid_cost;
	}


	cout << "Please enter in how many miles per gallon (mpg) the hybrid car gets: ";				//Entering in different wanted values and correcting for them if negative.
	double hybrid_mpg;
	cin >> hybrid_mpg;
	if (hybrid_mpg <= 0)
	{
		cout << "Only positive numbers may be entered. Please enter a positive number.\n\n";
		cout << "\nPlease enter in how many miles per gallon (mpg) the hybrid car gets: ";
		cin >> hybrid_mpg;
	}


	cout << "What's the estimated resale value of the hybrid car after five year?: $";				//Entering in different wanted values and correcting for them if negative.
	double hybrid_resale;
	cin >> hybrid_resale;
	if (hybrid_resale <= 0)
	{
		cout << "Only positive numbers may be entered. Please enter a positive number.\n\n";
		cout << "\nWhat's the estimated resale value of the hybrid car after five year?: $";
		cin >> hybrid_resale;
	}


	cout << "Please enter in how much a non-hybrid car costs that you want: $";				//Entering in different wanted values and correcting for them if negative.
	double normal_car_cost;
	cin >> normal_car_cost;
	if (normal_car_cost <= 0)
	{
		cout << "Only positive numbers may be entered. Please enter a positive number.\n\n";
		cout << "\nPlease enter in how much a non-hybrid car costs that you want: $";
		cin >> normal_car_cost;
	}


	cout << "Please enter in how many miles per gallon (mpg) the non-hybrid car gets: ";				//Entering in different wanted values and correcting for them if negative.
	double normal_car_mpg;
	cin >> normal_car_mpg;
	if (normal_car_mpg <= 0)
	{
		cout << "Only positive numbers may be entered. Please enter a positive number.\n\n";
		cout << "\nPlease enter in how many miles per gallon (mpg) the non-hybrid car gets: ";
		cin >> normal_car_mpg;
	}


	cout << "What's the estimated resale value of the non-hybrid car after five year: $";				//Entering in different wanted values and correcting for them if negative.
	double normal_car_resale;
	cin >> normal_car_resale;
	if (normal_car_resale <= 0)
	{
		cout << "Only positive numbers may be entered. Please enter a positive number.\n\n";
		cout << "\nWhat's the estimated resale value of the non-hybrid car after five year: $";
		cin >> normal_car_resale;
	}


	cout << "\n\nEnter \"gas\" for low gas consumption or \"total\" for low total cost: ";				//Entering in for car type preference.
	string desired;
	cin >> desired;
	
	if (desired != "Gas" && desired != "Total")
	{
		cout << "Please enter in either \"gas\"  \"total\".\n\n";
		cout << "\nEnter \"gas\" for low gas consumption or \"total\" for low total cost: ";
		cin >> desired;
	}

		//Part 2
	
	const double  years_owned = 5;

	const double hybrid_5year_gas = (miles_year / hybrid_mpg) * years_owned;
	const double normal_5year_gas = (miles_year / normal_car_mpg) * years_owned;			//Calculation for 5 year gas consumption.
	
	const double hybrid_gas_cost = hybrid_5year_gas * gas_cost;					//Calculation for 5 year gas cost.
	const double normal_gas_cost = normal_5year_gas * gas_cost;

	const double hybrid_depreciation = hybrid_cost - hybrid_resale;				//Calculation for 5 year car depreciation.
	const double normal_depreciation = normal_car_cost - normal_car_resale;

	const double hybrid_ownership_cost = hybrid_gas_cost + hybrid_depreciation;	//Calculation for 5 year car ownership.
	const double normal_ownership_cost = normal_gas_cost + normal_depreciation;


	
	if (desired == "Gas")
	{
		if (hybrid_5year_gas < normal_5year_gas)
		{	
			cout << "\n\n\t\tHybrid Car Information\n";
			cout << "Total gallons consumed in 5 years: " << hybrid_5year_gas;
			cout << "\nTotal cost of car ownership for 5 years: $" << hybrid_ownership_cost;		//Hybrid Car information
			cout << "\n\n\n";
			cout << "Normal Car Information\n";
			cout << "Total gallons consumed in 5 years: " << normal_5year_gas;
			cout << "\nTotal cost of car ownership for 5 years: $" << normal_ownership_cost;
			cout << "\n\n";
		}
		else
		{
			cout << "\t\tNormal Car Information\n";
			cout << "Total gallons consumed in 5 years: " << normal_5year_gas;
			cout << "\nTotal cost of car ownership for 5 years: $" << normal_ownership_cost;		//Normal Car Information
			cout << "\n\n\n";
			cout << "Hybrid Car Information\n";
			cout << "Total gallons consumed in 5 years: " << hybrid_5year_gas;
			cout << "\nTotal cost of car ownership for 5 years: $" << hybrid_ownership_cost;
			cout << "\n\n";
		}
	}
	else if (desired == "Total")
	{
		if (hybrid_ownership_cost < normal_ownership_cost)
		{
			cout << "\n\n\t\tHybrid Car Information\n";
			cout << "Total gallons consumed in 5 years: " << hybrid_5year_gas;
			cout << "\nTotal cost of car ownership for 5 years: $" << hybrid_ownership_cost;		//Hybrid Car information
			cout << "\n\n\n";
			cout << "Normal Car Information\n";
			cout << "Total gallons consumed in 5 years: " << normal_5year_gas;
			cout << "\nTotal cost of car ownership for 5 years: $" << normal_ownership_cost;
			cout << "\n\n";
		}
		else
		{
			cout << "\n\n\t\tNormal Car Information\n";
			cout << "Total gallons consumed in 5 years: \t" << normal_5year_gas;
			cout << "\nTotal cost of car ownership for 5 years: $" << normal_ownership_cost;		//Normal Car Information
			cout << "\n\n\n";
			cout << "Hybrid Car Information\n";
			cout << "Total gallons consumed in 5 years: " << hybrid_5year_gas;
			cout << "\nTotal cost of car ownership for 5 years: $" << hybrid_ownership_cost;
			cout << "\n\n";
		}
	}
	

	


	system("pause");
	return 0;
}