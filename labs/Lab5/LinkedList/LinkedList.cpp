//  Linked List
//  Sean Hansen
//  COSC-1436-20005

#include <iostream>
#include <iomanip>;
using namespace std;

/// @brief Node stores pointers to values with beginning and end points in memory
struct Node
{
    int value = 0;
    Node * Next = nullptr;
};

/// @brief LinkedList stores nodes
struct LinkedList
{
    Node * Head = nullptr;      //when using this, use pass by ref or mem. addresses
};

void DisplayHeader()
{
    cout << right << setw(27) << setfill('.') << "" << setfill(' ') << endl;
    cout << setw(10) << "Project: " << "Linked List\n" << setw(10) << "By: " << "Sean Hansen\n" << setw(10) << "Class: " << "COSC-1436-20005\n";
    cout << setw(27) << setfill('.') << "" << setfill(' ') << endl << endl;
};

void AddToList()
{
    int input;
    int validInput;

        cout << "Enter a Value: ";
        cin >> input;

        //if (isdigit(input) == true)
        //{
        //    validInput = input;
        //    isValidated = true;
        //    break;
        //}
        //else
        //{
        //    cout << left << setfill('=') << setw(35) << "" << setfill(' ') << endl;
        //    cout << "ERROR: Must input a valid integer" << endl;
        //    cout << left << setfill('=') << setw(35) << "" << setfill(' ') << endl << endl;
        //}
        
}

bool DisplayMenu()
{
    char menuInput;
    bool done = false;
    bool quit = false;

    cout << left << setfill('-') << setw(20) << "" << setfill(' ') << endl;
    cout << left << setw(20) << "Q) uit" << endl;
    cout << left << setw(20) << "A) dd" << endl;
    cout << left << setfill('-') << setw(20) << "" << setfill(' ') << endl;

    do
    {
        cout << "Selection: ";
        cin >> menuInput;
        cout << endl;

        switch (menuInput)
        {
            case 'Q':
            case 'q': quit = true; done = true; break;

            case 'A':
            case 'a': AddToList(); done = true; break;

            default:
            {
                cout << left << setfill('=') << setw(35) << "" << setfill(' ') << endl;
                cout << "ERROR: Must input a valid chracter" << endl;
                cout << left << setfill('=') << setw(35) << "" << setfill(' ') << endl << endl;
            }
        }
    } while (done == false);

    return quit;
}

int main()
{
    DisplayHeader();

    bool quit = false;
    while(true)
    {
        quit = DisplayMenu();
        if (quit == true)
            break;
    }
}