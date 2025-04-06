#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student
{
public:
	//Constructors/Destructors
	Student(int _id, string _name, double _gpa, int _enrollmentYear);
	virtual ~Student(){ }

	//Accessors
	int GetId() { return m_id; }
	string GetName() { return m_name; }
	double GetGPA() { return m_gpa; }
	int GetEnrollmentYear() { return m_enrollmentYear; }

	void Display();

private:
	//Members
	int m_id;
	string m_name;
	double m_gpa;
	int m_enrollmentYear;
};

#endif // !STUDENT_H