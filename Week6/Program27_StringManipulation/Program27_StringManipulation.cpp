#include <iostream>
#include <string>
using namespace std;

int main()
{
	string testString = "Do you know who loves C++ XX does!";
	string name1, name2;
	cout << "Enter your name:" << endl;
	getline(cin, name1);
	testString = testString.insert(testString.find("XX") + 1, name1, 0, name1.length());
	cout << testString << endl;
	testString.replace(testString.find("X"),1,"");
	testString.replace(testString.rfind("X"),1,"");
	cout << testString << endl;
	cout << "Enter another name:" << endl;
	do
	{
		getline(cin, name2);
		if (name1.length() > name2.length())
		{
			cout << "This name should be longer than the first one." << endl;
		}
		else
		{
		cout << testString.replace(testString.find(name1), name1.length(), name2);
		}
	} while (name1.length() > name2.length());
}