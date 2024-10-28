//Falling Distance
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
    cout << left << setw(10) << "Project:" << "Falling Distance\n" << setw(10) << "By:" << "Sean Hansen\n" << setw(10) << "Class:" << "COSC-1436-20005\n";
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;
};

/// @brief PromptInput Get user input for falling time
/// @return Returns value input for total fallingTime
int PromptFallingTime()
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

    return fallingTime;
};

/// @brief Prompts input for measurementUnit (feet || meters ? true : false)
/// @return returns measurementUnit of choice
bool PromptMeasurementUnit()
{
    char InputMeasurementUnit; bool measurementUnit;

    while(true)
    {
        cout << "Would you like to use feet or meters (f/m)? ";
        cin >> InputMeasurementUnit;
        cout << endl;

        switch (InputMeasurementUnit)
        {
            case 'M':
            case 'm': measurementUnit = false; return measurementUnit; break;

            case 'F':
            case 'f': measurementUnit = true; return measurementUnit; break;

            default:
                cout << "ERROR: You must input 'f' or 'm'.\n";
        };
    };
};

/// @brief CalculateFallingDistance Calculates the distance fallen over a given second
/// @param givenSecond the second for which you would like to calculate the distance traveled
/// @return distanceFallen returns the value calculated for distanceFallen back to CalculateFallingDistance
double CalculateFallingDistance(int givenSecond)
{
    double const gravity = 9.8;
    double distanceFallen = (gravity / 2) * pow(givenSecond, 2);

    return distanceFallen;
};

/// @brief Converts answer in meters into feet
/// @param distanceForGivenSecond the distance for a given second in meters
/// @return returns the value converted to feet
double ConvertMetersToFeet(double distanceForGivenSecond)
{
    distanceForGivenSecond *= 3.28084;
    return distanceForGivenSecond;
};

/// @brief DisplayTable Displays the table for distance traveled per given amount of seconds
/// @param fallingTime takes total length of time fallen
/// @param measurementUnit unit of measurement required
void DisplayTable( int fallingTime, bool measurementUnit )
{
    cout << fixed << setprecision(2);
    cout << setw(10) << "Seconds" << "Distance\n";
    cout << setw(22) << setfill('-') << "" << setfill(' ') << endl;

    if (!measurementUnit)
    {
        for (int index = 1; index <= fallingTime; ++index)
        {
            double distanceForGivenSecond = CalculateFallingDistance(index);
            cout << setw(10) << index << distanceForGivenSecond << " m" << endl;
        };
    } else if (measurementUnit)
    {
        for (int index = 1; index <= fallingTime; ++index)
        {
            double distanceForGivenSecond = CalculateFallingDistance(index);
            double distanceForGivenSecondInFeet = ConvertMetersToFeet( distanceForGivenSecond );
            cout << setw(10) << index << distanceForGivenSecondInFeet << " f" << endl;
        }
    }
};

int main()
{
        DisplayHeader();

        int fallingTime = PromptFallingTime();
        bool measurementUnit = PromptMeasurementUnit();

        DisplayTable(fallingTime, measurementUnit);
}