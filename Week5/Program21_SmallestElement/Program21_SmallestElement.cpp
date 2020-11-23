#include <iostream>
using namespace std;

int main()
{
	int a[10];
	cout << "You should input 10 numbers." << endl;
	cout << "Enter number 0:" << endl;
	cin >> a[0];
	int min = a[0], smallPos = 0;
	for (int i = 1; i < 10; i++)
	{
		cout << "Enter number "<<i<<":" << endl;
		cin >> a[i];
		if (a[i] < min)
		{
			min = a[i];
			smallPos = i;
		}
	}
	cout << "The smallest number is " << min << " and it is found on position " <<smallPos<< endl;
	return 0;
}