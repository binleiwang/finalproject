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
#include "BST.h"
#include "Robot.h"
using namespace std;

class EmployeeInterface {

private:
	Heap heap;
	vector<Order> orders; // TBD if need this, or if access orders a different way.
	BST<Robot> nameTree;
	BST<Robot> asinTree;
	bool checkName(string t);
	bool checkAsin(string t);

public:
	//EmployeeInterface();
	EmployeeInterface(Heap h, BST<Robot> t1, BST<Robot> t2);
	void welcome();
	void employeeRights();
    void viewOrders(); // print orders from the heap in order of priority
    void shipOrder(); // ships the #1 priority order. (delete root of heap)
    void listRobotsName(); // prints current inventory - primary key
    void listRobotsAsin(); // prints current inventory - secondary key
    void addNewRobot(); // add a new robot to the database
    void removeRobot(); // delete an existing robot from the database
    					// does not affect current orders
};




#endif /* EMPLOYEEINTERFACE_H_ */
