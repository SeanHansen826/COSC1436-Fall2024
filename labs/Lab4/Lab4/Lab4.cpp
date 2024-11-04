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
/// @param MaxValues passes MaxValues of array, AKA array size
/// @param MinValues Passes minValues of array
void PromptArrayInput( int valueArray[], const int MaxValues, const int MinValues, int count = 0 )
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

///// @brief 
///// @param menuInput 
///// @param lowerCaseInput 
///// @param upperCaseInput 
///// @return uppercase validated menuInput
//char ValidateMenuInput(char menuInput, char upperCaseInput, char lowerCaseInput)
//{
//    while(true)
//    {
//        //switch (menuInput)
//        //{
//        //    case lowerCaseInput: 
//        //    case upperCaseInput: menuInput = upperCaseInput; break;
//        //}
//        if (menuInput == lowerCaseInput || menuInput == upperCaseInput)
//        {
//            menuInput = upperCaseInput;
//            return menuInput;
//        } else if (menuInput != lowerCaseInput || menuInput != upperCaseInput)
//        {
//            cout << "ERROR: must input " << upperCaseInput << " or " << lowerCaseInput << endl;
//            cout << "Choose Calculation Type: ";
//            cin >> menuInput;
//            cout << endl;
//        }
//    }
//}

/// @brief Displays main menu
void DisplayMenu()
{
    cout << "Main Menu\n";
    cout << setfill('-') << setw(9) << "" << setfill(' ') << endl;
    cout << "L) argest Value\n";
}

/// @brief Calculates largest value of valueArray
void GetLargestValue()
{
    int largestValue = 0;       //need to pass through Array
    
    //for (int index = 0, index <= count, ++index)           //loops through index to find larger and larger values, until count is reached (<=)
    //{
    //    if (valueArray[index] > largestValue)
    //        largestValue = valueArray[index];
    //}

    cout << "Largeset Value: " << largestValue << endl;
}

/// @brief Decides which calculation to use
void GetDesiredCalculation()
{
    bool done = false;
    char menuInput;
    do
    {
        cout << "Choose Calculation Type: ";
        cin >> menuInput;

        switch (menuInput)
        {
            case 'l':
            case 'L': GetLargestValue(); cout << endl; done = true; break;

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
    int valueArray[MaxValues] = {0};

    PromptArrayInput( valueArray, MaxValues, MinValues );
    DisplayMenu();
    GetDesiredCalculation();
}
