#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
using std::cout;
using std::cin;

struct Point
{
    int x;
    int y;
};

struct Rectangle
{
    Point topLeft;      //has x,y coords stored in the struct call -- stored to as single "topLeft" var
    Point bottomRight;
};

/// @brief 
/// @param point 
void Display(Point point)
{
    cout << "(" << point.x << "," << point.y << ")";
};

/// @brief 
/// @param rect 
void Display(Rectangle rect)
{
    cout << "(" << rect.topLeft.x << "," << rect.topLeft.y << ")";
    cout << "(";
    Display(rect.topLeft);
    cout << " ";
    Display(rect.bottomRight);
    cout << ")" << endl;
};

/// @brief 
/// @param rect 
/// @param offsetX 
/// @param offsetY 
void Translate(Rectangle& rect, int offsetX, int offsetY)
{
    rect.topLeft.x += offsetX;
    rect.bottomRight.x += offsetX;

    rect.topLeft.y += offsetY;
    rect.bottomRight.y += offsetY;

};

void TestPassByReference()
{
    Rectangle rc;
    rc.topLeft.x = 10;
    rc.topLeft.y = 20;

    rc.bottomRight.x = 100;
    rc.bottomRight.y = 75;
    Display(rc);

    Translate(rc, 5, 10);   //5 right, 10 down
    Display(rc);
}

///////////////////////////////////////////////////////////////

//scalar values (variables, structs... only store one variable)

int main()
{
    //Array -- set of related data

/*    string student1;
    string student2;
    string student3;
    string student4;
    string student5*/

    //must be a compile time constant
    const int MaxStudents = 100;
    string students [MaxStudents];      //set as max amount and const, so it is a compile time const. (only available to primitives)


    //Store roster of students
    for (int index = 0; index < MaxStudents; ++index)
    {
        string student;                 
        cout << "Enter student name: ";         //get student info
        getline(cin, student);
        if (student == "")
            break;

        //student at index 0, first element
        //  read as student sub 0 ... subscript
        // [] is the array access operator, only used for arrays

        //since it is essentially a variable you can push this into a function
        students[index] = student;                  //assign student info to array element
    };

    //Print Roster
    for (int index = 0; index < MaxStudents; ++index)
    {
        if (students[index] != "")
            cout << students[index] << endl;
    }
}

