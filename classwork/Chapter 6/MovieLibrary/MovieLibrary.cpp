#include <iostream>
#include<iomanip>
#include<string>

using namespace std;
using std::cout;
using std::cin;

//functions = module that calculates a value
//procedure = module that does something
//subroutine = wrapper term for modules
// 
//c++ refers to all (modules) as functions ...
//
//

struct Movie
{
    string Title;

    int RunLength = 0;

    string Description;

    int ReleaseYear = 0;

    bool IsClassic = 0;

    string Genre;
};

enum MenuCommand
{   
    AddMovie = 1,
    EditMovie,
    DeleteMovie,
    ViewMovie,
};

//// Function Definition
// type identification ()
// {
//      statement*
// }

////Function Definition
// decleration =    Declares existance of something & what it is (var decleration :: int input)
//                  Used by compiler to recognize the use of the identifier
//                  Must be declared before usage
// 
// definition =     what it does (made for the linker : point after the compiler ... makes troubleshooting difficult)
//                  compilers just look for decleration not definitions, therefore the linker will be looking for the definition
//                  (Variable : scope or point where var is defined) 
//                  (Function : everything in the curlyg braces of a function)

// Name functions as actions / verbs ... (get ... display ... call ...)
//      Casing : Pascal Casing
// 
// Every function should have a Commented Header
//      Versions
//      Doxygen
//      Microsoft (default) -- change this!
//

/// @brief Displays main menu
void DisplayMenu()
{
    cout << "Movie Library" << endl;
    cout << "---------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;
}

/// @brief Handles the menu selection
void HandleMenu()
{
    //HACK: Fix this
    MenuCommand menuCommand = static_cast<MenuCommand>(0);
    switch (menuCommand)
    {
        case MenuCommand::AddMovie:
        case MenuCommand::EditMovie:
        case MenuCommand::DeleteMovie:
        case MenuCommand::ViewMovie: cout << "Not Implemented" << endl; break;
    };
}

int main()
{
    //Function call = id();
    DisplayMenu();

    MenuCommand menuCommand = static_cast<MenuCommand>(0);

    //// Get Input
    do     
    {
        char input;
        cin >> input;

        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::AddMovie; break;

            case 'E':
            case 'e': menuCommand = MenuCommand::EditMovie; break;

            case 'D':
            case 'd': menuCommand = MenuCommand::DeleteMovie; break;

            case 'V':
            case 'v': menuCommand = MenuCommand::ViewMovie; break;

            default: cout << "Bad input" << endl; break;
        };
    } while (menuCommand == 0);
    cin.ignore();

    //// Handle menu command
    HandleMenu();
    //switch (menuCommand)
    //{
    //    case MenuCommand::AddMovie:
    //    case MenuCommand::EditMovie:
    //    case MenuCommand::DeleteMovie:
    //    case MenuCommand::ViewMovie: cout << "Not Implemented" << endl; break;
    //};
    
    Movie movie;

    //// Get title
    do
    {
        cout << "Enter a title: ";
        getline(cin, movie.Title);

        if (movie.Title == "")

            cout << "ERROR: Title is required" << endl;
    } while (movie.Title == "");

    //// Get run length
    do
    {
        cout << "Enter run legth (in minutes): ";
        cin >> movie.RunLength;

            if (movie.RunLength < 0 || movie.RunLength > 1440)
            {
                cout << "ERROR: Run length must be between 0 and 1440" << endl;
            };
    } while (movie.RunLength < 0 || movie.RunLength > 1440);

    //// Get year
    do
    {
        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;

        if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
        {
            cout << "ERROR: Release year must be between 1900 and 2100" << endl;
        };
    } while (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100);

    //// Get optional description
    cout << "Enter optional description: ";
    cin.ignore();
    getline(cin, movie.Description);

    //// Get isClassic
    bool done = false;
    while (!done)
    {
        char isClassic;
        cout << "Is this a Classic (Y/N)?";
        cin >> isClassic;

        switch (isClassic)
        {
            case 'Y': 
            case 'y': movie.IsClassic = true;  done = true; break;

            case 'N': 
            case 'n': movie.IsClassic = false; done = true; break;

            default:
            {
                cout << "ERROR: You must enter Y or N ";
            };
        };
    }
    cin.ignore();

    //// Get genre
    for (int index = 0; index < 5; ++index)
    {
        cout << "Enter optional genre " << (index + 1) << ": ";

        string genre;
        getline(cin, genre);
        if (genre == "")
            break;

        movie.Genre += genre + ", ";
    };

    //// Display library
    cout << "------------" << endl;
    cout << movie.Title << " (" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;
    
    cout << "Is Classic? " << (movie.IsClassic ? "Yes" : "No") << endl;
    if (movie.Genre != "")
        cout << "Genre(s) " << movie.Genre << endl;
    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "------------" << endl;
}