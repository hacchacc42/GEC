#include <iostream>
using namespace std;
//Void would be much easier D:
int smallestNumber(int a, int b);

int main()
{
	int a, b;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter 2 numbers : " << endl;
		cin >> a;
		cin >> b;
		smallestNumber(a, b);
	}
}

int smallestNumber(int a, int b)
{
	if (a == b) {
		cout << "Both number are the same ." << endl;
		return 0;
	}
	else if (a < b)
	{
		cout << "The second number is bigger than the first one ." << endl;
		return 0;
	}
	else
	{
		cout << "The first number is bigger than the second one ." << endl;
		return 0;
	}
	cout << "Something is wrong with the inputs";
	return 1;
}