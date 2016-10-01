/*
Juarez, Freddy
CS A200
September 27, 2016

Class Student
*/

#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<iostream>
using namespace std;

class Student
{
	friend ostream& operator<<(ostream& out, const Student& s);
public:
	Student();

	void setStudentInfo(int newID, const string& newFirst, const string& newLast);

	bool operator==(const Student & otherStudent) const;

	bool operator>(const Student & otherStudent) const;

	Student operator=(const Student & otherStudent);

	~Student();

private:
	int ID;
	string firstName;
	string lastName;


};
#endif // !STUDENT_H