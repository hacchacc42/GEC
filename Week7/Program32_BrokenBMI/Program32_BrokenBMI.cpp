// BrokenBMI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void height();
void weight();
void output_bmi(float weight, float height);

int total_inches, total_weight;


int main()
{
	double bmi;
	const string message = "Welcome to your BMI Calculator.";
	string name;

	cout << message << endl;
	cout << "Firstly what is your full name?" << endl;
	getline(cin, name);
	cout << "Hi " << name << " lets get started." << endl;

	weight();
	height();

	output_bmi(total_weight, total_inches);
}

void height()
{
	int inches=0, feet=0;
	do
	{
		cout << "Please enter your height in feet:" << endl;
		cin >> feet;
		if (feet < 2 || feet > 7)
		{
			cout << "You must be between 2 and 7 feet" << endl;
		}
		else
		{
			cout << "Thank you!" << endl;
			break;
		}
	} while (feet <= 2 || feet >= 7);
	do
	{
		cout << "\nPlease enter the inches:" << endl;
		cin >> inches;

		if (inches < 0 || inches > 11)
		{
			cout << "\nInches must be between 0 and 11" << endl;
		}
		else
		{
			cout << "Thank you!" << endl;
			break;
		}
	} while (inches <= 0 || inches >= 11);
	total_inches = feet * 12 + inches;
	cout << "Your total height in inches is: " << total_inches << endl;
}

void weight()
{
	int stone=0, pounds=0;
	do
	{
		cout << "\nPlease enter your weight in stone:" << endl;
		cin >> stone;
		if (stone < 3 || stone > 30)
		{
			cout << "\nYou must be between 3 and 30 stone" << endl;
		}
		else
		{
			cout << "Thank you!" << endl << endl;
			break;
		}
	} while (stone <= 3 || stone >= 30);

	do
	{
		cout << "Please enter the pounds:" << endl;
		cin >> pounds;

		if (pounds < 0 || pounds >= 13)
		{
			cout << "Pounds must be between 0 and 13" << endl;
		}
		else
		{
			cout << "Thank you!" << endl << endl;
			break;
		}

	} while (pounds < 0 || pounds >= 13);
	//there are 14 lbs in 1 stone not 12
	total_weight = stone * 14 + pounds;
	cout << "Your total weight in pounds is: " << total_weight << endl;
}

void output_bmi(float weight, float height)
{
	float BMI;
	BMI = weight * 703 / (height * height);
	cout << "\nYour BMI is: " << BMI;
}