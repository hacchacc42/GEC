#include <iostream>
using namespace std;

int main()
{
    int rain = 1, snow = 2;
    int ask, temp;
    cout << "Please tell me if it is raining with '1' or snowing with '2'." << endl;
    cin >> ask;
    cout << "What is the temperature in Celsius?" << endl;
    cin >> temp;
    if (ask == 1)
    {
        if (temp > 15)
        {
            cout << "Wear a light raincoat." << endl;
        }
        else
        {
            cout << "Wear a thick coat." << endl;
        }
    }
    else if (ask == 2)
    {
        if (temp > 5)
        {
            cout << "Wear somthing warm." << endl;
        }
        else if (temp > 0)
        {
            cout << "You should warm yourself very well." << endl;
        }
        else
        {
            cout << "You better stay home." << endl;
        }
    }
    else
    {
        cout << "If it is neither raining nor snowing, then it should be a good day for going outside." << endl;
    }
    //Just for Screenshot purpose it will output one extra empty row and will go back to main to get another input
    cout << endl;
    return main();
}