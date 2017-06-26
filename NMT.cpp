#include "NMT.h"

/******************************************insertData********************************/


void NMT::insertData(Robot robot)
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


void NMT::insertData(NodePtr root, Robot robot)
 {
	if (robot.get_name() == root->data.get_name()) {
		return;
	} else if (robot.get_name() < root->data.get_name()) {
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


void NMT::Print(ostream& out)
{
    Print(out,root);
}

void NMT::Print(ostream& out, NodePtr root) {
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


void NMT::printMenu(ostream& out)
{
	printMenu(out,root);
}

void NMT::printMenu(ostream& out, NodePtr root)
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

bool NMT::search(Robot robot)
 {
	assert(!empty());
	if (robot.get_name() == root->data.get_name()) {
		return true;
	} else
		return search(root, robot);
}

void NMT::printItem()
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

bool NMT::search(NodePtr root, Robot robot)
 {
	if (robot.get_name() == root->data.get_name()) {
		return true;
	} else if (robot.get_name() < root->data.get_name()) {
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

Robot NMT::findRobot(NodePtr root, string name)
 {
	Robot *rEmpty = new Robot;
	if (name == root->data.get_name()) {
		return root->data;
	} else if (name < root->data.get_name()) {
		if (root->left != NULL) {
			return findRobot(root->left, name);
		} else {
			return *rEmpty;
		}
	} else {
		if (root->right != NULL) {
			return findRobot(root->right, name);
		} else {
			return *rEmpty;
		}
	}
}

/****************************************minimum and maximum*************************************/

Robot NMT::minimum()
{
    assert(!empty());
    return minimum(root);
}

Robot NMT::minimum(NodePtr root)
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



Robot NMT::maximum()
{
    assert(!empty());
    return maximum(root);
}


Robot NMT::maximum(NodePtr root)
 {
	if (root->right != NULL) {
		return maximum(root->right);
	} else {
		return root->data;
	}
}


/*****************************************deletion**********************************/


void NMT::removeData(Robot robot)
{
    if (empty())
    	cout << "The product list is empty!\n";
    else if (!search(robot))
    	cout << "Sorry, " << robot.get_name() << " was not found.\n";
    else
    	root = deleteData(root, robot);
}


typename NMT::NodePtr NMT::deleteData(NodePtr root, Robot robot)
 {
	if (root == NULL) {
		return root;
	} else if (robot.get_name() < root->data.get_name()) {
		root->left = deleteData(root->left, robot);
	} else if (robot.get_name() > root->data.get_name()) {
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

int NMT::size()
{
	int size=0;
    this->size(root,size);
    return size;
}


void NMT::size(NodePtr root, int& size)
{
    if(root!=NULL)
    {
    size++;
    this->size(root->left,size);
    this->size(root->right,size);
    }
}


/**********************************height*************************************/


int NMT::height()
{
	return height(root);
}

int NMT::height(NodePtr root)
{
    if(root==NULL)
        return -1;
    return max(height(root->left),height(root->right))+1;
}


/***********************************Constructors and destructors**************************/

NMT::NMT()
{
    root = NULL;
}

NMT::NMT(const NMT &bst)
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

void NMT::makeCopy(NodePtr copy)
{
    if(copy==NULL)
    {
        return;
    }
    insertData(copy->data);
    makeCopy(copy->left);
    makeCopy(copy->right);
}


NMT::~NMT()
{
    freeNode(root);
}


void NMT::freeNode(NodePtr root)
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

bool NMT::empty()
{
    return root==NULL;
}

Robot NMT::getRoot()
{
    return root->data;
}

string NMT::getOtherKey(Robot robot)
{
	Robot rTemp = findRobot(root, robot.get_name());
	return rTemp.get_asin();
}

Robot NMT::getRobot(Robot robot)
{
	return findRobot(root, robot.get_name());
}
