//
//  Customer.h
//  Robot
//
//  Created by Stephen Hung on 6/17/17.
//  Copyright © 2017 Stephen Hung. All rights reserved.
//

#ifndef Customer_h
#define Customer_h

#include <string>
#include "List.h"
#include "Order.h"
using namespace std;

class Customer {
private:
    string first_name;
    string last_name;
    string address;
    string city;
    string state;
    int zip;
    List<Order> orders;
    
public:
    Customer();
    string getFirst() const;
    string getLast() const;
    string getAddress() const;
    string getCity() const;
    string getState() const;
    int getZip() const;
    void setFirst(string);
    void setLast(string);
    void setAddress(string);
    void setCity(string);
    void setState(string);
    void setZip(int);
    friend ostream& operator<<(ostream& os, const Customer& c);
    bool operator==(const Customer& c);
};
#endif /* Customer_h */


//Lack of getter and setter for ORDERS
