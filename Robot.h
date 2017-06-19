/*
 * Robot.h
 *
 *  Created on: Jun 12, 2017
 *      Author: My Nguyen
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <string>
#include <ostream>

using namespace std;

class Robot{

private:
	string name;	//primary key
	string asin; 	//secondary key
	double price;
	string manufacturer;
	string purpose;
	string user;
	double weight; // lbs
	double rating; // average review rating 0-5.0
	int qtyInStock;

public:
	//Constructor
	Robot();

	/**Access Functions*/
	string get_name();
	string get_asin();
	double get_price();
	string get_manufacture();
	string get_purpose();
	string get_user();
	double get_weight();
	double get_rating();
	int get_quantity();

	/**Manipulation Procedures*/
	void set_name(string called);
	void set_asin(string number);
	void set_price(double cost);
	void set_manufacture(string made);
	void set_purpose(string use);
	void set_user(string type);
	void set_weight(double pounds);
	void set_rating(int rate);
	void set_quantity(int amount);

	/**Additional Functions*/
	friend ostream& operator<<(ostream& os, const Robot& robot);
	bool operator==(const Robot& robot);
	bool operator<(const Robot& robot);
	bool operator>(const Robot& robot);
};

#endif /* ROBOT_H_ */
