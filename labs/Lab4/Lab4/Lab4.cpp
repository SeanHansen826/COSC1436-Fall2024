//Array Calculator
//Sean Hansen
//COSC-1436-20005

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/// @brief DisplayHeader Displays project header
void DisplayHeader()
{
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;
    cout << left << setw(10) << "Project:" << "Array Calculator\n" << setw(10) << "By:" << "Sean Hansen\n" << setw(10) << "Class:" << "COSC-1436-20005\n";
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;
};

int ValidateArrayInput( int minInput, int maxInput, int input)
{
    while (input < minInput || input > maxInput)
    {
        cout << "ERROR: Input must be between " << minInput << " and " << maxInput << endl;

        cout << "Enter a value: ";
        cin >> input;
    }

    return input;
}

void PromptArrayInput()
{
    const int MaxValues = 100;
    int valueArray[MaxValues] = { 0 };
    int count = 0;

    for (int index = 0; index <= MaxValues; ++index)     //use count instead of maxvalues when displaying, it's necessary here but not in later steps!
    {
        cout << "Enter a value: ";
        cin >> valueArray[index];

        valueArray[index] = ValidateArrayInput(0, MaxValues, valueArray[index]);

        if (valueArray[index] == 0)
            break;

        //return valueArray[index];
        
        ++count;
    }
}

char ValidateMenuInput(char menuInput, char lowerCaseInput, char upperCaseInput)
{
    if (menuInput == lowerCaseInput || upperCaseInput)
    {
        menuInput = upperCaseInput; 
        return menuInput;
    }
    else if (!lowerCaseInput || !upperCaseInput)
        cout << "ERROR: must input " << lowerCaseInput << " or " << upperCaseInput << endl;
}

char DisplayMenu()
{
    char menuInput;

    cout << "Main Menu\n";
    cout << setfill('-') << setw(9) << "" << setfill(' ') << endl;
    cout << "A) dd\n";
    cout << "Option 2\n";
    cout << "Option 3\n";
    cout << "Option 4\n";
    cout << "Option 5\n";
    cout << "Option 6\n";
    cout << "Option 7\n";

    cin >> menuInput;
    ValidateMenuInput(menuInput, 'A', 'a');

    return menuInput;
}

int main()
{
    DisplayHeader();
    PromptArrayInput();
    //DisplayMenu();
}
