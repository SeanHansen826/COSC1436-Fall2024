#include <iostream>

using namespace std;

struct Student
{
    string name;
    int year;
    char letterGrade;
};

void StudentRoll()
{
    for (int index = 0; index < 5; ++index);
    {
        Student index;
        cin >> index.name;
        cin >> index.year;
        cin >> index.letterGrade;

        cout << index.name << " " << index.year << " " << index.letterGrade << endl; //not looping
    }
}
int main()
{
    StudentRoll();
}
