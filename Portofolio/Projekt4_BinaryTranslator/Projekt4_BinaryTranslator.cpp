#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;
int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int pos = 0, final = 0;
    long x;
    char y;
    /*BINARY TO DECIMAL
    while (!inputFile.eof())
    {
        inputFile >> x;
        pos = 0;
        final = 0;
        while (x > 0)
        {
            cout << "POS =" << pos << " Final= " << final << " x=" << x << endl;
            if (x % 10 != 0 && x % 10 != 1)
            {
                cout << "ERROR CODE 2 : Wrong input, the input is not binary." << endl;
                return 2;
            }
            final += (x % 10) * pow(2,pos);
            pos++;
            x /= 10;
        }
        if (pos > 8)
        {
            cout << "ERROR CODE 1: Wrong input, try using the 8 bit standard." << endl;
                return 1;
        }
        cout << endl << final << endl;
        inputFile >> y;
        outputFile << final << " ";
    }
    */
    /* BINARY TO TEXT
    while (!inputFile.eof())
    {
        inputFile >> x;
        pos = 0;
        final = 0;
        while (x > 0)
        {
            cout << "POS =" << pos << " Final= " << final << " x=" << x << endl;
            if (x % 10 != 0 && x % 10 != 1)
            {
                cout << "ERROR CODE 2 : Wrong input, the input is not binary." << endl;
                return 2;
            }
            final += (x % 10) * pow(2, pos);
            pos++;
            x /= 10;
        }
        if (pos > 8)
        {
            cout << "ERROR CODE 1: Wrong input, try using the 8 bit standard." << endl;
            return 1;
        }
        cout << endl << (char)final << endl;
        inputFile >> y;
        outputFile << (char)final;
    }
    */
    /* BINARY TO HEX
    int x1, x2;
    char hex1, hex2;
    while (!inputFile.eof())
    {
        inputFile >> x;
        pos = 0;
        final = 0;
        x1 = 0; 
        x2 = 0;
        hex1 = 0;
        hex2 = 0;
        while (x > 0)
        {
            cout << "POS =" << pos << " hex1= " << x1<<" hex2="<<x2 << " x=" << x << endl;
            if (x % 10 != 0 && x % 10 != 1)
            {
                cout << "ERROR CODE 2 : Wrong input, the input is not binary." << endl;
                return 2;
            }
            if (pos < 4)
            {
                x1 += (x % 10) * pow(2, pos%4 );
            }
            else
            {
                x2 += (x % 10) * pow(2, pos%4 );
            }
            pos++;
            x /= 10;
        }
        if (pos > 8)
        {
            cout << "ERROR CODE 1: Wrong input, try using the 8 bit standard." << endl;
            return 1;
        }
        if (x1 > 9)
        {
            switch (x1)
            {
            case 10:
                hex1 = 'A';
                break;
            case 11:
                hex1 = 'B';
                break;
            case 12:
                hex1 = 'C';
                break;
            case 13:
                hex1 = 'D';
                break;
            case 14:
                hex1 = 'E';
                break;
            }
        }
        else
        {
            hex1 = x1+ 48;
        }
        if (x2 > 9)
        {
            switch (x2)
            {
            case 10:
                hex2 = 'A';
                break;
            case 11:
                hex2 = 'B';
                break;
            case 12:
                hex2 = 'C';
                break;
            case 13:
                hex2 = 'D';
                break;
            case 14:
                hex2 = 'E';
                break;
            }
        }
        else
        {
            hex2 = x2+48;
        }
        cout << endl << hex2<<hex1 << endl;
        inputFile >> y;
        outputFile << hex2 << hex1 << " ";
    }
    */
    inputFile.close();
    outputFile.close();
    cout << "DONE";
    return 0;
}