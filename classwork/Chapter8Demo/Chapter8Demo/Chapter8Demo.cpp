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
        //  Employee*, 
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
        employees[index] = nullptr;  //always reset to null to avoid issues
        delete employees[index];    //this works
        //employee->Id = 20;  //going to fail, pointing to memory you don't own

        //delete $index;  //Bad things will happen -- not allocated with 'new' operator, undefined behavior!
    }
}

// Pointers can be passed as parameters (essentially pass by referene as they are both pointing to a memory location)
//void DisplayIntArray(int arr[], int size)
void DisplayIntArray(int* arr, int size) //intPOINTER array
{
    for (int index = 0; index < size; ++index)
        arr[index] = index + 1;
}

void ArrayPointerDemo()
{
    int values[100];

    //array variables are pointers (the first element)
    int* ptrValues = values;

    for (int index = 0; index < 100; ++index)
    {
        //arr[index] == arr + index = arr + (sizeof(T) * index)

        //POINTER ARITHEMETIC
        //      ADD / SUBTRACT (only ones that work)
        //      Value is always multiplied by size of t, referencing a whole element
        //why indexes are 0 based (would keep having a +1)
        //what is generated in a for loop (!)
        //(ptrValues + (sizeof(int) * index)) = index + 1;  LONG VERSION
        //arr[index] = *(arr + index)   generated by compiler
        *(ptrValues + index) = index + 1;
    }

    /*for (int index = 0; index < 100; ++index)
        values[index] = index + 1;*/

    DisplayIntArray(ptrValues, 100);    //can pass a ptr into something that needs an array!

    int localVariable = 100;
    DisplayIntArray(&localVariable, 1);
}

void NewArrayDemo()
{
    //double arr[100];

    //dynamically allocate size of array at run time
    int size;
    cout << "How many elements: ";
    cin >> size;

    //array decleration wont work at run time, use ptr
    //  new T[size}
    //      size must be integral and >0
    //      ensure you delete when finished
    double* arr = new double[size];

    //arrays and pointers are inter-changeable so nothing else changes
    for (int index = 0; index < size; ++index)
    {
        cout << "Enter a value: ";
        cin >> arr[index];

        if (arr[index] == 0)
            break;
    }

    //cleanup
    //delete arr; only cleans up the single value, not an array if youve allocated on there.
    //use array delete operator instead
    delete[] arr;
}

void NewArrayDemo2()
{
    while (true)
    {
        NewArrayDemo();

        cout << "Keep going (Y/N)? ";
        char choice;
        cin >> choice;

        if (choice == 'n' || choice == 'N')
            break;
    }
}

//Employee is pass by reference, changes to employee are visible to caller
void InitializeEmployeeByRef(int& employee)
{
    cout << "Enter the employee ID: ";
    cin >> employee;
}

//Employee is pass by value (memory address), any changes to employee are visible to caller
void InitializeEmployeeByPointer(int* employee)
{
    //employee++; //taking memory address and mucking with it. 

    cout << "Enter the employee ID: ";
    cin >> *employee;   //dereferences to get value at memory location, this is where you get the pass by ref
}

void PassByRefVsPointerDemo()
{
    int employeeId;

    //Pass by ref - must pass a variable
    InitializeEmployeeByRef(employeeId);    //cannot tell it is pass by ref, and can be changes
    InitializeEmployeeByPointer(&employeeId); //only accepts pointers, is clear it will acces the memory location

    //InitializeEmployeeByPointer(nullptr); would crash program
}

int main()
{
    NewArrayDemo2();
}