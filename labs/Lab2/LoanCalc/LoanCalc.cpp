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

    double loanBalance = 0;
    while (loanBalance < 1 || loanBalance > 1000)
    {
        cout << "Input your initial loan amount (between 1 and 1000): ";
        cin >> loanBalance;

        if (loanBalance < 1 || loanBalance > 1000)
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

    bool validInput = false; //set as false to make sure loop runs
    double monthlyPayment = 0;
    while (!validInput)
    {
        cout << "Input your desired monthly payment (between 0 and your initial loan balance): ";
        cin >> monthlyPayment;

        if (monthlyPayment < 0 || monthlyPayment > loanBalance)
            cout << "Error: Monthly payment must be within 0 and your initial loan balance\n";
        else validInput = true;
    };

    interestRate /= 100;
    cout << "Interest stored as: " << interestRate << endl;

    double monthlyInterest = 0.0;


    for (int index = 0; index < 12; ++index)
    {
        double oldLoanBalance = loanBalance;

        if (index == 0)
        {
            monthlyInterest = 0;
            loanBalance += monthlyInterest;
        }
        else
        {
            monthlyInterest = (loanBalance * interestRate);
            loanBalance = loanBalance + monthlyInterest - monthlyPayment;
        }

        if (loanBalance < 0)
        {
            monthlyPayment = 0;
            monthlyInterest = 0;
            loanBalance = 0;
        }

        double newLoanBalance = loanBalance;

        
        if (index == 0)
        {
            cout << right << "Month" << setw(7) << "Balance" << setw(9) << "Interest" << setw(10) << "New Balance" << endl; //outputs funky, check setw's
            cout << setw(78) << setfill('-') << "" << setfill(' ') << endl;
        }
        cout << fixed << setprecision(2);
        cout << right << (index + 1) << setw(7) << oldLoanBalance << setw(9) << monthlyInterest << setw(10) << newLoanBalance << endl; //outputs funky
    };
}