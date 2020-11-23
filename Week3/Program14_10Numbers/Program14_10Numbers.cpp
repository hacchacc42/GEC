#include <iostream>
using namespace std;

int main()
{
    float num1, num2;
    cout << "You will enter 2 numbers." << endl;
    cout << "Enter the first number :" << endl;
    cin >> num1;
    cout << "Enter the second number :" << endl;
    cin >> num2;

    float mean, numx, sum;
    int numtotal = 2;
    sum = num1 + num2;
    mean = sum / numtotal;

    cout << "Sum value is :" << sum << endl;
    cout << "Mean value is :" <<mean<< endl << endl;

    do
    {
        cin >> numx;
        if (numx == 0)
        {
            cout << "You entered 0, so the program will end." << endl;
            break;
        }
        numtotal++;
        sum += numx;
        mean = sum / numtotal;
        cout << "Sum value is :" << sum << endl;
        cout << "Mean value is :" << mean << endl << endl;
    } 
    while (numx != 0);
    
    return 0;
}