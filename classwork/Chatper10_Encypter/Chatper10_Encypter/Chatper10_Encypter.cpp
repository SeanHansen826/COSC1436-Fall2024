#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string GetFilename(const char* message)
{
    cout << message;

    string filename;
    getline(cin, filename);

    return filename;
}

void Encrypt(fstream& input, fstream& output, char key)     //all streams (files) are passed by ref
{
    //Caesar cipher (additive cipher)

    //read next character
    while (!input.eof())
    {
        char ch;
        input.get(ch);

        //encrypt it
        ch += key;          //depending on overflow

        //write out
        output.put(ch);          //displays the value just called by get
    }                           //getfunction reads next character and reads it out
}

void GetInputFile(fstream& input)
{
    do
    {
        string inputFilename = GetFilename("Enter input file: ");

        input.open(inputFilename, ios_base::in);

        //ERROR checking functions
        // input.fail() -> true if failed otherwise false for last file opeation (checks for bad and other conditions, possibly recoverable as well)
        // input.bad() -> true if failed otherwise false for last file operation (catastrophic, means stream might be corrupt)
        // .goo() -> true if last file operation succeeded or false otherwise
        //if (!input.fail())
            //return;
        //if (input.good())
            //return;

        if (input.is_open())
            return;

        cout << " ERROR opening file" << endl;
    } while (true);
}

void GetoutputFile(fstream& output)
{
    do
    {
        string outputFilename = GetFilename("Enter output file: ");

        output.open(outputFilename, ios_base::out | ios_base::binary | ios_base::trunc);

        //ERROR checking functions
        // input.fail() -> true if failed otherwise false for last file opeation (checks for bad and other conditions, possibly recoverable as well)
        // input.bad() -> true if failed otherwise false for last file operation (catastrophic, means stream might be corrupt)
        // .goo() -> true if last file operation succeeded or false otherwise
        //if (!input.fail())
            //return;
        //if (input.good())
            //return;

        if (output.is_open())
            return;

        cout << " ERROR opening file" << endl;
    } while (true);
}

enum Direction
{
    EncryptMode,
    DecryptMode
};

Direction GetDirection()
{
    do
    {
        cout << "(E)ncrypt or (D)ecrypt? ";

        char ch;
        cin >> ch;
        switch (ch)
        {
            case 'E':
            case 'e': return Direction::EncryptMode;

            case 'D':
            case 'd': return Direction::DecryptMode;
        }

        cout << "ERROR:: Bad Input" << endl;
    } while (true);
}

void Decrypt(fstream& input, fstream& output, char key)     //all streams (files) are passed by ref
{
    //Caesar cipher (additive cipher)

    //read next character
    while (!input.eof())
    {
        char ch;
        input.get(ch);

        //resets error state of a stream        (if you've read past readable text in a txt file, input.get will not be able to be compile again in that instance, this allows you to try again but doesn't fix it)
        input.clear();

        //dencrypt it
        ch -= key;          

        //write out
        output.put(ch);          
    }                           
}

int main()
{
    //get input/output files with helper function
    //string inputFilename= GetFilename("Enter input file: ");
    

    //open input file for reading, output file for writing
    fstream inputFile;
    //inputFile.open(inputFilename, ios_base::in);
    GetInputFile(inputFile);

    //open output file
    //string outputFilename = GetFilename("Enter output file: ");
    //outputFile.open(outputFilename, ios_base::out | ios_base::trunc | ios_base::binary);
    fstream outputFile;
    GetoutputFile(outputFile);

    Direction mode = GetDirection();
    switch (mode)
    {
        case Direction::EncryptMode: Encrypt(inputFile, outputFile, 56); break;
        case Direction::DecryptMode: Decrypt(inputFile, outputFile, 56); break;
    }
    
    Encrypt(inputFile, outputFile, 56);
}