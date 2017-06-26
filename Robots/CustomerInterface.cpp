/*
 * UserInterface.cpp
 *
 *  Created on: Jun 18, 2017
 *      Author: My Nguyen
 */
#include "CustomerInterface.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include "FileIO.h"
#include "Robot.h"
#include "AST.h"
#include "NMT.h"
#include "Order.h"
#include "HashTable.h"
#include "Customer.h"
#include "Heap.h"
#include <cmath>

using namespace std;

CustomerInterface::CustomerInterface(NMT *bst1, AST *bst2, HashTable *hash, Heap<Order> *heap1, Order *order, Customer *c, Robot *robot)
{
	namebst = bst1;
	asinbst = bst2;
	table = hash;
	heap = heap1;
	newOrder = order;
	customer = c;
	choice = "";
	menuNum = 0;
	number = "";
}

void CustomerInterface::welcome() 
{
	cout << "Welcome to our robot store!  " << endl << endl;
}

void CustomerInterface::printOptions()
{
	cout << "1. Search for a product" << endl;
	cout << setw(9) << "-Find and display one record using the primary key"
			<< endl;
	cout << setw(9) << "-Find and display one record using the secondary key"
			<< endl;
	cout << "2. List Database of Products" << endl;
	cout << setw(9) << "-List data sorted by primary key" << endl;
	cout << setw(9) << "-List data sorted by secondary key" << endl;
	cout << "3. Place an Order" << endl;
	cout << setw(9) << "-Overnight Shipping" << endl;
	cout << setw(9) << "-Rush Shipping" << endl;
	cout << setw(9) << "-Standard Shipping" << endl;
	cout << "4. View Purchases" << endl;
	cout << setw(9) << "Determine whether or not an order has shipped" << endl;
	cout << "5. Quit" << endl << endl;
}

void CustomerInterface::searchByKey()
{
	cout << "Please choose an option between 1 and 5 in the menu: ";
	promptUserInput();
	while(menuNum < 1 || menuNum > 5){
		cout << "Invalid choice." << endl;
		cout << "Only choose between 1 and 5. Enter again: ";
		promptUserInput();
	}

	switch (menuNum)
	{
	case 5:
		quitShopping();
		break;
	case 4:
		viewPurchase();
		break;
	case 3:
		cout << "Please chose a product first." << endl;
		cout << "Please chose option 1 or 2 from the menu: ";
		searchByKey();
		break;
	case 2:
		cout << "\nDo you want to see list of robots by name or by asin? ";
		choice.clear();
		getline(cin, choice);
		while(choice != "name" && choice != "asin"){
			cout << "Invalid entry or typo. Please enter again(name or asin) ";
			choice.clear();
			getline(cin, choice);
		}
		if(choice == "name")
			namebst->printMenu(cout);
		 else if (choice == "asin")
			asinbst->printMenu(cout);
		break;
	case 1:
		search();
		break;
	default:
		quitShopping();
	} // end switch
}

void CustomerInterface::search()
{
	bool status = false;
	string answer;
	string purchase;
	char option;
	string temp;
	string choice;
	string name;
	newOrder = new Order;
	
	do {
		cout << "Do you want to search for the product by name or asin? ";
		choice.clear();
		getline(cin, choice);
		Robot *rTemp = new Robot;
		if (choice == "name") 
		{
			cout << "Please enter name of the robot: ";
			name.clear();
			getline(cin, name);

			rTemp->set_name(name);
			status = namebst->search(*rTemp);
			if (status)
				*rTemp = namebst->getRobot(*rTemp);
		} 
		else
		{
			cout << "Please enter asin number of the robot: ";
			getAsinInput();
			rTemp->set_asin(number);
			status = asinbst->search(*rTemp);
			if (status)
				*rTemp = namebst->getRobot(*rTemp);
		}

		if (status == true) 
		{
			cout << *rTemp;
			cout << "\nDo you want to purchase this product? ";
			getline(cin, purchase);

			if (purchase == "yes") 
			{
				//call function in Heap to add robot to the priority queue
				*rTemp = namebst->getRobot(*rTemp);
				cout << "adding a robot to newOrder.\n";
				newOrder->addRobot(*rTemp);
				cout << "The product is your added to your order list." << endl << endl;
				cout << "Chose your shipping method:" << endl;
				cout << "O - Over night ($10.99)" << endl;
				cout << "R - Rush ($6.99)" << endl;
				cout << "S - Standard ($3.99)" << endl;
				getline(cin, temp);
				option = temp.c_str()[0];
				//call function in Heap to set method option
				newOrder->setPriorityVal(option);
				cout << endl << endl;
				// if / else: if the options are equal, call time functon
			}
			else
				cout << "The product wasn't added to your order." << endl << endl;
		}
		else 
		{
			cout << "We currently do not have this product in our store. " << endl;
		}

		cout << "Do you want to search another product? ";
		getline(cin, answer);

	} while (answer == "yes" || answer == "Yes");

	if (answer == "no" || answer == "NO")
	{
		if (newOrder->getSize() == 0)
		{
			cout << "newOrder has size 0!\n";
			return;
		}
		else
		{
			placeOrder();
			viewPurchase();
		}
	}


	//call function in Heap to add order
	heap->insert(*newOrder);
	cout << endl << endl;
}

void CustomerInterface::placeOrder()
{
	string firstname, lastname, email;
	string address, city, state;
	string temp;
	int zip;

	//cout << "Here is you order list: " << endl;
	//call function in Order.h to display the order list

	cout << "Please enter your purchase information: " << endl;
	cout << "First name: ";
	getline(cin, firstname);
	cout << "\nLast name: ";
	getline(cin, lastname);
	customer->setFirst(firstname);
	customer->setLast(lastname);
	cout << "Street address: ";
	getline(cin, address);
	customer->setAddress(address);
	cout << "\nCity: ";
	getline(cin, city);
	customer->setCity(city);
	cout << "\nState: ";
	getline(cin, state);
	customer->setState(state);
	cout << "\nZip: ";
	getline(cin, temp);
	zip = atoi(temp.c_str());
	customer->setZip(zip);
	cout << "Email: ";
	getline(cin, email);
	customer->setEmail(email);

	//call function in HashTable to add customer info
	table->insertData(*customer);

}
void CustomerInterface::viewPurchase() {
	if (newOrder->getSize() > 0)
		cout << newOrder;
	else
		cout << "You haven't yet made a purchase.\n";
}

void CustomerInterface::quitShopping() {
	if (newOrder->getSize() > 0)
		cout << "The receipt is sent to " << customer->getEmail() << endl;
	cout << "Exiting the customer interface.\n";
}

void CustomerInterface::promptUserInput()
{
	getline(cin, choice);
	menuNum = atoi(choice.c_str());
}

void CustomerInterface::getAsinInput()
{
	getline(cin, number);
	size_t position = 0;
	for (position = number.find(" "); position != string::npos; position =
			number.find(" ", position)) {
		number.replace(position, 1, "");
	}
	cout << "***Trimmed number[" << number << "]***\n";
}
