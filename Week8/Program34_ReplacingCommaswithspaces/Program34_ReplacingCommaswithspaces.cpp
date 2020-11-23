#include <iostream>
using namespace std;

void comma2blank(char* text);

int main()
{
    char textTochange[100];
    cout << "Instert a text ( uses commas instead of spaces):";
    cin.getline(textTochange, 100);
    comma2blank(textTochange);
    cout << textTochange;
}

void comma2blank(char* text)
{
    int i = 0;
    do
    {
        if (text[i] == ',')
        {
            text[i] = ' ';
        }
        i++;
    } while (text[i] != '\0');
}