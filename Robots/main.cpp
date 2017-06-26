/*
 * main.cpp
 *
 *  Created on: Jun 18, 2017
 *      Author: Lucy
 */

#include <iostream>
#include <fstream>
#include <string>
#include "FileIO.h"
#include "List.h"
#include "AST.h"
#include "NMT.h"
#include "Robot.h"
#include "HashTable.h"
#include "CustomerInterface.h"
#include "EmployeeInterface.h"

using namespace std;

int main()
{
	cout << "Hi\n";
	FileIO file;
	Robot robot;
	NMT nameTree;
	AST asinTree;
	Heap<Order> orders;
	HashTable customers;
	Order singleOrder;
	Customer singleCustomer;

	file.readFromFile(&robot, &nameTree, &asinTree);

	// when you search for an item,
	// it prints to screen 2 times, once for each tree (or it did before i removed the code)
	// i moved print to its own function, but it wont work within th eBST class.
	// *** use a robot print function
	// *  cout << r;

	CustomerInterface c(&nameTree, &asinTree, &customers, &orders, &singleOrder, &singleCustomer, &robot);

	c.welcome();
	c.searchByKey();

	EmployeeInterface e(&orders, &nameTree, &asinTree);

	e.welcome();
	e.employeeRights();

	cout << "Test\n";
	return 0;
}
