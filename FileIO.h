/*
 * FileIO.h
 *
 *  Created on: Jun 18, 2017
 *      Author: My Nguyen
 */

#ifndef FILEIO_H_
#define FILEIO_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include "Robot.h"
#include "BST.h"

using namespace std;

class FileIO {
private:
	string infileName;
	string outfileName;

public:
	FileIO();
	void readFromFile(Robot &robot, BST<Robot> &bst1,  BST<Robot> &bst2);

};

#endif /* FILEIO_H_ */
