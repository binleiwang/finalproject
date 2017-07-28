#ifndef HashTable_h
#define HashTable_h

#include <string>
#include <vector>
#include "Customer.h"
#include "List.h"
using namespace std;

class HashTable {
public:
    HashTable() : Table(SIZE) {};
    int hash(string key);
    int countBucket(int index);
    int searchData(Customer c);
    void insertData(Customer c);
    void removeData(Customer c);
    void printBucket(int index);
    void printTable(ostream& out);
    ostream &printCustomerDetail(ostream &out);
private:
    //Let's say we have about 25 customers
    static const int SIZE = 50;
    vector <List<Customer> > Table;

};

#endif /* HashTable_h */
