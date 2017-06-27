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

void HashTable::printTable(ostream& out)
{
    for(int i = 0; i < SIZE; i++)
    {
        if(Table[i].empty())
        {
            out << "Bucket: " << i << endl;
            out << "Number of customers at this bucket: " << countBucket(i) << endl;
            out << "__________________________________" << endl << endl;
        }
        else
        {
            out << "Bucket: " << i << endl;
            out << Table[i].getBegin();
            out << "Number of customers at this bucket: " << countBucket(i) << endl;
            out << "__________________________________" << endl << endl;
        }
    }
}
