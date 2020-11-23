#include <iostream>
using namespace std;
int main()
{
    int x;
    char quest = 'Y';
    do {
        cout << "Please enter a number: " << endl;
        cin >> x;
        while (x < 0 || x>10 )
        {
            cout << "Be sure that the number is between 1 and 10" << endl;
            cin >> x;
        }
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j <=i; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
        cout << "Do you want to continue?" << endl;
        cin >> quest;
        if (quest == 'Y' || quest == 'y')
        {
            continue;
        }
        else if (quest == 'N' || quest == 'n')
        {
            cout << "Good Bye"<< endl;
                break;
        }
        else 
        {
            cout << "Invalid Input." << endl;
            break;
        }
    } while (quest == 'Y' || quest=='y');
}