//Falling Distance
//Sean Hansen
//COSC-1436-20005

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using namespace std;

/// @brief Displays project header
void DisplayHeader()
{
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;
    cout << left << setw(10) << "Project:" << "Falling Distance\n" << setw(10) << "By:" << "Sean Hansen\n" << setw(10) << "Class:" << "COSC-1436-20005\n";
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;
};

/// @brief Prompts user input for time fallen
void PromptInput()
{
    int fallingTime;
    do
    {
        cout << "How many seconds was the object falling (1-60 seconds)? ";
        cin >> fallingTime;

        if (fallingTime < 1 || fallingTime > 60)
        {
            cout << "ERROR: Falling Time must be between 1 and 60 seconds.\n";
        };
    } while (fallingTime < 1 || fallingTime > 60);

    char inputMeasurementUnit;
    bool measurementUnit;
    bool done = 0;
    do
    {
        cout << "Would you like to use feet or meters (f/m)? ";
        cin >> inputMeasurementUnit;

        switch (inputMeasurementUnit)
        {
            case 'F':
            case 'f': measurementUnit = true; done = true; break;   //try revising to include Feet or Meters instead of True of False

            case 'M':
            case 'm': measurementUnit = false; done = true; break;

            default:
                cout << "ERROR: You must input f/m.\n";
        };
    } while (!done);
};

/// @brief Calculates distance fallen using prompted input
void CalculateDistance()
{
    double const gravity = 9.8;
    int givenSecond = 0;
    double distanceFallen = (gravity / 2) * pow(givenSecond, 2);

    //if(measurementUnit == 1)                                      //needs revision, cannot call into another function yet
        //distanceFallen *= 3.28084
};

/// @brief Displays table including each second and the distance correlated
void DisplayTable()
{
    for (int index = 0; index < /*fallingTime*/ 10; index++)        //needs revision, cannot call into another function yet
    {
        CalculateDistance();    //when (givenSecond = index + 1)

        if (index == 0)
            cout << endl;
            cout << right << setw(5) << "Seconds" << setw(8) << "Distance\n";

        if (index != 0 /*&& measurementUnit == 0*/)                 //needs revision, cannot call into another function yet
            cout << index + 1 << /*distanceFallen*/ "m" << endl;

        if (index != 0 /*&& measurementUnit == 1*/)                 //needs revision, cannot call into another function yet
            cout << index + 1 << /*distanceFallen*/ "f" << endl;
    };
};





int main()
{
    DisplayHeader();
    PromptInput();
    DisplayTable();
}