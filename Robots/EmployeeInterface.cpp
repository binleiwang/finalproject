#include "CustomerInterface.h"
#include "EmployeeInterface.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "FileIO.h"
#include "Robot.h"
#include "AST.h"
#include "NMT.h"
#include "HashTable.h"
#include "Customer.h"
#include "Heap.h"

EmployeeInterface::EmployeeInterface()
{
	asinTree = new AST;
	nameTree = new NMT;
	heap = new Heap<Order>;
	//orders = new vector<Order> ordersTemp;
}

EmployeeInterface::EmployeeInterface(Heap<Order> *h, NMT *t1, AST *t2)
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
	for (unsigned int i = 0; i < t.length(); i++)
		t[i] = toupper(t[i]);
	return t == "N" || t == "NAME";
}

bool EmployeeInterface::checkAsin(string t)
{
	for (unsigned int i = 0; i < t.length(); i++)
		t[i] = toupper(t[i]);
	return t == "A" || t == "ASIN";
}

void EmployeeInterface::welcome()
{
	cout << "Welcome to the employee control panel!" << endl << endl;
}

void EmployeeInterface::menu()
{
	cout << "Options:\n";
	cout << "1. View Orders by Priority" << endl;
	cout << "2. Ship an Order" << endl;
	cout << "3. List Database of Products" << endl;
	cout << setw(6) << "-List data sorted by primary key" << endl;
	cout << setw(6) << "-List data sorted by secondary key" << endl;
	cout << "4. Add New Robot" << endl;
	cout << "5. Remove Robot" << endl;
	cout << "6. Exit Employee Menu" << endl << endl;
}

void EmployeeInterface::employeeRights()
{
	int menuNum;
	string answer;
	string choice;

	do {
		//display menu
		menu();

		cout << "Please chose an option between 1 and 6: ";
		getline(cin, answer);
		menuNum = atoi(answer.c_str());
		answer.clear();
		while(menuNum < 1 || menuNum > 6){
			cout << "Invalid choice." << endl;
			cout << "Only chose between 1 and 6. Enter again: ";
			getline(cin, answer);
			menuNum = atoi(answer.c_str());
			answer.clear();
		}

		switch(menuNum){
		case 1:
			viewOrders();
			break;
		case 2:
			shipOrder();
			break;
		case 3:
			cout << "Do you want to see list inventory by name or by asin? ";
			getline(cin, choice);

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
		case 6:
			quit();
			break;
		default:
			quit();
			break;
		}

		cout << "Do you want to chose another option? ";
		getline(cin, answer);

		cout << endl << endl;

	} while (answer == "yes" || answer == "Yes");
}

void EmployeeInterface::viewOrders()
{
	cout << "Printing orders:\n";
	//heap->buildHeap(); // no worky
	heap->printOrders();
}

void EmployeeInterface::shipOrder()
{
	if (heap->getSize() == 0)
		cout << "Unable to ship an order, because there are no orders!\n";
	else
	{
		cout << "Shipping order: \n";
		heap->showOrder(0);
		cout << endl << "The order has been shipped!\n";
		heap->deleteMax();
	}

	//shipping each order in the Heap
	//orders->at(0).print();
	//after shipping, delete that order from the Heap
	//orders->erase(orders->begin()); // deletes first element from a vector
	// OR, call a newly created "deleteFirstOrder" function from Heap
}

void EmployeeInterface::listRobotsName()
{
	cout << "Current inventory, by name:\n\n";
	nameTree->printMenu(cout);
}

void EmployeeInterface::listRobotsAsin()
{
	cout << "Current inventory, by ASIN:\n\n";
	asinTree->printMenu(cout);
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
	cout << ".";

	cout << "ASIN (like an ID number): ";
	getline(cin, temp);
	rNew->set_asin(temp);

	cout << "Price (in USD): ";
	getline(cin, temp);
	rNew->set_price(atof(temp.c_str()));

	cout << "Manufacturer: ";
	getline(cin, temp);
	rNew->set_manufacture(temp);

	cout << "Purpose of this robot: \n";
	getline(cin, temp);
	rNew->set_purpose(temp);


	cout << "Who is the intended audience of this robot?\n";
	cout << "ex: everyone, adults, children\n";
	getline(cin, temp);
	rNew->set_user(temp);

	cout << "Weight (lbs): ";
	getline(cin, temp);
	rNew->set_weight(atof(temp.c_str()));

	cout << "Average User Rating (0-5): ";
	getline(cin, temp);
	rNew->set_rating(atoi(temp.c_str()));

	cout << "Inserting " << rNew->get_name() << "...\n";
	nameTree->insertData(*rNew);
	asinTree->insertData(*rNew);
}

void EmployeeInterface::removeRobot()
{
	string temp;
	cout << "Deleting robots from the database." << endl;

	cout << "Would you like to delete by NAME or ASIN?\n";
	getline(cin, temp);

	while (!checkName(temp) && !checkAsin(temp))
	{
		temp.erase();
		cout << "There was an error with your input...\n";
		cout << "Please enter name, n, asin, or a: ";
		getline(cin, temp);
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
		if (nameTree->search(rTemp))
		{
			tASIN = nameTree->getOtherKey(rTemp);
			rTemp.set_asin(tASIN);
		}
	}
	else
	{
		cout << "Please enter the ASIN of the robot you wish to delete:\n";
		getline(cin, tASIN);
		rTemp.set_asin(tASIN);
		if (asinTree->search(rTemp))
		{
			tName = asinTree->getOtherKey(rTemp);
			rTemp.set_name(tName);
		}
	}
	cout << "Deleting " << tName << " #" << tASIN << " from the database.\n";
	nameTree->removeData(rTemp);
	asinTree->removeData(rTemp);
}

void EmployeeInterface::quit() {
	cout << "Exiting the employee menu.\n";
}
