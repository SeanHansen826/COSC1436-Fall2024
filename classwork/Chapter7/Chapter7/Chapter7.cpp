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

    //parallel arrays ... same size and relate each index number (month 0 days, month name 0)
    //int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};     //zero extends all but first element, continues in order with ","    !!do this!!
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", 
                             "Jun", "Jul", "Aug", "Sep", "Oct", 
                             "Nov", "Dec"};

    //monthNames[0] = "Jan";
    //monthNames[1] = "Feb";
    //monthNames[2] = "Mar";
    //monthNames[3] = "Apr";
    //monthNames[4] = "May";
    //monthNames[5] = "Jun";
    //monthNames[6] = "Jul";
    //monthNames[7] = "Aug";
    //monthNames[8] = "Sep";
    //monthNames[9] = "Oct";
    //monthNames[10] = "Nov";
    //monthNames[11] = "Dec";

    //daysInMonth[0] = daysInMonth[2] = daysInMonth[4] = daysInMonth[6] = daysInMonth[7] = daysInMonth[9] = daysInMonth[11] = 31;
    //daysInMonth[1] = 28;
    //daysInMonth[3] = daysInMonth[5] = daysInMonth[8] = daysInMonth[10] = 30;

    for (int index = 0; index < 12; ++index)
    {
        cout << monthNames[index] << " has " << daysInMonth[index] << " days" << endl;
    }
}

//COMPARE ARRAYS
// function parameters 'T id[]'
bool AreArraysEqual(int left[], int leftSize, int right[], int rightSize)          //no size in parameter decleration "Open array" means you can pass in any size array
{
    if (leftSize != rightSize)
        return false;

    for (int index = 0; index < leftSize; ++index)
    {
        if (left[index] != right[index])
            return false;
    }

    return true;
}

int CopyArray(int left[], int leftSize, int right[], int rightSize)
{
    int size = (leftSize < rightSize) ? leftSize : rightSize;   //calculates the smaller of the two to do the copying from

    for (int index = 0; index < size; ++index)
        left[index] = right[index];

    return size;        //returns size so the caller understands if there are values stomped over, or left over based on the size difference of the arrays
}

//Array cannot be return type from function (because size is not available at run-time)
void InitializeArray( int values[], int size, int initialValue)
{
    for (int index = 0; index < size; ++index)       //behaves like pass-by-ref, because it looks at the same point in memory ... modifies original array
        values[index] = initialValue;
}

void UseArrayDemo()
{
    int array1[20] = {0};

    //for (int index = 0; index < 20; ++index)
    //    array1[index] = index + 1;

    InitializeArray(array1, 20, 2);

    //int index2 = 0;
    //while (index2 < 20)
    //{
    //    array1[index2++] = index2 + 1;      //same as code below... assigns value to first element, then on second iteration it will update to the second element.
    //    //array1[index2] = index2 + 1;
    //    //++index2;
    //}

    //for loop for iterating arrays
    //for (int index = 0; index < 20; ++index)
    //  cout << array1[index] << endl;
    for (int value : array1)            //for (type id : arrayName)     //gens same code for each, but this calculates the iteration count for you          !!USE THIS (if declaring array in same block)!!
        cout << value << endl;

/*    for (int& value : array1)
        cout << value << endl;*/          //modifies array by adding the &, becomes pass by reference since the int value is just a temp variable like the function parameter

    int array2[20] = {0};
    int array3[20] = {0};

    //Compare Arrays
    cout << (array2 == array3)     //cannot compare array size at run-time ... 
        << " " << AreArraysEqual(array2, 20, array3, 20) << endl;      //don't have to use the entirety of the array, can just use some of the values

    //Assignment
    int elementsCopied = CopyArray(array3, 20, array2, 20);
    cout << elementsCopied;
}

void DisplayArray(int values[], int size, int valueWidth, int maxCellsPerRow)
{
    cout << left;
    for (int index = 0; index < size; ++index)
    {
        cout << setw(valueWidth) << values[index] << " ";

        //if (index > 0 && index % maxCellsPerRow == 0)           //% = modulos (remainder)   if printed out maxCellsPerRow values, endl (newLine)
        if((index + 1) % maxCellsPerRow == 0)
            cout << endl;
    }
    cout << endl << right;
}

void DisplayTable(int values[][10], int size)       //all dimensions other than rows must be fixed, col = 10
{
    for (int row = 0; row < size; ++row)
        for (int col = 0; col < 10; ++col)
        {
            DisplayArray(values[row], 10, 5, 10);       //row doesn't have to be a const, but col does as it can't get your size at run tim
        }
}

void TableDemo()
{
    //index[rows][columns]      --compile time constant for all dimensions      this doubles as your time, typeSize * (rows * columns)
    //int multiplyTable[5][10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
    //                             2, 4, 6, 8, 10, 12, 14, 16, 18 ,20}    //when the values run out of rows to assign it will move onto next column
    int multiplyTable[5][10] = {{1, 2, 3, 4, 5}
                             ,  {2, 4, 6, 8, 10, 12, 14, 16, 18 ,20}};    //each set of brackets assigns the rows in each column (in order)


    //ROW MAJOR - rows are enumerated, then columns         //always use this
    for (int row = 0; row < 5; ++row)
        for (int col = 0; col < 10; ++col)
            multiplyTable[row][col] = (row + 1) * (col + 1);

    //COLUMN MAJOR ordering - columns are enumerated, then rows     //very slow, essentially random access memory and very slow
    /*for (int col = 0; col < 5; ++col)
        for (int row = 0; row < 10; ++row)
            multiplyTable[row][col] = (row + 1) * (col + 1);*/

    /*DisplayTable(multiplyTable, 5);*/
    //for (int row = 0; row < 5; ++row)
    //{
    //    for (int col = 0; col < 10; ++col)
    //        cout << setw(5) << multiplyTable[row][col];

    //    cout << endl;
    //}
}

int main()
{
    TableDemo();
    /*int values[] = {1,2,3,4,5};

    DisplayArray(values, 5, 10, 3);*/       //displays 2d array
}

//void NameArrayDemo()
//{
//    //Array -- set of related data
//
///*    string student1;
//    string student2;
//    string student3;
//    string student4;
//    string student5*/
//
//    //must be a compile time constant
//    const int MaxStudents = 100;
//    string students [MaxStudents];      //set as max amount and const, so it is a compile time const. (only available to primitives)        //use this for lab!
//
//
//    //Store roster of students
//    for (int index = 0; index < MaxStudents; ++index)
//    {
//        string student;                 
//        cout << "Enter student name: ";         //get student info
//        getline(cin, student);
//        if (student == "")
//            break;
//
//        //student at index 0, first element
//        //  read as student sub 0 ... subscript
//        // [] is the array access operator, only used for arrays
//
//        //since it is essentially a variable you can push this into a function
//        students[index] = student;                  //assign student info to array element
//    };
//
//    //Print Roster
//    for (int index = 0; index < MaxStudents; ++index)
//    {
//        if (students[index] != "")
//            cout << students[index] << endl;
//    }
//}

