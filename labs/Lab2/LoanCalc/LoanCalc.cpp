//Loan Calculator
//Sean Hansen
//COSC-1436-20005

#include <iostream>
#include <iomanip>

using std::cout;    //1)
using std::cin;     //2) Found that adding these fixes our "cout is ambiguous" error from class
using namespace std;

int main()
{
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;
    cout << left << setw(10) << "Project" << "Loan Calculator\n" << setw(10) << "By:" << "Sean Hansen\n" << setw(10) << "Class:" << "COSC-1436-20005\n";
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;

    while(true)
    {
        char newLoanInput;
        bool newLoanBool;
        bool done = 0;
        do
        {
            cout << "Start a new loan calculation? (y/n): ";
            cin >> newLoanInput;
            cout << endl;
        
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
            cout << "Initial loan amount (1 - 1000): ";
            cin >> loanBalance;

            if (loanBalance < 1 || loanBalance > 1000)
                cout << "ERROR: Initial loan must be between 1 and 1000\n";

        } while (loanBalance < 1 || loanBalance > 1000);

        double interestRate = 0;
        do
        {
            cout << "Interest rate percentage (between 1 - 100): ";
            cin >> interestRate;

            if (interestRate < 1.0 || interestRate > 100.0)
                cout << "Error: Interest rate must be between 1 and 100\n";

        } while (interestRate < 1.0 || interestRate > 100.0);
        interestRate /= 100;

        double monthlyPayment = 0;
        do
        {
            cout << "Monthly payment (0 - initial loan balance): ";
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
                cout << fixed << setprecision(2);
                cout << left << setw(7) << "Month" << setw(11) << "Balance" << setw(11) << "Payment" << setw(13) << "Interest" << "New Balance" << endl;
                cout << setw(53) << setfill('-') << "" << setfill(' ') << endl;
                cout << left << setw(7) << (index + 1) << "$ " << setw(9) << oldLoanBalance << "$ " << setw(9) << "0.00" << "$ " << setw(11) << monthlyInterest << "$ " << loanBalance << endl;
                continue;
            } else
            {
                cout << fixed << setprecision(2);
                cout << left << setw(7) << (index + 1) << "$ " << setw(9) << oldLoanBalance << "$ " << setw(9) << monthlyPayment << "$ " << setw(11) << monthlyInterest << "$ " << loanBalance << endl;
            };

            if (index == 11)
            {
                cout << setw(53) << setfill('-') << "" << setfill(' ') << endl;
                cout << left << setw(18) << "Total" << "$ " << setw(9) << sumPayments << "$ " << sumInterest << endl;
                cout << endl;
            };
        };
    };

    cout << "Now Closing Program...\n";
};