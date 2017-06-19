//
//  HashTable.h
//  Robot
//
//  Created by Stephen Hung on 6/17/17.
//  Copyright © 2017 Stephen Hung. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h


#include <string>
#include "Customer.h"
#include "List.h"
using namespace std;

class HashTable {
public:
    int hash(string key);
    int countBucket(int index);
    int searchData(Customer c);
    void insertData(Customer c);
    void removeData(Customer c);
    void printBucket(int index);
    void printTable();
private:
    //Let's say we have about 25 customers
    static const int SIZE = 50;
    List<Customer> Table[SIZE];
};

#endif /* HashTable_h */
