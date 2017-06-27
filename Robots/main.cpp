/*
 * main.cpp
 *
 *  Created on: Jun 18, 2017
 *      Author: Lucy
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "FileIO.h"
#include "List.h"
#include "AST.h"
#include "NMT.h"
#include "Robot.h"
#include "HashTable.h"
#include "CustomerInterface.h"
#include "EmployeeInterface.h"

using namespace std;

bool isCustomer(string input);
bool isEmployee(string input);
bool quitProgram(string input);

int main()
{
	cout << "Test\n";
	FileIO file;
	Robot robot;
	NMT nameTree;
	AST asinTree;
	Heap<Order> orders;
	HashTable customers;
	Order singleOrder;
	Customer singleCustomer;
	string input = "x";

	file.readFromFile(&robot, &nameTree, &asinTree);
	CustomerInterface c(&nameTree, &asinTree, &customers, &orders, &singleCustomer, &robot);
	EmployeeInterface e(&orders, &nameTree, &asinTree);

	// when you search for an item,
	// it prints to screen 2 times, once for each tree (or it did before i removed the code)
	// i moved print to its own function, but it wont work within th eBST class.
	// *** use a robot print function
	// *  cout << r;
	cout << "Please type C for customer, or E for employee, or type Q to quit.\n";
	getline(cin, input);

	while (!quitProgram(input))
	{
		if (isCustomer(input))
		{
			c.welcome();
			c.printOptions();
			c.searchByKey();
		}
		else if (isEmployee(input))
		{
			e.welcome();
			e.employeeRights();
		}
		else
		{
			cout << "There was a problem with your input...\n";
		}
		cout << "Please type C for customer, or E for employee, or type Q to quit.\n";
		input.clear();
		getline(cin, input);
	}
// exit msg?
	cout << "Thank you for shopping at our store." << endl;
	cout << "Have a great day!!!" << endl << endl;
	return 0;
}

bool isCustomer(string input)
{
	if (input == "C" || input == "c")
		return true;
	return false;
}

bool isEmployee(string input)
{
	if (input == "E" || input == "e")
		return true;
	return false;
}

bool quitProgram(string input)
{
	if (input == "Q" || input == "q")
		return true;
	return false;
}
