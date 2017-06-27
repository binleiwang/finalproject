#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <string>
#include <cstddef>
#include <assert.h>
using namespace std;

template <class listdata>
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
    bool isSorted(NodePtr node);
    int binarySearch(int low, int high, listdata data);
public:
    List();
    ~List();
    List<listdata>(const List<listdata>&);
    listdata getBegin() const;
    listdata getEnd() const;
    void beginIterator();
    listdata getIterator();
    void advanceIterator();
    void reverseIterator();
    bool offEnd();
    bool empty() const;
    int getLength() const;
    void deleteEnd();
    void deleteBegin();
    void deleteList();
    void insertEnd(listdata data);
    void insertBegin(listdata data);
    void insertIterator(listdata data);
    void deleteIterator();
    void print() const;
    void printNumberedList() const;
    List<listdata> operator=(const List &list);
    bool operator==(const List &list);
    void printReverse();
    bool isSorted();
    int getIndex();
    void advanceToIndex(int index);
    int linearSearch(listdata data);
    int binarySearch(listdata data);
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
	if (length == 0)
		return;
    NodePtr after = begin;
    NodePtr before;
    while (after != NULL) {
        before = after->nextnode;
        after->previousnode = NULL;
        delete after;
        after = before;
    }
    length = 0;
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
	listdata data;
	if (length > 0)
		return end->data;
	else
		return data;
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
