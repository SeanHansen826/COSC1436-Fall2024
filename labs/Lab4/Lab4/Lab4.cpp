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
    cout << setw(27) << setfill('.') << "" << setfill(' ') << endl;
    cout << left << setw(10) << "Project:" << "Array Calculator\n" << setw(10) << "By:" << "Sean Hansen\n" << setw(10) << "Class:" << "COSC-1436-20005\n";
    cout << setw(27) << setfill('.') << "" << setfill(' ') << endl << endl;
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
    cout << setw(23) << right << "-= INSTRUCTIONS =-\n";
    cout << setfill('.') << setw(27) << "" << setfill(' ') << endl;
    cout << "* Input values " << minValue << " - " << maxValue << endl;
    cout << "* Input '0' when finished\n";
    cout << setfill('.') << setw(27) << "" << setfill(' ') << endl << endl;
}

/// @brief Prompts user for integer input into an array
/// @param valueArray Passes array of values
/// @param MaxValues passes MaxValues of array, AKA array size
/// @param MinValues Passes minValues of array
/// @param count reference passes the amount of items input into the array
void PromptArrayInput( int valueArray[], const int MaxValues, const int MinValues, int& count )         //instead of pass by ref... return count? (set intmain promptInput equal to count, then pass that value to GetDesiredCalc!
{
    /*int count = 0;*/
    DisplayArrayInstructions( MinValues, MaxValues );

    for (int index = 0; index < MaxValues; ++index)
    {
        cout << "value " << index + 1 << ": ";
        cin >> valueArray[index];

        valueArray[index] = ValidateArrayInput(MinValues, MaxValues, valueArray[index]);

        if (valueArray[index] == 0 || index == MaxValues - 1)
        {
            cout << endl;
            break;
        }
        
        ++count;
    }
}

/// @brief Displays main menu
void DisplayMenu()
{
    cout << setw(14) << "Main Menu\n";
    cout << setfill('-') << setw(17) << "" << setfill(' ') << endl;
    cout << "L) argest Value\n";
    cout << "Q) uit\n";
    cout << endl;
}

/// @brief Calculates largest value of valueArray
void GetLargestValue( int valueArray[], int count )
{
    int largestValue = 0;
    
    for (int index = 0; index <= count; ++index)
    {
        if (valueArray[index] > largestValue)
            largestValue = valueArray[index];
    }

    cout << "Largest Value: " << largestValue << endl;
}

/// @brief GetDesiredCalculation prompts, validates, and decides which calculation to use
/// @param valueArray Passes array of values
/// @param MaxValues passes MaxValues of array, AKA array size
/// @param MinValues Passes minValues of array
/// @param count reference passes the amount of items input into the array
/// @return quit true or false
bool GetDesiredCalculation(int valueArray[], const int MaxValues, const int MinValues, int count)
{
    bool done = false;
    char menuInput;
    bool quit = false;
    do
    {
        cout << "Choose Calculation Type: ";
        cin >> menuInput;
        cout << endl;

        switch (menuInput)
        {
            case 'l':
            case 'L': GetLargestValue(valueArray, count); cout << endl; done = true; return quit; break;

            case 'Q':
            case 'q': quit = true; done = true; return quit; break;

            default:
            {
                cout << "ERROR: Must input valid menu command" << endl;
            }
        }
    } while (!done);
}

int main()
{
    DisplayHeader();

    const int MaxValues = 100;
    const int MinValues = 0;
    int count = 0;
    int valueArray[MaxValues] = {0};

    PromptArrayInput(valueArray, MaxValues, MinValues, count);

    bool done = false;
    do
    {
        DisplayMenu();
        done = GetDesiredCalculation(valueArray, MaxValues, MinValues, count);
    } while (!done);

    cout << setfill('.') << setw(27) << "" << setfill(' ') << endl;
    cout << setw(23) << "Terminating Program" << endl;
    cout << setfill('.') << setw(27) << "" << setfill(' ') << endl;
}
