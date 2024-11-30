//  Linked List
//  Sean Hansen
//  COSC-1436-20005

#include <iostream>
#include <iomanip>

using namespace std;

/// @brief Node stores pointers to values with beginning and end points in memory
struct Node
{
    int value = 0;
    Node * pNext = nullptr;
};

/// @brief LinkedList stores nodes
struct LinkedList
{
    Node * Head = nullptr;
};

/// @brief Displays project header information
void DisplayHeader()
{
    cout << right << setw(27) << setfill('.') << "" << setfill(' ') << endl;
    cout << setw(10) << "Project: " << "Linked List\n" << setw(10) << "By: " << "Sean Hansen\n" << setw(10) << "Class: " << "COSC-1436-20005\n";
    cout << setw(27) << setfill('.') << "" << setfill(' ') << endl << endl;
};

/// @brief Adds value to list
/// @param list passes LinkedList member access
void AddToList(LinkedList &list)
{
    Node * pNewNode = new Node;
    
    cout << "Enter a Value: ";
    cin >> pNewNode->value;
    pNewNode->pNext = nullptr;

    if(list.Head == nullptr)
        list.Head = pNewNode;
    else
    {
        Node * pCurrent = list.Head;

        while (pCurrent->pNext != nullptr)
            pCurrent = pCurrent->pNext;

        pCurrent->pNext = pNewNode;
    }
}

/// @brief Delets value from list
/// @param list passes LinkedList member access
void DeleteFromList(LinkedList &list)
{
    int toBeDeleted;
    cout << "Value to be deleted: ";
    cin >> toBeDeleted;

    if (list.Head == nullptr)
    {
        cout << "ERROR: List is empty\n";
        return;
    }

    Node * pCurrent = list.Head;
    Node * pPrevious = nullptr;

    if (pCurrent->value == toBeDeleted)
    {
        list.Head = pCurrent->pNext;
        delete pCurrent;
        cout << "Success\n";
        return;
    }

    while (pCurrent != nullptr && pCurrent->value != toBeDeleted)
    {
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    if (pCurrent == nullptr)
    {
        cout << "ERROR: No value match in list\n";
        return;
    }

    pPrevious->pNext = pCurrent->pNext;
    delete pCurrent;

    cout << "Successfully deleted " << toBeDeleted << endl;
}

/// @brief Clears entire list
/// @param list passes Linked list
void ClearList(LinkedList &list)
{
    char isConfirmedInput;
    cout << "This will clear ALL inputs from the list, are you sure (Y/N)? ";
    cin >> isConfirmedInput;

    if (isConfirmedInput == 'Y' || isConfirmedInput == 'y')
    {
        Node * pCurrent = list.Head;
        Node * pNext = nullptr;

        while (pCurrent != nullptr)
        {
            pNext = pCurrent->pNext;
            delete pCurrent;
            pCurrent = pNext;
        }

        list.Head = nullptr;
        cout << "Successfully cleared list\n";
    } 
    else
        cout << "Operation Cancelled\n";
}

/// @brief Prints entire list
/// @param list passes LinkedList member access
void PrintList(const LinkedList &list)
{
    Node * pCurrent = list.Head;
    int count = 1;

    cout << setfill('*') << setw(48) << "" << setfill(' ') << endl;

    while (pCurrent != nullptr && pCurrent->value % 10)
    {
        cout << setw(4) << pCurrent->value << " ";
        ++count;

        if ((count - 1) % 10 == 0)
            cout << endl;

        pCurrent = pCurrent->pNext;
    }

    if (count % 10 != 0)
        cout << endl;

    cout << setfill('*') << setw(48) << "" << setfill(' ') << endl;
}

/// @brief Displays main menu
/// @param list Passes LinkedList member access
/// @return quit, if true exits program
bool DisplayMenu(LinkedList &list)
{
    char menuInput;
    bool done = false;
    bool quit = false;

    cout << left << setfill('-') << setw(20) << "" << setfill(' ') << endl;
    cout << left << setw(20) << "A) dd" << endl;
    cout << left << setw(20) << "C) lear" << endl;
    cout << left << setw(20) << "D) elete" << endl;
    cout << left << setw(20) << "P) rint" << endl;
    cout << left << setw(20) << "Q) uit" << endl;
    cout << left << setfill('-') << setw(20) << "" << setfill(' ') << endl;

    do
    {
        cout << "Selection: ";
        cin >> menuInput;
        cout << endl;

        switch (menuInput)
        {
            case 'A':
            case 'a': AddToList(list); cout << endl; done = true; break;

            case 'C':
            case 'c': ClearList(list); cout << endl; done = true; break;

            case 'D':
            case 'd': DeleteFromList(list); cout << endl << endl; done = true; break;

            case 'P':
            case 'p': PrintList(list); cout << endl << endl; done = true; break;

            case 'Q':
            case 'q': quit = true; done = true; break;

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

    LinkedList list;

    bool quit = false;
    while(true)
    {
        quit = DisplayMenu(list);
        if (quit == true)
        {
            ClearList(list);
            break;
        }
    }
}