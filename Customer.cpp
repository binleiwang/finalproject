//
//  Customer.cpp
//  Robot
//
//  Created by Stephen Hung on 6/17/17.
//  Copyright © 2017 Stephen Hung. All rights reserved.
//

#include <string>
#include "Customer.h"

Customer::Customer()
{
    first_name = "";
    last_name = "";
    address = "";
    city = "";
    state = "";
    zip = 0;
    email = "";
}

void Customer::setFirst(string s)
{
    first_name = s;
}

void Customer::setLast(string s)
{
    last_name = s;
}

void Customer::setAddress(string s)
{
    address = s;
}

void Customer::setCity(string s)
{
    city = s;
}

void Customer::setState(string s)
{
    state = s;
}

void Customer::setZip(int i)
{
    zip = i;
}

void Customer::setEmail(string info)
{
    email = info;

string Customer::getFirst() const
{
    return first_name;
}

string Customer::getLast() const
{
    return last_name;
}

string Customer::getAddress() const
{
    return address;
}

string Customer::getCity() const
{
    return city;
}

string Customer::getState() const
{
    return state;
}

int Customer::getZip() const
{
    return zip;
}

string Customer::getEmail() const
{
    return first_name;
}
    
bool Customer::operator ==(const Customer& c)
{
    return (first_name == c.first_name && last_name == c.last_name);
}

ostream &operator <<(ostream &os, const Customer& c)
{
    os << "Customer: " << c.first_name << " " << c.last_name << endl;
    os << "Address: " << c.address << endl;
    os << "City: " << c.city << endl;
    os << "State: " << c.state << endl;
    os << "Zip Code: " << c.zip << endl;
    return os;
}
//Lack of getter and setter for ORDERS
//Remind the members to take care of print() function in List(with otream parameter)
