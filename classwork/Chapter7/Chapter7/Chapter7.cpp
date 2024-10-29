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

void GradeArrayDemo()
{
    const int MaxGrades = 20;
    double dummyValue2 = -1;
    int grades[MaxGrades];
    double dummyValue = 0;

    int estimatedMaxArraySize = //size of array / size of element
        sizeof(grades) / sizeof(int);

    int count = 0;
    for (int index = 0; index < MaxGrades; ++index)//++count)        //count gets +1 each time, not likely but useful
    {
        cout << "Enter a grade: ";
        cin >> grades[index];
        //grades[index] = 100;                            //sets each element in the array to 100

        if (grades[index] <= 0)
            break;

        ++count;            //increases the element in array counted each time a value is input
    };

    for (int index = 0; index < count; ++index)     //change condition to however many values were used! (index < count)
    {
        cout << grades[index] << endl;
    };

    int indexToChange;
    do
    {
        cout << "Enter the index of the grade to change: ";
        cin >> indexToChange;

    } while (indexToChange < 0 || indexToChange >= MaxGrades);


    int newGrade;
    cout << "Enter the new grade: ";
    cin >> newGrade;

    grades[indexToChange] = newGrade;
}

void InitArrayDemo()
{
    const int MaxRates = 100;
    double payRates[MaxRates] = {0};    //zero initialize array

//    for (int index = 0; index < MaxRates; ++index)
//        payRates[index] = 0;           //zero initialize array
}

int main()
{
    InitArrayDemo();
}

void NameArrayDemo()
{
    //Array -- set of related data

/*    string student1;
    string student2;
    string student3;
    string student4;
    string student5*/

    //must be a compile time constant
    const int MaxStudents = 100;
    string students [MaxStudents];      //set as max amount and const, so it is a compile time const. (only available to primitives)        //use this for lab!


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

