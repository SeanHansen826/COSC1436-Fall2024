#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void StackDemo()
{
    double localDouble = 45.6;      //local variables stored on all-stack

    //Declare a pointer
    //Pointer is always a memory address
    //Pointer is always either 4 or 8 bytes long (8 in our case of x86)
    //Pointer value is always an int value

    //Pointers have two data points:
    //  value (memory address)  ex. 656777
    //  value they reference (in memory) ex. 65.6777
    double* ptrDouble;  //read as "pointer to a double" //stores a pointer to a memory address that is a double     //looks for the same type in that memory address, the type allows it to translate the gobbldygook
}

int main()
{
    StackDemo();
}