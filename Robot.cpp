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
	rating = 0;
	qtyInStock = 25;
	url = " ";
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
int Robot::get_rating(){
	return rating;
}
int Robot:: get_quantity(){
	return qtyInStock;
}
string Robot::get_moreInfo(){
	return url;
}

//Manipulation procedures
void Robot::set_name(string a){
	name = a;
}
void Robot::set_asin(string b){
	asin = b;
}
void Robot::set_price(double c){
	price = c;
}
void Robot::set_manufacture(string d){
	manufacturer = d;
}
void Robot::set_purpose(string e){
	purpose = e;
}
void Robot::set_user(string f){
	user = f;
}
void Robot::set_weight(double g){
	weight = g;
}
void Robot::set_rating(int h){
	rating = h;
}
void Robot::set_moreInfo(string i){
	url = i;
}

//Additional dunctions
ostream& operator<<(ostream& os, const Robot& robot)
{
	os << endl;
	os << "Information of robot " << robot.name << endl;
	os << "1. ASIN: " << robot.asin << endl;
	os << "2. Price: " << robot.price << endl;
	os << "3. Manufacture: " << robot.manufacturer << endl;
	os << "4. Purpose: " << robot.purpose << endl;
	os << "5. User: " << robot.user << endl;
	os << "6. Weight: " << robot.weight << endl;
	os << "7. Rating: " << robot.rating << endl;
	os << "8. For more information: " << robot.url << endl << endl;

	return os;
}

bool Robot::operator==(const Robot& robot){
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
}
