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
#include "Order.h"
#include "FileIO.h"
#include "Robot.h"
#include "AST.h"
#include "NMT.h"
#include "HashTable.h"
#include "Customer.h"
#include "Heap.h"
#include <cmath>

using namespace std;

static int orderNum = 1000;

CustomerInterface::CustomerInterface(NMT *bst1, AST *bst2, HashTable *hash, Heap<Order> *heap1, Robot *robot)
{
	namebst = bst1;
	asinbst = bst2;
	table = hash;
	heap = heap1;
	newOrder = new Order;
	customer = NULL;
	choice = "";
	menuNum = 0;
	menuOpt = 'z';
	number = "";
	temp = "";
} // need REF to newOrder (Order *)

void CustomerInterface::welcome() 
{
	cout << "Welcome to our robot store!  " << endl << endl;
}

void CustomerInterface::printOptions()
{
	cout << "1 - Search for a product" << endl;
	cout << setw(9) << "    - Find and display one record using the primary key (name)"
			<< endl;
	cout << setw(9) << "    - Find and display one record using the secondary key (ASIN - Amazon ID Number)"
			<< endl;
	cout << "2 - List Full Product Details" << endl;
	cout << setw(9) << "    - List data sorted by primary key" << endl;
	cout << setw(9) << "    - List data sorted by secondary key" << endl;
	cout << "3 - List Mini Product Menu" << endl;
	cout << "Q - Quit" << endl << endl;
}

void CustomerInterface::searchByKey()
{
	cout << "Please choose option 1, 2, 3 or Q to quit: ";
	promptUserInput();
	while(!checkMenuOpt()){
		cout << "Invalid choice." << endl;
		cout << "Please choose option 1, 2, 3 or Q to quit: ";
		promptUserInput();
	}

	switch (menuOpt)
	{
	case 'Q':
	case 'q':
		quitShopping();
		break;
	case '3':
		namebst->printMiniMenuFormatted(cout);
		break;
	case '2':
		cout << "\nDo you want to see list of robots by name or by ASIN? ";
		choice.clear();
		getline(cin, choice);
		while(!checkName(choice) && !checkAsin(choice)){
			cout << "Invalid entry or typo. Please try again (name or ASIN): ";
			choice.clear();
			getline(cin, choice);
		}
		if(checkName(choice))
			namebst->printMenu(cout);
		 else if (checkAsin(choice))
			asinbst->printMenu(cout);
		break;
	case '1':
		//searchTest();
		search();
		break;
	default:
		quitShopping();
	}
}

void CustomerInterface::searchTest()
{
	Robot rTemp;
	string query;
	List<Robot> rList;
	rList.deleteList();
	namebst->queryResult.deleteList();
	// ADD THE REST
	cout << "Name to search: ";
	getline(cin, query);
	rTemp.set_name(query);

	namebst->buildQuery(rTemp);
	rList = namebst->queryResult;
	printRobotList(rList);
}

void CustomerInterface::printRobotList(List<Robot> items)
{
	Robot rTemp;
	if (items.getLength() > 0)
		items.beginIterator();
	else
		cout << "Sorry, nothing was found.\n";
	for (int i = 1; i <= items.getLength(); i++)
	{
		rTemp = items.getIterator();
		cout << i << ": " << rTemp.get_name() << " || " << rTemp.get_asin() << endl;
		if (i < items.getLength())
			items.advanceIterator();
	}
}

void CustomerInterface::search()
 {
	bool status = false;
	string query;
	string choice;
	string name;
	namebst->printMiniMenuFormatted(cout);
	newOrder = buildNewOrder();
	do {
		Robot *rTemp = new Robot;
		cout << "Do you want to search for the product by name or ASIN (ID#)? ";
		choice.clear();
		getline(cin, choice);

		 while (!checkName(choice) && !checkAsin(choice))
		{
			 cout << "There was a problem with your input...\n";
			 cout << "Type ASIN or name: ";
			 getline(cin, choice);
		}
			if (checkName(choice)) {
				cout << "Please enter a name to search for: ";
				name.clear();
				getline(cin, name);
				rTemp->set_name(name);
				status = namebst->search(*rTemp);
				if (status)
				*rTemp = namebst->getRobot(*rTemp);
			} else if (checkAsin(choice)) {
				cout << "Please enter ASIN number of the robot: ";
				getAsinInput();
				rTemp->set_asin(number);
				status = asinbst->search(*rTemp);
				if (status)
				{
					name = asinbst->getOtherKey(*rTemp);
					rTemp->set_name(name);
					*rTemp = namebst->getRobot(*rTemp);
				}

			}
		if (status == true) {
			cout << *rTemp;
			cout << "Do you want to purchase this product? ";
			getline(cin, choice);

			if (choice == "yes") {
				//call function in Heap to add robot to the priority queue
				*rTemp = namebst->getRobot(*rTemp);
				cout << "Adding " << rTemp->get_name() << " to your order.\n";
				newOrder->addRobot(*rTemp);
				// update QTY of robot!!
			} else
				cout << "The product wasn't added to your order." << endl
						<< endl;
		} else {
			cout << "We currently do not have this product in our store. "
					<< endl;
		}

		cout << "Do you want to search for another product? ";
		getline(cin, choice);

	} while (choice == "yes" || choice == "Yes");

	if ((choice == "no" || choice == "NO") && (newOrder->getSize() > 0)) {
		newOrder->setTotal();
		newOrder->setDate();
		newOrder->displayTime(newOrder->getDate());
		cout << "The product is your added to your order list." << endl << endl;
		cout << "Chose your shipping method:" << endl;
		cout << "    O - Over night ($10.99)" << endl;
		cout << "    R - Rush ($6.99)" << endl;
		cout << "    S - Standard ($3.99)" << endl;
		getline(cin, temp);
		while (!checkShippingMethod()) {
			cout << "There was an error with your input; you only have these options:\n";
			cout << "    O - Over night ($10.99)" << endl;
			cout << "    R - Rush ($6.99)" << endl;
			cout << "    S - Standard ($3.99)" << endl;
			getline(cin, temp);
		}
		newOrder->setOption(temp.c_str()[0]);
		//call function in Heap to set method option
		newOrder->setPriorityVal(temp.c_str()[0]);
		cout << endl << endl;
		orderNum++;
		newOrder->setOrderNum(orderNum);
		// if / else: if the options are equal, call time functon
		if (newOrder->getSize() == 0) {
			cout << "PROBLEM: newOrder has size 0!\n";
			return;
		} else {
			placeOrder();
			viewPurchase();
			heap->insert(*newOrder);
			cout << "Inserting Order #" << newOrder->getOrderNum() << ". Heap size: " << heap->getSize() << endl;
			if (heap->getSize() > 1)
				heap->heapIncreaseKey(*newOrder, heap->getSize()-1); // doesn't work yet
		}
	}
	cout << "Returning to Main Menu.\n\n";
}

void CustomerInterface::placeOrder()
{
	string firstname, lastname, email;
	string address, city, state;
	string temp;
	int zip;
	customer = new Customer;
	cout << "Please enter your purchase information: " << endl;
	cout << "First name: ";
	getline(cin, firstname);
	cout << "Last name: ";
	getline(cin, lastname);
	customer->setFirst(firstname);
	customer->setLast(lastname);
	cout << "Street address: ";
	getline(cin, address);
	customer->setAddress(address);
	cout << "City: ";
	getline(cin, city);
	customer->setCity(city);
	cout << "State: ";
	getline(cin, state);
	customer->setState(state);
	cout << "Zip: ";
	getline(cin, temp);
	zip = atoi(temp.c_str());
	customer->setZip(zip);

	table->insertData(*customer);
	Order o;
	o = *newOrder;
	customer->insertOrder(o);

	orders = customer->getOrders();
}
void CustomerInterface::viewPurchase() {
	Order oTemp;
	cout << "Viewing Purchase:\n";
	if (orders.getLength() > 0)
		printOrders();
	else
		cout << "You haven't yet made a purchase.\n";
}

void CustomerInterface::quitShopping() {
	cout << "Exiting the customer interface.\n";
}

void CustomerInterface::promptUserInput()
{
	getline(cin, choice);
	//menuNum = atoi(choice.c_str());
	menuOpt = (choice.c_str()[0]);
}

void CustomerInterface::getAsinInput()
{
	getline(cin, number);
	size_t position = 0;
	for (position = number.find(" "); position != string::npos; position =
			number.find(" ", position)) {
		number.replace(position, 1, "");
	}
}

bool CustomerInterface::checkName(string t)
{
	for (unsigned int i = 0; i < t.length(); i++)
		t[i] = toupper(t[i]);
	return t == "N" || t == "NAME";
}

bool CustomerInterface::checkAsin(string t)
{
	for (unsigned int i = 0; i < t.length(); i++)
		t[i] = toupper(t[i]);
	return t == "A" || t == "ASIN";
}

bool CustomerInterface::checkMenuOpt()
{
	if (menuOpt != '1' && menuOpt != '2' && menuOpt != '3' && menuOpt != 'q' && menuOpt != 'Q')
		return false;
	return true;
}

Order *CustomerInterface::buildNewOrder()
{
	return new Order;
}

void CustomerInterface::printOrders()
{
	Order tempO;
	orders.beginIterator();

	for (int i = 0; i < orders.getLength(); i++)
	{
		tempO = orders.getIterator();
		cout << tempO;
		cout << endl;
		if (i < orders.getLength() - 1)
			orders.advanceIterator();
	}
}

bool CustomerInterface::checkShippingMethod()
{
	if (temp != "O" && temp != "o" && temp != "S" && temp != "s" && temp != "R" && temp != "r")
		return false;
	return true;
}
