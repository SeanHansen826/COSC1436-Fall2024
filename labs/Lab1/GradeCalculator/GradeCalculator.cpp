//Lab 1
//Sean Hansen
//COSC1436-Fall2024

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main()
{
    cout << "Lab 1\n";
    cout << "Sean Hansen\n";
    cout << "COSC1436-Fall2024\n";
    cout << endl;

    string userName;

    cout << "Please Input Your First and Last Name: ";
    getline(cin, userName);
    cout << endl;

    int lab1Grade; int lab2Grade; int lab3Grade; int lab4Grade;

    cout << "Please Input Your Lab Grades, " << userName << ":\n";
    cout << "Lab 1: ";
    cin >> lab1Grade;
    cout << "Lab 2: ";
    cin >> lab2Grade;
    cout << "Lab 3: ";
    cin >> lab3Grade;
    cout << "Lab 4: ";
    cin >> lab4Grade;
    cout << endl;

    int exam1Grade; int exam2Grade; int exam3Grade;
    
    cout << "Please Input your Exam Grades, " << userName << ":\n";
    cout << "Exam 1: ";
    cin >> exam1Grade;
    cout << "Exam 2: ";
    cin >> exam2Grade;
    cout << "Exam 3: ";
    cin >> exam3Grade;
    cout << endl;

    int participationGrade;

    cout << "Please Input Your Participation Grade, " << userName << ":\n" << "Participation Grade: ";
    cin >> participationGrade;
    cout << endl;

    int finalExam;
    cout << "Please Input Your Final Exam Grade, " << userName << ":\n" << "Final Exam Grade: ";
    cin >> finalExam;
    cout << endl;

    cout << fixed << setprecision(2);
    double labAverage = (lab1Grade + lab2Grade + lab3Grade + lab4Grade) / 4.0;
    double examAverage = (exam1Grade + exam2Grade + exam3Grade) / 3.0;
    double classAverage = (examAverage * 0.20) + (labAverage * .65) + (participationGrade * .05) + (finalExam * .10); // classAverage = (avgA * weightA) + (avgB * weightB)... etc.
    cout << endl;
    
    cout << setw(17) << left << "Assignment" << setw(7) << "Grade" << endl;
    cout << setw(17 + 7) << setfill('-') << "" << setfill(' ') << endl;
    cout << setw(17) << "Lab 1" << setw(8) << lab1Grade << endl;
    cout << setw(17) << "Lab 2" << setw(8) << lab2Grade << endl;
    cout << setw(17) << "Lab 3" << setw(8) << lab3Grade << endl;
    cout << setw(17) << "Lab 4" << setw(8) << lab4Grade << endl;
    cout << setw(17) << "Exam 1" << setw(8) << exam1Grade << endl;
    cout << setw(17) << "Exam 2" << setw(8) << exam2Grade << endl;
    cout << setw(17) << "Exam 3" << setw(8) << exam3Grade << endl;
    cout << setw(17) << "Participation" << setw(8) << participationGrade << endl;
    cout << setw(17) << "Final Exam" << setw(8) << finalExam << endl;
    cout << endl;
    cout << setw(17) << left << "Assignment" << setw(12) << "Average" << setw(6) << "Weight" << endl;
    cout << setw(17 + 18) << setfill('-') << "" << setfill(' ') << endl;
    cout << setw(17) << "Lab Avg" << setw(12) << labAverage << setw(6) << "65%" << endl;
    cout << setw(17) << "Exam Avg" << setw(12) << examAverage << setw(6) << "20%" << endl;
    cout << setw(17) << "Participation" << setw(12) << participationGrade << setw(6) << "5%" << endl;
    cout << setw(17) << "Final Exam" << setw(12) << finalExam << setw(6) << "10%" << endl;
    cout << endl;
    cout << setw(17) << left << "Assignment" << setw(7) << "Average" << endl;
    cout << setw(17 + 7) << setfill('-') << "" << setfill(' ') << endl;
    cout << setw(17) << "Class Avg" << setw(8) << classAverage << endl;
}