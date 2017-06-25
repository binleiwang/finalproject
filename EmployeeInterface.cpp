/*
 * EmployeeInterface.cpp
 *
 *  Created on: Jun 24, 2017
 *      Author: My Nguyen
 */
#include "CustomerInterface.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "FileIO.h"
#include "Robot.h"
#include "BST.h"
#include "HashTable.h"
#include "Customer.h"
#include "Heap.h"

/*EmployeeInterface::EmployeeInterface()
{
	//heap = new Heap; // temp
	//orders = new vector<Order> ordersTemp; // temp for testing
}*/

EmployeeInterface::EmployeeInterface(Heap h, BST<Robot> t1, BST<Robot> t2)
{
	heap = h;
	//orders = &(heap.getOrders());
	// Heap::getOrders() doesn't exist but likely will need this to use
	// the vector inside Employee
	// OR, could write a Heap::printOrders() function and call it from here.
	// if we use orders vector, it must be a reference value
	// so that when we delete from the front, it updates the real heap.
	nameTree = t1;
	asinTree = t2;
}

bool EmployeeInterface::checkName(string t)
{
	for (int i = 0; i < t.length(); i++)
		t[i] = toupper(t[i]);
	return t == "N" || t == "NAME";
}

bool EmployeeInterface::checkAsin(string t)
{
	for (int i = 0; i < t.length(); i++)
		t[i] = toupper(t[i]);
	return t == "A" || t == "ASIN";
}

void EmployeeInterface::welcome()
{
	cout << "Welcome to the employee control panel!" << endl << endl;
}

void EmployeeInterface::employeeRights()
{
	cout << "Options:\n";
	cout << "1. View Orders by Priority" << endl;
	cout << "2. Ship an Order" << endl;
	cout << "3. List Database of Products" << endl;
	cout << setw(6) << "-List data sorted by primary key" << endl;
	cout << setw(6) << "-List data sorted by secondary key" << endl;
	cout << "4. Add New Robot" << endl;
	cout << "5. Remove Robot" << endl << endl;

	int option;
	string answer;
	string choice;

	do{
		cout << "Please chose an option between 1 and 5: ";
		cin >> option;

		while(option < 1 || option > 5){
			cout << "Invalid choice." << endl;
			cout << "Only chose between 1 and 5. Enter again: ";
			cin >> option;
		}

		switch(option){
		case 1:
			viewOrders();
			break;
		case 2:
			shipOrder();
			break;
		case 3:
			cout << "Do you want to see list inventory by name or by asin? ";
			cin >> choice;

			if(choice == "name")
				listRobotsName();
			else
				listRobotsAsin();
			break;
		case 4:
			addNewRobot();
			break;
		case 5:
			removeRobot();
			break;
		}

		cout << "Do you want to chose another option? ";
		cin >> answer;

		cout << endl << endl;

	}while (answer == "yes" || answer == "Yes");
}

void EmployeeInterface::viewOrders()
{
	cout << "Printing orders:\n";
	for (int i = 0; i < orders->size(); i++);
		// temp until print is added
		//orders->at(i).print(); // need a way to print an order, either << or print()in Order.h
		//print all order in the Heap
}

void EmployeeInterface::shipOrder()
{
	cout << "Shipping order...\n";
	//shipping each order in the Heap
	//orders->at(0).print();
	//after shipping, delete that order from the Heap
	//orders->erase(orders->begin()); // deletes first element from a vector
	// OR, call a newly created "deleteFirstOrder" function from Heap
}

void EmployeeInterface::listRobotsName()
{
	cout << "Current inventory, by name:\n\n";
	//display the robot tree by name
}

void EmployeeInterface::listRobotsAsin()
{
	cout << "Current inventory, by ASIN:\n\n";
	//display the robot tree by asin
}

void EmployeeInterface::addNewRobot()
{
	cout << "Adding a new robot. Please enter the specified information:\n\n";
	Robot *rNew;
	rNew = new Robot;
	string temp;

	cout << "Name: ";
	getline(cin, temp);
	rNew->set_name(temp);
	//temp.erase();

	cout << "ASIN (like an ID number): ";
	getline(cin, temp);
	rNew->set_asin(temp);
	//temp.erase();

	cout << "Price (in USD): ";
	getline(cin, temp);
	rNew->set_price(atof(temp.c_str())); // uses stdlib.h to convert str to double
	//temp.erase();

	cout << "Manufacturer: ";
	getline(cin, temp);
	rNew->set_manufacture(temp);
	//temp.erase();

	cout << "Purpose of this robot: \n";
	getline(cin, temp);
	rNew->set_purpose(temp);
	//temp.erase();


	cout << "Who is the intended audience of this robot?\n";
	cout << "ex: everyone, adults, children\n";
	getline(cin, temp);
	rNew->set_user(temp);
	//temp.erase();

	cout << "Weight (lbs): ";
	getline(cin, temp);
	rNew->set_weight(atof(temp.c_str()));
	//temp.erase();

	cout << "Average User Rating (0-5): ";
	getline(cin, temp);
	rNew->set_rating(atoi(temp.c_str()));
	//temp.erase();

	cout << "Inserting " << rNew->get_name() << "...\n";
	//insert in the name tree
	nameTree.insertData(*rNew);
	//insert in the asin tree
	asinTree.insertData(*rNew);
}

void EmployeeInterface::removeRobot()
{
	string temp;
	cout << "Deleting robots from the database." << endl;

	cout << "Would you like to delete by NAME or ASIN?\n";
	cin >> temp;

	while (!checkName(temp) && !checkAsin(temp))
	{
		temp.erase();
		cout << "There was an error with your input...\n";
		cout << "Please enter name, n, asin, or a: \n";
		cin >> temp;
	}
	bool byName = checkName(temp);
	temp.erase();

	Robot rTemp;
	string tName;
	string tASIN;
	if (byName)
	{
		cout << "Please enter the name of the robot you wish to delete:\n";
		getline(cin, tName);
		rTemp.set_name(tName);
		// *** Need a way to get the corresponding ASIN from BST
		//     so we can delete it from the ASIN tree also.
		// ex: possible BST function, unique to robot object:
		//       string BST::getKey(string t)
		//       searches BST name and ASIN for a match,
		//          if name is found, return its ASIN
		//          if ASIN is found, return its name
		// ***      else return some dummy value (null).
		if (nameTree.search(rTemp))
		{
			//tAsin = nameTree->getKey(rTemp); // ex: get ASIN using name
			rTemp.set_asin(tASIN);
		}
	}
	else
	{
		cout << "Please enter the ASIN of the robot you wish to delete:\n";
		getline(cin, tASIN);
		rTemp.set_asin(tASIN);
		if (asinTree.search(rTemp))
		{
			// tName = asinTree->getKey(rTemp); // ex: get name using ASIN
			rTemp.set_name(tName);
		}
	}
	cout << "Deleting " << tName << " #" << tASIN << " from the database.\n";
	nameTree.removeData(rTemp);
	asinTree.removeData(rTemp);
}

