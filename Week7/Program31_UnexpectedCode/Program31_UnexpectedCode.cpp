#include <iostream>
using namespace std;

int main()
{
    int count = 3;
    //Replaced i > count with i <=
    for (int i = 1; i <= count; i++)
    {
        cout << i;
        //Replaced count = 2 with i % 2 == 0 / also can be replaced with i==2 for this short program 
        if (i % 2==0)
            cout << " is an even number" << endl;
        else
            cout << " is an odd number"<< endl;
    }

    // Pause the output
    cin.get();

    return 0;
}
