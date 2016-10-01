#include "Student.h"

ostream& operator<<(ostream& out, const Student& s)
{
	out << s.ID << " - " << s.lastName << ", " << s.firstName << endl;
	return out;
}

Student::Student()
{
	ID = 0;
}

void Student::setStudentInfo(int newID, const string& newFirst, const string& newLast)
{
	ID = newID;
	firstName = newFirst;
	lastName = newLast;

}

bool Student::operator==(const Student &otherStudent) const
{
	return (ID == otherStudent.ID);
}

bool Student::operator>(const Student &otherStudent) const
{
	return(ID > otherStudent.ID);
}

Student Student::operator=(const Student &otherStudent)
{
	if (*this == otherStudent)
		cout << "Cannot Copy item to itself.";
	else
	{
		ID = otherStudent.ID;
		firstName = otherStudent.firstName;
		lastName = otherStudent.lastName;
	}
	return *this;
}

Student::~Student()
{}