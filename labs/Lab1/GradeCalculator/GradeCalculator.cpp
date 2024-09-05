//Lab 1
//Sean Hansen
//COSC1436-Fall2024

#include<iostream>
#include<iomanip>

int main()
{
    std::cout << "Lab 1\n";
    std::cout << "Sean Hansen\n";
    std::cout << "COSC1436-Fall2024\n";

    std::string userName;

    std::cout << "Please Input Your Name:\t";
    std::cin >> userName;
    std::cout << std::endl;

    double lab1Grade = 0.0;
    double lab2Grade = 0.0;
    double lab3Grade = 0.0;
    double lab4Grade = 0.0;

    std::cout << "Please Input Your Lab Grades, " << userName << ":\n";
    std::cout << "Lab 1: ";
    std::cin >> lab1Grade;
    std::cout << "Lab 2: ";
    std::cin >> lab2Grade;
    std::cout << "Lab 3: ";
    std::cin >> lab3Grade;
    std::cout << "Lab 4: ";
    std::cin >> lab4Grade;
    std::cout << std::endl;

    double exam1Grade = 0.0;
    double exam2Grade = 0.0;
    double exam3Grade = 0.0;
    
    std::cout << "Please Input your Exam Grades, " << userName << ":\n";
    std::cout << "Exam 1: ";
    std::cin >> exam1Grade;
    std::cout << "Exam 2: ";
    std::cin >> exam2Grade;
    std::cout << "Exam 3: ";
    std::cin >> exam3Grade;
    std::cout << std::endl;

    double participationGrade = 0.0;

    std::cout << "Please Input Your Participation Grade, " << userName << ":\n";
    std::cout << "Participation Grade: ";
    std::cin >> participationGrade;
    std::cout << std::endl;

    double finalExam = 0.0;
    std::cout << "Please Input Your Final Exam Grade, " << userName << ":\n";
    std::cout << "Final Exam Grade: ";
    std::cin >> finalExam;
    std::cout << std::endl;

    std::cout << "Here Are Your Grades, " << userName << ":\n";
    std::cout << "Lab 1: " << lab1Grade << std::endl;
    std::cout << "Lab 2: " << lab2Grade << std::endl;
    std::cout << "Lab 3: " << lab3Grade << std::endl; 
    std::cout << "Lab 4: " << lab4Grade << std::endl; 
    
    std::cout << "Exam 1: " << exam1Grade << std::endl;
    std::cout << "Exam 2: " << exam2Grade << std::endl;
    std::cout << "Exam 3: " << exam3Grade << std::endl;

    std::cout << "Participation: " << participationGrade << std::endl;

    std::cout << "Final Exam: " << finalExam << std::endl;
    std::cout << std::endl;

    const double labAssigmentCount = 4;
    double labAverage = (lab1Grade + lab2Grade + lab3Grade + lab4Grade) / labAssigmentCount;
    std::cout << "Lab Average (65% of total): " << std::fixed << std::setprecision(2) << labAverage << std::endl;

    const double examAssignmentCount = 3;
    double examAverage = (exam1Grade + exam2Grade + exam3Grade) / examAssignmentCount;
    std::cout << "Exam Average (20% of total): " << std::fixed << std::setprecision(2) << examAverage << std::endl;

    std::cout << "Participation (5% of total): " << participationGrade << std::endl;

    std::cout << "Final Exam (10% of total): " << finalExam << std::endl;
    std::cout << std::endl;

    double classAverage = (examAverage * 0.20) + (labAverage * .65) + (participationGrade * .05) + (finalExam * .10);
    std::cout << "Class Average: " << std::fixed << std::setprecision(2) << classAverage << std::endl;
}