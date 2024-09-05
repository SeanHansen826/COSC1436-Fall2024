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

    double lab1Grade = 0;
    double lab2Grade = 0;
    double lab3Grade = 0;
    double lab4Grade = 0;

    std::cout << "Please Input 4 of Your \"Lab\" Grades:1\n";
    std::cout << "Lab 1:\t";
    std::cin >> lab1Grade;
    std::cout << "Lab 2:\t";
    std::cin >> lab2Grade;
    std::cout << "Lab 3:\t";
    std::cin >> lab3Grade;
    std::cout << "Lab 4:\t";
    std::cin >> lab4Grade;

    double exam1Grade = 0;
    double exam2Grade = 0;
    double exam3Grade = 0;
    
    std::cout << "Please Input 3 \"Exam\" Grades:\n";
    std::cout << "Exam 1:\t";
    std::cin >> exam1Grade;
    std::cout << "Exam 2:\t";
    std::cin >> exam2Grade;
    std::cout << "Exam 3:\t";
    std::cin >> exam3Grade;  

    std::cout << "Lab Grades for:\t" << userName;
    std::cout << std::endl;
    std::cout << "Lab 1:\t" << lab1Grade << std::endl;
    std::cout << "Lab 2:\t" << lab2Grade << std::endl;
    std::cout << "Lab 3:\t" << lab3Grade << std::endl; 
    std::cout << "Lab 4:\t" << lab4Grade << std::endl; 
    
    std::cout << "Exam 1:\t" << exam1Grade << std::endl;
    std::cout << "Exam 2:\t" << exam2Grade << std::endl;
    std::cout << "Exam 3:\t" << exam3Grade << std::endl;

    const double labAssigmentCount = 4;
    double labAverage = (lab1Grade + lab2Grade + lab3Grade + lab4Grade) / labAssigmentCount;
    std::cout << "Lab Average (75% of total):\t" << std::fixed << std::setprecision(2) << labAverage << std::endl;

    const double examAssignmentCount = 3;
    double examAverage = (exam1Grade + exam2Grade + exam3Grade) / examAssignmentCount;
    std::cout << "Exam Average (25% of total):\t" << std::fixed << std::setprecision(2) << examAverage << std::endl;

    double classAverage = (examAverage * 0.25) + (labAverage * .75);
    std::cout << "Class Average:\t" << std::fixed << std::setprecision(2) << classAverage << std::endl;
}