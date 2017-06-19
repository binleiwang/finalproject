/*
 * Order.h
 *
 *  Created on: Jun 15, 2017
 *      Author: kathy
 */

#ifndef ORDER_H_
#define ORDER_H_

#include <string>
#include <iostream>
#include <ctime>
#include "Robot.h"

using namespace std;

class Order {
private:
	string name;
	double price; //will link with Robot
	int orderNum; //like A001 ?
	int priorityVal;
	char opt;
	time_t orderTime;
public:
	/*Constructors*/
	Order();
	/**Access Functions*/
	string getName();
	double getPrice();
	int getOrderNum();
	int getPriorityVal();
	char getOption();
	time_t getDate();
	/**Manipulation Procedures*/
	void setName(Robot R); //should be (Robot R) name = R.getName();
	void setPrice(Robot R);
	void setOrderNum(int num);
	void setPriorityVal(int priority);
	void setOption(char o);
	void setDate(time_t tm);

	/**Additional Functions*/

	bool operator<(const Order& O);

	bool operator>(const Order& O);

};

#endif /* ORDER_H_ */
