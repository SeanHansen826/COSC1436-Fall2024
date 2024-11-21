#include <iostream>
#include <iomanip>
#include<string>
#include<cctype>    //chartypes functions from C

using namespace std;

//Character sets - maps numeric values to characters
//  ascii (7 bit) 0-127
//  ansi (1 byte) 0-255 *** will be using! if only english
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

//"C" string
//C++ string only works in C++
// #include <cstring> if not working
//  strlen(const char*) size_t == returns number of characters
void CStringDemo()
{
    //const char* name = "Bob"; //const char* becaue strings are compile constants (4bytes including the null)
    //char nameArray[] = "Bob"; //identical

    //const int MaximumName = 100 + 1; //+1 accounts for the NULL
    //char buffer[MaximumName] = {0};   //array is just a pointer! zero initializing the array


    //cout << "Enter first name: ";
    //cin >> buffer;  //works but doesn't support bounds checking, if you make a input with 110 char, it will over-write by 10

    ////string length, takes (char*) => (size_t) null doesn't count
    //int len = strlen(buffer);
    //buffer[len++] = ' ';    //makes the element after your string, adds a space, then adds the space back into the size of the len

    //cout << "Enter last name: ";

    
    ////cin >> buffer[len];       only gives us the char, using the & op we get the memory address and can see the actual total val
    //cin >> &buffer[len];
    //cout << buffer;


    /*------------------Previous Code--------------------*/



    const char* name = "Bob"; //const char* becaue strings are compile constants (4bytes including the null)
    char nameArray[] = "Bob"; //identical

    const int MaximumName = 100 + 1; //+1 accounts for the NULL
    char buffer[MaximumName] = {0};   //array is just a pointer! zero initializing the array

    char firstName[MaximumName] = {0};
    cout << "Enter first name: ";
    cin >> buffer;  //works but doesn't support bounds checking, if you make a input with 110 char, it will over-write by 10

    //string length, takes (char*) => (size_t) null doesn't count
    int len = strlen(buffer);
    buffer[len++] = ' ';    //makes the element after your string, adds a space, then adds the space back into the size of the len

    cout << "Enter last name: ";
    
    char lastName[MaximumName] = {0};
    //cin >> buffer[len];       only gives us the char, using the & op we get the memory address and can see the actual total val
    cin >> &buffer[len];
    cout << buffer;

    char fullName[MaximumName + MaximumName] = {0};

    //strcpy(fullName, firstName); //strcpy(char* , const char*) the first value is what you want to modify
                                 //stomps over any info on first value, continues reading value to be copied until null 0
                                 //Malicous, can be used poorly when there are size differences

    strncpy_s(fullName, firstName, MaximumName); //strncpy(char* , const char* , size) strncpy accepts the size

    strcat_s(fullName, " "); //concatenates strings together, this one adds a space after the first string
                           //strcat(char* , const char*) - first string with the null replaced by second string with null added at the end
                           //be wary of "off by one" errors

    strncat_s(fullName, lastName, MaximumName);

    cout << fullName << endl;


    //comparison
    //if (firstName == lastName);
    if (strncmp(firstName, lastName, MaximumName) == 0)    //if first name is equal to last name, returns 0 which is false, therefore negate the funct to get reverse
        cout << lastName << endl;
    else
        cout << fullName << endl;
            //string comparison
            //strcmp(const char* , const char*) returns an int, also has a n version (strncomp(const char* , const char*))
            // <0 = L<R
            // =0 = L=R
            // >0 = L>R

    //Find in string
    char productName[] = "Microsoft Windows 11";
    char operatingSystem[] = "Windows";

    char* pPos = strstr(productName, operatingSystem);
    if (pPos != nullptr)
        cout << pPos << endl;               //strstr(const char* const char*) => cc*
                                            //      (char* , char*) => char*
                                            // returns back pointer starting at the beggining of the string that makes sense according to whatever you searched (?)
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

void CPlusPlusStringDemo()
{
    string firstName;
    cout << "Enter first name: ";
    cin >> firstName;  

    string lastName;
    cout << "Enter last name: ";
    cin >> lastName;

    //char fullName[MaximumName + MaximumName] = {0};
    string fullName;

    //strncpy_s(fullName, firstName, MaximumName);
    fullName = firstName;

    //strcat_s(fullName, " "); 
    fullName += " ";

    //strncat_s(fullName, lastName, MaximumName);
    fullName += lastName;
    //  or -- fullName.append(lastName);
    //str.append(const char*) this appends the const char string to the originial string

    string middleName;
    cout << "Enter middle name: ";
    cin >> middleName;

    //Insert middle name
    //  first we need to find where to insert (c++)

    int index = fullName.find(" "); //finds the desired, returns the index, or -1 if doesn't find it    //equivalent of strstr()

    //Insert

    fullName.insert(index, middleName); //str.insert(index, string)     //equivalent to strcat(str+index)

    cout << fullName << endl;

    //Get last name
    string onlyLastName = fullName.substr(index + 1); //str.substr(index, [count]) returns string, can stop displaying ater a certain amount of elements.

    //Misc
    const char* pCString = fullName.c_str();                //return pointer to initial const buffer
    int len = fullName.length();                        //how many characters are in the array/string
    bool isEmpty = fullName.empty();                //true if empty, false otherwise
    fullName.clear();                               //Empties the string, useful as a similar to "new/delete" process
}

void NumberStringDemo()
{
    while (true)
    {
        char buffer[100] = {0};

        cout << "Enter a number: ";
        cin >> buffer;      //want to know if user entered a number


        //Conversion
        //  if no iostream, #include <cstdlib>
        //     atoi(const char*) int == Converts string to int (ansi(string) to Integer)
        //      serially walks through each element and adds it to the list while valid, and once invalid stops.
        //      ***NOT good for verification
        //     atol(const char*) long
        //     atof(const char*) double (floatingpoint, not float)
        
        //bool isNumber = isIntegral()
        int value = atoi(buffer);
        cout << "Value as int = " << value << endl;
    }
}

int main()
{
    //CharDemo();
    //WideCharDemo();
    //CStringDemo();'

    NumberStringDemo();

    //StringDemo();   //would typically be impelemented by a library
}
