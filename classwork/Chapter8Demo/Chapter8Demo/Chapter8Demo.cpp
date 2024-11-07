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

    //local variable, value is stored on callstack
    //read as "pointer to a double" 
    //stores a pointer to a memory address that is a double     
    //looks for the same type in that memory address, the type allows it to translate the gobbldygook
    
    // address-of :: &variable (needs to be an already assigned variable)
    //      type of the expression is T* where T is the type of the variable

    double* ptrDouble = &localDouble;  

    //Type coercion not allowed
    int localInt = 56;
    localDouble = localInt;
    
    // double* != double
    //  ptrDouble = 90.6    doesn't work because it needs a memory address
    //asterisk to the variable name dereferences!

    //assign new value to memory address
    *ptrDouble = 89.7;  //de referenced, then assigned

    //dereferencing a pointer
    //  dereference-op :: *expr
    //      type of expression is T where Expr is T*
    cout << ptrDouble << " " << * ptrDouble << endl;
    cout << (*ptrDouble == localDouble) << endl;
}

void EmptyDemo()
{
    float payRate = 12.50;

    //when declaring a pointer, always initialize to 0 or valid memory
    //float* pPayRate = NULL; // C, old school method
    float* pPayRate = nullptr; // c++, recommended, points to nothing, not specifically 0

    cout << pPayRate << " ";

    //always verify pointer before dereferencing (not everytime but in every instance of function usage)
    //if (pPayRate != nullptr)  // long version
    if (pPayRate)   //bool! if 0 = false, anything else = true
        cout << *pPayRate;
    cout << endl; //de refernces
}

struct Employee
{
    int Id;
    string Name;

    int dummyValues[1000];
};

void DynamicMemoryDemo()
{
    const int MaxEmployees = 100;
    //Employee employees[MaxEmployees]; //very large, expensive
    Employee* employees[MaxEmployees] = {0};   //cheaper! uses less memory than showing each element at run time     //now you can 0 initi
    int id = 1000;
    
    //int numberOfEmployees = 0;
    for (int index = 0; index < MaxEmployees; ++index)
    {
        string name;
        cout << "Enter name or empty to quit: ";
        getline(cin, name);

        if (name == "")
            break;

        //Add to array
        //new operator == new T; returns T* 
        Employee* employee = new Employee;
        //(*employee).Id = ++id;
        employee->Id = ++id;    //arrow, usefule for member access in structs with pointers
        employee->Name = name;
        employees[index] = employee;    //array is stored as pointers to dynamically update each employee

        //++numberOfEmployees;
    }

    //Print employees
    for (int index = 0; index < MaxEmployees; ++index)
    {
        if (employees[index] == nullptr)    //checks 
            break;

        cout << "[" << employees[index]->Id << "] " << "[" << employees[index]->Name << "] " << endl;   //since array is stored as pointers, we need to use the arrow to dereference
    }

    //Ensure there are no memory leaks with the 'new' operator
    //use delete operator == delete E:
    for (int index = 0; index < MaxEmployees; ++index)
    {
        if (employees[index] == nullptr)
            break;

        //delete the memory
        Employee* employee = employees[index];
        delete employee;
        employees[index] == nullptr;  //always reset to null to avoid issues
        delete employees[index];    //this works
        //employee->Id = 20;  //going to fail, pointing to memory you don't own

        //delete $index;  //Bad things will happen -- not allocated with 'new' operator, undefined behavior!
    }
}

int main()
{
        DynamicMemoryDemo();
}