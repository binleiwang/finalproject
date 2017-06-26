/**
 * Binlei Wang
 * CIS 22C, Lab 7
 */


#ifndef AST_H_
#define AST_H_

#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <iomanip>
#include "Robot.h"
using namespace std;

class AST {
private:
    struct Node {
        Robot data;
        Node* left;
        Node* right;

        Node(Robot newdata):left(NULL), right(NULL), data(newdata) {}
    };

    typedef struct Node* NodePtr;

    NodePtr root;
    void insertData(NodePtr root, Robot robot);
    void Print(ostream& out, NodePtr root);
    void makeCopy(NodePtr copy);
    void freeNode(NodePtr root);
    bool search(NodePtr root, Robot robot);

    Robot minimum(NodePtr root);
    Robot maximum(NodePtr root);
    NodePtr deleteData(NodePtr root, Robot robot);
    void size(NodePtr root, int& size);
    int height(NodePtr root);
    void printMenu(ostream& out, NodePtr root);
    Robot findRobot(NodePtr root, string asin);
public:

    AST();
    AST(Robot robot);
    AST(const AST &bst);
    ~AST();
    Robot minimum();
    Robot maximum();
    bool empty();
    int size();
    Robot getRoot();
    int height();
    bool search(Robot robot);
    void insertData(Robot robot);
    void removeData(Robot robot);
    void Print(ostream& out);
    void printMenu(ostream& out);
    string getOtherKey(Robot robot);
    Robot getRobot(Robot robot);
    void printItem();
};
#endif /* AST_H_ */
