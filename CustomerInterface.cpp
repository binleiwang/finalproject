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
#include "BST.h"
#include "Order.h"
#include "HashTable.h"
#include "Customer.h"
#include "Heap.h"
#include <cmath>

using namespace std;

CustomerInterface::CustomerInterface(BST<Robot> bst1, BST<Robot> bst2, Hashtable hash, Heap heap1, Order order, Customer customer, Robot robot)
{
	namebst = bst1;
	asinbst = bst2;
	table = hash;
	heap = heap1;
	orders = order;
	customers = customer;
}

void CustomerInterface::welcome() {
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
	string choice;
	int option;

	cout << "Please chose an option between 1 and 5 in the menu: ";
	cin >> option;

	while(option < 1 || option > 5){
		cout << "Invalid choice." << endl;
		cout << "Only chose between 1 and 5. Enter again: ";
		cin >> option;
	}

	do{
		switch (option) {
		case 5:
			quitShopping();
			break;
		case 4:
		case 3:
			cout << "Please chose a product first." << endl;
			cout << "Please chose option 1 or 2 from the menu ";
			cin >> option;
			break;
		case 2:
			cout << "\nDo you want to see list of robots by name or by asin? ";
			cin >> choice;

			while (choice != "name" || choice != "asin") {
				cout
						<< "Invalid entry or typo. Please enter again(name or asin) ";
				cin >> choice;
			}

			/*if(choice == "name")
			 //call function in BST to display a tree by name with only a few information
			 else(choice == "asin")
			 ////call function in BST to display a tree by name with only a few information
			 */
			search();
			break;
		case 1:
			search();
			break;
		} // end switch
	} while (option == 1 || option == 2);
}

void CustomerInterface::search()
{
	bool status;
	string answer;
	string purchase;
	char option;
	char method;
	string choice;
	string name, number;
	do {
		cout << "Do you want to search for the product by name or asin? ";
		cin >> choice;
		if (choice == "name") {
			cout << "Please enter name of the robot: ";
			cin >> name;
			//call search function in BST to search by name
			//status = namebst.search(number);
			//display the product info if it's found
		} else {
			cout << "Please enter asin number of the robot: ";
			cin >> number;
			//call search function in BST to search by asin
			//status = asinbst.search(number);
			//display the product info if it's found
		}

		if (status == true) {
			cout << "Do you want to purchase this product? ";
			cin >> purchase;

			if (purchase == "yes") {
				//call function in Heap to add robot to the priority queue
				//order.addRobot(name);
				cout << "The product is your added to your order list." << endl << endl;
				cout << "Chose your shipping method:" << endl;
				cout << "O - Over night" << endl;
				cout << "R - Rush" << endl;
				cout << "S - Standard" << endl;
				cin >> method;
				//call function in Heap to set method option
				//order.setPriorityVal(option);
				cout << endl << endl;
			}
			else
				cout << "The product wasn't added to your order." << endl << endl;
		}
		else {
			cout << "We currently do not have this product in our store. " << endl;
		}

		cout << "Do you want to search another product? ";
		cin >> answer;

	} while (answer == "yes" || answer == "Yes");

	//call function in Heap to add order
	//heap.heapInsert(order);
	cout << endl << endl;

}

void CustomerInterface::placeOrder()
{
	string firstname, lastname, email;
	string address, city, state;
	int zip;

	cout << "You can make a purchase now. " << endl;
	cout << "Please enter your name: ";
	cin >> firstname >> lastname;
	//customers.setFirst(firstname);
	//customers.setLast(lastname);
	cin.ignore();
	cout << "Please enter your address: ";
	getline(cin, address);
	//custmomers.setAddress(address);
	getline(cin, city);
	//customers.setCity(city);
	getline(cin, state);
	//customers.setState(state);
	cin >> zip;
	cin.ignore();
	//customers.setZip(zip);
	cout << "Please enter yout email: ";
	getline(cin, email);
	//customers.setEmail(email);

	//call function in HashTable to add customer info
	//table.insertData(customers);

}
void CustomerInterface::viewPurchase() {
	cout << "Here is you order list: " << endl;
	//call function in Heap.h to display the order list
	//heap.showOrder(int index);
}

void CustomerInterface::quitShopping() {
	cout << "The receipt is sent to " << customers.getEmail() << endl;
	cout << "Thank you for shopping at our store." << endl;
	cout << "Have a great day!!!" << endl << endl;
}

