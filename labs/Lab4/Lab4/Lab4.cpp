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
        int input;
        cout << "value " << index + 1 << ": ";
        cin >> input;

        if (input != 0)
        {
            input = ValidateArrayInput(MinValues, MaxValues, input);
            valueArray[index] = input;
        }
        else if(input == 0)
        {
            cout << endl;
            break;
        }

        ++count;
    }
}

/// @brief Calculates largest value of valueArray
/// @param valueArray passes value array
/// @param count passes size which is equal to the number of array entries
void GetLargestValue( int valueArray[], int count, const int MinValues )
{
    int largestValue = MinValues;
    
    for (int index = 0; index < count; ++index)
    {
        if (valueArray[index] > largestValue)
            largestValue = valueArray[index];
    }

    cout << "* Largest Value: " << largestValue << " *" << endl << endl;
}

void GetSmallestValue(int valueArray[], int count, const int MaxValues)
{
    int smallestValue = MaxValues;

    for (int index = 0; index < count; ++index)
    {
        if (valueArray[index] < smallestValue)
            smallestValue = valueArray[index];
    }

    cout << "* Smallest Value: " << smallestValue << " *" << endl << endl;
}

/// @brief Displays main menu, Gets desired Calculation
/// @param valueArray Passes array of values
/// @param MaxValues passes MaxValues of array, AKA array size
/// @param MinValues Passes minValues of array
/// @param count reference passes the amount of items input into the array
/// @return quit true or false
bool DisplayMenu(int valueArray[], const int MaxValues, const int MinValues, int count)
{
    cout << setw(14) << "Main Menu\n";
    cout << setfill('-') << setw(17) << "" << setfill(' ') << endl;
    cout << "L) argest Value\n";
    cout << "S) mallest Value\n";
    cout << "Q) uit\n";
    cout << endl;

    bool done = false;
    char menuInput;
    bool quit = false;
    do
    {
        cout << "Choose Calculation Type: ";
        cin >> menuInput;

        switch (menuInput)
        {
            case 'l':
            case 'L': GetLargestValue(valueArray, count, MinValues); cout << endl; done = true; return quit; break;

            case 'S':
            case 's': GetSmallestValue(valueArray, count, MaxValues); cout << endl; done = true; return quit; break;

            case 'Q':
            case 'q': quit = true; done = true; return quit; break;

            default:
            {
                cout << "ERROR: Must input valid menu command" << endl;
            }
        }
    } while (!done);
}   //not all control paths return a value (?)

void DisplayQuitMessage()
{
    cout << endl << endl;
    cout << setfill('.') << setw(27) << "" << setfill(' ') << endl;
    cout << setw(23) << "Terminating Program" << endl;
    cout << setfill('.') << setw(27) << "" << setfill(' ') << endl;
}

int main()
{
    DisplayHeader();

    const int MaxValues = 100;
    const int MinValues = 1;
    int count = 0;
    int valueArray[MaxValues] = {0};

    PromptArrayInput(valueArray, MaxValues, MinValues, count);

    bool done = false;
    do
    {
        done = DisplayMenu(valueArray, MaxValues, MinValues, count);
    } while (!done);

    DisplayQuitMessage();
}
