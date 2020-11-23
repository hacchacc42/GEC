#include <iostream>
using namespace std;

int num;
void input();
void output();
void plus25();
void minus25(int& num1);
int &rNum = num;

int main()
{
	input();
	output();
	plus25();
	output();
	input();
	minus25(rNum);
	output();
}

void plus25()
{
	cout << "Adding 25 to your number." << endl;
	rNum += 25;
}
void output()
{
	cout << "Your number is : " << num << endl;
}
void input()
{
	cout << "Number please : ";
	cin >> rNum;
}
void minus25(int& num1)
{
	cout << "Substracting 25 from your number." << endl;
	num1 -= 25;
}