//Falling Distance
//Sean Hansen
//COSC-1436-20005

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using namespace std;

/// @brief DisplayHeader Displays project header
void DisplayHeader()
{
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;
    cout << left << setw(10) << "Project:" << "Falling Distance\n" << setw(10) << "By:" << "Sean Hansen\n" << setw(10) << "Class:" << "COSC-1436-20005\n";
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;
};

/// @brief PromptInput Get user input for falling time
int PromptInput()
{
    int fallingTime;

    do
    {
        cout << "Input time fallen (1-60 seconds): ";
        cin >> fallingTime;

        if (fallingTime < 1 || fallingTime > 60)
        {
            cout << "ERROR: Falling Time must be between 1 and 60 seconds.\n";
        };
    } while (fallingTime < 1 || fallingTime > 60);
};

double CalculateFallingDistance()
{
    double const gravity = 9.8;
    double distanceFallen = (gravity / 2) * pow(fallingTime, 2);

    return distanceFallen;
}

int main()
{
    DisplayHeader(); 
    PromptInput();
    CalculateFallingDistance();
};










////    Put on Time-Out

///// @brief Prompts user input for time fallen
///// @param &measurementUnit used for meters or feet
///// @param &fallingTime used for input time fallen
//void PromptInput(bool &measurementUnit, int &fallingTime)   //the &variable allows you to modify the value once it has been passed to the next function, changing it for all functions
//{
//    do
//    {
//        cout << "How many seconds was the object falling (1-60 seconds)? ";
//        cin >> fallingTime;
//
//        if (fallingTime < 1 || fallingTime > 60)
//        {
//            cout << "ERROR: Falling Time must be between 1 and 60 seconds.\n";
//        };
//    } while (fallingTime < 1 || fallingTime > 60);
//
//    char inputMeasurementUnit;
//    bool done = 0;
//    do
//    {
//        cout << "Would you like to use feet or meters (f/m)? ";
//        cin >> inputMeasurementUnit;
//
//        switch (inputMeasurementUnit)
//        {
//            case 'F':
//            case 'f': measurementUnit = true; done = true; break;   //try revising to include Feet or Meters instead of True of False
//
//            case 'M':
//            case 'm': measurementUnit = false; done = true; break;
//
//            default:
//                cout << "ERROR: You must input 'f' or 'm'.\n";
//        };
//    } while (!done);
//};
//
///// @brief Calculates distance fallen using prompted input
///// @param measurementUnit used for meters or feet
///// @param givenSecond used to calculate each seconds distance traveled
//void CalculateDistance(bool measurementUnit, int givenSecond)
//{
//    double const gravity = 9.8;
//    double distanceFallen = (gravity / 2) * pow(givenSecond, 2);
//
//    if (measurementUnit == 1)
//        distanceFallen *= 3.28084;
//};
//
///// @brief Displays table including each second and the distance correlated
///// @param measurementUnit used for meters or feet
///// @param givenSecond used to calculate each seconds distance traveled
///// @param distanceFallen used distance fallen given the particular second
///// @param used for input time fallen
//void DisplayTable(bool measurementUnit, /*int givenSecond*/, double distanceFallen, int fallingTime)
//{
//    for (int index = 0; index < fallingTime; index++)        //needs revision, cannot call into another function yet
//    {
//        int givenSecond;
//        //CalculateDistance();    //when (givenSecond = index + 1)
//
//        if (index == 0)
//            cout << endl;
//        cout << right << setw(5) << "Seconds" << setw(8) << "Distance\n";
//
//        if (index != 0 && measurementUnit == 0)
//            cout << index + 1 << distanceFallen << "m" << endl;
//
//        if (index != 0 && measurementUnit == 1)
//            cout << index + 1 << distanceFallen << "f" << endl;
//    };
//};
//
//int main()
//{
//    DisplayHeader();
//
//    int fallingTime = 0;
//    bool measurementUnit = 0;       //storing values that are changed during run time (?)
//
//    PromptInput(measurementUnit, fallingTime);
//    DisplayTable(measurementUnit, fallingTime, measurementUnit);
//}