#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

fstream myFile;

void displayScore();
void countScores();
void Swap(int& x, int& y);
void loadScore();
void saveScore();
int scores[10];
int y;
int main()
{
	char x;
	cout <<endl<< "What do you want to do?" << endl << "1.	Enter a score" << endl << "2.	Display scores" << endl << "3.	Exit" << endl;
	cin >> x;
	if (x == '1')
	{
		cin >> y;
		countScores();
	}
	else if(x=='2') {
		displayScore();
	}
	else if (x == '3')
	{
		return 0;
	}
	else
	{
		cout << "Invalid output." << endl;
		return main();
	}
}

void displayScore()
{
	loadScore();
	cout << "Rank   Score" << endl;
	for (int i = 9; i >= 0; i--)
	{
		cout <<setw(7)<<left<<9- i + 1 << scores[i] << endl;
	}
	main();
}

void countScores()
{
	int value = -1;
	loadScore();
	//Bubble Sort
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (scores[j] > scores[j + 1])
			{
				Swap(scores[j], scores[j + 1]);
			}
		}
	}
	//Checking the right position
	for (int i = 0; i < 10; i++)
	{
		if (y > scores[i])
		{
			value++;
		}
	}
	//Shifting the others positions
	if (value != -1)
	{	
		for (int k = 0; k <=value; k++)
		{
			scores[k] = scores[k + 1];
		}
		scores[value] = y;
	}
	saveScore();
	main();
}

void Swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void loadScore()
{
	myFile.open("scores.txt", ios::in);
	if (!myFile.is_open())
	{
		cout << "Fail to load" << endl;
	}
	else
	{
		int len = 0, x;
		while (myFile >> x)
		{
			scores[len] = x;
			len++;
		}
		if (len == 10)
		{
			for (int i = 0; i < 10; i++)
			{
				myFile >> scores[i];
			}
		}
		else
		{
			cout << "Less than 10 scores, suplying with some 0." << endl;
			for (int i = len; i < 10; i++)
			{
				scores[i] = 0;
			}
		}
		myFile.close();
	}
}

void saveScore()
{
	myFile.open("scores.txt", ios::out);
	for (int i = 0; i < 10; i++)
	{
		myFile << scores[i] << " ";
	}
	myFile.close();
}