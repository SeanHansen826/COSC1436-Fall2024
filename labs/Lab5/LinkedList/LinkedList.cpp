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
    Node * Head = nullptr;                      //when using this, use pass by ref or mem. addresses
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
void AddToList(LinkedList &list)                //init &list means we can edit values by ref
{
    Node * pNewNode = new Node;                 //creates pNewNode dynamic mem address
    
    cout << "Enter a Value: ";
    cin >> pNewNode->value;                     //with -> it auto dereferences it to the value stored, not the mem adress
    pNewNode->pNext = nullptr;

    if(list.Head == nullptr)                    //checks for initial values
        list.Head = pNewNode;                   //sets as head (mem address)
    else
    {
        Node * pCurrent = list.Head;            //finds head of list, sets to current

        while (pCurrent->pNext != nullptr)      //loops through list until nullptr
            pCurrent = pCurrent->pNext;         //when !nullptr, sets to next (moving to next memory address in list)

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
        cout << "ERROR: List is empty\n";       //Handles empty list and gets out of function
        return;
    }

    Node * pCurrent = list.Head;
    Node * pPrevious = nullptr;                 //makes a second variable to step with during loop

    if (pCurrent->value == toBeDeleted)         //if deleted value is the head
    {
        list.Head = pCurrent->pNext;            //sets Head to the next node
        delete pCurrent;                        //deletes previous node no longer used (RAII)
        cout << "Success\n";
        return;                                 //exits function
    }

    while (pCurrent != nullptr && pCurrent->value != toBeDeleted)
    {
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;             //moves current & previous to each of their next nodes respectively
    }

    if (pCurrent == nullptr)                    //if current equals nullptr before finding value
    {
        cout << "ERROR: No value match in list\n";
        return;                                 //exits function
    }

    pPrevious->pNext = pCurrent->pNext;         //if funct hasn't exited, current is targeted at toBeDeleted, which means we can replace the node end points from previous into the current
    delete pCurrent;                            //clear mem address (and value) from current

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
            pNext = pCurrent->pNext;            //creates temp vairable "next" which allows us to delete "current->Next" safely.
            delete pCurrent;
            pCurrent = pNext;
        }

        list.Head = nullptr;                    //after using the head to delete the rest of the list, we set it to nullptr
        cout << "Successfully cleared list\n";
    } 
    else
        cout << "Operation Cancelled\n";
}

/// @brief Prints entire list
/// @param list passes LinkedList member access
void PrintList(const LinkedList &list)                              //Passed const list by ref for memory performance
{
    Node * pCurrent = list.Head;                                    //looks at mem address of the head to call to
    int count = 1;

    cout << setfill('*') << setw(48) << "" << setfill(' ') << endl;

    while (pCurrent != nullptr && pCurrent->value % 10)             //while the value at the list is not nullptr
    {
        cout << setw(4) << pCurrent->value << " ";                  //displays the dereferenced value at the memaddress "current"
        ++count;

        if ((count - 1) % 10 == 0)
            cout << endl;

        pCurrent = pCurrent->pNext;                                 //moves to the next address if not nullptr
    }

    if (count % 10 != 0)
        cout << endl;                                               //always endl after last value printed

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
            case 'a': AddToList(list); cout << endl; done = true; break;      //passes list to be used in AddToList

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

    LinkedList list;                    //creates a new variable in main to be passed into other functions!

    bool quit = false;
    while(true)
    {
        quit = DisplayMenu(list);       //passes list to be used in functions
        if (quit == true)
        {
            ClearList(list);            //calls clearlist to ensure no memory leaks!
            break;
        }
    }
}