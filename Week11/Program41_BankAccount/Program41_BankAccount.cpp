#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class baseAcc
{
public:
	baseAcc()
	{
		sureName = "SURENAME";
		foreName = "FORENAME";
		adress = "ADRESS";
		intrestRate = 0;
		balance = 0;
		number = 0;
		type = acctype(0);
	};
	void NewAcc();
	void SetDetails2(string fore, string sure, string add, int bal, int num);
	void SetDetails1();
	void CheckAccount();
	void DisplayAccount(int acc);
	bool SearchAcc(int acc);
protected:
	string sureName;
	string foreName;
	string adress;
	int intrestRate;
	int balance;
	int number;
	enum acctype {
		Basic = 0,
		General,
		Junior,
		Saving
	}type;
};

bool baseAcc::SearchAcc(int acc)
	{
		//if not found
		return false;
	}

void baseAcc::DisplayAccount(int acc)
{
	//bool accFound = SearchAcc(acc);
	bool accFound = true;
	if (accFound)
	{
		cout << "Account Number : " << number << endl
			<< "Account Name : " << sureName << " " << foreName << endl
			<< "Account Balance : " << balance <<" $"<< endl
			<< "Adress : " << adress << endl
			<< "Intrest rate : " << intrestRate <<" %"<< endl
			<< "Account type : " << type<< endl;
	}
	else
	{
		cout << "Account not found." << endl;
	}
}

void baseAcc::CheckAccount()
{
	cout << "Please input your account number:";
	int accnum;
	cin >> accnum;
	DisplayAccount(accnum);
}
void Menu();

void baseAcc::SetDetails1()
{
	string sN, fN, A;
	int N, B;
	cout << "Enter your Surename : ";
	cin >> sN;
	cout << "Enter your Fornemae : ";
	cin >> fN;
	cout << "Enter your Adress : ";
	cin.ignore();
	getline(cin, A);
	cout << "Enter the initial Balance : ";
	cin >> B;
	if (B > 0)
	{
		//Give a number
		SetDetails2(fN, sN, A, B, 0);
	}
	else
	{
		cout << "Balance should be above 0, return to main";
	}
}
void NewAcc();

void baseAcc::SetDetails2(string fore, string sure, string add, int bal, int num)
{
	foreName = fore;
	sureName = sure;
	adress = add;
	balance = bal;
	number = num;
}

class generalAcc:public baseAcc
{
public:
	generalAcc()
	{
		sureName = "SURENAME";
		foreName = "FORENAME";
		adress = "ADRESS";
		intrestRate = 3;
		balance = 0;
		number = 0;
		type = acctype(1);
	};
};

class juniorAcc :public baseAcc
{
public:
	juniorAcc()
	{
		sureName = "SURENAME";
		foreName = "FORENAME";
		adress = "ADRESS";
		intrestRate = 5;
		balance = 0;
		number = 0;
		type = acctype(2);
	};
};
class savingAcc : public baseAcc
{
public:
	savingAcc()
	{
		sureName = "SURENAME";
		foreName = "FORENAME";
		adress = "ADRESS";
		intrestRate = 8;
		balance = 0;
		number = 0;
		type = acctype(3);
	};
};
baseAcc* acc;
int main()
{
	while (true)
	{
		Menu();
	}
}

void Menu()
{
	cout << "Choose one of the following :" << endl
		<< "1. Open a new account" << endl
		<< "2. View an account" << endl
		<< "3. Close an account" << endl
		<< "4. Exit program" << endl;
	char ch;
	cin >> ch;
	if (ch == '1')
	{
		NewAcc();
	}
	else if (ch == '2')
	{
		acc->DisplayAccount(0);
	}
	else if (ch == '3')
	{
		//Delete Acc
	}
	else if (ch == '4')
	{
		cout << "Good Bye" << endl;
	}
	else
	{
		cout << "Invalid input" << endl;
		Menu();
	}
}

void NewAcc()
{
	cout << "Select an account type " << endl
		<< "1. General account" << endl
		<< "2. Junior account" << endl
		<< "3. Savings account" << endl
		<< "4. Return to main menu" << endl;
	char ch;
	cin >> ch;
	if (ch == '1')
	{
		acc = new generalAcc();
		acc->SetDetails1();
	}
	else if (ch == '2')
	{
		acc = new juniorAcc();
		acc->SetDetails1();
	}
	else if (ch == '3')
	{
		acc = new savingAcc();
		acc->SetDetails1();
	}
	else
	{
		Menu();
	}
}