#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int money = 100,x;

void TypeOfBet(int tob);
int main()
{
	srand(time(NULL));
	int bet,selectedi,selectedm;
	char selectedc;
	cout << "Balance: " << money << endl;
	cout << "Select your bet type:" << endl;
	cout << "1. Number Select" << endl;
	cout << "2. Black or Red" << endl;
	cout << "3. Odd or Even" << endl;
	cout << "4. 12" << endl;
	cout << "5. 2 to 1" << endl;
	cout << "6. Halfs" << endl;
	cin >> selectedm;
	/*cout << "Select the ammount you wish to bet :" << endl;
	cin >> bet;
	money -= bet;*/
	x = rand() % 36 + 1;
	TypeOfBet(selectedm);
}

void TypeOfBet(int tob) 
{
	cout << x << " " << tob << endl;
	main();
}