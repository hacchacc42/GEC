#include <iostream>
using namespace std;
int main()
{
    int hariboPacks = 40;
    int students = 14;
    //I divided the number of harbio pack on student to get how many packs each student will get.
    cout << "Each student will get: " << hariboPacks / students << " ." << endl;
    //I took the rest of haribo packs using the modulo symbol.
    cout << "The teacher will remain with: " << hariboPacks % students << " ." << endl;
}