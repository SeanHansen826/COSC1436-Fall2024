#include <iostream>

using namespace std;

//number exclamation - 1 * 2 * 3 ... * N
int Factorial ( int number )
{
    int result = 1;

    for (int index = 0; index < number; ++index)
        result *= (index + 1);

    return result;
}

int Factorial2(int number)       //stack overflow is when a call runs out of space after being called too much
{
    if (number <= 1)        //stops the wrap around of the int type...
        return 1;

    return number * Factorial2(number - 1);     //recursive -- 3! (factorial) is equal to 3 * 2!
}

void DisplayTruthTable()
{
    cout << " A " << " B " << " && " << " || " << endl;

    //Conditional Operator
    // ::= Eb ? Et : Ef
    //False, False
    cout << false << false << (false && false ? "true" : "False") << (false || false ? "true" : "False") << endl;
    //False, True
    cout << false << true << (false && true ? "true" : "False") << (false || true ? "true" : "False") << endl;
    //True, False
    cout << true << false << (true && false ? "true" : "False") << (true || false ? "true" : "False") << endl;
    //True, True
    cout << true << true << (true && true ? "true" : "False") << (true || true ? "true" : "False") << endl;
}

void PrefixPostfixDemo()
{
    int value;
    cout << "Enter a value: ";
    cin >> value;

    // prefix ++X => X = X + 1      increment before, stores it back into x
    // postfix X++                  stores X, increments after

    cout << value++ << " ";
    cout << ++value << " ";
    cout << value-- << " ";
    cout << --value << " " << endl;
}

bool IsLetter(char value)
{
    if((value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z')) //would use the integral values of the letters instead of a long switch
       return true;

    return false;
}

bool IsDigit(char value)
{
    switch (value)  //must be int (including char)
    {
        case '0':
        case '1':
        case '2':   //must be compatible with int type... and "run time const" (easy math or non compulation
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': return true;
    };

    return false;
}

string GetCharacterClass( char value )
{
    //Identify the char
    //  a...z letter
    //  0...9 digit
    //  * symbol
    if (IsDigit(value))
        return "Digit";
    else if (IsLetter(value))       //if you have another condition just use another else if until the last one...
        return "Letter";
    else
        return "Symbol";
}

void SwitchDemo()
{
    do
    {
        char input;
        cout << "Enter a character: ";
        cin >> input;

        cout << GetCharacterClass(input) << endl;
    } while (true);
}



int main()
{
   /* cout << Factorial(3) << " " << Factorial2(3) << endl;
    cout << Factorial(1) << " " << Factorial2(1) << endl;
    cout << Factorial(5) << " " << Factorial2(5) << endl;*/

    //DisplayTruthTable();

    //PrefixPostfixDemo();

    SwitchDemo();
}