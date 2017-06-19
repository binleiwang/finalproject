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
	string name;
	string asin; // Amazon Standard Identification Number
	double price;
	string manufacturer;
	string purpose;
	string user;
	double weight; // lbs
	int rating; // average review rating 0-5.0
	int qtyInStock;
	string url;

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
	int get_rating();
	int get_quantity();
	string get_moreInfo();

	/**Manipulation Procedures*/
	void set_name(string a);
	void set_asin(string b);
	void set_price(double c);
	void set_manufacture(string d);
	void set_purpose(string e);
	void set_user(string f);
	void set_weight(double g);
	void set_rating(int h);
	void set_moreInfo(string i);

	/**Additional Functions*/
	friend ostream& operator<<(ostream& os, const Robot& robot);
	bool operator==(const Robot& robot);
	bool operator<(const Robot& robot);
	bool operator>(const Robot& robot);

};

#endif /* ROBOT_H_ */
