#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
using std::cout;
using std::cin;

//Funtion overloading - 2 or more functions have the same name but different signatures

//Overload Resoltuion - essentially an if else if where the compiler decides with overloaded function to use
//      looks at how many parameters first, and then chooses the exact types, then types that can be coerced up! (int => float)
// 
//      For overloading make sure each "overload" does the same thing
//  
//  Function Signature -- function name + the argument types            ***QUIZ***


//I

/// @brief Reads an integer from console
/// @param message Message to display
/// @return Integral value provided by user
int ReadInt(string message)
{
    //Display Message
    //Get int value and return

    cout << message;

    int value;
    cin >> value;

    return value;
};

int ReadInt(string message, int minValue, int maxValue)
{
    int value;

    do
    {
        value = ReadInt(message);

        if (value < minValue || value > maxValue)
            cout << "value must be between " << minValue << " & " << maxValue;

    } while (value < minValue || value > maxValue);

    return value;
};

int ReadInt(string message, int minValue)
{
    return ReadInt(message, minValue, INT32_MAX);        //INT32_MAX provides a value for the parameter that we're not needing, basically a placeholder
};

struct Employee
{
    int Id;
    string Name;

    int YearsOfService;
    double PayRate;
};

void Display(Employee employee)
{
    cout << employee.Name << endl;
    cout << employee.Id << endl;
    cout << "Years of Service: " << employee.YearsOfService << endl;
    cout << "Pay Rate: $" << employee.PayRate << endl;

    employee.YearsOfService *= 2;
};

void GivePayRaise(Employee& employee)       //pass by ref usefule with struct!
{
    //If Years > 3, payrate + $ 5
    //If Years > 5, payrate + $ 10

    if (employee.YearsOfService > 3)
        employee.PayRate += 5;
    else if (employee.YearsOfService > 5)
        employee.PayRate += 10;
}

int main()
{

    //int value = ReadInt ( "Enter a value between 1 - 10", 1, 10 );

    //int positive = ReadInt("Enter a positive Number: ", 0);

    //int anyValue = ReadInt("Enter a number: ");

    //int test = ReadInt("a message", 10, 50);

    Employee employee;
    employee.Id = 10;
    employee.Name = "Bob";
    employee.YearsOfService = 10;
    employee.PayRate = 20.5;

    Display(employee);
    GivePayRaise(employee);
    Display(employee);
}

