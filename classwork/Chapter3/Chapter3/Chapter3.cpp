#include <iostream>
#include <string>
//include <string> for getline()


int main()
{
    //Getting user's name
    std::string name;
    std::cout << "Enter your name: ";

    // std::cin >> V
    //Inserts value up to first whitespaec into variable
    //Doestn' work with spaced strings!
    // ** std::cin >> name;
    std::getline(std::cin, name);

    //std::getline(cin, variable cin is stored in)

    std::cout << "Hello " << name << std::endl;

    int hours;
    std::cout << "how many hours did you work this week? ";
    std::cin >> hours;

    double payRate;
    std::cout << "How much do you earn an hour? ";
    std::cin >> payRate;
    std::cout << "you earned $" << (hours * payRate) << " (before taxes) this week" << std::endl;

    //Multi-value input, values are whitespace seperated, user can enter both seperately, with tabs, or spaces, it will idndividually assign them.
    int x, y;
    std::cout << "Enter the X,Y values of a point: ";
    std::cin >> x >> y;


    //Type coercion - Compiler changes type of expression
    //no impact on runtim code generation (types don't exist at runtime!)
    //Always safe (won't lose data with type coercion)

    //double result = 10/3.0   =    3.33
    //double result = 10/3     =    3.00

    //make your division problem have a double and it will solve your output problem!

    //Always store the value as the type it best fits! don't make it work so your expressions are easier, the type coercion will work for you!

    // Type heirarchy: Larger of two operand types
    //  double
    //  float
    //  unsigned long
    //  long
    //  unsigned
    //  int
    //  char/short/unsigned short (automatically converted into an int)

    //double = int * double
    //double = double * double (type coercion)
    //double = double
    double result = hours * payRate;

    // double + float * int => double  ...   don't think arithmetically, think the biggest value amount in a type;

    //Assignment doesn't matter, types determined on each side of operator
    //double = int * float
    //doesn't matter what you equal it out to, it will be a float! the compiler will turn the float into a double but the expression may be missing values from the desired output.

    //Overflow and Underflow
    short smallValue = 32767 + 1; //Overflow
    std::cout << smallValue << std::endl;
    short largeValue = -32768 - 1; //Underflow
    std::cout << largeValue << std::endl;

    float floatValue = 1e38 * 2e20;
    std::cout << floatValue << std::endl;

}