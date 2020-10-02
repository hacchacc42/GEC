#include <iostream>
using namespace std;

int main()
{
    // I've choosen "x" as the example integer, beacause it's a common letter in math.
    // Initialise x to 1
    int x = 1;

    cout << "x = " << x << endl;
    cout << "Increment Operator before x = " << ++x << endl;
    cout << "x after = " << x << endl << endl;

    /* Reset x to 1
    This is a multiple line comment*/
    x = 1;

    cout << "x = " << x << endl;
    cout << "Increment Operator after x = " << x++ << endl;
    cout << "x after = " << x << endl << endl;

    //Reset x to 1
    x = 1;

    cout << "x = " << x << endl;
    cout << "Decrement Operator before x = " << --x << endl;
    cout << "x after = " << x << endl << endl;

    //Reset x to 1
    x = 1;

    cout << "x = " << x << endl;
    cout << "Decrement Operator after x = " << x-- << endl;
    cout << "x after = " << x << endl << endl;

    return 0;
}