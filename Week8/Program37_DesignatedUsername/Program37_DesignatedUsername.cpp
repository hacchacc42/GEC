#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

void generateName(string& st);

int main()
{
    string username;
    cout << "Enter your username:";
    getline(cin, username);
    cout << "That username is already taken, but the username below is avelible :";
    generateName(username);
    cout << username;
}
void generateName(string& st)
{
    srand(time(NULL));
    int num = rand()%100 + 1;
    &st.append(to_string(num));
}