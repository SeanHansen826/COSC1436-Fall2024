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
    while (!validInput) //try while (true)
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

    double sumInterest; //calc before finished
    double sumPayments; //calc before finished

    for (int index = 0; index < 12; ++index)
    {
        double oldLoanBalance = loanBalance;

        if (index == 0)   //modify the equation to include the (loanBalance - monthylPayment ( + monthly interest )) when the answer is <= 0
        {
            monthlyInterest = 0;
            loanBalance += monthlyInterest;
        }
        else
        {
            monthlyInterest = (loanBalance * interestRate);
            loanBalance = loanBalance + monthlyInterest - monthlyPayment;
        }

        
        //if (loanBalance < 0)
        //{
            //monthlyPayment = 0;
            //monthlyInterest = 0;
            //loanBalance = 0;
        //}

        double newLoanBalance = loanBalance;

        
        if (index == 0)
        {
            cout << left << setw(7) << "Month" <<setw(9) << "Balance" << setw(9) << "Payment" << setw(11) << "Interest" << "New Balance" << endl; //outputs funky, check setw's
            cout << setw(38) << setfill('-') << "" << setfill(' ') << endl;
        }
        cout << fixed << setprecision(2);
        cout << left << setw(7) << (index + 1) << setw(9) << oldLoanBalance << setw(9) << monthlyPayment << setw(11) << monthlyInterest << newLoanBalance << endl; //outputs funky
    };
}

//   balance = $100
//      interest = 10%
//      payment = $10
// 
//      newBalance = balance - payment + interest           --you dont know the interest at run time of this code ... order is important
// 
//      interest = balance * interestRate
// 
// -     month       pay     int     new
// 1     100         0       0       100
// 2     100         10      9       99
// 3     99         10      8.9     97.9
// 4     etc...
// 
//      interest = newbalance * interest
//      newBalance += interest
// 
//      balance = newBalance   --- meant to make sure that your newbalance is stored as your new balance instead of reusing your initial balance.
// 
// 
//