#include <iostream>
#include <string>
#include <cmath> //C Math functions
#include <iomanip> //IO Manipulator for formatted behavior

//include the std namespace so we don't have to prefix it on everything
using namespace std;
///include <string> for getline()


int main()
{
    //// Getting user's name
    //std::string name;
    //std::cout << "Enter your name: ";

    //// std::cin >> V
    //// Inserts value up to first whitespaec into variable
    //// Doestn' work with spaced strings!
    //// ** std::cin >> name;
    //std::getline(std::cin, name);

    //// std::getline(cin, variable cin is stored in)

    //std::cout << "Hello " << name << std::endl;

    //int hours;
    //std::cout << "how many hours did you work this week? ";
    //std::cin >> hours;

    //double payRate;
    //std::cout << "How much do you earn an hour? ";
    //std::cin >> payRate;
    //std::cout << "you earned $" << (hours * payRate) << " (before taxes) this week" << std::endl;

    //// Multi-value input, values are whitespace seperated, user can enter both seperately, with tabs, or spaces, it will idndividually assign them.
    //int x, y;
    //std::cout << "Enter the X,Y values of a point: ";
    //std::cin >> x >> y;


    //// Type coercion - Compiler changes type of expression
    //// no impact on runtim code generation (types don't exist at runtime!)
    //// Always safe (won't lose data with type coercion)

    //// double result = 10/3.0   =    3.33
    //// double result = 10/3     =    3.00

    //// make your division problem have a double and it will solve your output problem!

    //// Always store the value as the type it best fits! don't make it work so your expressions are easier, the type coercion will work for you!

    //// Type heirarchy: Larger of two operand types
    ////  double
    ////  float
    ////  unsigned long
    ////  long
    ////  unsigned int
    ////  int
    ////  char/short/unsigned short (automatically converted into an int)

    ////double = int * double
    ////double = double * double (type coercion)
    ////double = double
    //double result = hours * payRate;

    //// double + float * int => double  ...   don't think arithmetically, think the biggest value amount in a type;

    //// Assignment doesn't matter, types determined on each side of operator
    //// double = int * float
    //// doesn't matter what you equal it out to, it will be a float! the compiler will turn the float into a double but the expression may be missing values from the desired output.

    //// Overflow and Underflow
    //short smallValue = 32767 + 1; //Overflow
    //std::cout << smallValue << std::endl;
    //short largeValue = -32768 - 1; //Underflow
    //std::cout << largeValue << std::endl;

    //float floatValue = 1e38 * 2e20;
    //std::cout << floatValue << std::endl;

    //// Typecasting - you convert an expression to another type explicity (code-smell)
    //int totalSales = 50000;
    //int departments = 8;

    //// static_cast<Type>(E) => preferred approach!
    ////  Must be allowable
    //double averageSalesPerDepartment = static_cast<double>(totalSales) / departments;
    ////double averageSalesPerDepartment = totalSales / static_cast<double>(departments);
    //averageSalesPerDepartment = (double)totalSales/ departments;   //This is the version of cast *(type)expression* is from C, where there is not staticcast command

    //// Compiler Error, cannot convert int >> string
    //std::string someString = "Hello";
    ////int someString = static_cast<int>(someString);

    //// use cast to truncated data w/o compiler warning (will warn that there will be data loss if going from float >> int, so a static cast tells the compiler "you know what your doing"
    //int truncatedValue = static_cast<int>(floatValue);

    //// Math functions (all defined in C)
    //// pow(x, y) => x to the y power
    //// sqrt(x) => square root of x
    //// exp(x) => e to the x power
    //// log(x) => log of x    log(exp(x)) = x
    //// sin(x), cos(x), tan(x), cot(x), sec(x), csc(x), ...h
    //// abs(x) => positive value of x (can be a good way to get rid of a negative sign that may come from a value)
    //// ceil(x) => smallest possible int value less than or equal to x (will return the back the same type, but will only have an int value **20.2 => 20** while still being a double)
    //// floor(x) => largest possible int value greater than or equal to x
    //// trunc(x) => rounds towards zero! gets rid of decimal place (basically typecasts into an int)
    //// round(x) => rounds to the nearest interger

    //double xValue = 45.6;
    //double mathResult;

    //std::cout << pow(xValue, 2) << std::endl; //xValue * xValue
    //std::cout << sqrt(xValue) << std::endl;

    //std::cout << exp(2) << std::endl;    // (euler math) e to the nth power, e = 2.718 -- magic math, for higher level math
    //std::cout << log(5.4) << std::endl;  // root of e

    //std::cout << abs(-45) << std::endl;  // positive x = 45

    //std::cout << ceil(xValue) << std::endl;  //46
    //std::cout << floor(xValue) << std::endl; //45

    //std::cout << trunc(xValue) << std::endl; //45
    //std::cout << round(xValue) << std::endl; //46
    //
    ////Formatted output
    //std::cout << 4.567898357738 << std::endl; // cout will determine the best format to use for the implication (scientific notation, rounded to 4 after dec point, etc...)
    //std::cout << 5.67e3 << std::endl;
    
    
    // Rectangular select Mode -- CTRL + ALT, click and drag.
    //      will activate rect select mode, affecting a rectangular area.
    
    
    // Create a table
    // Manipulator          |   behavior                            |   Persist
    // --------
    // setw(i)              |   pads the value to i (setwidth)      |   Not persistent across the columns, have to replicate line for every column (default right justified)
    // left                 |   Left justifies                      |   Persistent to subsequent expressions
    // right                |   Right justifies                     |   Persistent to subsequent expressions
    // fixed                |   forces fixed point notation (0.00)  |   Persistent
    // setprecision(i)      |   setd precision of floats            |   Persistent      // sets precision to total digits if !fixed and decimal digits is fixed
    // setfill(char)        |   characters to pad with              |   Persistent      // should be set back if not intending to continue to use the new fill for all whitespaces

    cout << left << setw(8) << "Student" << setw(6) << "Grade " << setw(6) << "Letter" << endl;
    cout << setw(20) << setfill ('-') << "" << setfill(' ') << endl;
    cout << fixed << setprecision(2);
    cout << setw(8) << "Bob" << setw(6) << 95.67 << setw(6) << "A" << endl;
    cout << setw(8) << "Sue" << setw(6) << 98.543 << setw(6) << "A" << endl;
    cout << setw(8) << "Jim" << setw(6) << 84.567 << setw(6) << "B" << endl;
    cout << setw(8) << "Jan" << setw(6) << 78.987 << setw(6) << "C" << endl;
}