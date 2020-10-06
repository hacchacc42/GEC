#include <iostream>
using namespace std;

int main()
{
    char play_again;
    cout << "Wanna play again?" << endl;
    cin >> play_again;
    switch (play_again)
    {
    case 'y':
        cout << "you chose to paly again" << endl;
        break;
    case 'n':
        cout << "good bye" << endl;
        break;
    default :
        cout << "that's not y or n" << endl;
        break;
    }
}