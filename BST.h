/**
 * Binlei Wang
 * CIS 22C, Project Test
 */


#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

template<typename bstdata>
class BST {
private:
    struct Node {
        bstdata data;
        Node* left;
        Node* right;
        
        Node(bstdata newdata):left(NULL), right(NULL), data(newdata) {}
    };
    
    typedef struct Node* NodePtr;
    
    NodePtr root;
    
    /**Private helper functions*/
    void insertData(NodePtr root, bstdata value);
    //private helper function for insert
    //recursively inserts a value into the BST
    
    void inOrderPrint(ostream& out, NodePtr root);
    //private helper function for inOrderPrint
    //recursively prints tree values in order from smallest to largest
    
    void preOrderPrint(ostream& out, NodePtr root);
    //private helper function for preOrderPrint
    //recursively prints tree values in pre order
    
    void postOrderPrint(ostream& out, NodePtr root);
    //private helper function for postOrderPrint
    //recursively prints tree values in post order
    
    void makeCopy(NodePtr copy);
    //recursive helper function to the copy constructor
    
    void freeNode(NodePtr root);
    //private helper function for the destructor
    //recursively frees the memory in the BST
    
    bool search(NodePtr root, bstdata value);
    //recursive helper function to search
    //returns whether the value is found in the tree
    
    bstdata minimum(NodePtr root);
    //recursive helper function to minimum
    //returns the minimum value in the tree
    
    bstdata maximum(NodePtr root);
    //recursive helper function to maximum
    //returns the maximum value in the tree
    
    NodePtr deleteData(NodePtr root, bstdata value);
    //recursive helper function to removeData
    //removes value from the tree
    
    void size(NodePtr root, int& size);
    //recursive helper function to the size function
    //calculates the size of the tree
    //stores the result in size
    
    int height(NodePtr root);
    //recursive helper function to the height function
    //returns the height of the tree
    
public:
    
    /**constructors and destructor*/
    
    BST();
    //Instantiates a new BST
    
    BST(const BST &bst);
    //copy constructor
    
    ~BST();
    //deallocates the tree memory
    
    /**access functions*/
    
    bstdata minimum();
    //returns the minimum value in the BST
    //pre: !empty()
    
    bstdata maximum();
    //returns the maximum value in the BST and returns it
    //pre: !empty()
    
    bool empty();
    //determines whether the BST is empty
    
    int size();
    //returns the size of the tree
    
    bstdata getRoot();
    //returns the value stored at the root of the BST
    //pre: !empty()
    
    int height();
    //returns the height of the tree
    
    bool search(bstdata value);
    //returns whether the value is found in the tree
    //pre: !empty()
    
    /**manipulation procedures*/
    
    void insertData(bstdata value);
    //inserts a new value into the BST
    
    void removeData(bstdata value);
    //removes the specified value from the tree
    //pre: value is located in the tree
    
    /**additional functions*/
    
    void inOrderPrint(ostream& out);
    //calls the inOrderPrint function to print out the values
    //stored in the BST
    
    void preOrderPrint(ostream& out);
    //calls the reOrderPrint function to print out the values
    //stored in the BST
    
    void postOrderPrint(ostream& out);
    //calls the postOrderPrint function to print out the values
    //stored in the BST
};

/******************************************insertData********************************/

template<typename bstdata>
void BST<bstdata>::insertData(bstdata value)
{
    if (root==NULL)
    {
        root = new Node(value);
    }
    else
    {
        insertData(root, value);
    }
}

template<typename bstdata>
void BST<bstdata>::insertData(NodePtr root, bstdata value)
{
    if (value==root->data)
    {
        return;
    }
    else if (value<root->data)
    {
        if(root->left==NULL)
        {
            root->left = new Node(value);
        }
        else
        {
            insertData(root->left,value);
        }
    }
    else
    {
        if(root->right==NULL)
        {
            root->right = new Node(value);
        }
        else
        {
            insertData(root->right,value);
        }
    }
}

/****************************Print functions*******************************/

template<typename bstdata>
void BST<bstdata>::inOrderPrint(ostream& out)
{
    inOrderPrint(out,root);
}
//calls the inOrderPrint function to print out the values
//stored in the BST

template<typename bstdata>
void BST<bstdata>::preOrderPrint(ostream& out)
{
    preOrderPrint(out, root);
}

template<typename bstdata>
void BST<bstdata>::postOrderPrint(ostream& out)
{
    postOrderPrint(out, root);
}
//calls the postOrderPrint function to print out the values
//stored in the BST

template<typename bstdata>
void BST<bstdata>::inOrderPrint(ostream& out, NodePtr root)
{
    if(root==NULL)
    {
        return;
    }
    inOrderPrint(out,root->left);
    out<<root->data;
    inOrderPrint(out,root->right);
    
}

template<typename bstdata>
void BST<bstdata>::preOrderPrint(ostream& out, NodePtr root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        out<<root->data;
        preOrderPrint(out, root->left);
        preOrderPrint(out, root->right);
    }
}

template<typename bstdata>
void BST<bstdata>::postOrderPrint(ostream& out, NodePtr root)
{
    if(root==NULL)
    {
        return;
    }
    postOrderPrint(out,root->left);
    postOrderPrint(out,root->right);
    out<<root->data;
}

/********************************search************************************/

template<typename bstdata>
bool BST<bstdata>::search(bstdata value)
{
    assert(!empty());
    if(value==root->data)
        return true;
    else
        return search(root,value);
}

template<typename bstdata>
bool BST<bstdata>::search(NodePtr root, bstdata value)
{
    if(value==root->data)
    {
        return true;
    }
    else if (value<root->data)
    {
        if(root->left!=NULL)
        {
            return search(root->left,value);
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(root->right!=NULL)
        {
            return search(root->right,value);
        }
        else
        {
            return false;
        }
    }    
}

/****************************************minimum and maximum*************************************/

template<typename bstdata>
bstdata BST<bstdata>::minimum()
{
    assert(!empty());
    return minimum(root);
}
//returns the minimum value in the BST
//pre: !empty()

template<typename bstdata>
bstdata BST<bstdata>::minimum(NodePtr root)
{
    if (root==NULL)
    {
        return root->data;
    }
    else
    {
        if (root->left!=NULL)
        {
            return minimum(root->left);
        }
        else
        {
            return root->data;
        }
    }
}

template<typename bstdata>
bstdata BST<bstdata>::maximum()
{
    assert(!empty());
    return maximum(root);
}

template<typename bstdata>
bstdata BST<bstdata>::maximum(NodePtr root)
{    
    if (root->right!=NULL)
    {
        return maximum(root->right);
    }
    else
    {
        return root->data;
    }
    
}

/*****************************************deletion**********************************/

template<typename bstdata>
void BST<bstdata>::removeData(bstdata value)
{
    assert(!empty()&&search(value));
    root=deleteData(root, value);
}
//removes the specified value from the tree
//pre: value is located in the tree

template<typename bstdata>
typename BST<bstdata>::NodePtr BST<bstdata>::deleteData(NodePtr root, bstdata value)
{
    if (root==NULL)
    {
        return root;
    }
    else if (value<root->data)
    {
        root->left=deleteData(root->left,value);
    }
    else if (value>root->data)
    {
        root->right=deleteData(root->right,value);
    }
    else
    {
        if (root->left == NULL && root->right ==NULL)
        {
            delete root;
            root=NULL;
        }
        else if (root->left==NULL)
        {
            NodePtr N=root;
            root=root->right;
            delete N;
        }
        else if (root->right==NULL)
        {
            NodePtr N=root;
            root=root->left;
            delete N;
        }
        else
        {
            bstdata temp = minimum(root->right);
            root->data=temp;
            root->right=deleteData(root->right,temp);
        }
    }
    return root;
}
//recursive helper function to removeData
//removes value from the tree

/**************************************size****************************************/

template<typename bstdata>
int BST<bstdata>::size()
{
    int size=0;
    this->size(root,size);
    return size;
}
//returns the size of the tree

template<typename bstdata>
void BST<bstdata>::size(NodePtr root, int& size)
{
    if(root!=NULL)
    {
        size++;
        this->size(root->left,size);
        this->size(root->right,size);
    }
}
//recursive helper function to the size function
//calculates the size of the tree
//stores the result in size

/**********************************height*************************************/

template<typename bstdata>
int BST<bstdata>::height()
{
    return height(root);
}
//returns the height of the tree

template<typename bstdata>
int BST<bstdata>::height(NodePtr root)
{
    if(root==NULL)
        return -1;
    return max(height(root->left),height(root->right))+1;
}
//recursive helper function to the height function
//returns the height of the tree

/***********************************Constructors and destructors**************************/

template<typename bstdata>
BST<bstdata>::BST()
{
    root = NULL;
}

template<typename bstdata>
BST<bstdata>::BST(const BST &bst)
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

template<typename bstdata>
void BST<bstdata>::makeCopy(NodePtr copy)
{
    if(copy==NULL)
    {
        return;
    }
    insertData(copy->data);
    makeCopy(copy->left);
    makeCopy(copy->right);
}

template<typename bstdata>
BST<bstdata>::~BST()
{
    freeNode(root);
}

template<typename bstdata>
void BST<bstdata>::freeNode(NodePtr root)
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

template<typename bstdata>
bool BST<bstdata>::empty()
{
    return root==NULL;
}

template<typename bstdata>
bstdata BST<bstdata>::getRoot()
{
    return root->data;
}

#endif /* BST_H_ */
