#include <iostream>
#include <fstream>

using namespace std;

struct account
{
	string name;
	int number;
	double balance;
};
int main()
{
	account inputS, outputS;
	int choise;
	char repeat;
	fstream myFile;
	do
	{
		cout << "What do you want to do ?" << endl;
		cout << "1. Enter new details." << endl << "2. Display the account details." << endl << "3. Display accounts that have a balance over 10,00." << endl << "4. exit the program" << endl;
		cin >> choise;
		if (choise == 1)
		{
			myFile.open("outputfile.txt",ios::out);

			if (myFile.is_open())
			{
				cout << "What's the account name ?" << endl;
				cin >> inputS.name;
				myFile << inputS.name << endl;
				cout << "What's the account number ?" << endl;
				cin >> inputS.number;
				myFile << inputS.number << endl;
				cout << "What's the account balance ?" << endl;
				cin >> inputS.balance;
				myFile << inputS.balance;
				cout << "Do you wanna modify the elements ?" << endl;
			}
			else
			{
				cout << "Eror while loading file." << endl;
			}
			myFile.close();
		}
		else if (choise == 2)
		{
			myFile.open("outputfile.txt",ios::in);
			if (myFile.is_open())
			{
				myFile >> outputS.name;
				myFile >> outputS.number;
				myFile >> outputS.balance;
				if (outputS.name == "")
				{
					cout << "ERROR while loading program" << endl;
				}
				else
				{
					cout << "Name : " << outputS.name << endl << "Number : " << outputS.number << endl << "Balance : " << outputS.balance << endl;
				}
			}
			else
			{
				cout << "Eror while loading file." << endl;
			}
			myFile.close();
		}
		else if (choise == 3)
		{
			myFile.open("outputfile.txt", ios::in);
			if (myFile.is_open())
			{
				myFile >> outputS.name >> outputS.number >> outputS.balance;
				if (outputS.balance > 10000)
				{
					cout << "Name : " << outputS.name << endl << "Number : " << outputS.number << endl << "Balance : " << outputS.balance << endl;
				}
				else
				{
					cout << "This account dosent have a balance above 10.000" << endl;
				}
			}
			else
			{
				cout << "Eror while loading file." << endl;
			}
			myFile.close();
		}
		else if (choise == 4)
		{
			cout << "Good Bye!";
			break;
		}
		else
		{
			cout << "Unknown operation" << endl;
		}
			cout << "Do you want to do another operation ?(Y/N)" << endl;
			cin >> repeat;
	}while (repeat == 'Y');
}