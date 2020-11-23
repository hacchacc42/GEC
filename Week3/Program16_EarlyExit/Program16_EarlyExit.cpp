#include <iostream>
using namespace std;

int main()
{
    int playerLife = 100, question = 1, damage;
    bool dead = false;
    while (question <= 10 && playerLife >= 0)
    {
        cout << "Player HP: " << playerLife << endl;
        cout << "Question " << question << ": How much damage should I deal?" << endl;
        cin >> damage;
        while (cin.fail() || damage < 0) 
        {
            while (cin.fail())
            {
                cout << "That's a bad input." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> damage;
            }
            while (damage < 0)
            {
                cout << "I can't heal." << endl;
                cin >> damage;
            }
        }
        question++;
        playerLife -= damage;
        if (playerLife <= 0)
        {
            cout << "Early end. Player Died!" << endl;
            dead = true;
        }
    }
    if (!dead)
    {
        cout << "All questions asked. Player survived!" << endl;
    }
    return 0;
}