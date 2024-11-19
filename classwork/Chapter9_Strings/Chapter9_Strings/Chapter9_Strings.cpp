#include <iostream>
#include <iomanip>
#include<string>
#include<cctype>    //chartypes functions from C

using namespace std;

//Character sets - maps numeric values to characters
//  ascii (7 bit) 0-127
//  ansi (1 byte) 0-255
//  mbcs (1-4 multibyte character set) - for localization
//      Each byte has to be examined to determin if subsequent bytes are needed for full char
//  unicode (2 bytes, windows, or 4 bytes) - asll languages in world (Wchar_t)

bool IsIdentifier(char input)
{
    return isalnum(input) || input == '_';
}

bool IsIntegral(string const& value)
{
    //for (int index = 0; index < value.length(); ++ index)
    for (char ch : value)   //compiler rewrites this to full version
        if (!isdigit(ch))
            return false;
}

bool IsValideIdentifier(string const& value)
{
    for (char ch : value)
        if (!isalnum(ch) && ch != '_')
            return false;

    return true;
}

void StringDemo()
{
    while (true)
    {
        string input;
        cout << "Enter a value: ";
        getline(cin, input);

        cout << "Integer = " << IsIntegral(input) << endl;
        cout << "Identifier = " << IsValideIdentifier(input) << endl;
    }
}

void CharDemo()
{
    while (true)
    {
        char input;
        cout << "Enter a character: ";
        cin >> input;

        //Classification :: int func ( int ) --- C functions so C Functions don't work with Char!
        // isalpha - true if letter, false otherwise
        // isalpha - true if digit, false otherwise
        // isalnum - true if digit, false otherwise
        // islower - true if lower case, false otherwise
        // isupper - true if upper case, false otherwise
        // isspace - true if space (white), false otherwise

        cout << "Alpha = " << setw(4) << (isalpha(input) ? 'Y' : 'N') << endl;

        cout << "Digit = " << setw(4) << (isdigit(input) ? 'Y' : 'N') << endl;

        cout << "Alnum = " << setw(4) << (isalnum(input) ? 'Y' : 'N') << endl;

        cout << "Lower = " << setw(4) << (islower(input) ? 'Y' : 'N') << endl;

        cout << "Upper = " << setw(4) << (isupper(input) ? 'Y' : 'N') << endl;

        cout << "Space = " << setw(4) << (isspace(input) ? 'Y' : 'N') << endl;

        cout << "ID =" << setw(4) << (IsIdentifier(input) ? 'Y' : 'N') << endl;

        //Conversion :: int func ( int ) 
        cout << "Lower = " << tolower(input) << endl; //converts to lower case
        cout << "Upper = " << toupper(input) << endl; //converts to upper case
    }
}

void WideCharDemo()
{
    while (true)
    {
        wchar_t input;
        cout << "Enter a character: ";
        wcin >> input;

        //Classification :: int func ( int ) --- C functions so C Functions don't work with Char!
        // isalpha - true if letter, false otherwise
        // isalpha - true if digit, false otherwise
        // isalnum - true if digit, false otherwise
        // islower - true if lower case, false otherwise
        // isupper - true if upper case, false otherwise
        // isspace - true if space (white), false otherwise

        cout << "Alpha = " << setw(4) << (iswalpha(input) ? 'Y' : 'N') << endl; //ALL GET (isWalpha)

        cout << "Digit = " << setw(4) << (iswdigit(input) ? 'Y' : 'N') << endl;

        cout << "Alnum = " << setw(4) << (iswalnum(input) ? 'Y' : 'N') << endl;

        cout << "Lower = " << setw(4) << (iswlower(input) ? 'Y' : 'N') << endl;

        cout << "Upper = " << setw(4) << (iswupper(input) ? 'Y' : 'N') << endl;

        cout << "Space = " << setw(4) << (iswspace(input) ? 'Y' : 'N') << endl;

        //cout << "ID =" << setw(4) << (IsIdentifier(input) ? 'Y' : 'N') << endl;

        //Conversion :: int func ( int ) 
        cout << "Lower = " << towlower(input) << endl; //converts to lower case
        cout << "Upper = " << towupper(input) << endl; //converts to upper case
    }
}

int main()
{
    //CharDemo();
    WideCharDemo();

    //StringDemo();   //would typically be impelemented by a library
}
