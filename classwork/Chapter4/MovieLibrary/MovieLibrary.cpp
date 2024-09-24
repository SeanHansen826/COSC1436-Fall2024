#include <iostream>
#include<iomanip>
#include<string>

using namespace std;

//Movie: Title, Actors, Run length, Description, Genres, Director(s), Release Year, MPAA Rating
struct Movie
{
    // Required
    string Title;

    // At Least 0
    int RunLength;

    //Optional
    string Description;

    // >= 1900
    int ReleaseYear;

    bool IsClassic;

};

//Int data types with named values, technically writing your own primitive type
enum MenuCommand
{
    MC_AddMpvie,
    MC_EditMovie,
    MC_DeleteMovie,
    MC_ViewMovie

};
int main()
{
        
    //Decision making - IF statement
    // if-statement :: 


 
    ////Relational demo
    ////  rel_operand :: < <= > >= == !=
    ////  rel_expression :: E - Rel_op = outputs boolean
    ////int left, right;
    //string left, right;
    //cout << "enter a left and right value: ";
    //cin >> left >> right;

    ////Mangle the values ( be aware of epsilon // rounding errors )
    ////  Do not use == equality floating point values to avoidrounding errors
    ////  except when comparing floating point value to an integral (e.g. f == 45) 
    ////      due to you not expecting two seperate decimal point value
    ////left = (left * 21) / 21;
    ////right = (right * 15) / 15;

    ////bool areEqual = left = right == 20;
    ////  tip ( 20 == left ) by doing this it will call a compiler error if you forget an equal sign and accidentally assign them!

    ////String comparison for case insensitive
    ////  _strcmpi() asks for two strings, and gives out an int
    ////  _strcmpi(str,str) = int
    ////      left < right <0
    ////      left == right 0
    ////      left > right >0
    ////          string.c_str() allows C to understand C++ strings
    ////  You typically want to compare strings while being case insenstive (_strcmpi())
    //cout << left << " ciequal " << right << " = " << _strcmpi(left.c_str(), right.c_str()) << endl;
    //
    //cout << left << " == " << right << " = " << (left == right) << endl;
    //cout << left << " < " << right << " = " << (left < right) << endl;
    //cout << left << " <= " << right << " = " << (left <= right) << endl;
    //cout << left << " > " << right << " = " << (left > right) << endl;
    //cout << left << " >= " << right << " = " << (left >= right) << endl;
    //cout << left << " != " << right << " = " << (left != right) << endl;


    /////Add a new movie
    //create a new movie

    //show menu

    cout << "Movie Library" << endl;
    cout << "---------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;

    char input;
    cin >> input;

    //we should try and seperate input validation and core functions:

    //used MenuCommand enum, with variable menuCommand
    MenuCommand menuCommand;

    switch (input)
    {
        case 'A':
        case 'a': menuCommand = 1; break;

        case 'E':
        case 'e': menuCommand = 2; break;

        case 'D':
        case 'd': menuCommand = 3; break;

        case 'V':
        case 'v': menuCommand = 4; break;

        default: cout << "Bad input" << endl; break;
    };


    //Handle Menu Command using enum
    switch (menuCommand)
    {
        case MenuCommand::MC_AddMpvie:
        case MenuCommand::MC_EditMovie:
        case MenuCommand::MC_DeleteMovie:
        case MenuCommand::MC_ViewMovie: cout << "Not Implemented" << endl; break;
    };

    Movie movie; //= {0};

    //Get required Title
    cout << "Enter a title: ";
    getline(cin, movie.Title);

    //When using an If statement, the sentence that is conditional should be indented

    if (movie.Title == "")
    {
        cout << "ERROR: Title is required" << endl;
        cout << "Enter a title: ";
        getline(cin, movie.Title);
    };

    //Get run length, at least 0 minutes
    cout << "Enter run legth (in minutes): ";
    cin >> movie.RunLength;

    if (movie.RunLength <= 0)
    {
        //Look at additional stuff (example)
        //      try and avoid nested if's, if else ifs are alright, but nested ifs can be a pain to read.

        //  Nested Ifs :::
        //      if (condition 1){
        //          {
        //          If (condition 2)
        //          }
        //                  Statement if 1&2 are true
        //      }else
        //              statement if else
        // 
        //  Else Rules ... Elses always go withthe immediately preceding If statement !!!
        //  Try and put {} around the else if combo you want, if else needs to go with if (cond 1) then replicate code


        //LOGICAL OPERATORS
        // && = and     --  if the left operand is true, expression is true. same for false
        // || = or      --  inverse of &&
        // !  = not     --  

        //  Truth Table

        if (movie.RunLength < 0 || movie.RunLength > 1440)
        {
            cout << "ERROR: Run length must be between 0 and 1440" << endl;

            cout << "Enter run length (in minutes): ";
            cin >> movie.RunLength;
        };
        //The || removes the need for this extra else...
    //} else if (movie.RunLength > 1440)
    //{
    //    cout << "ERROR: Run length cannot be greater than a day" << endl;

    //    cout << "Enter run length (in minutes): ";
    //    cin >> movie.RunLength;
    };

    cout << "Enter release year (1900+): ";
    cin >> movie.ReleaseYear;

    if (movie.ReleaseYear <= 1900 || movie.ReleaseYear > 2100)
    {
        cout << "ERROR: Release year must be between 1900 and 2100" << endl;

        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;
    };


    //  Get optional description
    cout << "Enter optional description: ";
    cin.ignore(); //May fix cin problems when mixing an matching cin with getline or equivalent...
    getline(cin, movie.Description);

    //  Get IsClassic
    char isClassic;
    cout << "Is this a Classic (Y/N)?";
    cin >> isClassic;

    //  for either or expression, you don't want to ask uneccessary questions and waste processing time.
    //      Else statement
    //          only use when you need to make a choice
    //if (isClassic == 'Y')
        //movie.IsClassic = true;
    //else
        //movie.IsClassic = false;
    //  If Else If ... if (condition 1)
    //                      statement 1
    //                 else if (condition 2)
    //                      statement 2
    //                  else if etc. etc. etc.
    //  This is useful to get out of the If command group once it's come to a decision already, not running irrelevant code.

/*    if (isClassic == 'Y')
        movie.IsClassic = true;
    else if (isClassic == 'y')
        movie.IsClassic = false;
    else if (isClassic == 'N')
        movie.IsClassic = true;
    else if (isClassic == 'n')
        movie.IsClassic = false;
    else  */                              //this last line is meant to handle anything other than the described inputs ... aka "t" "f" ...

    //Using the Logical operators we now reduced the lines of code and computation time.
    
    //if (isClassic == 'Y' || isClassic == 'y')
    //    movie.IsClassic = true;
    //else if (isClassic == 'N' || isClassic == 'n');
    //else
    //{
    //    cout << "ERROR: You must enter Y or N ";

    //    cout << "Is this a classic (Y/N)? ";
    //    cin >> isClassic;
    //};

    //          SWITCH 
    // 
    // switch select statement - replacement for if-elseif where same expression compared to multiple values
    // 1. Must compare single expression to one or more constant values with equality
    // 2. Switch Expression must be integral type (char counts) (no strings!)
    // 3. Each case label must be a compile-time constant expression
    //          can only be something that isn't defined during run time
    //          can have an expression as long as it is during compile time not run time.
    // 4. Each case label must be unique (no duplicates)
    // Switch (E)
    // {
    //      case-statement*
    // }
    // case statement -- case expression : statement
    //during run time, it finds if something's case label is equal, and then finds it in the list of possibilities, ignoring the others!!!
    //NIGHT AND DAY PERFORMANCE DIFFERENCE
    //violates the single statement, includes the Break; statement tacked onto the finished statement.

    //Default executes if nothing matches the cases. (make sure it's last!)

    //to get switches to break out of the fallthrough, use breaks! mostly used in loops but can be used inside of switches as well...

    switch (isClassic)
    {
        case 'Y': movie.IsClassic = true; break;
        case 'y': movie.IsClassic = true; break;

        case 'N': movie.IsClassic = false; break;
        case 'n': movie.IsClassic = false; break;

        default:
        {
            cout << "ERROR: You must enter Y or N ";

            cout << "Is this a classic (Y/N)? ";
            cin >> isClassic;
        };;
    };

    //if (isClassic == 'Y' || isClassic == 'y')
    //    movie.IsClassic = true;
    //else if (isClassic == 'N' || isClassic == 'n');
    //else
    //{
    //    cout << "ERROR: You must enter Y or N ";

    //    cout << "Is this a classic (Y/N)? ";
    //    cin >> isClassic;
    //};

   
    /*
        if (movie.IsClassic)
            cout << "Is Classic? Yes" << endl;
        else
            cout << "Is Classic? No" << endl;
    */
    /////Display movie details
    cout << "------------" << endl;
    cout << movie.Title << " (" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;
    
    // Better form but still long --
    //string classicIndicator;
    ///*if (movie, isClassic)
    //    classicIndicator = "Yes";
    //else
    //    classicIndicator = "No";

    //CONDITIONAL --   :
    //  E bool ? E : E
    //  if bool is true, it is the first value of the expression after the q mark
    //  if bool false, it is the last value after q mark.
    //      conditionals are for choosing one of two possible values, not for printing something out!
    //      the compiler converts this expression to an if statement

    //string classicIndictor = movie.IsClassic ? "Yes" : "No";
    //cout << "Is Classic? " << classicIndicator << endl;

    //              CONDITIONAL OPERATORS Ebool ? Et : Ef
    // 
    //may work without parens, but with them the cout cunfuses the compiler
    //E true & E False = Must be the exact same type, Type coercion is not possible. USE STATIC CAST
    //  This is true becuase during run time the compiler must know the type, this command happens during the run!
    cout << "Is Classic? " << (movie.IsClassic ? "Yes" : "No") << endl;




    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "------------" << endl;
}
