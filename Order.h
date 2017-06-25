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
#include "List.h"

using namespace std;

class Order {
private:
	string name;
	double price;
	double totalPrice;
	int orderNum;
	int priorityVal;
	char opt;
	bool status;
	time_t orderTime;

	List<Robot> cart;
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
	bool getStatus();
	double getTotal();//for total price before tax and handling
	string shippingType();//to print out type of shipping
	double shippingFee();

	/**Manipulation Procedures*/
	void setName(Robot R); //should be (Robot R) name = R.getName();
	void setPrice(Robot R);
	void setOrderNum(int num);
	void setPriorityVal(char opt);
	void setOption(char o);
	void setDate(time_t tm);
	void setStatus(bool s);
	void setTotal(List<Robot>cart);
	void addRobot(Robot R);
	//void setTotalPrice();
	/**Additional Functions*/
	friend ostream& operator<<(ostream& os, const Order& O);
	bool operator==(const Order& O);
	bool operator<(const Order& O);
	bool operator>(const Order& O);
	bool operator>=(const Order& O);

};

#endif /* ORDER_H_ */
