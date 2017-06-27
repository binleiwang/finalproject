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
	int size;
	int priorityVal, numR;
	char opt;
	bool status;
	//int size;
	time_t orderTime;

	List<Robot> cart;
public:
	/*Constructors*/
	Order();
	/**Access Functions*/
	string getName() const;
	double getPrice() const;
	int getOrderNum() const;
	int getPriorityVal() const;
	char getOption() const;
	time_t getDate() const;
	bool getStatus() const;
	double getTotal() const;//for total price before tax and handling
	string shippingType() const;//to print out type of shipping
	double shippingFee() const;
	int getSize() const;
	void setSize();

	/**Manipulation Procedures*/
	void setName(Robot R); //should be (Robot R) name = R.getName();
	void setPrice(Robot R);
	void setOrderNum(int num);
	void setPriorityVal(char opt);
	void setOption(char o);
	void setDate();
	void setStatus(bool s);
	void setTotal();
	void addRobot(Robot R);
	char* displayTime(time_t) const;
	/**Additional Functions*/
	friend ostream& operator<<(ostream& os, Order& O);
	bool operator==(const Order& O);
	bool operator<(const Order& O);
	bool operator>(const Order& O);
	bool operator>=(const Order& O);

};

#endif /* ORDER_H_ */
