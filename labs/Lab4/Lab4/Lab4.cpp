//Array Calculator
//Sean Hansen
//COSC-1436-20005

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
using std::cout;
using std::cin;


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

void GetSum(int valueArray[], int count)
{
    int sumOfArray = 0;

    for (int index = 0; index < count; ++index)
    {
        sumOfArray += valueArray[index];
    }

    cout << "* Sum of Array: " << sumOfArray << " *" << endl << endl;
}

void DisplayArray(int valueArray[], int count)
{
    cout << "* Values *" << endl;
    cout << setfill('=') << setw(10) << "" << setfill(' ') << endl;
    for (int index = 0; index < count; ++index)     //show 10 values per line
    {
        cout << "value " << index + 1 << ": " << valueArray[index] << endl;
    }
}

/// @brief Calculates largest value of valueArray
/// @param valueArray passes value array
/// @param count passes size which is equal to the number of array entries
void GetLargest( int valueArray[], int count, const int MinValues )
{
    int largestValue = MinValues;
    
    for (int index = 0; index < count; ++index)
    {
        if (valueArray[index] > largestValue)
            largestValue = valueArray[index];
    }

    cout << "* Largest Value: " << largestValue << " *" << endl << endl;
}

void GetMean(int valueArray[], int count)
{
    double meanOfArray = 0;
    int sumOfArray = 0;

    for (int index = 0; index < count; ++index)
    {
        sumOfArray += valueArray[index];
    }

    meanOfArray = (double)sumOfArray / count;

    cout << fixed << setprecision(3);
    cout << "* Mean: " << meanOfArray << " * " << endl << endl;
}

/// @brief Gets smallest value
/// @param valueArray calls array
/// @param count calls count for total array values
/// @param MaxValues sets maxValues as the smallestValue while (count != 0)
void GetSmallest(int valueArray[], int count, const int MaxValues)
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
    cout << "A) dd\n";
    cout << "D) isplay\n";
    cout << "L) argest\n";
    cout << "M) ean\n";
    cout << "S) mallest\n";
    cout << "Q) uit\n";
    cout << endl;

    bool done = false;
    char menuInput;
    bool quit = false;

    if(count != 0)
    {
        do
        {
            if(count != 0)
            cout << "Choose Calculation Type: ";
            cin >> menuInput;
            cout << endl;

            switch (menuInput)
            {
                case 'A':
                case 'a': GetSum(valueArray, count); cout << endl; done = true; return quit; break;

                case 'D':
                case 'd': DisplayArray(valueArray, count); cout << endl; done = true; return quit; break;

                case 'L':
                case 'l': GetLargest(valueArray, count, MinValues); cout << endl; done = true; return quit; break;

                case 'M':
                case 'm': GetMean(valueArray, count); cout << endl; done = true; return quit; break;

                case 'S':
                case 's': GetSmallest(valueArray, count, MaxValues); cout << endl; done = true; return quit; break;

                case 'Q':
                case 'q': quit = true; done = true; return quit; break;

                default:
                {
                    cout << "ERROR: Must input valid menu command" << endl;
                }
            }
        } while (!done);
    }
    else if (count == 0)
    {
        cout << "* NO ARRAY INPUTS *" << endl << endl;
    }
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
