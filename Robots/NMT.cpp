#include "NMT.h"

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

void NMT::Print(ostream& out) {
	Print(out, root);
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


void NMT::printMenu(ostream& out) {
	printMenu(out, root);
}

void NMT::printMenu(ostream& out, NodePtr root) {
	if (root == NULL) {
		return;
	}
	printMenu(out, root->left);
	out << "Name: " << root->data.get_name() << endl;
	out << "Asin: " << root->data.get_asin() << endl;
	out << "Purpose: " << root->data.get_purpose() << endl << endl;
	printMenu(out, root->right);
}

bool NMT::search(Robot robot)
 {
	assert(!empty());
	if (robot.get_name() == root->data.get_name()) {
		return true;
	} else
		return search(root, robot);
}

void NMT::printItem(NodePtr root, ostream &out)
{
	if (root == NULL)
		return;
	printItem(root->left, out);
	out << "-------------------------------------------\n";
	out << "Name: " << root->data.get_name() << endl;
	out << "Asin: " << root->data.get_asin() << endl;
	out << "Price: " << root->data.get_price() << endl;
	out << "Manufacture: " << root->data.get_manufacture() << endl;
	out << "Purpose: " << root->data.get_purpose() << endl;
	out << "User: " << root->data.get_user() << endl;
	out << "Weight: " << root->data.get_weight() << endl;
	out << "Rating: " << root->data.get_rating() << endl;
	out << "Quantity: " << root->data.get_quantity() << endl;
	out << "-------------------------------------------\n";
	printItem(root->right, out);
}

void NMT::printItem(ostream &out)
{
	printItem(root, out);
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

void NMT::printMiniMenu(ostream& out) {
	printMiniMenu(out, root);
}

void NMT::printMiniMenu(ostream& out, NodePtr root) {
	if (root == NULL) {
		return;
	}
	printMiniMenu(out, root->left);
	out << "Name: " << root->data.get_name();
	out << " || ASIN: " << root->data.get_asin() << endl;
	out << "Purpose: " << root->data.get_purpose() << endl << endl;
	printMiniMenu(out, root->right);
}

bool NMT::smartSearch(Robot robot)
{
	string query = robot.get_name();
	cout << "In smartSearch. searching for [" << query << "]\n";
	return smartSearch(root, robot);
}

bool NMT::smartSearch(NodePtr root, Robot robot)
{
	string query = robot.get_name();
	string name = root->data.get_name();
	size_t found = name.find(query);
	cout << "checking [" << name << "] vs [" << query << "]\n";
	cout << "Found: " << found << " npos: " << string::npos << endl;
	if (root->left != NULL)
		smartSearch(root->left, robot);
	if (root->right != NULL)
		smartSearch(root->right, robot);
	if (found != string::npos) {
		cout << "in smartSearch, found a match:" << name << endl;
		return true;
	}
	else
		return false;
}

void NMT::buildQuery(NodePtr root, string query)
 {
	string target = capitalize(query);
	string name = capitalize(root->data.get_name());
	size_t found = name.find(target);
	//cout << "checking [" << name << "] vs [" << target << "]\n";
	if (root->left != NULL)
		buildQuery(root->left, query);
	if (root->right != NULL)
		buildQuery(root->right, query);
	if (found != string::npos) {
		queryResult.insertEnd(root->data);
		return;
	}
	 else
		 return;
}

void NMT::buildQuery(Robot robot)
{
	buildQuery(root, robot.get_name());
}

string NMT::capitalize(string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
		s[i] = toupper(s[i]);
	return s;
}
