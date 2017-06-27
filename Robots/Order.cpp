///*
// * Order.cpp
// *
// *  Created on: Jun 17, 2017
// *      Author: kathy
// */

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Robot.h"
#include "List.h"
#include "Order.h"

using namespace std;
Order::Order() {
	//size = 0;
	numR = 0;
	size = 0;
	name = "";
	price = 0.0;
	orderNum = 0;
	priorityVal = 0;
	opt = 'z';
	orderTime = 0;
	status = false;
	totalPrice = 0.0;
}

string Order::getName() const {
	return name;
}
double Order::getPrice() const {
	return price;
}
int Order::getOrderNum() const {
	return orderNum;
}
int Order::getPriorityVal() const {
	return priorityVal;
}
char Order::getOption() const {
	return opt;
}
time_t Order::getDate() const {
	return orderTime;
}
double Order::getTotal() const {
	return totalPrice;
}
bool Order::getStatus() const {
	return status;
}
int Order::getSize() const {
	return size;
}
double Order::shippingFee() const {
	if (getOption() == 'O' || getOption() == 'o')
		return 10.99;
	else if (getOption() == 'R' || getOption() == 'r') //option for 3 days shipping
		return 6.99;
	else
		return 3.99;
}
string Order::shippingType() const {
	string t;
	if (getOption() == 'O' || getOption() == 'o')
		t = "Overnight shipping";
	else if (getOption() == 'R' || getOption() == 'r')
		t = "Rush shipping";
	else
		t = "Standard shipping";
	return t;
}
void Order::setName(Robot R) {
	name = R.get_name();
}
void Order::setPrice(Robot R) {
	price = R.get_price();
}
void Order::setOrderNum(int num) {
	orderNum = num;
}
void Order::setPriorityVal(char opt) {
	if (opt == 'O' || opt == 'o') //option for overnight
		priorityVal = 6;
	else if (opt == 'R' || opt == 'r') //option for 3 days shipping
		priorityVal = 4;
	else
		priorityVal = 1;
}
void Order::setOption(char o) {
	opt = o;
}
void Order::setDate() {
	 orderTime =time(0);

}
void Order::setStatus(bool s) {
	status = s;
}

void Order::setSize() {
	size = cart.getLength();
}
void Order::addRobot(Robot R) {
	cart.insertEnd(R);
	size++;
	price += R.get_price();
}
char* Order:: displayTime(time_t tm)const{
	return ctime(&tm);
}

void Order::setTotal() {
	double tol = 0;
	cart.beginIterator();
	for (int i = 0; i < cart.getLength(); i++) {
		tol += cart.getIterator().get_price();
		if (i < cart.getLength() - 1)
			cart.advanceIterator();
	}
	totalPrice = tol;
}

ostream& operator<<(ostream& os, const Order& O) {
	os << "Order number: " << O.orderNum << endl;
	for (int i = 0; i < O.cart.getLength(); i++) {
		os << "Product " << i + 1 << ": " << O.name << endl;
		os << "Price: $" << O.price << endl;
		os << "Order time: " << O.displayTime(O.getDate()) << endl;
	}

	os << "Shipping option: " << O.shippingType();
	os << "    Status:" << boolalpha << O.getStatus() << endl;
	os << "Price before tax and handling: " << fixed << setprecision(2) << O.getTotal() << endl;
	os << "Shipping fee: " << O.shippingFee() << endl;
	os << "Total price: " << (O.getTotal() + O.shippingFee()) * 1.09 << endl;
	return os;
}

bool Order::operator==(const Order& O) {
	if(priorityVal == O.priorityVal)
		return true;
	else
		return orderTime == O.orderTime;
}

bool Order::operator<(const Order& O) {
	if(priorityVal < O.priorityVal)
		return true;
	else
		return orderTime > O.orderTime;
	}

bool Order::operator>(const Order& O) {
	if (priorityVal > O.priorityVal)
		return true;
	else
		return orderTime < O.orderTime;

}

bool Order::operator>=(const Order& O) {
	if (priorityVal >= O.priorityVal)
		return true;
	else
		return orderTime <= O.orderTime;
}

//
//
//#include <string>
//#include <iostream>
//#include <iomanip>
//#include <ctime>
//#include "Robot.h"
//#include "List.h"
//#include "Order.h"
//
//using namespace std;
//Order::Order() {
//	//size = 0;
//	numR = 0;
//	size = 0;
//	name = "";
//	price = 0.0;
//	orderNum = 0;
//	priorityVal = 0;
//	opt = 'z';
//	orderTime = 0;
//	status = false;
//	totalPrice = 0.0;
//}
//
//string Order::getName() const {
//	return name;
//}
//double Order::getPrice() const {
//	return price;
//}
//int Order::getOrderNum() const {
//	return orderNum;
//}
//int Order::getPriorityVal() const {
//	return priorityVal;
//}
//char Order::getOption() const {
//	return opt;
//}
//double Order::getTotal() const {
//	return totalPrice;
//}
//bool Order::getStatus() const {
//	return status;
//}
//int Order::getSize() const {
//	return size;
//}
//double Order::shippingFee() const {
//	if (getOption() == 'O' || getOption() == 'o')
//		return 10.99;
//	else if (getOption() == 'R' || getOption() == 'r') //option for 3 days shipping
//		return 6.99;
//	else if (getOption() == 'S' || getOption() == 's')
//		return 3.99;
//	else
//		cout << "There was an error in Order::shippingFee!\n";
//	return 9999;
//}
//string Order::shippingType() const {
//	string t;
//	if (getOption() == 'O' || getOption() == 'o')
//	{
//		t = "Overnight shipping";
//	}
//	else if (getOption() == 'R' || getOption() == 'r')
//		t = "Rush shipping";
//	else
//		t = "Standard shipping";
//	return t;
//}
//void Order::setName(Robot R) {
//	name = R.get_name();
//}
//void Order::setPrice(Robot R) {
//	price = R.get_price();
//}
//void Order::setOrderNum(int num) {
//	orderNum = num;
//}
//void Order::setPriorityVal(char opt) {
//	if (opt == 'O' || opt == 'o') //option for overnight
//		priorityVal = 6;
//	else if (opt == 'R' || opt == 'r') //option for 3 days shipping
//		priorityVal = 4;
//	else
//		priorityVal = 1;
//}
//void Order::setOption(char o) {
//	opt = o;
//}
//
//void Order::setStatus(bool s) {
//	status = s;
//}
//
//void Order::setSize() {
//	size = cart.getLength();
//}
//void Order::addRobot(Robot R) {
//	cart.insertEnd(R);
//	size++;
//	price += R.get_price();
//}
//void Order::setTotal() {
//	double tol = 0;
//	cart.beginIterator();
//	for (int i = 0; i < cart.getLength(); i++) {
//		tol += cart.getIterator().get_price();
//		if (i < cart.getLength() - 1)
//			cart.advanceIterator();
//	}
//	totalPrice = tol;
//}
//
//ostream& operator<<(ostream& os, Order O) {
//	cout << "-----------------------------------------\n";
//	os << "Order number: " << O.orderNum << endl;
//	O.cart.beginIterator();
//	for (int i = 0; i < O.cart.getLength(); i++) {
//		os << "Product " << i + 1 << ": " << O.cart.getIterator().get_name() << endl;
//		os << "Price: $" << O.cart.getIterator().get_price() << endl;
//		O.cart.advanceIterator();
//	}
//	os << "Order time: " << O.displayTime(O.getDate()) << endl;
//	os << "Shipping option: " << O.shippingType();
//	os << "\tShipped yet: " << (O.getStatus() ? "Yes" : "No") << endl;
//	os << "Price before tax and handling: " << fixed << setprecision(2) << O.getTotal() << endl;
//	os << "Tax: " << O.getTotal() * 0.09 << endl;
//	os << "Shipping fee: " << O.shippingFee() << endl;
//	os << "Total price: " << O.getTotal() * 1.09 + O.shippingFee() << endl;
//	cout << "-----------------------------------------\n";
//	return os;
//}
//bool Order::operator==(const Order& O) {
//	if (priorityVal != O.priorityVal)
//		return orderTime == O.orderTime;
//	else
//		return priorityVal == O.priorityVal;
//}
//
//bool Order::operator<(const Order& O) {
//	if (priorityVal == O.priorityVal)
//		return orderTime > O.orderTime;
//	else
//		return priorityVal < O.priorityVal;
//}
//
//bool Order::operator>(const Order& O) {
//	if (priorityVal == O.priorityVal)
//		return orderTime < O.orderTime;
//	else
//		return priorityVal > O.priorityVal;
//}
//
//bool Order::operator>=(const Order& O) {
//	if (priorityVal == O.priorityVal)
//		return orderTime <= O.orderTime;
//	else
//		return priorityVal >= O.priorityVal;
//}
//
//time_t Order::getDate() const {
//	return orderTime;
//}
//void Order::setDate() {
//	 orderTime =time(0);
//
//}
//char* Order:: displayTime(time_t tm) const {
//	return ctime(&tm);
//}
