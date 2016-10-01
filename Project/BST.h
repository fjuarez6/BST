/*
Juarez, Freddy
CS A200
September 15, 2016

Class BST
*/

#ifndef BST_H
#define BST_H

#include <string>		
#include <iostream>
using namespace std;

template<class T>
class Node
{
	template<class T>
	friend class BST;
public:
	Node(){}
	~Node(){}
private:
    T data;
    Node<T> *rlink, *llink;
};

template<class T>
class BST
{
public:

	BST();
		//Default constructor

	~BST();   
		//Destructor  

    void destroyTree();
		//Deallocates the memory space occupied by the BST

	// Declaration function insert 
	// (Only one declaration for both recursive and non-recursive)
	// Inserts a given item in the BST 
	void insert(T num);
	
	void inorderTraversal() const;
		//Prints nodes of the BT in the inorder sequence
	
	// Declaration function totalNodes
	int totalNodes() const;
		//Determines the number of nodes in the BST
	
private:	
	Node<T> *root; //Pointer to the root

	void destroyTree(Node<T>* &p);
		//Destroy the BST to which p points
	
	// Declaration overloaded function insert (recursive)
	// Inserts a new node in the tree
	void insert(T num, Node<T>* &p);


	// Declaration overloaded function inorderTraversal
	// Prints the inorder traversal of the BT to which p points
	void inorderTraversal(Node<T>* p) const;

	// Declaration overloaded function totalNodes
	// Returns the number of nodes in the BST to which p points
	int totalNodes(Node<T>* p) const;
};

#endif