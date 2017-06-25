/*
 * UserInterface.h
 *
 *  Created on: Jun 18, 2017
 *      Author: My Nguyen
 */

#ifndef CUSTOMERINTERFACE_H_
#define CUSTOMERINTERFACE_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include "Robot.h"
#include "BST.h"
#include "Heap.h"
#include "HashTable.h"

using namespace std;

class CustomerInterface {

private:
	BST<Robot> namebst;
	BST<Robot> asinbst;
	Hashtable table;
	Heap heap;
	Order orders;
	Customer customers;

public:
	CustomerInterface(BST<Robot> bst1, BST<Robot> bst2, Hashtable hash, Heap heap1, Order order, Customer customer, Robot robot);
	void welcome();
	void searchByKey();
	void search();
	void placeOrder();
	void viewPurchase();
	void quitShopping();

};

#endif /* CUSTOMERINTERFACE_H_ */
