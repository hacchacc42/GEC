#include <iostream>

using namespace std;

int main()
{
	char input[100];
	cout << "Input a text:" << endl;
	cin.getline(input, 100);
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == 'e')
		{
			input[i] = 'X';
		}
	}
	cout << input;
}