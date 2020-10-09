#include <iostream>
using namespace std;

int main()
{
    int mySavings = 2000;
    float yourPercentage = 50;
    int yourShare = (mySavings * (yourPercentage / 100));
    cout << "Your share: " << yourShare << endl;
    
    return 0;
}
