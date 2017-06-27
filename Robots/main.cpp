#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
//#include "ColorConsole.h"
#include "FileIO.h"
#include "List.h"
#include "AST.h"
#include "NMT.h"
#include "Robot.h"
#include "HashTable.h"
#include "CustomerInterface.h"
#include "EmployeeInterface.h"

using namespace std;

bool isCustomer(string input);
bool isEmployee(string input);
bool quitProgram(string input);
void printRobotAscii();
void printMenuInstructions();
void welcome();

int main()
{
	welcome();
	FileIO file;
	Robot robot;
	NMT nameTree;
	AST asinTree;
	Heap<Order> orders;
	HashTable customers;
	string input = "x";

	file.readFromFile(&robot, &nameTree, &asinTree);
	CustomerInterface c(&nameTree, &asinTree, &customers, &orders, &robot);
	EmployeeInterface e(&orders, &nameTree, &asinTree);

	// when you search for an item,
	// it prints to screen 2 times, once for each tree (or it did before i removed the code)
	// i moved print to its own function, but it wont work within th eBST class.
	// *** use a robot print function
	// *  cout << r;
	printMenuInstructions();
	getline(cin, input);

	while (!quitProgram(input))
	{
		if (isCustomer(input))
		{
			c.welcome();
			c.printOptions();
			c.searchByKey();
		}
		else if (isEmployee(input))
		{
			e.welcome();
			e.employeeRights();
		}
		else
		{
			cout << "There was a problem with your input...\n";
		}
		printMenuInstructions();
		input.clear();
		getline(cin, input);
		// if q
		// write output file.
		if (input == "q" || input == "Q")
		{
			cout << "Writing data to outputFile.txt.\n";
			file.writeToFile(&nameTree, &asinTree, &customers);
		}
	}
// exit msg?
	cout << "Thank you for shopping at our store." << endl;
	cout << "Have a great day!!!" << endl << endl;
	printRobotAscii();
	return 0;
}

bool isCustomer(string input)
{
	if (input == "C" || input == "c")
		return true;
	return false;
}

bool isEmployee(string input)
{
	if (input == "E" || input == "e")
		return true;
	return false;
}

bool quitProgram(string input)
{
	if (input == "Q" || input == "q")
		return true;
	return false;
}

void welcome()
{
	cout << "Welcome to Robot Land!\n";
	cout << "This program simulates a marketplace where you can buy and sell robots.\n";
	cout << "It utilizes several data structures, such as a heap, hash table, binary search trees, and linked lists.\n";
	cout << "You may interact with the item database as either a customer (to search and order Robots),\n";
	cout << "or an employee (to ship/view orders and add/delete Robots from the store.\n\n";
}

void printMenuInstructions()
{
	cout << "========================= Main Menu ==========================\n";
	cout << "Please type C for customer, E for employee, or type Q to quit.\n";
}

void printRobotAscii()
{
	cout << "          ________" << endl;
	cout << "     _,.-Y  |  |  Y-._" << endl;
	cout << "    .-~\"   ||  |  |  |   \"-." << endl;
	cout << "    I\" \"\"==\"|\" !\"\"! \"|\"[]\"\"|     _____" << endl;
	cout << "    L__  [] |..------|:   _[----I\" .-{\"-." << endl;
	cout << "   I___|  ..| l______|l_ [__L]_[I_/r(=}=-P" << endl;
	cout << "  [L______L_[________]______j~  '-=c_]/=-^" << endl;
	cout << "    \\_I_j.--.\\==I|I==_/.--L_]" << endl;
	cout << "    [_((==)[`-----\"](==)j" << endl;
	cout << "    I--I\"~~\"\"\"~~\"I--I" << endl;
	cout << "    |[]|         |[]|" << endl;
	cout << "    l__j         l__j" << endl;
	cout << "    |!!|         |!!|" << endl;
	cout << "    |..|         |..|" << endl;
	cout << "    ([])         ([])" << endl;
	cout << "    ]--[         ]--[" << endl;
	cout << "    [_L]         [_L]  -Row  (the Ascii-Wizard of Oz)" << endl;
	cout << "   /|..|\\       /|..|\\" << endl;
	cout << "  `=}--{='     `=}--{='" << endl;
	cout << " .-^--r-^-.   .-^--r-^-." << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
