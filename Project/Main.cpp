#include "BST.h"
#include "BST.cpp"
#include "Student.h"

#include <iostream>
#include <fstream>
using namespace std;

template <class T>
void processTree(BST<T>&, char[]);

template <class T>
void testTree(BST<T>&);

void processStudentTree(BST<Student>&, char[]);

int main()
{
	cout << "TESTING: Integer BST\n\n";
	BST<int> intBST;
	char fileNameInt1[] = "data_int_1.txt";
	processTree(intBST, fileNameInt1);
	testTree(intBST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: Deleting tree...\n\n";
	intBST.destroyTree();
	testTree(intBST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: Character BST\n\n";
	BST<char> charBST;
	char fileNameChar1[] = "data_char_1.txt";
	processTree(charBST, fileNameChar1);
	testTree(charBST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: Deleting tree...\n\n";
	charBST.destroyTree();
	testTree(charBST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: Double BST\n\n";
	BST<double> doubleBST;
	char fileNameDouble1[] = "data_double_1.txt";
	processTree(doubleBST, fileNameDouble1);
	testTree(doubleBST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: Student BST\n\n";
	BST<Student> studentBST;
	char fileNameStudent1[] = "data_student_1.txt";
	processStudentTree(studentBST, fileNameStudent1);
	testTree(studentBST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: Deleting tree...\n\n";
	doubleBST.destroyTree();
	testTree(doubleBST);

	cout << endl << endl;
	system("Pause");
	return 0;
}

template<class T>
void processTree(BST<T>& t, char fileName[])
{
	ifstream infile;
	infile.open(fileName);

	if (!infile)
		cerr << "Cannot open the input file." << endl;
	else
	{
		T data;
		infile >> data;

		while (!infile.eof())
		{
			t.insert(data);
			infile >> data;
		}

		infile.clear(); //reset eof for next input
	}

	infile.close();
}

template <class T>
void testTree(BST<T>& bst)
{
	//TEST: inorderTraversal
	cout << "Inorder traversal: ";
	bst.inorderTraversal();

	//TEST: totalNodes
	cout << "\nTotal nodes: " << bst.totalNodes();
}

void processStudentTree(BST<Student>& studentTree, char fileName[])
{
	ifstream infile;
	infile.open(fileName);

	if (!infile)
		cerr << "Cannot open the input file." << endl;
	else
	{
		int id;
		string fName, lName;
		Student student;

		infile >> id;

		while (!infile.eof())
		{
			infile >> fName;
			infile >> lName;

			student.setStudentInfo(id, fName, lName);

			studentTree.insert(student);

			infile >> id;
		}
		infile.clear(); //reset eof for next input
	}

	infile.close();
}