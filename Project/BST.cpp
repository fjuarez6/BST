#include "BST.h"
#include "Student.h"

	//default constructor
template<class T>
BST<T>::BST()
{
	root = nullptr;
}

	//destructor
template<class T>
BST<T>::~BST()
{
	destroyTree(root);
}

	//destroyTree
template<class T>
void  BST<T>::destroyTree()
{
	destroyTree(root);
}

	//inorderTraversal
template<class T>
void BST<T>::inorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		inorderTraversal(root);
	}
}

	//totalNodes
template<class T>
int BST<T>::totalNodes() const
{
	if (root == nullptr)
		return 0;
	else
		return totalNodes(root);
}

	//destroy
template<class T>
void  BST<T>::destroyTree(Node<T>* &p)
{
	if(p != nullptr)
	{
		destroyTree(p->llink);
		destroyTree(p->rlink);
		delete p;
		p = nullptr;
	}
}

/***************************************************************

	Implement your functions below this line.

***************************************************************/

// Definition function insert (non-recursive)
//template<typename T>
//void BST<T>::insert(T num)
//{
//	Node *temp = root;
//
//	if (root == nullptr)
//	{
//		root = new Node();
//		root->data = num;
//		root->llink = nullptr;
//		root->rlink = nullptr;
//	}
//	else
//	{
//		bool check = false;
//
//		while (temp != nullptr && !check)
//		{
//
//			if (temp->data == num)
//			{
//				cout << "The item to insert is already in the list - duplicates are not allowed.";
//				check = true;
//			}
//			else
//			{
//				if (temp->data > num)
//				{
//					if (temp->llink == nullptr)
//					{
//
//						Node *newNode = new Node();
//						newNode->data = num;
//						newNode->llink = nullptr;
//						newNode->rlink = nullptr;
//						
//						temp->llink = newNode;
//						
//						check = true;
//					}
//					else
//					{
//						temp = temp->llink;
//
//					}
//				}
//				else if (num > temp->data)
//				{
//					if (temp->rlink == nullptr)
//					{
//						Node *newNode = new Node();
//						newNode->data = num;
//						newNode->llink = nullptr;
//						newNode->rlink = nullptr;
//
//						temp->rlink = newNode;
//
//						check = true;
//					}
//					else
//					{
//						temp = temp->rlink;
//					}
//				}
//			}
//		}
//	}
//}


 //Definition function insert (recursive)
template<class T>
void BST<T>::insert(T num)
{
	insert(num, root);
}

// Definition overloaded function insert (recursive)
template<class T>
void BST<T>::insert(T num, Node<T>* &p)
{

	if (p == nullptr)
	{
		Node<T> *newNode = new Node<T>();
		newNode->data = num;
		newNode->llink = nullptr;
		newNode->rlink = nullptr;
		p = newNode;

	}
	else if (p->data == num)
		cout << "The item to insert is already in the list - duplicates are not allowed.";
	else if (p->data > num)
		insert(num, p->llink);
	else
		insert(num, p->rlink);
}

// Definition overloaded function inorderTraversal(Node*)
template<class T>
void BST<T>::inorderTraversal(Node<T>* p) const
{
	if (p != nullptr)
	{
		inorderTraversal(p->llink);
		cout << p->data << " ";
		inorderTraversal(p->rlink);
	}
}

// Definition overloaded function totalNodes(Node*)
template<class T>
int BST<T>::totalNodes(Node<T>* p) const
{
	if (p != nullptr)
	{
		return (1 + totalNodes(p->llink) + totalNodes(p->rlink));
	}

	return 0;
}