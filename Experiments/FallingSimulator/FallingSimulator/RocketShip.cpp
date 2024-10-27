#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
using std::cout;
using std::cin;

bool GetStartInput()
{
    char startInput;
    bool startIsTrue;
    cout << "Ready to play (y/n)? ";
    cin >> startInput;

    switch (startInput)
    {
        case 'Y':
        case 'y': startIsTrue = true; break;

        case 'N':
        case 'n': startIsTrue = false; break;

        default:
            cout << "ERROR: Please input y/n\n";
    };

    return startIsTrue;
};

void DisplayInstructions()
{
    cout << "Instructions: \n";
    cout << "Type \"left\" or \"right\" to move your ship";
};

void DisplayShip( int leftSpace, int rightSpace )
{
    cout << setw(leftSpace) << "<|>" << setw(rightSpace) << endl;
}

void PlayingField()
{
    int leftSpace = 6;
    int rightSpace = 6;

    DisplayShip(leftSpace, rightSpace);

    for (int index = 0; index < 10; ++index)
    {
        string movementInput;
        cout << "Direction (l/r/n): ";

        cin >> movementInput;
        //getline(cin, movementInput);

        if (movementInput == "l" || movementInput == "L")
        {
            leftSpace -= 1;
            rightSpace += 1;
        }
        if (movementInput == "r" || movementInput == "R")
        {
            leftSpace += 1;
            rightSpace -= 1;
        }
        if (movementInput == "n" || movementInput == "N")
        {
            leftSpace += 0;
            rightSpace -= 0;
        }

        DisplayShip(leftSpace, rightSpace);
    }
};


int main()
{
    bool startIsTrue;
    startIsTrue = GetStartInput();

    if (startIsTrue == true)
    {
        PlayingField();
    }
    else
        cout << "Closing program ... ";
}
