#include <iostream>
// anything that starts with # is a preprocessor

struct Point
{
    //Declare variables - fields
    //calling them fields is just to delineate between variables that are in the main code, and variables inside of a struct
    int X;
    int Y;
};
int main()
{
    //Messages (Hello Worlds)
    std::cout << "Hello World" << std::endl;

    std::cout << "Hello" << " " << "World" << std::endl;

    std::cout << "Hello";
    std::cout << " ";
    std::cout << "World";
    std::cout << std::endl;

    std::cout << "Hello\tWorld\n";

    std::cout << "Hello\"Bob\"";

    //File Paths
    std::cout << "C:\\Windows\\Temp";

    //Variables - named memory location to store data

    //decleration - tell compiler a variable exists
    //scope - lifetime of a variable
    int length;
    length = 0;

    int releaseYear = 1900;

    int rating = 3, stars =5;
        

    std::cout << length;

    //Identifiers
    //int _hours, _1stGrade, 1stGrade, 1stGrade, first-grade;
    int examGrade = 0, hoursWorked = 0;
    std::cout << examGrade;

    //Types
    // Define: What kind of data is stored, range, and size

 // double and float
    double largeNumber = 10E100;

    int intSize = sizeof(int);




    //assignment
    //asn_op ::=V = E
    //Must be type compatible (same type between the two)

    int shapeLength = 10;
    int shapeWidth = 20;
    int shapeArea;


    shapeArea = shapeLength;
    shapeWidth = 10;
    // does not work |  20 = shapeWidth;
    int remainder = 10 % 3; // 1

    double dresult = 10.0 / 3.0; //3.333
    

    //string stuff
    //not a primitive
    
    // + is called concatenate
    std::string name = "Sean";

    std::string message = "Hello";
    message = message + " World";
    message = message + " " + name;

    std::string empty;
    empty = empty + "Hello";

    //Combination operators
    //  variable operand= Expression, handles right value before hand, after blowing it out to "long-hand"
    empty += " World"; // empty = empty + " World"

    //+= is called a combination operator.

    //C++ is strongly typed = when something is assigned a type it stays that way unless you change that initializing.
    //expressions are "type"'d at the point of compulation (compiling)

    //weakly typed languages could change the type of expressions at run time, something could go from =10 to =string.

    int number = 10;
    //number = "20"; //Compiler error, cannot change type of variable

    //remember, Types are for the compiler to see how you want to store information, it does not affect run time.

    //Type inferencing  (C++11)
    //  auto ::= compiler figures it out... usable mostly in variable declerations.
    //      must use an initializer expression when declaring the variable
    //      once initialized, the type inferencing kicks in
    auto payRate = 45.6;    //double payRate = 45.6
        //payRate = "45.6";
        double averagePayRate = 40 / payRate;

    //hybrid between literal (unwriteable) and variable (writeable)
    //Area of a circle = PI*r2;
    //double pi = 3.14159;
    double radius = 10;

    //Constant expressions (compile time constant) are expressions calculated at compile time, Primitive;
    //  4+5 * 8 = 44
    //Literals are great unless you need them everywhere (typing takes time);
    //Variables are better at reuse but may accidentally be changed; (Variables are constant expressions)
    const double pi = 3.14159;
    double area = pi * radius * radius;
    //double area = 3.145159 * radius * radius;
    //area = pi * radius * radius;

    //Constant;
    // have type, value, name, can only be read!;
    //to make a variable contant, preceed the type with "const"

    //const double pi = 3.14159;
    //pi = 10; this now gives us a compiler error, as it has a name like a variable, but cannot be written over.
    //constant are usefule for numeric literals, string messages that are repeated, that shouldn't ever be written over without recompiling. (magical constants)

    //when changing your initializer constant, it changes everywhere it was used in its block.


    //Structure - a group of related data points (C);
    //Prompt user for a point
    //int x, y;
    //once a struct is created you can use it as a type, and declare variables for it.
    Point pt = {0};
    std::cout << "Enter X value: ";
    //member access is = "member name . variable name"
    pt.X = 5;
    std::cout << "Enter y value: ";
    pt.Y = 10;

    //structures are useful for grouping multiple values into just one "variable" (Point - struct    pt - variable)
    //Limitations: cannot use structs with cout
    //              Struct variables are undefined!
    //              Most struct variable declerations initialize an expression with {0}
    //              {0} in a struct initializer will assing 0 to all of the variables INSIDE the struct.
    //(5, 10)
    std::cout << "(" << pt.X << ", " << pt.Y << ")";
    //Struct assignment is value assignment, all fields are copied
    Point pt2 = pt;

    //assignment is only a copy, if you change something that was copied from pt1 to pt2, it will only affect the variable targeted.
    
}

//Declares a point as an X and Y value
//C++ uses total camelCasing, but PascalCasing for structures and their variables;
//struct Point
//{
    //Declare variables - fields
    //calling them fields is just to delineate between variables that are in the main code, and variables inside of a struct
    //int X;
    //int Y;
//};

//struct point2
//{
    //int x;
    //int y;
//};