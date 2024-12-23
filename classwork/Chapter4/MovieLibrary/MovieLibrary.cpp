#include <iostream>
#include<iomanip>
#include<string>

using namespace std;
using std::cout;
using std::cin;

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

    string Genre;
};

//Most enums are just strongly typed integers ... in c++ you can use a new syntax is used to create a new type altogether.
//      you can add "class" to your enum initializer with more strongly typed rules about it -- now become scoped in your enum, not whole prgrm
//Int data types with named values, technically writing your own primitive type
//const int MenuCommand::MC_AddMovie = 0
enum MenuCommand
{
    //Begin,   //begin and end enums can be useful to range check your enum using if (>begin && <end)
    AddMovie = 1,    //beginning value is default 0, 1, 2, 3 ... if you set one beginning value, the rest will incrementally assign
    EditMovie,
    DeleteMovie,
    ViewMovie,
    //End
};

//  not scoped to enum, all enum variables can be used for the entire program... can get around by creating an acronym for your new enum variable
//enum class TestEnum
//{
//    TE_AddMovie
//};
//TestEnum testValue = TE_AddMovie;//TestEnum::MC_AddMovie;       you can leave off your enumerated type, comes from C

int main()
{

    //nested loop demo
    //int iterations = 0;
    //for (int i = 0; i < 100; ++i)
    //{
    //    }
    //    for (int j = 0; j < 100; ++j)
    //    {
    //        ++iterations; //will execute 1000 times if not careful
    //        cout << i << ", " << j << " = " << iterations << endl;

    //        if (iterations % 100 == 0) // modulus is remainder ... 100 has no remainder therefore ....
    //        {
    //            char choice;
    //            cout << "do you want to give up?";
    //            cin >> choice;
    //            if (choice == 'Y' || choice == 'y')
    //                break;      //this break would only take you out of the current nested loop, not all
    //    };
    //    cout << "Total iterations = " << iterations << endl;
    //}
        
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

    /// Get input
    //while command wraps everything involved in a block!
    //  Pretest Loop! statement executes 0 or more times... only  executes if it is true.
    MenuCommand menuCommand = static_cast<MenuCommand>(0);
    //bool done = false;
    //while (!done)

    //INFINITE LOOPS
    //always make sure you do NOT have a semicolon after a while command is true
    // ex)  while (menuCommand == 0);    note the semicolon. since it is always true it will never stop looping.


    //do while loop -- Post Test Loop
    // executes statement, then determines whether or not to run again!
    // 
    //  do
    // {
    //      statement
    // } while (expression)
    //

    do     
    {
        char input;
        cin >> input;

        //we should try and seperate input validation and core functions:

        //used MenuCommand enum, with variable menuCommand

        //cannot take int and assign it to an enum type... change it to the actual enum instead of any values
        //while loop is useful if you need to continue looping
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

    //int shouldntWork = MenuCommand::MC_AddMovie;
    //menuCommand = static_cast<MenuCommand>(1);


    //Handle Menu Command using enum
    //when using enum, call to it with ::
    switch (menuCommand)
    {
        case MenuCommand::AddMovie:
        case MenuCommand::EditMovie:
        case MenuCommand::DeleteMovie:
        case MenuCommand::ViewMovie: cout << "Not Implemented" << endl; break;
    };

            //Looping Operators
        //-----------------
        //  x++  |  prefix increment    |   sets x = x + 1  | stores original value and returns that    
        //  ++x  |  postfix increment   |   sets x = x + 1  |
        //  x--  |  prefix decrement    |   sets x = x - 1  |
        //  --x  |  postfix decrement   |   sets x = x - 1  |

        // example  x = 10
        // cout << x++ << x
        // grabs original value, uses that as the value of x++ (x++ is equal to 10 in the equation) but when we cout the variable x, it shows 11 which isthe side effect

        // example  x = 10
        // cout << ++x << x
        //  grabs original value, does the increment, stores ++x as 11, and cout is 11

        // post fix gives us the unmodified variable in the postfixed slot, side effect is the new variable value is incremented.
        // pre fix gives us the modified variable in the pre fixed slot, and cout the new variable with the increment.
    
    Movie movie; //= {0};

    //Get required Title
    do
    {
        cout << "Enter a title: ";
        getline(cin, movie.Title);

        //When using an If statement, the sentence that is conditional should be indented


        if (movie.Title == "")

            cout << "ERROR: Title is required" << endl;
    } while (movie.Title == "");

    //Get run length, at least 0 minutes
    //movie.RunLength = -1;        //not recommended but makes sure the user it prompted the first time around!
    //while (movie.RunLength < 0 || movie.RunLength > 1440)
    do
    {
        cout << "Enter run legth (in minutes): ";
        cin >> movie.RunLength;
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
            //  Try and put {} around the else if combo you want, if else needs to go with if (cond 1) then replicate code/


            //LOGICAL OPERATORS
            // && = and     --  if the left operand is true, expression is true. same for false
            // || = or      --  inverse of &&
            // !  = not     --  

            //  Truth Table

            if (movie.RunLength < 0 || movie.RunLength > 1440)
            {
                cout << "ERROR: Run length must be between 0 and 1440" << endl;
            };
    } while (movie.RunLength < 0 || movie.RunLength > 1440);

        //The || removes the need for this extra else...
    //} else if (movie.RunLength > 1440)
    //{
    //    cout << "ERROR: Run length cannot be greater than a day" << endl;

    //    cout << "Enter run length (in minutes): ";
    //    cin >> movie.RunLength;
    
    //while (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
    do
    {
        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;

        if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
        {
            cout << "ERROR: Release year must be between 1900 and 2100" << endl;
        };
    } while (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100);

    //  Get optional description
    cout << "Enter optional description: ";
    cin.ignore(); //May fix cin problems when mixing an matching cin with getline or equivalent...
    getline(cin, movie.Description);

    //  Get IsClassic
    bool done = false;
    while (!done)
    {
        char isClassic;
        cout << "Is this a Classic (Y/N)?";
        cin >> isClassic;

        //  for either or expression, you don't want to ask uneccessary questions and waste processing time.
        //      Else statement
        //          only use when you need to make a choice
        //if (isClassic == 'Y')
        //    movie.IsClassic = true;
        //else
        //    movie.IsClassic = false;
        //  If Else If ... if (condition 1)
        //                      statement 1
        //                 else if (condition 2)
        //                      statement 2
        //                  else if etc. etc. etc.
        //  This is useful to get out of the If command group once it's come to a decision already, not running irrelevant code.

        if (isClassic == 'Y')
        {
            movie.IsClassic = true;
        }
        else if (isClassic == 'y')
            movie.IsClassic = false;
        else if (isClassic == 'N')
            movie.IsClassic = true;
        else if (isClassic == 'n')
            movie.IsClassic = false;
        else                                //this last line is meant to handle anything other than the described inputs ... aka "t" "f" ...

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

    //Get Genre
    //Get genre(s)
    //int genreCount = 0;
    //while (genreCount < 5) // starting from 0, using "less than" (instead of <=) so you iterate only 5 times instead of 6
    //{
    //    cout << "Enter optional genre " << (genreCount + 1) << ": "; //user sees 1 - 5 while we are coding with 0 - 4

    //    string genre;
    //    getline(cin, genre);
    //    if (genre != "")
    //    {
    //        movie.Genre += genre + ", ";
    //    }

    //    genreCount++; //postfix increment -- x changes to x+1 each time through
    //}


    //For Loop - designed to iterate a fixed number of times with a well known start and end
    //      compiler should know how many times it is going to run ... 
    //      while loops typically loop until it is no longer necesarry.

    //  For Loop Format -- for (init expression; test expression; e3)
    //                        single statement;   
    // init expresion evaluates before the for loop ...
    // test expression (condition) sees as long as it is true the for statement will loop
    // update expression evaulates the update expression

    //  For Loop is essentially ::
    //  initial expression
    //  while ( test expression )
    //  {
    //      statement
    //      update expression
    //  }
    //int genreIndex = 0; -- initializing your variable (Index) inside your "for" loop scopes it into the actual loop, you cannot accidentally use it elsewhere!
    for (int index = 0; index < 5; ++index)     // starting from 0, using "less than" (instead of <=) so you iterate only 5 times instead of 6
    {
        cout << "Enter optional genre " << (index + 1) << ": "; //user sees 1 - 5 while we are coding with 0 - 4

        string genre;
        getline(cin, genre);
        if (genre == "")
            break;  //exits loop, no update, no nothing ... just exits immediately! Do what you can to only break when you really need to
                    //use this instead of creating an imDone Variable or similar change...
        //continue;   //Loops only - stops current iteration and loops again (break here, restart loop)
        movie.Genre += genre + ", ";
    };

    ////More complex For Loops
    //for (int index = 0, int y = 1; index < 5 && index <y; ++index, y += 2) //only seperate your init expression or your update expression by commas, the conditional statement will only use the expression after the comma
    //{

    //};

    //int someIndex = 0
    //    for (;;) {}; // infinite loop !!! //can leave off parts of the expression, if there is no equation the update will infinitely check

   

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
    if (movie.Genre != "")
        cout << "Genre(s) " << movie.Genre << endl;
    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "------------" << endl;
}

// When Should we use which loops --- always ask yourself how many times you need to run the loop
// 
//            While                    Do-While                                    For
//  s         0 or more                 1 or more                                  0 or more
//  iter's    inf(++i or variable)      inf (++i or variable)                      fixed (initializer; test;)
// Breaks     Yes                       Yes                                        Yes
// post/pre    pre-test                 post-test                                  pre-test
//