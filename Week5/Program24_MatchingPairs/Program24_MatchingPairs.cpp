#include <iostream>
using namespace std;

char boardCards[10] = { 'A','B','D','E','A','E','C','C','D','B' };
bool cardFound[10] = { false };
int attempts = 0;

void Draw1();
void Draw2(int guess1,int guess2);

int main()
{
	int score = 0;
	bool playing = true;
	while (playing)
	{
		Draw1();
		int guess1, guess2;
		cout << "Your first guess" << endl;
		cin >> guess1;
		cout << "Your second guess" << endl;
		cin >> guess2;
		attempts++;
		Draw2(guess1,guess2);
		sleep(2000);
		//Check Results
		if (boardCards[guess1-1] == boardCards[guess2-1]&&guess1!=guess2&&cardFound[guess1-1]==false)
		{
			score++;
			cardFound[guess1-1] = true;
			cardFound[guess2-1] = true;
		}
		else
		{
			cout << "No match" << endl;
		}
		if (score == 5)
		{
			system("cls");
			cout << "You WON !" << endl;
			cout << "Number of attempts: " << attempts << endl;
			playing = false;
		}
	}
}
void Draw1()
{
	system("cls");//Clearing the board
	cout << "Your current attempt is :" << attempts << endl;
	for (int i = 0; i < 10; i++)
	{
		if (cardFound[i])
		{
			cout << "[" << boardCards[i] << "]";
		}
		else
		{
			cout << "[" << i + 1 << "]";
		}
		if (i == 4)
		{
			cout << endl;
		}
	}
	cout << endl;
}
void Draw2(int guess1,int guess2)
{
	system("cls");//Clearing the board
	cout << "Your current attempt is :" << attempts << endl;
	for (int i = 0; i < 10; i++)
	{
		if ((cardFound[i]) || ((i+1) == guess1) || ((i+1)== guess2))
		{
			cout << "[" << boardCards[i] << "]";
		}
		else
		{
			cout << "[" << i + 1 << "]";
		}
		if (i == 4)
		{
			cout << endl;
		}
	}
	cout << endl;
}