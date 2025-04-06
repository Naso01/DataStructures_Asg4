#include "Student.h"

Student::Student(int _id, string _name, double _gpa, int _enrollmentYear) {
	m_id = _id;
	m_name = _name;
	m_gpa = _gpa;
	m_enrollmentYear = _enrollmentYear;
}

void Student::Display() {
	cout << "------------" << endl;
	cout << "ID: " << m_id << endl;
	cout << "Name: " << m_name << endl;
	cout << "GPA: " << m_gpa << endl;
	cout << "Enrollment Year: " << m_enrollmentYear << endl;
	cout << "------------" << endl;
}