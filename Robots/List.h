/*
 * List.h
 *
 *  Created on: Apr 25, 2017
 *      Edited: May 8, 2017
 *      Author: Lucy McLaurin
 *       Class: 22C Spring 2017
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <string>
#include <cstddef> //for NULL
#include <assert.h>
using namespace std;

template <class listdata> // list stores generic list data, not any specific C++ type
class List {
private:
    struct Node {
        listdata data;
        Node* nextnode;
        Node* previousnode;
        Node(listdata newdata) : data(newdata), nextnode(NULL), previousnode(NULL) {}
    };

    typedef struct Node* NodePtr;

    NodePtr begin;
    NodePtr end;
    NodePtr iterator;

    int length;

    void reverse(NodePtr node);
    //Helper function for the public printReverse() function.
    //Recursively prints the data in a List in reverse.

    bool isSorted(NodePtr node);
    //Helper function for the public isSorted() function.
    //Recursively determines whether a list is sorted in ascending order.

    int binarySearch(int low, int high, listdata data);
    //Recursively search the list by dividing the search space in half
    //Returns the index of the element, if it is found in the List
    //Returns -1 if the element is not in the List

public:

    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes and empty list
    //Postcondition: Creates an empty linked list with all pointers set to NULL.

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: Deletes the list.

    List<listdata>(const List<listdata>&);
    // Copy constructor: Creates a separate copy of the list.

    /**Accessors*/

    listdata getBegin() const;
    //Returns the first element in the list
    //Precondition: There must be at least 1 node in the list.

    listdata getEnd() const;
    //Returns the last element in the list
    //Precondition: There must be at least 1 node in the list.

    void beginIterator();
    // Iterator points to the beginning of the list.

    listdata getIterator();
    // Precondition: iterator != NULL
    // Returns the data contained in whatever iterator points to.

    void advanceIterator();
    // Precondition: iterator != NULL
    // Moves the iterator forward 1 node.

    void reverseIterator();
    // Precondition: iterator != NULL
    // Moves the iterator back 1 node.

    bool offEnd();
    // Tests iterator to see if it's pointing to something.

    bool empty() const;
    //Determines whether a list is empty.

    int getLength() const;
    //Returns the size of the list

    /**Manipulation Procedures*/

    void deleteEnd();
    //Removes the value of the last element in the list
    //Precondition: There must be at least 1 node in the list.
    //Postcondition: Last element is deleted; 2nd to last element is the new end.

    void deleteBegin();
    //Removes the value of the first element in the list
    //Precondition: There must be at least 1 node in the list.
    //Postcondition: First element deleted, 2nd element is now 1st.

    void deleteList();

    void insertEnd(listdata data);
    //Inserts a new element at the end of the list
    //If the list is empty, the new element becomes both first and last
    //Postcondition: Insert 1 node at the end of the list. End now points to this new node.

    void insertBegin(listdata data);
    //Inserts a new element at the start of the list
    //If the list is empty, the new element becomes both first and last
    //Postcondition: Begin points to the newly created node, and 2nd node is previous 1st.

    void insertIterator(listdata data);
    // Precondition: iterator != NULL
    // Postcondition: New node inserted after what iterator points to.

    void deleteIterator();
    // Precondition: iterator != NULL
    // Postcondition: Deletes the node iterator is pointing to, sets iterator to NULL.

    /**Additional List Operations*/

    void print() const;
    //Prints to the console the value of each element in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty

    void printNumberedList() const;
    // Prints linked list with #s in front, 1 item per line

    List<listdata> operator=(const List &list);

    bool operator==(const List &list);
    // Tests two lists to determine whether their contents are equal
    // Postcondition: returns true if lists are equal and false otherwise

    void printReverse();
    //Wrapper function that calls the reverse helper function to print a list in reverse
    //prints nothing if the List is empty

    bool isSorted();
    //Wrapper function that calls the isSorted helper function to determine whether
    //a list is sorted in ascending order.
    //We will consider that a list is trivially sorted if it is empty.
    //Therefore, no precondition is needed for this function

    int getIndex();
    //Indicates the index of the Node where the iterator is currently pointing
    //Nodes are numbered from 1 to size of the list
    //Pre: length != 0
    //Pre: !offEnd()

    void advanceToIndex(int index);
    //Moves the iterator to the node whose index number is specified in the parameter
    //Pre: length != 0
    //Pre: index <= length

    int linearSearch(listdata data);
    //Searchs the list, element by element, from the start of the List to the end of the List
    //Returns the index of the element, if it is found in the List
    //Calls the above indexing functions in its implementation
    //Returns -1 if the element is not in the List
    //Pre: length != 0

    int binarySearch(listdata data);
    //Returns the index where data is located in the List
    //Calls the private helper function binarySearch to perform the search
    //Pre: length != 0
    //Pre: List is sorted (must test on a sorted list)
};

template <class listdata>
List<listdata>::List() {
	begin = NULL;
	end = NULL;
	iterator = NULL;
	length = 0;
}

template <class listdata>
List<listdata>::~List() {
    NodePtr after = begin;
    NodePtr before;
    while (after != NULL) {
        before = after->nextnode;
        after->previousnode = NULL;
        delete after;
        after = before;
    }
}

template <class listdata>
void List<listdata>::deleteList()
{
    NodePtr after = begin;
    NodePtr before;
    while (after != NULL) {
        before = after->nextnode;
        after->previousnode = NULL;
        delete after;
        after = before;
    }
}

// Copy Constructor
template <class listdata>
List<listdata>::List(const List<listdata>&oldList)
{
	// empty list
	if (oldList.length == 0) {
		begin = end = iterator = NULL;
		length = 0;
	}
	else {
		length = 0;
		iterator = NULL;
		NodePtr tempOld = oldList.begin;
		NodePtr newBegin = new Node(tempOld->data); // allocate 1st node
		begin = newBegin; // set begin
		NodePtr tempNew = newBegin;
		length++;
		while (tempOld->nextnode != NULL) {
			NodePtr N = new Node(tempOld->nextnode->data);
			length++;
			tempNew->nextnode = N;
			N->previousnode = tempNew;
			tempOld = tempOld->nextnode;
			tempNew = tempNew->nextnode;
		}
		// set end
		end = tempNew; // tempNew currently points at the last node.
	}
}

template <class listdata>
void List<listdata>::print() const
{
    NodePtr temp = begin; //create a temporary iterator
    while (temp != NULL) {
    	cout << temp->data << " ";
    	temp = temp->nextnode;
    }
    cout << endl; // print newline
}

template <class listdata>
void List<listdata>::printNumberedList() const
{
	NodePtr temp = begin;
	for (int i = 1; i <= length; i++)
	{
		cout << i << ". " << temp->data << endl;
		temp = temp->nextnode;
	}
}

template <class listdata>
bool List<listdata>::operator==(const List& list)
{
    if(length != list.length)
        return false;
    NodePtr temp1 = begin;
    NodePtr temp2 = list.begin;
    while(temp1 != NULL)
    {
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->nextnode;
        temp2 = temp2->nextnode;
    }
    return true;
}

template <class listdata>
void List<listdata>::insertBegin(listdata data) {
    if(length == 0) { // if list is empty, initialize
        begin = end = new Node(data);
    } else {
        NodePtr N = new Node(data);
        N->nextnode = begin;
        begin->previousnode = N;
        begin = N;
    }
    length++;
}

template <class listdata>
void List<listdata>::insertEnd(listdata data) {
	if (length == 0) {
		begin = end = new Node(data);
	} else {
		NodePtr N = new Node(data);
		end->nextnode = N;
		N->previousnode = end;
		end = N;
	}
	length++;
}

template <class listdata>
void List<listdata>::deleteBegin() {
	assert(!empty());
    if (length == 1) {
        delete begin;
        begin = end = NULL;
        length = 0;

    } else {
        NodePtr temp = begin; //store this location so we don't lose access to it
        begin = begin->nextnode; //advance the pointer
        delete temp; //free the memory for the original begin node
        begin->previousnode = NULL;
        length--;
    }
}

template <class listdata>
void List<listdata>::deleteEnd()
{
	assert(!empty());
    if (length == 1) {
    	delete end;
    	begin = end = NULL;
    	length = 0;
    } else {
    	end = end->previousnode;
        delete end->nextnode; //free the memory for the original last node
        end->nextnode = NULL; //so last->next is not pointing at freed memory
        length--;
    }

}

template <class listdata>
void List<listdata>::beginIterator()
{
	iterator = begin;
}

template <class listdata>
listdata List<listdata>::getIterator()
{
	assert(iterator != NULL);
	return iterator->data;
}

template <class listdata>
void List<listdata>::advanceIterator()
{
	assert(!offEnd());
	iterator = iterator->nextnode;
}

template <class listdata>
void List<listdata>::reverseIterator()
{
	assert(!offEnd());
	iterator = iterator->previousnode;
}

template <class listdata>
void List<listdata>::insertIterator(listdata data)
{
	assert(!offEnd());
	if (iterator == end) {
		insertEnd(data);
	} else {
		NodePtr N = new Node(data);
		N->nextnode = iterator->nextnode;
		N->previousnode = iterator;
		iterator->nextnode->previousnode = N;
		iterator->nextnode = N;
		length++;
	}
}

template <class listdata>
void List<listdata>::deleteIterator()
{
	assert(!offEnd());
	if (iterator == begin) {
		deleteBegin();
	} else if (iterator == end) {
		deleteEnd();
	} else {
		iterator->previousnode->nextnode = iterator->nextnode;
		iterator->nextnode->previousnode = iterator->previousnode;
		delete iterator;
		length--;
	}
	iterator = NULL;
}

template <class listdata>
bool List<listdata>::offEnd()
{
	return iterator == NULL;
}

template <class listdata>
bool List<listdata>::empty() const
{
	return length == 0;
}

template <class listdata>
int List<listdata>::getLength() const
{
	return length;
}

template <class listdata>
listdata List<listdata>::getBegin() const
{
	assert(!empty());
	return begin->data;
}

template <class listdata>
listdata List<listdata>::getEnd() const
{
	assert(!empty());
	return end->data;
}

template <class listdata>
void List<listdata>::reverse(NodePtr node)
{
	if (node == NULL)
	{
		cout << endl;
	}
	else
	{
		cout << node->data << " ";
		reverse(node->previousnode);
	}
}

template <class listdata>
void List<listdata>::printReverse()
{
	reverse(end);
}

template <class listdata>
bool List<listdata>::isSorted(NodePtr node)
{
	if (length <= 1)
		return true;
	else if (node->nextnode == NULL)
		return true;
	else
	{
		return node->data <= node->nextnode->data && isSorted(node->nextnode);
	}
}

template <class listdata>
bool List<listdata>::isSorted()
{
	return isSorted(begin);
}

template <class listdata>
int List<listdata>::getIndex()
{
	assert(length != 0);
	assert(!offEnd());
	int i = 1;
	NodePtr temp = begin;
	while (temp != NULL)
	{
		if (iterator == temp)
			return i;
		temp = temp->nextnode;
		i++;
	}
	return i;
}

template <class listdata>
void List<listdata>::advanceToIndex(int index)
{
	assert(length != 0);
	assert(index <= length);
	beginIterator();
	for (int i = 1; i < index; i++)
		advanceIterator();
}

template <class listdata>
int List<listdata>::linearSearch(listdata data)
{
	assert(length != 0);
	for (int i = 1; i <= length; i++)
	{
		advanceToIndex(i);
		if (data == getIterator())
			return getIndex();
	}
	return -1;
}

template <class listdata>
int List<listdata>::binarySearch(listdata data)
{
	assert (length != 0);
	assert (isSorted());
	return binarySearch(0, length, data);
}

template <class listdata>
int List<listdata>::binarySearch(int low, int high, listdata data)
{
	if (high < low)
		return -1;
	int mid = low + (high - low) / 2;
	advanceToIndex(mid);
	if (getIterator() == data)
		return mid;
	if (data < getIterator())
		return binarySearch(low, mid-1, data);
	else
		return binarySearch(mid+1, high, data);
}

template <class listdata>
List<listdata> List<listdata>::operator=(const List &oldList)
{
	// empty list
		if (oldList.length == 0) {
			begin = end = iterator = NULL;
			length = 0;
		}
		else {
			length = 0;
			iterator = NULL;
			NodePtr tempOld = oldList.begin;
			NodePtr newBegin = new Node(tempOld->data); // allocate 1st node
			begin = newBegin; // set begin
			NodePtr tempNew = newBegin;
			length++;
			while (tempOld->nextnode != NULL) {
				NodePtr N = new Node(tempOld->nextnode->data);
				length++;
				tempNew->nextnode = N;
				N->previousnode = tempNew;
				tempOld = tempOld->nextnode;
				tempNew = tempNew->nextnode;
			}
			// set end
			end = tempNew; // tempNew currently points at the last node.
		}
		return *this;
}


#endif /* LIST_H_ */
