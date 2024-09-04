//Lab 1
//Sean Hansen
//COSC1436-Fall2024

#include<iostream>

int main()
{
    std::string userName;
    //bool userNameCorrect;
    int lab1Grade = 0;
    int lab2Grade = 0;
    int lab3Grade = 0;
    int lab4Grade = 0;
    int exam1Grade = 0;
    int exam2Grade = 0;
    int exam3Grade = 0;

    std::cout << "Lab 1\n";
    std::cout << "Sean Hansen\n";
    std::cout << "COSC1436-Fall2024\n";
    std::cout << std::endl;

    std::cout << "Please Input Your Name:\t";
    std::cin >> userName;
    //std::cout << "Is This Correct?\t";
    //std::cout << userName;
    //std::cout << "\n y/n:\t";
    //std::cin >> userNameCorrect;
    //std::cout << userNameCorrect;
    std::cout << std::endl;

    std::cout << "Please Input 4 of Your \"Lab\" Grades:1\n";
    std::cout << "\"Lab\" 1:\t";
    std::cin >> lab1Grade;
    std::cout << "\"Lab\" 2:\t";
    std::cin >> lab2Grade;
    std::cout << "\"Lab\" 3:\t";
    std::cin >> lab3Grade;
    std::cout << "\"Lab\" 4:\t";
    std::cin >> lab4Grade;
    
    std::cout << "Please Individually Input 3 \"Exam\" Grades:\n";
    std::cout << "\"Exam\" 1:\t";
    std::cin >> exam1Grade;
    std::cout << "\"Exam\" 2:\t";
    std::cin >> exam2Grade;
    std::cout << "\"Exam\" 3:\t";
    std::cin >> exam3Grade;  

    std::cout << "These Values Should Reflect Your Inputs:\n";
    std::cout << "Student's Name:\t";
    std::cout << userName;
    std::cout << std::endl;
    std::cout << "\"Lab\" 1:\t";
    std::cout << lab1Grade;
    std::cout << std::endl;
    std::cout << "\"Lab\" 2:\t";
    std::cout << lab2Grade;
    std::cout << std::endl;
    std::cout << "\"Lab\" 3:\t";
    std::cout << lab3Grade;
    std::cout << std::endl;
    std::cout << "\"Lab\" 4:\t";
    std::cout << lab4Grade;
    std::cout << std::endl;
    std::cout << "\"Exam\" 1:\t";
    std::cout << exam1Grade;
    std::cout << std::endl;
    std::cout << "\"Exam\" 2:\t";
    std::cout << exam2Grade;
    std::cout << std::endl;
    std::cout << "\"Exam\" 3:\t";
    std::cout << exam3Grade;
    std::cout << std::endl;
}