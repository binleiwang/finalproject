/*
 * FileIO.cpp
 *
 *  Created on: Jun 18, 2017
 *      Author: My Nguyen
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "FileIO.h"
#include "Robot.h"
#include "BST.h"
#include <fstream>

using namespace std;

FileIO::FileIO() {

	infileName = "robotFile.txt";
	outfileName = "outputFile.txt";
}

void FileIO::readFromFile(Robot &robot, BST<Robot> &bst1, BST<Robot> &bst2)
{
	ofstream outputFile;
	ifstream inputFile;
	string name, asin;
	double price, weight;
	string manufacture;
	string purpose, user;
	double rate;
	string empty;

	//open input file
	inputFile.open(infileName.c_str());

	//read from file
	while(!inputFile.eof())
	{
		getline(inputFile,name);
		robot.set_name(name);
		getline(inputFile, asin);
		robot.set_asin(asin);
		inputFile >> price;
		robot.set_price(price);

		inputFile.ignore();

		getline(inputFile, manufacture);
		robot.set_manufacture(manufacture);
		getline(inputFile, purpose);
		robot.set_purpose(purpose);
		getline(inputFile, user);
		robot.set_user(user);
		inputFile >> weight;
		robot.set_weight(weight);
		inputFile >> rate;
		robot.set_rating(rate);

		inputFile.ignore();

		getline(inputFile, empty);

		bst1.PriInsert(robot);
		bst2.SecInsert(robot);
	}
}
