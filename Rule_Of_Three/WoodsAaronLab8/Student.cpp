#include "Student.h"
#include <iostream>

// Default constructor
Student::Student() {}

// SetGPA method
void Student::SetGPA(float newGPA)
{
	gpa = newGPA;
}

// Overridden DisplayRecord method
void Student::DisplayRecord()
{
	// Use GetName() to get the name
	std::cout << "Student Name: " << GetName() << std::endl;
	std::cout << "GPA: " << gpa << std::endl;
}

