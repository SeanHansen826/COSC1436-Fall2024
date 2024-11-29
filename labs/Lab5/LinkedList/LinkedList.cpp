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
    Node * Head = nullptr;                  //when using this, use pass by ref or mem. addresses
};

/// @brief Displays project header information
void DisplayHeader()
{
    cout << right << setw(27) << setfill('.') << "" << setfill(' ') << endl;
    cout << setw(10) << "Project: " << "Linked List\n" << setw(10) << "By: " << "Sean Hansen\n" << setw(10) << "Class: " << "COSC-1436-20005\n";
    cout << setw(27) << setfill('.') << "" << setfill(' ') << endl << endl;
};

void AddToList(LinkedList &list)
{
    Node * pNewNode = new Node;             //creates pNewNode dynamic mem address
    
    cout << "Enter a Value: ";
    cin >> pNewNode->value;                 //with -> it auto dereferences it to the value stored, not the mem adress
    pNewNode->Next = nullptr;

    if (list.Head == nullptr)               //checks for initial values
        list.Head = pNewNode;               //sets as head
    else
    {
        Node * current = list.Head;         //finds head of list, sets to current

        while (current->Next != nullptr)    //loops through list until nullptr
            current = current->Next;        //when !nullptr, sets to next (moving to next memory address in list)

        current->Next = pNewNode;           //when nullptr, sets equal to pNewNode mem adress, with value stored by ref

        //delete pNewNode; (?)              //need to delete new node to resolve mem leak
    }
}

void PrintList(const LinkedList &list)      //Passed const list by ref for memory performance
{
    Node * current = list.Head;             //looks at mem address of the head to call to

    while (current != nullptr)              //while the value at the list is not nullptr
    {
        cout << current->value << " ";      //displays the dereferenced value at the memaddress "current"
        current = current->Next;            //moves to the next address if not nullptr
    }
    cout << endl << endl;                   //line break when finished displaying
}

bool DisplayMenu(LinkedList &list)
{
    char menuInput;
    bool done = false;
    bool quit = false;

    cout << left << setfill('-') << setw(20) << "" << setfill(' ') << endl;
    cout << left << setw(20) << "A) dd" << endl;
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
            case 'a': AddToList(list); done = true; break;      //passes list to be used in AddToList

            case 'P':
            case 'p': PrintList(list); done = true; break;

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
            break;
    }
}