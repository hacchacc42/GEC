#include <iostream>

using namespace std;

int main()
{
    char input[100];
    cout << "Enter your First 2 initials, followed by your surename, be sure that there is a space between them." << endl;
    cin.getline(input, 100);
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            cout << endl;
        }
        else
        {
            cout << input[i];
        }
    }
}