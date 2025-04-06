// DataStructures_Asg4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SortingAlgorithms.h"
#include "Student.h"

int main()
{
    vector<Student> studentList;

    studentList.push_back(Student(105, "Ethan Williams", 3.65, 2021));
    studentList.push_back(Student(103, "Charlie Brown", 3.92, 2024));  
    studentList.push_back(Student(107, "George Miller", 3.20, 2022)); 
    studentList.push_back(Student(102, "Bob Johnson", 3.50, 2022));
    studentList.push_back(Student(106, "Fiona Garcia", 4.00, 2024));
    studentList.push_back(Student(101, "Alice Smith", 3.85, 2023));
    studentList.push_back(Student(108, "Hannah Davis", 3.95, 2025));
    studentList.push_back(Student(104, "Diana Lee", 3.78, 2023));
    
    

    SortingAlgorithms::printArray(studentList);
}
