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
}

void CustomerInterface::welcome() 
{
	cout << "Welcome to our robot store!  " << endl << endl;
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
	string choice = "";
	int menuNum;
	//char option;

	cout << "Please chose an option between 1 and 5 in the menu: ";
	cin >> menuNum;
	while(menuNum < 1 || menuNum > 5){
		cout << "Invalid choice." << endl;
		cout << "Only chose between 1 and 5. Enter again: ";
		cin >> menuNum;
	}

	switch (menuNum)
	{
	case 5:
		quitShopping();
		break;
	case 4:
	case 3:
		cout << "Please chose a product first." << endl;
		cout << "Please chose option 1 or 2 from the menu: ";
		cin >> menuNum;
		break;
	case 2:
		cout << "\nDo you want to see list of robots by name or by asin? ";
		cin >> choice;

		while(choice != "name" && choice != "asin"){
			cout << "Invalid entry or typo. Please enter again(name or asin) ";
			cin >> choice;
		}

		if(choice == "name")
			namebst->printMenu(cout);
		 //call function in BST to display a tree by name with only a few information
		 else if (choice == "asin")
			asinbst->printMenu(cout);
		 ////call function in BST to display a tree by name with only a few information

		//search();
		break;
	case 1:
		search();
		break;
	} // end switch
}

void CustomerInterface::search()
{
	bool status = false;
	string answer;
	string purchase;
	char option;
	string choice;
	string name, number;
	Robot *rTemp = new Robot;
	
	do {
		cout << "Do you want to search for the product by name or asin? ";
		cin >> choice;
		
		if (choice == "name") 
		{
			cout << "Please enter name of the robot: ";
			cin.ignore();
			getline(cin, name);
			rTemp->set_name(name);
			status = namebst->search(*rTemp);
		} 
		else
		{
			cout << "Please enter asin number of the robot: ";
			cin >> number;
			rTemp->set_asin(number);
			status = asinbst->search(*rTemp);
		}

		if (status == true) 
		{

			cout << "Do you want to purchase this product? ";
			cin >> purchase;

			newOrder = new Order;

			if (purchase == "yes") 
			{
				//call function in Heap to add robot to the priority queue
				*rTemp = namebst->getRobot(*rTemp);
				newOrder->addRobot(*rTemp);
				cout << "The product is your added to your order list." << endl << endl;
				cout << "Chose your shipping method:" << endl;
				cout << "O - Over night" << endl;
				cout << "R - Rush" << endl;
				cout << "S - Standard" << endl;
				cin >> option;
				//call function in Heap to set method option
				newOrder->setPriorityVal(option);
				cout << endl << endl;
				// if / else: if the options are equal, call tme functon
			}
			else
				cout << "The product wasn't added to your order." << endl << endl;
		}
		else 
		{
			cout << "We currently do not have this product in our store. " << endl;
		}

		cout << "Do you want to search another product? ";
		cin >> answer;

	} while (answer == "yes" || answer == "Yes");

	if (answer == "no" || answer == "NO")
	{
		placeOrder();
		viewPurchase();
	}


	//call function in Heap to add order
	heap->insert(*newOrder);
	cout << endl << endl;
}

void CustomerInterface::placeOrder()
{
	string firstname, lastname, email;
	string address, city, state;
	int zip;

	cout << "Here is you order list: " << endl;
	//call function in Order.h to display the order list

	cout << "You can make a purchase now. " << endl;
	cout << "Please enter your name: ";
	cin >> firstname >> lastname;
	customer->setFirst(firstname);
	customer->setLast(lastname);
	cin.ignore();
	cout << "Please enter your address: ";
	getline(cin, address);
	customer->setAddress(address);
	getline(cin, city);
	customer->setCity(city);
	getline(cin, state);
	customer->setState(state);
	cin >> zip;
	cin.ignore();
	customer->setZip(zip);
	cout << "Please enter yout email: ";
	getline(cin, email);
	customer->setEmail(email);

	//call function in HashTable to add customer info
	table->insertData(*customer);

}
void CustomerInterface::viewPurchase() {
	cout << newOrder;
}

void CustomerInterface::quitShopping() {
	cout << "The receipt is sent to " << customer->getEmail() << endl;
	cout << "Thank you for shopping at our store." << endl;
	cout << "Have a great day!!!" << endl << endl;
}

