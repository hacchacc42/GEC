#include <iostream>
using namespace std;

int main()
{
	//I've used a char instead of int, because if I had use an int and input a char , the progral will crash
	char choice;
	cout << "Please choose an option:  1. Sunny 2. Cloudy 3.  Raining 4. Exit" << endl;
	cin >> choice;
	switch (choice)
	{
		case '1':
			cout << "Don't forget your sunscreen." << endl;
			break;
		case '2':
			cout << "It might rain, it might not." << endl;
			break;
		case '3':
			cout << "Bring an umbrella with you." << endl;
			break;
		case '4':
			cout << "Good Bye." << endl;
			return 0;
			break;
		default:
			cout << "What is the meaning of this?" << endl;
		break;
	}
}