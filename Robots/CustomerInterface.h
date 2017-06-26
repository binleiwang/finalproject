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
#include "AST.h"
#include "NMT.h"
#include "Heap.h"
#include "HashTable.h"
#include "Order.h"

using namespace std;

class CustomerInterface {

private:
	NMT *namebst;
	AST *asinbst;
	HashTable *table;
	Heap<Order> *heap;
	Order *newOrder;
	Customer *customer;
	string choice, number;
	List<Order> orders;
	int menuNum;
	bool checkName(string t);
	bool checkAsin(string t);
public:
	CustomerInterface(NMT *bst1, AST *bst2, HashTable *hash, Heap<Order> *heap1, Customer *customer, Robot *robot);
	Order *buildNewOrder();
	void welcome();
	void printOptions();
	void searchByKey();
	void search();
	void placeOrder();
	void viewPurchase();
	void quitShopping();
	void promptUserInput();
	void getAsinInput();
};

#endif /* CUSTOMERINTERFACE_H_ */
