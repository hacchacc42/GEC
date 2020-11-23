#include <iostream>
#include <string>
using namespace std;

struct User
{
	string name;
	int age;
	string telephoneNumber;
	void PrintDetails()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Telephone number: "<<telephoneNumber << endl;
	}
}personalDetails;
int main()
{
	cout << "Enter your name: ";
	getline(cin, personalDetails.name);
	cout << "Enter your age: ";
	cin >> personalDetails.age;
	cout << "Enter your telephone number: ";
	cin >> personalDetails.telephoneNumber;

	personalDetails.PrintDetails();
}