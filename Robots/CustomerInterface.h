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

using namespace std;

class CustomerInterface {

private:
	NMT *namebst;
	AST *asinbst;
	HashTable *table;
	Heap<Order> *heap;
	Order *newOrder;
	Customer *customer;

public:
	CustomerInterface(NMT *bst1, AST *bst2, HashTable *hash, Heap<Order> *heap1, Order *order, Customer *customer, Robot *robot);

	void welcome();
	void searchByKey();
	void search();
	void placeOrder();
	void viewPurchase();
	void quitShopping();

};

#endif /* CUSTOMERINTERFACE_H_ */
