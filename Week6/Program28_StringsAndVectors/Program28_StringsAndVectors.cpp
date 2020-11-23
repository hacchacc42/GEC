#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DisplayOptions(string item1, string item2);
void DisplayInventory();
void MagicRing();
void Rob();

const int MAX_SPACE = 3;
vector<string> Inventory;
string input;
bool full = false;

int main()
{
	Inventory.push_back("Sword");
	DisplayOptions("Knife", "Staff");
	DisplayOptions("Healing potion", "Fire spell");
	MagicRing();
	DisplayInventory();
	Rob();
	DisplayInventory();
}

void DisplayOptions(string item1, string item2)
{
	if (!full) {
		cout << "Type which item you wish to keep: " << item1 << " or " << item2 << endl;
		do {
			getline(cin, input);
			if ((input.compare(item1) && input.compare(item2)))
			{
				cout << "That's is not a corect choice" << endl;
			}
			else
			{
				Inventory.push_back(input);
			}
		} while ((input.compare(item1) && input.compare(item2)));
	}
	DisplayInventory();
}

void DisplayInventory()
{
	if (Inventory.size() == 0)
	{
		cout << "Inventory is now:" << endl << "Empty!" << endl;
	}
	else {
		cout << "Your inventory holds:" << endl;
		for (vector<string>::iterator i = Inventory.begin(); i != Inventory.end();i++)
		{
			cout << *i << endl;
		}
	}
	if (Inventory.size() >= MAX_SPACE)
	{
		cout << endl << "Your inventory is full!" << endl;
	}
	cout << endl;
}

void MagicRing()
{
	int j = 1;
	cout << endl << "You have found a Magic ring what would you like to replace in your invetory?" << endl << "Choices:" << endl;
	for (vector<string>::iterator i = Inventory.begin(); i != Inventory.end(); i++)
	{
		cout << j << ": " << *i << endl;
		j++;
	}
	cout << endl;
	int inputRing;
	do
	{
		cin >> inputRing;
		if (!(inputRing == 1 || inputRing == 2 || inputRing == 3))
		{
			cout << "Input is not correct" << endl;
		}
		else
		{
			Inventory[inputRing - 1] = "Magic ring";
		}
	} while (!(inputRing == 1 || inputRing == 2 || inputRing == 3));
}

void Rob()
{
	cout << "You have been robbed!!" << endl;
	Inventory.clear();
}