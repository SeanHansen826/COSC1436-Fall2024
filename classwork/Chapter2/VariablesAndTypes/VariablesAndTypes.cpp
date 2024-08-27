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

    //Variables - named memore location to store data

    //decleration - tell compiler a variable exists
    //scope - lifetime of a variable
    int length;
    length = 0;

    int releaseYear = 1900;

    int rating = 3, stars =5;


    std::cout << length;
}