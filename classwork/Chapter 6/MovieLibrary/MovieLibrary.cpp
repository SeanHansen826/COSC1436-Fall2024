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
    MC_AddMovie = 1,
    MC_EditMovie,
    MC_DeleteMovie,
    MC_ViewMovie,
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

MenuCommand g_menuCommand = static_cast<MenuCommand>(0);    //BIG NO-NO, GLOBAL VARIABLE CHEAT
Movie g_movie;                                              //BIG NO-NO, GLOBAL VARIABLE CHEAT


string ReadString(string message, bool isRequired)
{
    string input;
    do
    {
        cout << message;
        getline(cin, input);

        if (isRequired && input == "")
            cout << "ERROR: Value is required" << endl;
    } while (isRequired && input == "");

    return input;
}

/// @brief Reads a string from input
/// @param message Message to display
/// @return Input from user
string ReadString(string message)
{
    return ReadString(message, false);
};

/// @brief Adds the movie
void AddMovie()
{
    Movie movie;

    //// Get title
    movie.Title = ReadString("Enter a title: ");

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
    cin.ignore();
    movie.Description = ReadString("Enter optional description: ");

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
        string genre = ReadString("Enter optional genre ");
        //cout << "Enter optional genre " << (index + 1) << ": ";

        //string genre;
        //getline(cin, genre);
        if (genre == "")
            break;

        movie.Genre += genre + ", ";
    };

    //HACK: Don't do this
    g_movie = movie;
};

/// @brief Edits the movie
void EditMovie()
{
    cout << "EditMovie";
};

/// @brief Deletes the movie
void DeleteMovie()
{
    cout << "DeleteMovie";
};

/// @brief Views the movie
void ViewMovie ( Movie movie )
{
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
};

/// @brief Displays main menu
void DisplayMenu()
{
    cout << "Movie Library" << endl;
    cout << "--------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;

    MenuCommand menuCommand = static_cast<MenuCommand>(0);
    do
    {
        char input;
        cin >> input;

        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::MC_AddMovie; break;
                                                 
            case 'E':                            
            case 'e': menuCommand = MenuCommand::MC_EditMovie; break;
                                                 
            case 'D':                            
            case 'd': menuCommand = MenuCommand::MC_DeleteMovie; break;
                                                 
            case 'V':                            
            case 'v': menuCommand = MenuCommand::MC_ViewMovie; break;

            default: cout << "Bad input" << endl; break;
        };
    } while (menuCommand == 0);
    cin.ignore();

    //HACK
    g_menuCommand = menuCommand;
}

//Parameter ::= data used inside function

//  parameter kind  (pass-by value)
//      input = read in function (can write but will have no impact on caller)  -- any valid expression/type -- creates a copy of the argument being given
//      output = writes, caller has no input                                    -- return type(s)            --
//      input/output =
//
/// @brief Handles the menu selection
/// @param menuCommand The command to handle
void HandleMenu(MenuCommand menuCommand)
{
    switch (menuCommand)
    {
        case MenuCommand::MC_AddMovie: AddMovie(); break;
        case MenuCommand::MC_EditMovie: EditMovie(); break;
        case MenuCommand::MC_DeleteMovie: DeleteMovie(); break;
        case MenuCommand::MC_ViewMovie: ViewMovie(g_movie); break;     //HACK
    };
}

int main()
{
    do
    {
    //Function call = id();
        DisplayMenu();

        //argument ::= data (expression) passed to a function
        //using the variable name works as an expression ... passes variable assignment to function (right side of =)
        HandleMenu(g_menuCommand);      //HACK
    } while (true);
}