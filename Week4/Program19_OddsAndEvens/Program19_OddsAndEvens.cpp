#include <iostream>
using namespace std;

void outputResults(int numofOdd, int oddTotal, int numOfEven, int evenTotal);
bool odd(int x);

int main()
{
	int x, numOfOdd = 0, numOfEven = 0, oddTotal = 0, evenTotal = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << "Input a number :";
		cin >> x;
		if (odd(x))
		{
			numOfOdd++;
			oddTotal += x;
		}
		else
		{
			numOfEven++;
			evenTotal += x;
		}
	}
	outputResults(numOfOdd, oddTotal, numOfEven, evenTotal);
}
bool odd(int x)
{
	return x % 2 == 0 ? false : true;
}
void outputResults(int numofOdd, int oddTotal, int numOfEven, int evenTotal)
{
	cout << "You have inputed " << numofOdd << " odd numbers." << endl;
	cout << "The sum of your odd numbers are " << oddTotal << endl;
	cout << "Also you have inputed " << numOfEven << " even numbers." << endl;
	cout << "And their sum is " << evenTotal << endl;
}