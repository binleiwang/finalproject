/*
 * EmployeeInterface.h
 *
 *  Created on: Jun 24, 2017
 *      Author: My Nguyen
 */

#ifndef EMPLOYEEINTERFACE_H_
#define EMPLOYEEINTERFACE_H_

#include <stdlib.h>
#include <string>
#include "List.h"
#include "Heap.h"
#include "AST.h"
#include "NMT.h"
#include "Robot.h"
using namespace std;

class EmployeeInterface {

private:
	Heap<Order> *heap;
	//vector<Order> orders; // TBD if need this, or if access orders a different way.
	NMT *nameTree;
	AST *asinTree;
	HashTable *customers;
	bool checkName(string t);
	bool checkAsin(string t);

public:
	EmployeeInterface();
	EmployeeInterface(Heap<Order> *h, NMT *t1, AST *t2, HashTable *t);
	void welcome();
	void menu();
	void employeeRights();
    void viewOrders(); // print orders from the heap in order of priority
    void shipOrder(); // ships the #1 priority order. (delete root of heap)
    void listRobotsName(); // prints current inventory - primary key
    void listRobotsAsin(); // prints current inventory - secondary key
    void addNewRobot(); // add a new robot to the database
    void removeRobot(); // delete an existing robot from the database
    					// does not affect current orders
    void searchCustomer();
    void quit();
};




#endif /* EMPLOYEEINTERFACE_H_ */
