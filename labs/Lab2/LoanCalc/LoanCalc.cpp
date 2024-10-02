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

    interestRate /= 100;
    cout << "Interest stored as: " << interestRate << endl;

    double totalInterest;
    totalInterest = (loanBalance * interestRate);

    double monthlyInterest = 0.0;

    double monthlyPayment = 0.0;
    monthlyPayment = (loanBalance + totalInterest) / 12.0;

    for (int index = 0; index < 12; ++index)
    {
        if (index == 0)
            monthlyInterest = 0;

        else monthlyInterest = loanBalance * interestRate;

        loanBalance = loanBalance - monthlyPayment - monthlyInterest;

        if (loanBalance < 0)
        {
            loanBalance = 0;
            monthlyInterest = 0;
        }

        cout << fixed << setprecision(2);

        if (index == 0)
            cout << setw(63) << setfill('-') << "" << setfill(' ') << endl;
        
        cout << left << "Month: " << setw(7) << (index +1) << "Loan Balance: " << setw(12) << loanBalance << "Monthly Interest: " << monthlyInterest << endl;
        cout << setw(63) << setfill('-') << "" << setfill(' ') << endl;
    };
}