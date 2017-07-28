#include "HashTable.h"
#include "Customer.h"
#include <assert.h>
#include <iostream>

//Hash function
int HashTable::hash(string key)
{
    int index, sum = 0;
    for(unsigned int i = 0; i < key.length(); i++)
        sum += (int) key[i];
    index = sum % SIZE;
    return index;
}

//Accessor functions
int HashTable::countBucket(int index)
{
    assert(0 <= index && index < SIZE);
    int count = 0;
    count = Table[index].getLength();
    return count;
}

int HashTable::searchData(Customer c)
{
    string tPa;
    tPa = c.getFirst() + c.getLast();
    int i = hash(tPa);
    int find = Table[i].linearSearch(c);
    if(find != -1)
        return i;
    else
        return find;
}

//Manipulation functions
void HashTable::insertData(Customer c)
{
    string tPa;
    tPa = c.getFirst() + c.getLast();
    int i = hash(tPa);
    Table[i].insertEnd(c);
}

void HashTable::removeData(Customer c)
{
    string tPa;
    tPa = c.getFirst() + c.getLast();
    int i = hash(tPa);
    Table[i].advanceToIndex(Table[i].linearSearch(c));
    Table[i].deleteIterator();
}

//Two different printing functions
void HashTable::printBucket(int index)
{
    assert(0 <= index && index < SIZE);
    Table[index].print();
}

void HashTable::printTable(ostream &out)
{
	int n = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(!Table[i].empty())
        {
			Table[i].beginIterator();
			for (int j = 0; j < Table[i].getLength(); j++) {
				out << Table[i].getIterator() << endl;
				out << "__________________________________\n";
				if (j < Table[i].getLength() - 1)
					Table[i].advanceIterator();
			}
			out << "__________________________________" << endl << endl;
			n++;
		}
    }
    if (n == 0)
    	out << "There were no customers in this session.\n";
}

ostream &HashTable::printCustomerDetail(ostream &out)
{
	int n = 0;
	Customer cTemp;
    for(int i = 0; i < SIZE; i++)
    {
        if(!Table[i].empty())
        {
        	Table[i].beginIterator();
        	for (int j = 0; j < Table[i].getLength(); j++) {
        		Table[i].getIterator().printDetail(out);
        		if (j < Table[i].getLength() - 1)
        			Table[i].advanceIterator();
        	}
            out << "__________________________________" << endl << endl;
            n++;
        }
    }
    if (n == 0)
    	out << "There were no customers in this session.\n";
}
