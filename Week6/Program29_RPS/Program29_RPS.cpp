#include <iostream>
#include <string>
#include <random>
#include <time.h>

using namespace std;

bool RPS();
void Selection();
void CheckingResults();
bool Score();

int playerPoints = 0, computerPoints = 0;
int playerChoice, computerChoice;
bool goodSelect;
string input;

int main()
{
	srand(time(NULL));
	while (RPS());
}

bool RPS()
{
	Selection();
	CheckingResults();
	return (!Score());
}

void CheckingResults()
{
	//Checking results
	if (computerChoice == 1)//Rock - Computer
	{
		if (playerChoice == 1)//Rock - Player
		{
			cout << "It is a draw." << endl;
		}
		else if (playerChoice == 2)//Paper - Player
		{
			cout << "Congratulations, you win!" << endl;
			playerPoints++;
		}
		else//Scissors - Player
		{
			cout << "You lost." << endl;
			computerPoints++;
		}
	}
	else if (computerChoice == 2)//Paper - Computer
	{
		if (playerChoice == 1)//Rock - Player
		{
			cout << "You lost." << endl;
			computerPoints++;
		}
		else if (playerChoice == 2)//Paper - Player
		{
			cout << "It is a draw." << endl;
		}
		else//Scissors - Player
		{
			cout << "Congratulations, you win!" << endl;
			playerPoints++;
		}
	}
	else//Scissors - Computer
	{
		if (playerChoice == 1)//Rock - Player
		{
			cout << "Congratulations, you win!" << endl;
			playerPoints++;
		}
		else if (playerChoice == 2)//Paper - Player
		{
			cout << "You lost." << endl;
			computerPoints++;
		}
		else//Scissors - Player
		{
			cout << "It is a draw." << endl;
		}
	}
}

void Selection()
{
	//Player Input
	goodSelect = false;
	do {
		cout << "Enter your selection: ";
		getline(cin, input);
		if (!input.compare("Rock"))
		{
			playerChoice = 1;
			goodSelect = true;
		}
		else if (!input.compare("Paper"))
		{
			playerChoice = 2;
			goodSelect = true;
		}
		else if (!input.compare("Scissors"))
		{
			playerChoice = 3;
			goodSelect = true;
		}
		if (!goodSelect)
		{
			cout << "Invalid input" << endl;
		}
	} while (!goodSelect);
	//Computer Choice (random)
	cout << "The computer chose: ";
	computerChoice = rand() % 3 + 1;
	if (computerChoice == 1)
	{
		cout << "Rock" << endl;
	}
	else if (computerChoice == 2)
	{
		cout << "Paper" << endl;
	}
	else
	{
		cout << "Scissors" << endl;
	}
}

bool Score()
{
	cout << "You need : " << 3 - playerPoints << " to complete the game." << endl;
	cout << "The computer needs : " << 3 - computerPoints << " to complete the game." << endl;
	cout << "********************" << endl;
	if (computerPoints == 3)
	{
		cout << "Oh no, you lost :(" << endl;
		cout << "Game Over..." << endl;
		return true;
	}
	if (playerPoints == 3)
	{
		cout << "Congratulations, you won ! :D" << endl;
		cout << "Game Over..." << endl;
		return true;
	}
	return false;
}