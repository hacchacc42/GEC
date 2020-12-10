#include <iostream>
using namespace std;

int main()
{
    const float pi = 3.14159f;
    float area, radius;
    radius = 25.0f;
    area = pi * radius * radius;

    cout << "The area of a circle with radius " << radius << " is " << area << endl;

    return 0;
}