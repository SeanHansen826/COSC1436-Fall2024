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
    cout << setw(30) << setfill('.') << "" << setfill(' ') << endl;
    cout << left << setw(10) << "Project:" << "Array Calculator\n" << setw(10) << "By:" << "Sean Hansen\n" << setw(10) << "Class:" << "COSC-1436-20005\n";
    cout << setw(30) << setfill('.') << "" << setfill(' ') << endl << endl;
};

/// @brief Validates input from PromptArrayInput
/// @param minInput Minimum input allowed in array
/// @param maxInput Maximum input allowed in array
/// @param input Input taken from user
/// @return Returns validated input
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

/// @brief Displays instructions for PromptArrayInput
/// @param minValue takes minimum value for display purposes
/// @param maxValue takes maximum vlue for display purposes
void DisplayArrayInstructions( int minValue, int maxValue )
{
    cout << setw(22) << right << "-=INSTRUCTIONS=-\n";
    cout << setfill('-') << setw(27) << "" << setfill(' ') << endl;
    cout << "* Input values " << minValue << " - " << maxValue << endl;
    cout << "* Input '0' when finished\n";
    cout << setfill('-') << setw(27) << "" << setfill(' ') << endl << endl;
}

/// @brief Prompts user for integer input into an array
/// @param valueArray Passes array of values
/// @param arraySize passes array size
void PromptArrayInput()
{
    const int MaxValues = 100;
    const int MinInput = 0;
    int valueArray[MaxValues] = { 0 };
    int count = 0;

    DisplayArrayInstructions( MinInput, MaxValues );

    for (int index = 0; index < MaxValues; ++index)     //use count instead of maxvalues when displaying, it's necessary here but not in later steps!
    {
        cout << "value " << index + 1 << ": ";
        cin >> valueArray[index];

        valueArray[index] = ValidateArrayInput(MinInput, MaxValues, valueArray[index]);

        if (valueArray[index] == 0 || index == MaxValues - 1)
        {
            cout << endl;
            break;
        }
        
        ++count;
    }
}

/// @brief 
/// @param menuInput 
/// @param lowerCaseInput 
/// @param upperCaseInput 
/// @return menuInput is now a validated Input returned as the upper case character
char ValidateMenuInput(char menuInput, char upperCaseInput, char lowerCaseInput)
{
    while(true)
    {
        if (menuInput == lowerCaseInput || menuInput == upperCaseInput)
        {
            menuInput = upperCaseInput;
            return menuInput;
        } else if (menuInput != lowerCaseInput || menuInput != upperCaseInput)
        {
            cout << "ERROR: must input " << upperCaseInput << " or " << lowerCaseInput << endl;
            cout << "Choose Calculation Type: ";
            cin >> menuInput;
            cout << endl;
        }
    }
}

/// @brief Displays main menu
/// @return validated menuInput from user
void DisplayMenu()
{
    char menuInput;

    cout << "Main Menu\n";
    cout << setfill('-') << setw(9) << "" << setfill(' ') << endl;
    cout << "L) argest Value\n";

    //cout << "Choose Calculation Type: ";
    //cin >> menuInput;
    //menuInput = ValidateMenuInput(menuInput, 'L', 'l');

    //return menuInput;
}

void GetLargestValue()
{
    int largestValue = 0;
    cout << "Largeset Value: " << largestValue;
}

void GetDesiredCalculation()
{
    char menuInput;

    cout << "Choose Calculation Type: ";
    cin >> menuInput;
    menuInput = ValidateMenuInput(menuInput, 'L', 'l');

    if (menuInput == 'L')
    {
        GetLargestValue();
        cout << endl;
    }
}

int main()
{
    DisplayHeader();

    PromptArrayInput();
    DisplayMenu();
    GetDesiredCalculation();
}
