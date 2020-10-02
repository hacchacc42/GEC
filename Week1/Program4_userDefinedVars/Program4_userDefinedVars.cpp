#include <iostream>

int main()
{
    typedef int cost;

    enum CarMake
    {
        FORD=1,
        FIAT,
        TESLA,
        VW,
        BMW,
        ASTONMARTIN,
        HONDA,
        NISSAN,
        TOYOTA,
        AUDI,
        JAGUAR,
        DOGE
    };
    cost myCarCost = 13000;
    CarMake myCarId = CarMake::HONDA;

    std::cout << "The cost of my car is: " << myCarCost << std::endl;
    std::cout << "My car id is: " << myCarId << std::endl;

    return 0;
}
