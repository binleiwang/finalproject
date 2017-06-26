/*
 * Robot.cpp
 *
 *  Created on: Jun 12, 2017
 *      Author: My Nguyen
 */

#include "Robot.h"
#include <iostream>
#include <iomanip>
#include <cmath>

//constructor
Robot::Robot()
{
	name = " ";
	asin = " ";
	price = 0.0;
	manufacturer = " ";
	purpose = " ";
	user = " ";
	weight = 0.0;
	rating = 0.0;
	qtyInStock = 25;
}

//Access functions
string Robot:: get_name(){
	return name;
}
string Robot::get_asin(){
	return asin;
}
double Robot::get_price(){
	return price;
}
string Robot::get_manufacture(){
	return manufacturer;
}
string Robot::get_purpose(){
	return purpose;
}
string Robot::get_user(){
	return user;
}
double Robot:: get_weight(){
	return weight;
}
double Robot::get_rating(){
	return rating;
}
int Robot:: get_quantity(){
	return qtyInStock;
}

//Manipulation procedures
void Robot::set_name(string called){
	name = called;
}
void Robot::set_asin(string number){
	asin = number;
}
void Robot::set_price(double cost){
	price = cost;
}
void Robot::set_manufacture(string made){
	manufacturer = made;
}
void Robot::set_purpose(string use){
	purpose = use;
}
void Robot::set_user(string type){
	user = type;
}
void Robot::set_weight(double pounds){
	weight = pounds;
}
void Robot::set_rating(int rate){
	rating = rate;
}
void Robot::set_quantity(int amount)
{
	qtyInStock = qtyInStock - amount;
}

//Additional dunctions
ostream& operator<<(ostream& os, const Robot& robot)
{
	os << "Information of robot " << robot.name << endl;
	os << "- ASIN: " << robot.asin << endl;
	os << setprecision(2) << fixed;
	os << "- Price: " << robot.price << endl;
	os << "- Manufacture: " << robot.manufacturer << endl;
	os << "- Purpose: " << robot.purpose << endl;
	os << "- User: " << robot.user << endl;
	os << setprecision(1) << fixed;
	os << "- Weight: " << robot.weight << endl;
	os << setprecision(1) << fixed;
	os << "- Rating: " << robot.rating << endl;
	os << "- Quantity: " << robot.qtyInStock << endl << endl;

	return os;
}

/*bool Robot::operator==(const Robot& robot){
	return (name == robot.name && asin==robot.asin);
}

bool Robot::operator<(const Robot& robot){
	bool status;
	if(name < robot.name)
		status = true;
	else if(name == robot.name && asin < robot.asin)
		status = true;
	else
		status = false;

	return status;
}

bool Robot::operator>(const Robot& robot)
{
	bool status;
	if(name > robot.name)
		status = true;
	else if(name ==  robot.name)
	{
		if(asin > robot.asin)
			status = true;
		else
			status = false;
	}

	return status;
}*/
