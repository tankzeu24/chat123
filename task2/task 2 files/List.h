#ifndef LIST_H
#define LIST_H
#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;


template <class Type>

class List
{
private:


    class Node
    {
    public:
        // Public attributes - Why are the attributes public?
        Type data;     // The data in the node
        Node* next;   // Pointer to next node

        // Constructors and destructor

        Node()
        {
            //data = 0; //disable because we can't know if its an int
            next = NULL;
        }


        Node(Type theData)
        {
            data = theData;
            next = NULL;
        }


        Node(Type theData, Node* theNextNode)
        {
            data = theData;
            next = theNextNode;
        }


        ~Node()
        {
        }

    }; // end Node



    Node *head; //Pointer to the first node in the list
    int size; //Records the number of nodes in the list

public:

    List(); //default constructor
    List(const List& lst); //copy constructor
    ~List();//destructor
    List& operator=(const List& list);
    Type& operator[](int index) ;
    const Type& operator[](int index) const;
    Type getItem(int index) const;
    // PRE:
    // POST: A new node containing the given data is inserted at the front
    //       of the list
    // PARAM: data is the data to be stored
    void add(Type data);

    // PRE:
    // POST: A new node containing the given data is inserted at the given
    //       position in the list
    // PARAM: pos specifies the (index) position to insert the new node
    //        data is the data to be stored
    void insertAt(int pos, Type data);

    // PRE:
    // POST: The first incidence of the given data is removed from the list.
    //       Returns true if data is found (and removed), false otherwise
    // PARAM: data specifies the data to be removed from the list
    bool remove(Type data );

    // PRE:
    // POST: Empties the list, freeing up dynamically allocated memory
    // PARAM:
    void removeAll();

    /* For Testing Purposes */
    // PRE:
    // POST: Prints the contents of the list to the screen, in order
    // PARAM:
    void printList();
    void copyList(const List& list);
    int getSize() const;



};





// Default constructor
template <class Type>
List<Type>::List()
{
    head = NULL;
    size = 0;
}


template <class Type>
List<Type>::List(const List& lst)
{
    copyList(lst);
}



template <class Type>
List<Type>::~List()
{
    removeAll();
}

template <class Type>
List<Type>& List<Type>::operator=(const List<Type>& list)
{
    if (this != &list)
    {
        removeAll();
        copyList(list);
    }
    return *this;
}


template<class Type>
void List<Type>::copyList(const List<Type> &lst)
{

    if (lst.head == NULL)
    {
        head = NULL;
        size = 0;
    }
    else
    {

        head = new Node;
        head->data = lst.head->data;
        /* Now copy the rest of the list.  To do this we'll need to create two
         * temporary pointers, one to go through the old list, one node at a
         * time, and one to keep pace in the new list, creating new nodes. */
        Node *pNewNode = head;
        Node *pOldNode = lst.head->next;
        // Repeat until the entire list is copied
        while (pOldNode != NULL)
        {
            pNewNode->next = new Node;
            pNewNode = pNewNode->next;
            pNewNode->data = pOldNode->data;;
            pOldNode = pOldNode->next;
        }
        pNewNode->next = NULL;
        size = lst.size;
    }
}

template<class Type>
int List<Type>::getSize() const
{
    return size;
}

template<class Type>
Type& List<Type>::operator[](int index)
{

    if(getSize()>=0 && index<=size-1)
    {
        int counter=0;
        Node *p=head;

        while( !(counter==index) )
        {
            p=p->next;
            counter++;
        }

        return p->data;
    }

    throw std::invalid_argument("wrong index");
}


template<class Type>
const Type& List<Type>::operator[](int index) const
{

    if(getSize()>=0 && index<=size-1)
    {
        int counter=0;
        Node *p=head;

        while( !(counter==index) )
        {
            p=p->next;
            counter++;
        }

        return p->data;
    }

    throw std::invalid_argument("wrong index");
}


template<class Type>
Type List<Type>::getItem(int index) const
{
    if(getSize()>=0 && index<=size-1)
    {
        int counter=0;
        Node *p=head;

        while( !(counter==index) )
        {
            p=p->next;
            counter++;
        }

        Type item(p->data);
        return item;
    }

    throw std::invalid_argument("wrong index");

}




/**************************************************************************/
// List Operations

// Adds a node to the start of the list, making it the new head
template <class Type>
void List<Type>::add(Type x)
{
    Node *p = new Node; //temporary node

    p -> data = x;
    p -> next = head;
    head = p;
    size++;
}

// Inserts a new node at the given position (or index) in the list
template <class Type>
void List<Type>::insertAt(int pos, Type x)
{
    Node *p;
    Node *newNode;

    // Check that pos is a valid index
    if (pos <= size)
    {
        newNode = new Node; //new node
        newNode->data = x;

        // Deal with case when item is to be inserted at the head of the list
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
        }// if(pos == 0)
        else
        {
            p = head;
            // Move to position BEFORE insertion point
            for(Type i = 0; i < pos-1; i++)
            {
                // Check that p points to a node
                // Note using exception handling should throw an exception here
                if(p == NULL)
                {
                    return;
                }
                p = p->next;
            }//for
            // Insert node
            newNode->next = p->next;
            p->next = newNode;
        }//else (pos != 0)
        size++;
    }//else (pos >= size) do nothing
}

// Removes the first node containing the given data, returns true
// iff data is found (and deleted).
template <class Type>
bool List<Type>::remove(Type x)
{
    Node *p = head;
    Node *temp;
    // Check to see if the list exists
    if (head == NULL)
    {
        return false;
    }
    // Check to see if target is at the head of the list
    else if (head->data == x)
    {
        head = head->next;
        delete p; //currently assigned head
        size--;
        return true;
    }
    // Otherwise iterate through list
    else
    {
        while(p->next != NULL)
        {
            // Check next node for target
            if(p->next->data == x)
            {
                temp = p->next;
                p->next = p->next->next;
                size--;
                delete temp;
                return true;
            }
            p = p->next;
        }
    }
    return false;
}

template <class Type>
// Empties the list by deleting each node, starting at the head
void List<Type>::removeAll()
{
    Node *p = head;
    // Traverse the list deleting nodes
    while (p!= NULL)
    {
        head = head->next;
        delete p; // De-allocate memory
        p = head; // Go to next node
    }
    head = NULL;
    size = 0;
}

template <class Type>
void List<Type>::printList()
{
    Node *p = head;
    cout << "["; //Nice format!
    // Traverse the list
    while (p != NULL)
    {
        cout << p -> data; // Print data
        p = p -> next; // Go to next node
        if (p != NULL)
        {
            cout << ","; // Print a comma unless at the end of the list
        }
    }
    cout << "]"; // Don't print a newline - it might not be wanted
}

#endif // LIST_H
