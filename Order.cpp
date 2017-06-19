/*
 * Order.cpp
 *
 *  Created on: Jun 17, 2017
 *      Author: kathy
 */
#include "Order.h"
#include <string>
#include <iostream>
#include <ctime>
#include "Robot.h"

using namespace std;
/*Constructors*/
Order::Order() {
	name = "";
	price = 0.0;
	orderNum = 0;
	priorityVal = 0;
	opt = NULL;
	orderTime = 0;
}
/**Access Functions*/
string Order::getName() {
	return name;
}
double Order::getPrice() {
	return price;
}
int Order::getOrderNum() {
	return orderNum;
}
int Order::getPriorityVal() {
	return priorityVal;
}
char Order::getOption() {
	return opt;
}
time_t Order::getDate() {
	return orderTime;
}
/**Manipulation Procedures*/
void Order::setName(Robot R) {
	name = R.get_name();
}
void Order::setPrice(Robot R) {
	price = R.get_price();
}
void Order::setOrderNum(int num) {
	orderNum = num;
}
void Order::setPriorityVal(int priority) {
	if(opt == 'O'||opt =='o') //option for overnight
		priorityVal = 6;
	else if(opt =='R'||opt =='r')//option for 3 days shipping
		priorityVal = 4;
	else
		priorityVal =1;
}
void Order::setOption(char o) {
	opt = o;
}
void Order::setDate(time_t tm) {
	orderTime = time(&tm); //function to display current time
}

/**Additional Functions*/
bool Order::operator==(const Order& O) {
	return priorityVal == O.priorityVal;
}

bool Order::operator<(const Order& O) {
	if (priorityVal == O.priorityVal)
		return orderTime < O.orderTime;
	else
		return priorityVal < O.priorityVal;
}

bool Order::operator>(const Order& O) {
	if (priorityVal == O.priorityVal)
		return orderTime > O.orderTime;
	else
		return priorityVal > O.priorityVal;
}

