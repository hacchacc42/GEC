#include <iostream>

using namespace std;

void inputDetails(int* n1, int* n2);
void outputDetails(int& integer1, int& integer2, int* pointer);

int main()
{
	int num1, num2;
	int* pNum = &num1;
	inputDetails(&num1, &num2);
	outputDetails(num1, num2, pNum);
	pNum = nullptr;
}

void inputDetails(int* n1, int* n2)
{
	cout << "num1 : ";
	cin >> *n1;
	cout << "num2 : ";
	cin >> *n2;
	
}
void outputDetails(int& integer1, int& integer2, int* pointer)
{
	cout << "num1 value : " << integer1 << endl;
	cout << "num1 address in memory : " << &integer1 << endl;
	cout << "num2 value :" << integer2 << endl;
	cout << "num2 address in memory : " << &integer2 << endl;
	cout << "pNum value : " << pointer << endl;
	cout << "pNum value : " << *pointer << endl;
	cout << "pNum value : " << &pointer << endl;
}