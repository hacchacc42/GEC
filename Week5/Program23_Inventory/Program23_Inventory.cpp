#include <iostream>
using namespace std;

int main()
{
	const int MAX_ITEMS = 4;
	int numItems = 0;
	string inventory[MAX_ITEMS];
	inventory[numItems++] = "sword";
	inventory[numItems++] = "battle axe";
	inventory[numItems++] = "healing potion";
	inventory[numItems++] = "dagger";
	int choice;
	do {
		cout << "You found a wizard's staff, would you like to pick it up and swap with your " << inventory[3] << " ?" << endl;
		cout << "1. Yes    2. No" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "You pick up the staff and throw the " << inventory[3] << " on the ground." << endl;
			inventory[3] = "wizard's staff";
		}
		else if (choice == 2)
		{
			cout << "You decide to leave the staff behind." << endl;
		}
		else {
			cout << "That is not a correct choice." << endl;
		}
	} while (!(choice == 1 || choice == 2));
	cout << "You have in your invetory :" << endl;
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		cout << inventory[i] << endl;
	}
}