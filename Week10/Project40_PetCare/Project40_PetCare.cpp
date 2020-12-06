#include "Pets.h"
#include <iostream>

using namespace std;

int main()
{
	Pet* petPtr;
	char ch, ch1, ch2;
	cout << "1.Dog 2.Cat 3.Hamster" << endl << "Enter your choice : ";

	cin >> ch2;

	switch (ch2)
	{
	case '1':
		petPtr = new Dog("dog");
		break;
	case '2':
		petPtr = new Cat("cat");
		break;
	case '3':
		petPtr = new Hamster("hamster");
		break;
	default:
		petPtr = new Pet("pet");
		break;
	}
	do
	{
		petPtr->Mood();
		cout << "what do you want to do ?" << endl << "0 - Quit " << endl << "1 - Listen to your pet" << endl << "2 - Feed your pet" << endl << "3 - Play with your pet" << endl << endl;
		cin >> ch;
		switch (ch)
		{
		case '0':
			cout << "Goodbye friend!" << endl;
		case '1':
			petPtr->Speak();
			break;
		case '2':
			cout << "What would you like to feed your pet?" << endl << "1. Bread" << endl << "2. Chocolate" << endl << "3. Specific food" << endl << endl;
			cin >> ch1;
			if (ch1 == '1')
			{
				petPtr->Feed(1);
			}
			else if (ch1 == '2')
			{
				petPtr->Feed(-2);
			}
			else if (ch1 == '3')
			{
				petPtr->Feed(4);
			}
			else
			{
				cout << "That's seems to be an invalid food." << endl;
			}
			break;
		case '3':
			cout << "How would you like to play with your pet ?" << endl << "1. Cuddle him" << endl << "2. Ignore him" << endl << "3. Go for a walk" << endl << endl;
			cin >> ch1;
			if (ch1 == '1')
			{
				petPtr->Play(3);
			}
			else if (ch1 == '2')
			{
				petPtr->Play(-1);
			}
			else if (ch1 == '3')
			{
				petPtr->Play(1);
			}
			break;
		default:
			cout << "I don't know what supposed to mean." << endl;
			break;
		}
	} while (ch != '0');
}