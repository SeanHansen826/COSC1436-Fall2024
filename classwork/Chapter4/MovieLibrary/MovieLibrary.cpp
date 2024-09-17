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

    /////Display movie details
    cout << "------------" << endl;
    cout << movie.Title << endl;
}
