#include <iostream>
#include <fstream>
using namespace std;

int FindASCII()
{
    char input;
    cout << "Input a character value: ";
    cin >> input;
    int ASCIIinput = int(input);
    cout << ASCIIinput << endl;

    return input;
}

int DisplayMenu()
{
    cout << "A) Find ASCII value of input\n";
    cout << "X) Exit Program\n";

    char selection;
    int output;
    cout << "Selection: ";
    cin >> selection;

    switch (selection)
    {
        case 'A':
        case 'a': output = FindASCII(); return output;

        case 'X':
        case 'x': return 0;

        default: "ERROR:: Please input a valid value";
    }
}

int main()
{
    bool quit = false;

    do
    {
        int output = DisplayMenu();

        if (output == 0)
            quit = true;
    } while (!quit);

    cout << "Terminating Program\n";
}