#include <iostream>
using namespace std;
int main()
{
    char status;
    int ask;
    cout << "Please tell me your status with 's' for student, 't' for teacher or 'o' for other." << endl;
    cin >> status;
    cout << "Which game would you like, 1 or 2?" << endl;
    cin >> ask;
    if (status == 's' || status == 't')
    {
        if (ask == 1) 
        {
            cout << "You get a 20% discount." << endl;
        }
        else if (ask == 2)
        {
            cout << "You get a 10% discount." << endl;
        }
        else
        {
            cout << "You are not entitled to a discount." << endl;
        }
    }
    else
    {
        cout << "You are not entitled to a discount." << endl;
    }
    //This line of code is just for screenshot purposes.
    cout << endl; return main();    
}