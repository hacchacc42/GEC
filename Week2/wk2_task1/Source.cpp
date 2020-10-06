#include <iostream>

int main()
{
	bool a=true;
	int num1 = 12, num2 = 5, num3 = 7;
	if (a)
	{
		num1++;
		num2 = 5;
	}
	num3 *= 2;
	std::cout << "num1 =" << num1 << std::endl;
	std::cout << "num2 =" << num2 << std::endl;
	std::cout << "num3 =" << num3 << std::endl;
}