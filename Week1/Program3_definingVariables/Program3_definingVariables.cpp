#include <iostream>

int main()
{
    //Integers
    int myInt1 = 1, myInt2 = 0, myInt3;
    myInt2 = 2;
    myInt3 = 3;
    const int kmyInt4 = 4;

    std::cout << "Value stored in myInt1 is " << myInt1 << std::endl;
    std::cout << "Value stored in myInt2 is " << myInt2 << std::endl;
    std::cout << "Value stored in myInt3 is " << myInt3 << std::endl;
    std::cout << "Value stored in kmyInt4 is " << kmyInt4 << std::endl << std::endl;

    //Floating points
    float myFloat1 = 1.1f, myFloat2;
    myFloat2 = -2.2f;

    std::cout << "Value stored in myFloat1 is " << myFloat1 << std::endl;
    std::cout << "Value stored in myFloat2 is " << myFloat2 << std::endl << std::endl;

    //Characters
    char myChar = 'z';

    std::cout << "Value stored in myChar is " << myChar << std::endl;
    return 0;
}