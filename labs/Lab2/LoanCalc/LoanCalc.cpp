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

    do
    {
        char newLoanInput;
        bool newLoanBool;
        bool done = 0;
        do
        {
            cout << "Start a new loan calculation? (y/n): ";
            cin >> newLoanInput;
        
            switch (newLoanInput)
            {
                case 'Y':
                case 'y': newLoanBool = true; done = true; break;

                case 'N':
                case 'n': newLoanBool = false; done = true; break;

                default:
                {
                    cout << "ERROR: You must enter y/n\n";
                };
            };
        } while (!done);

        if(newLoanBool == false)
           break;

        double loanBalance = 0;
        do
        {
            cout << "Input your initial loan amount (between 1 and 1000): ";
            cin >> loanBalance;

            if (loanBalance < 1 || loanBalance > 1000)
                cout << "ERROR: Initial loan must be between 1 and 1000\n";

        } while (loanBalance < 1 || loanBalance > 1000);

        double interestRate = 0;
        do
        {
            cout << "Input your interest rate (between 1.0 and 100.0): ";
            cin >> interestRate;

            if (interestRate < 1.0 || interestRate > 100.0)
                cout << "Error: Interest rate must be between 1.0 - 100.0\n";

        } while (interestRate < 1.0 || interestRate > 100.0);
        interestRate /= 100;

        double monthlyPayment = 0;
        do
        {
            cout << "Input your desired monthly payment (between 0 and your initial loan balance): ";
            cin >> monthlyPayment;

            if (monthlyPayment < 0 || monthlyPayment > loanBalance)
                cout << "Error: Monthly payment must be within 0 and your initial loan balance\n";

        } while (monthlyPayment < 0 || monthlyPayment > loanBalance);

        double monthlyInterest = 0;
        double sumPayments = 0;
        double sumInterest = 0;
        for (int index = 0; index < 12; ++index)
        {
            double oldLoanBalance = loanBalance;

            if (loanBalance < monthlyPayment)
            {
                monthlyPayment = loanBalance;
            };

            if (index != 0)
            {
                monthlyInterest = (loanBalance - monthlyPayment) * interestRate;
                loanBalance = loanBalance + monthlyInterest - monthlyPayment;
            };

            sumPayments += monthlyPayment;
            sumInterest += monthlyInterest;

            if (loanBalance <= 0)
            {
                loanBalance = 0;
                monthlyInterest = 0;
            };

            if (index == 0)
            {
                cout << left << setw(7) << "Month" << setw(9) << "Balance" << setw(9) << "Payment" << setw(11) << "Interest" << "New Balance" << endl;
                cout << setw(38) << setfill('-') << "" << setfill(' ') << endl;
                cout << left << setw(7) << (index + 1) << "$ " << setw(9) << oldLoanBalance << "$ " << setw(9) << monthlyPayment - monthlyPayment << "$ " << setw(11) << monthlyInterest << "$ " << loanBalance << endl;
                continue;
            } else
            {
                cout << fixed << setprecision(2);
                cout << left << setw(7) << (index + 1) << "$ " << setw(9) << oldLoanBalance << "$ " << setw(9) << monthlyPayment << "$ " << setw(11) << monthlyInterest << "$ " << loanBalance << endl;
            };

            if (index == 11)
            {
                cout << setw(38) << setfill('-') << "" << setfill(' ') << endl;
                cout << left << setw(18) << "Total" << "$ " << setw(9) << sumPayments << "$ " << sumInterest << endl;
                cout << endl;
            };
        };
    }while (true);

    cout << "\nNow Closing Program...\n";
};