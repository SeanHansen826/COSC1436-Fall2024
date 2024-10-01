//Loan Calculator
//Sean Hansen
//COSC-1436-20005

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;
    cout << left << setw(10) << "Project" << "Loan Calculator\n" << setw(10) << "By:" << "Sean Hansen\n" << setw(10) << "Class:" << "COSC-1436-20005\n";
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;

    int initialLoan = 0;
    while (initialLoan < 1 || initialLoan > 1000)
    {
        cout << "Input your initial loan amount (between 1 and 1000): ";
        cin >> initialLoan;

        if (initialLoan < 1 || initialLoan > 1000)
            cout << "ERROR: Initial loan must be between 1 and 1000\n";
    };

    double interestRate = 0;
    while (interestRate < 1.0 || interestRate > 100.0)
    {
        cout << "Input your interest rate (between 1.0 and 100.0): ";
        cin >> interestRate;

        if (interestRate < 1.0 || interestRate > 100.0)
            cout << "Error: Interest rate must be between 1.0 - 100.0\n";
    };
    
    interestRate /= 100;
    cout << interestRate;

    //Calculating table of first 12 months of loan ... table output ... for loop ... 
}