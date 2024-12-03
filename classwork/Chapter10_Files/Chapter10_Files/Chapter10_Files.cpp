#include <iostream>
#include <fstream>  //include file info
#include <string>
#include <sstream>
using namespace std;

void WriteFileDemo()
{
    fstream outFile;                    //declaring variable with fstream type

// WINDOWS "C:\\temp\\log.txt"  never case sens
// UNIX "/usr/temp/log";        always case sense

//opening a file for writing
    outFile.open("log.txt", ios_base::out | ios_base::app);            //open operator lets us open a file   
    // variable.open(file name, ios_base::<flag(enum)>)
    /*In or out
     Trunc->truncate(gets rid of all previous info)
     App->append(add to the end of the file)
     Ate->append by default (used to arbitrarily move where you start writing)*/


    //bitwise combination:: flag1 | flag2

    string line;

    cout << "Enter the file contents: ";

    while (true)
    {
        getline(cin, line);
        if (line == "Q" || line == "q")
            break;

        //write to file                 //everything used with cin and cout can be used for files, like << fixed << setprecision(2) << endl.
        outFile << line << endl;        //uses the variable created to send values to file (using "line" that was input)
    }
}

void ReadFileDemo()
{
    fstream inFile;

    inFile.open("log.txt", ios_base::in); //opening file for reading

    while (!inFile.eof())   //eof function returns true at end of file, only makes sense on input files
    {
        string line;
        getline(inFile, line);

        cout << line << endl;
    }
}

void Display(fstream& output, string const& message)     //streams must always be pass by ref! will compiler error if not
{
    output << message;      //file gets that message

    cout << message;        //user sees message
}
void LogOutputDemo()
{
    fstream logFile;

    logFile.open("output.txt", ios_base::out | ios_base::trunc);

    Display(logFile, "Enter your name: \n");    //passing file, just like getline you pass the stream first (getline(cin, variable))
    //cout << "Enter your name: ";
    
    string name;
    getline(cin, name);

    stringstream msg;

    msg << "Hello " << name << endl;    //allows writing to files with same syntax of cout and now it takes strings (using stringstream)

    Display(logFile, msg.str());        //used to build up complicated strings, especially with bounds (mins and maxs)
    /*Display(logFile, "Hello ");
    Display(logFile, name);
    Display(logFile, "\n");*/       //string way

    //cout << "Hello " << name << endl;
}

int main()
{
    //WriteFileDemo();
    //ReadFileDemo();
    LogOutputDemo();
}