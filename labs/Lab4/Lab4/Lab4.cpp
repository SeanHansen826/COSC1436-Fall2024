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

void PromptInput()
{
    const int MaxValues = 100;
    int valueArray[MaxValues] = { 0 };
    int count = 0;

    for (int index = 0; index < MaxValues; ++index)     //use count instead of maxvalues when displaying, it's necessary here but not in later steps!
    {
        cout << "Enter a value: ";
        cin >> valueArray[index];

        if (valueArray[index] < 0)
            cout << "ERROR: Input must be greater than 0" << endl;      //continue to prompt !!
        if (valueArray[index] = 0)
            break;

        //return valueArray[index];
        
        ++count;
    }
}

int main()
{
    DisplayHeader();
    PromptInput();
}
