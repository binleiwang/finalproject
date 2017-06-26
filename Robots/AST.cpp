#include "AST.h"

/******************************************insertData********************************/


void AST::insertData(Robot robot)
{
	if (root==NULL)
	{
		root = new Node(robot);
	}
	else
	{
		insertData(root, robot);
	}
}


void AST::insertData(NodePtr root, Robot robot)
 {
	if (robot.get_asin() == root->data.get_asin()) {
		return;
	} else if (robot.get_asin() < root->data.get_asin()) {
		if (root->left == NULL) {
			root->left = new Node(robot);
		} else {
			insertData(root->left, robot);
		}
	} else {
		if (root->right == NULL) {
			root->right = new Node(robot);
		} else {
			insertData(root->right, robot);
		}
	}
}



/****************************Print functions*******************************/


void AST::Print(ostream& out)
{
    Print(out,root);
}

void AST::Print(ostream& out, NodePtr root) {
	if (root == NULL) {
		return;
	}
	Print(out, root->left);
	out << "Name: " << root->data.get_name() << endl;
	out << "Asin: " << root->data.get_asin() << endl;
	out << "Price: " << root->data.get_price() << endl;
	out << "Manufacture: " << root->data.get_manufacture() << endl;
	out << "Purpose: " << root->data.get_purpose() << endl;
	out << "User: " << root->data.get_user() << endl;
	out << "Weight: " << root->data.get_weight() << endl;
	out << "Rating: " << root->data.get_rating() << endl;
	out << "Quantity: " << root->data.get_quantity() << endl;
	Print(out, root->right);
}


void AST::printMenu(ostream& out)
{
	printMenu(out,root);
}

void AST::printMenu(ostream& out, NodePtr root)
{
    if(root==NULL)
    {
        return;
    }
    printMenu(out,root->left);
    out<<"Name: "<<root->data.get_name()<<endl;
    out<<"Asin: "<<root->data.get_asin()<<endl;
    out<<"Purpose: "<<root->data.get_purpose()<<endl << endl;
    printMenu(out,root->right);
}


/********************************search************************************/

void AST::printItem()
{
	cout << "Name: " << root->data.get_name() << endl;
	cout << "Asin: " << root->data.get_asin() << endl;
	cout << "Price: " << root->data.get_price() << endl;
	cout << "Manufacture: " << root->data.get_manufacture() << endl;
	cout << "Purpose: " << root->data.get_purpose() << endl;
	cout << "User: " << root->data.get_user() << endl;
	cout << "Weight: " << root->data.get_weight() << endl;
	cout << "Rating: " << root->data.get_rating() << endl;
	cout << "Quantity: " << root->data.get_quantity() << endl << endl;
}

bool AST::search(Robot robot)
 {
	assert(!empty());
	if (robot.get_asin() == root->data.get_asin()) {
		return true;
	} else
		return search(root, robot);
}

bool AST::search(NodePtr root, Robot robot)
 {
	if (robot.get_asin() == root->data.get_asin()) {
		return true;
	} else if (robot.get_asin() < root->data.get_asin()) {
		if (root->left != NULL) {
			return search(root->left, robot);
		} else {
			return false;
		}
	} else {
		if (root->right != NULL) {
			return search(root->right, robot);
		} else {
			return false;
		}
	}
}

Robot AST::findRobot(NodePtr root, string asin)
 {
	Robot *rEmpty = new Robot;
	if (asin == root->data.get_asin()) {
		return root->data;
	} else if (asin < root->data.get_asin()) {
		if (root->left != NULL) {
			return findRobot(root->left, asin);
		} else {
			return *rEmpty;
		}
	} else {
		if (root->right != NULL) {
			return findRobot(root->right, asin);
		} else {
			return *rEmpty;
		}
	}
}

/****************************************minimum and maximum*************************************/

Robot AST::minimum()
{
    assert(!empty());
    return minimum(root);
}

Robot AST::minimum(NodePtr root)
 {
	if (root == NULL) {
		return root->data;
	} else {
		if (root->left != NULL) {
			return minimum(root->left);
		} else {
			return root->data;
		}
	}
}



Robot AST::maximum()
{
    assert(!empty());
    return maximum(root);
}


Robot AST::maximum(NodePtr root)
 {
	if (root->right != NULL) {
		return maximum(root->right);
	} else {
		return root->data;
	}
}


/*****************************************deletion**********************************/


void AST::removeData(Robot robot)
{
    if (empty())
    	cout << "The product list is empty!\n";
    else if (!search(robot))
    	cout << "Sorry, " << robot.get_asin() << " was not found.\n";
    else
    	root = deleteData(root, robot);
}


typename AST::NodePtr AST::deleteData(NodePtr root, Robot robot)
 {
	if (root == NULL) {
		return root;
	} else if (robot.get_asin() < root->data.get_asin()) {
		root->left = deleteData(root->left, robot);
	} else if (robot.get_asin() > root->data.get_asin()) {
		root->right = deleteData(root->right, robot);
	} else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		} else if (root->left == NULL) {
			NodePtr N = root;
			root = root->right;
			delete N;
		} else if (root->right == NULL) {
			NodePtr N = root;
			root = root->left;
			delete N;
		} else {
			Robot temp = minimum(root->right);
			root->data = temp;
			root->right = deleteData(root->right, temp);
		}
	}
	return root;
}



/**************************************size****************************************/

int AST::size()
{
	int size=0;
    this->size(root,size);
    return size;
}


void AST::size(NodePtr root, int& size)
{
    if(root!=NULL)
    {
    size++;
    this->size(root->left,size);
    this->size(root->right,size);
    }
}


/**********************************height*************************************/


int AST::height()
{
	return height(root);
}

int AST::height(NodePtr root)
{
    if(root==NULL)
        return -1;
    return max(height(root->left),height(root->right))+1;
}


/***********************************Constructors and destructors**************************/

AST::AST()
{
    root = NULL;
}

AST::AST(const AST &bst)
{
	if (bst.root==NULL)
	{
		root=NULL;
	}
	else
	{
		root=NULL;
		makeCopy(bst.root);
	}
}

void AST::makeCopy(NodePtr copy)
{
    if(copy==NULL)
    {
        return;
    }
    insertData(copy->data);
    makeCopy(copy->left);
    makeCopy(copy->right);
}


AST::~AST()
{
    freeNode(root);
}


void AST::freeNode(NodePtr root)
{
    NodePtr N = root;
    if(root==NULL)
    {
        return;
    }
    freeNode(root->left);
    freeNode(root->right);
    delete N;
}


/****************************************additional access************************************/

bool AST::empty()
{
    return root==NULL;
}

Robot AST::getRoot()
{
    return root->data;
}

string AST::getOtherKey(Robot robot)
{
	Robot rTemp = findRobot(root, robot.get_asin());
	return rTemp.get_name();
}

Robot AST::getRobot(Robot robot)
{
	return findRobot(root, robot.get_asin());
}
