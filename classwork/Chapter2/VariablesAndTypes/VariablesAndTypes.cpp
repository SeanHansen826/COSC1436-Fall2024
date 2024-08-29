#include <iostream>
// anything that starts with # is a preprocessor

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
}